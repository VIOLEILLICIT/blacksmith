#include "BlacksmithGameMode.h"
#include "TimerManager.h" 
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "EncyclopediaComponent.h"

ABlacksmithGameMode::ABlacksmithGameMode()
{
}

/* =================================================================
 * 🪑 상호작용 검사: 휴식 의자
 * ================================================================= */
bool ABlacksmithGameMode::CheckCanUseRestChair(FText& OutDenyMessage)
{
	if (CurrentTimeOfDay >= 450.0f)
	{
		if (CurrentDay >= 43)
			OutDenyMessage = FText::FromString(TEXT("지금은 쉬고 싶지 않다..."));
		else
			OutDenyMessage = FText::FromString(TEXT("슬슬 딸을 찾아봐야 할 시간이다. 쉴 수 없다."));
		return false;
	}

	if (CurrentDay <= 28 && CurrentTimeOfDay < 180.0f)
	{
		OutDenyMessage = FText::FromString(TEXT("딸이 아직 곁에 있어서 쉴 수 없다."));
		return false;
	}

	if (DailyScheduleMap.Contains(CurrentDay))
	{
		const FDailySchedule& TempSchedule = DailyScheduleMap[CurrentDay];
		if (!TempSchedule.bCanUseRestChair)
		{
			OutDenyMessage = TempSchedule.ChairDenyMessage; 
			return false;
		}
	}

	return true;
}

/* =================================================================
 * 🛏️ 상호작용 검사: 침대
 * ================================================================= */
bool ABlacksmithGameMode::CheckCanUseBed(FText& OutDenyMessage)
{
	if (CurrentTimeOfDay < 600.0f)
	{
		OutDenyMessage = FText::FromString(TEXT("아직 해가 떠 있다. 지금 잘 수는 없다."));
		return false;
	}

	if (CurrentDay <= 42 && !bIsDaughterAsleep)
	{
		OutDenyMessage = FText::FromString(TEXT("먼저 딸을 침대에 눕혀서 재워야 한다..."));
		return false;
	}

	return true;
}

/* =================================================================
 * 🚪 상호작용 검사: 문 (외출)
 * ================================================================= */
bool ABlacksmithGameMode::CheckCanUseDoor(FText& OutDenyMessage)
{
	if (CurrentDay <= 28 && !bIsDaughterAwake)
	{
		OutDenyMessage = FText::FromString(TEXT("아직 딸이 자고 있다. 먼저 깨우고 나가자..."));
		return false;
	}

	return true;
}

/* =================================================================
 * 타이머 및 시간 흐름 관리
 * ================================================================= */
void ABlacksmithGameMode::StartDailyTimer()
{
	CurrentTimeOfDay = 0.0f;
	bIsTimeToGoHome = false;
	bIsDaughterFound = false;
	bIsDaughterAsleep = false; 

	if (DailyScheduleMap.Contains(CurrentDay))
	{
		bHasTodaySchedule = true;
		TodayScheduleCache = DailyScheduleMap[CurrentDay];

		// 새 메인 퀘스트 발급 로직
		if (TodayScheduleCache.bHasMainQuest)
		{
			CurrentMainQuest = TodayScheduleCache.MainQuest;
			bIsMainQuestCompleted = false; 
			bHasActiveMainQuest = true; // 메인 퀘스트 활성화!
			DaysUntilDeadline = DefaultStartingDeadline; 
		}

		// 무기 도감 자동 해금
		if (TodayScheduleCache.WeaponsToUnlock.Num() > 0)
		{
			if (ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0))
			{
				if (UEncyclopediaComponent* EncyclopediaComp = PlayerCharacter->FindComponentByClass<UEncyclopediaComponent>())
				{
					for (UItemDataAsset* WeaponToUnlock : TodayScheduleCache.WeaponsToUnlock)
					{
						if (WeaponToUnlock)
							EncyclopediaComp->UnlockItem(WeaponToUnlock);
					}
				}
			}
		}

		// 진행 목록에 오늘의 서브 퀘스트 추가
		for (const FQuestData& NewSubQuest : TodayScheduleCache.SubQuests)
		{
			ActiveSubQuests.Add(NewSubQuest);
		}
	}
	else
	{
		bHasTodaySchedule = false; 
	}

	GetWorld()->GetTimerManager().SetTimer(DailyTimerHandle, this, &ABlacksmithGameMode::AdvanceTimeOneSecond, 1.0f, true);
}

void ABlacksmithGameMode::AdvanceTimeOneSecond()
{
	CurrentTimeOfDay += 1.0f; 

	if (bHasTodaySchedule)
	{
		for (const FTimerEventData& TEvent : TodayScheduleCache.TimerEvents)
		{
			if (FMath::IsNearlyEqual(CurrentTimeOfDay, TEvent.TriggerSecond))
				OnTriggerCustomTimeEvent(TEvent.EventID, TEvent.WidgetToShow);
		}
	}

	if (CurrentDay <= 28 && CurrentTimeOfDay == 180.0f) 
		OnDaughterHideEvent();
	
	if (CurrentDay <= 42 && CurrentTimeOfDay == 450.0f) 
	{
		bIsTimeToGoHome = true;
		OnTimeToGoHomeEvent();
	}

	// 🟢 600초 도달 (딸 수면 경고 시스템 작동)
	if (CurrentTimeOfDay >= 600.0f) 
	{
		GetWorld()->GetTimerManager().ClearTimer(DailyTimerHandle);
		
		if (CurrentDay <= 42 && !bIsDaughterAsleep)
		{
			DaughterSleepWarningCount++; 

			if (DaughterSleepWarningCount == 1)
			{
				const TArray<FGeneralEventData>& EventsToPlay = bIsDaughterFound ? Warning1_FoundEvents : Warning1_NotFoundEvents;
				for (const FGeneralEventData& Event : EventsToPlay) OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
			}
			else if (DaughterSleepWarningCount == 2)
			{
				const TArray<FGeneralEventData>& EventsToPlay = bIsDaughterFound ? Warning2_FoundEvents : Warning2_NotFoundEvents;
				for (const FGeneralEventData& Event : EventsToPlay) OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
			}
			else if (DaughterSleepWarningCount >= 3)
			{
				OnGameOverEvent(); 
				const TArray<FGeneralEventData>& EventsToPlay = bIsDaughterFound ? GameOver_FoundEvents : GameOver_NotFoundEvents;
				for (const FGeneralEventData& Event : EventsToPlay) OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
				return; // 3차는 게임 오버이므로 자율 시간 시작 안 함
			}
		}

		OnFreeTimeStartEvent();
	}
}

// 🪑 타임 워프 (시간 건너뛰기)
void ABlacksmithGameMode::WarpTimeTo(float TargetSeconds)
{
	if (CurrentTimeOfDay < TargetSeconds)
	{
		if (CurrentDay <= 28 && CurrentTimeOfDay < 180.0f && TargetSeconds >= 180.0f)
			OnDaughterHideEvent();
		
		if (CurrentDay <= 42 && CurrentTimeOfDay < 450.0f && TargetSeconds >= 450.0f)
		{
			bIsTimeToGoHome = true;
			OnTimeToGoHomeEvent();
		}

		CurrentTimeOfDay = TargetSeconds;

		// 🟢 워프 직후 600초 도달 시 (딸 수면 경고 시스템 동일하게 작동)
		if (CurrentTimeOfDay >= 600.0f)
		{
			GetWorld()->GetTimerManager().ClearTimer(DailyTimerHandle);
			
			if (CurrentDay <= 42 && !bIsDaughterAsleep)
			{
				DaughterSleepWarningCount++; 

				if (DaughterSleepWarningCount == 1)
				{
					const TArray<FGeneralEventData>& EventsToPlay = bIsDaughterFound ? Warning1_FoundEvents : Warning1_NotFoundEvents;
					for (const FGeneralEventData& Event : EventsToPlay) OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
				}
				else if (DaughterSleepWarningCount == 2)
				{
					const TArray<FGeneralEventData>& EventsToPlay = bIsDaughterFound ? Warning2_FoundEvents : Warning2_NotFoundEvents;
					for (const FGeneralEventData& Event : EventsToPlay) OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
				}
				else if (DaughterSleepWarningCount >= 3)
				{
					OnGameOverEvent(); 
					const TArray<FGeneralEventData>& EventsToPlay = bIsDaughterFound ? GameOver_FoundEvents : GameOver_NotFoundEvents;
					for (const FGeneralEventData& Event : EventsToPlay) OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
					return; 
				}
			}
			OnFreeTimeStartEvent();
		}
	}
}

// 🛏️ 수면 후 다음 날 처리 (하루 결산)
void ABlacksmithGameMode::SleepAndNextDay()
{
	// 🟢 1. 잠을 잤으니 무조건 기한부터 하루 깎습니다.
	DaysUntilDeadline--; 

	// 🟢 2. 깎인 마감일이 0이 되었는지 검사 (억울한 실패 방지 스위치 포함)
	if (bHasActiveMainQuest && DaysUntilDeadline <= 0 && !bIsMainQuestCompleted)
	{
		if (!bIsGracePeriodUsed)
		{
			// 첫 번째 실패: 까방권 발동
			FText GraceMsg = ActivateGracePeriod();
			bIsGracePeriodUsed = true; 
			
			for (const FGeneralEventData& Event : GracePeriodEvents)
				OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
		}
		else
		{
			// 두 번째 실패: 게임 오버
			OnGameOverEvent(); 
			
			for (const FGeneralEventData& Event : GameOverEvents)
				OnTriggerGeneralEvent(Event.EventID, Event.WidgetToShow);
				
			return; // 게임 오버 시 여기서 완전히 멈춤
		}
	}

	// 3. 정상 진행: 날짜 증가
	CurrentDay++; 

	// 4. 서브 퀘스트 기한 차감 및 만료된 것 삭제
	for (int32 i = ActiveSubQuests.Num() - 1; i >= 0; i--)
	{
		ActiveSubQuests[i].DeadlineDays--; 
		if (ActiveSubQuests[i].DeadlineDays <= 0)
		{
			ActiveSubQuests.RemoveAt(i); 
		}
	}

	CurrentTimeOfDay = 0.0f; 
	bIsDaughterAwake = false; 
}

// 🟢 까방권(유예 기간) 작동 로직
FText ABlacksmithGameMode::ActivateGracePeriod()
{
	int32 MaxDay = 0;
	
	// 전체 스케줄의 마지막 날짜 찾기
	for (auto& Pair : DailyScheduleMap)
	{
		if (Pair.Key > MaxDay) MaxDay = Pair.Key;
	}

	// 미래의 스케줄을 통째로 7일 뒤로 밀어내기
	for (int32 i = MaxDay; i > CurrentDay; i--)
	{
		if (DailyScheduleMap.Contains(i))
		{
			DailyScheduleMap.Add(i + GracePeriodDays, DailyScheduleMap[i]);
			DailyScheduleMap.Remove(i);
		}
	}

	// 현재 메인 무기의 해금 조건 숫자 추출
	int32 MainWeaponUnlockNum = 0;
	if (CurrentMainQuest.TargetItem)
	{
		MainWeaponUnlockNum = FCString::Atoi(*CurrentMainQuest.TargetItem->UnlockCondition);
	}

	// 해금 조건 숫자 이하의 무기들만 후보군으로 수집
	TArray<UItemDataAsset*> ValidWeapons;
	for (UItemDataAsset* Weapon : WeaponDatabase)
	{
		if (Weapon && Weapon->ItemCategory == EItemCategory::Weapon)
		{
			int32 WeaponUnlockNum = FCString::Atoi(*Weapon->UnlockCondition);
			if (WeaponUnlockNum <= MainWeaponUnlockNum)
			{
				ValidWeapons.Add(Weapon);
			}
		}
	}

	// 🟢 밀어낸 7일 동안 매일매일 '1일 기한짜리' 파밍 서브 퀘스트 생성
	for (int32 i = 1; i <= GracePeriodDays; i++)
	{
		int32 GraceDay = CurrentDay + i; 
		FDailySchedule GraceSchedule;
		GraceSchedule.bHasMainQuest = false; 
		
		if (ValidWeapons.Num() > 0) 
		{
			int32 RandomIndex = FMath::RandRange(0, ValidWeapons.Num() - 1);
			UItemDataAsset* SelectedWeapon = ValidWeapons[RandomIndex];
			int32 SelectedUnlockNum = FCString::Atoi(*SelectedWeapon->UnlockCondition);

			FQuestData GraceQuest;
			GraceQuest.bIsMainQuest = false;
			GraceQuest.QuestName = TEXT("유예 기간 일일 의뢰");
			GraceQuest.TargetItem = SelectedWeapon;
			
			// 요구 수량 밸런싱
			if (SelectedUnlockNum == MainWeaponUnlockNum)
				GraceQuest.TargetQuantity = 5;
			else
				GraceQuest.TargetQuantity = 10;

			GraceQuest.QuestDescription = FText::Format(
				FText::FromString(TEXT("{0}을(를) 만들어 주세요.")),
				FText::FromString(SelectedWeapon->ItemName)
			);
			
			// 🟢 1일로 고정! 당일 못 깨면 사라짐
			GraceQuest.DeadlineDays = 1; 

			// 🟢 퀘스트 완료 보상 (재화 = 아이템 판매가 * 요구 수량)
			FQuestReward CurrencyReward;
			CurrencyReward.RewardType = ERewardType::Currency;
			CurrencyReward.RewardAmount = SelectedWeapon->SellPrice * GraceQuest.TargetQuantity; 
			GraceQuest.QuestRewards.Add(CurrencyReward);

			GraceSchedule.SubQuests.Add(GraceQuest);
		}

		DailyScheduleMap.Add(GraceDay, GraceSchedule);
	}

	// 까방권 일수만큼 메인 마감일 연장
	DaysUntilDeadline += GracePeriodDays; 

	return GracePeriodUseText;
}