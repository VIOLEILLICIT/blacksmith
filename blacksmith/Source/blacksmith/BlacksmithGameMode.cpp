#include "BlacksmithGameMode.h"
#include "TimerManager.h" 
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "EncyclopediaComponent.h"
#include "BlacksmithGameInstance.h"
#include "DaughterNPC.h"

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
 * 🛏️ 상호작용 검사: 딸 침대 (대사 및 조건 수정)
 * ================================================================= */
bool ABlacksmithGameMode::CheckCanUseDaughterBed(FText& OutDenyMessage)
{
	// 1. 전쟁 파병 (43일 차 이상)
	if (CurrentDay >= 43)
	{
		OutDenyMessage = FText::FromString(TEXT("딸은 전쟁터로 떠났다. 이제 이 침대를 쓸 일은 없다..."));
		return false;
	}

	// 2. 450초 이전 (낮 시간대) -> 일반적인 가구 조사 대사 출력
	if (CurrentTimeOfDay < 450.0f)
	{
		OutDenyMessage = FText::FromString(TEXT("딸의 침대이다."));
		return false;
	}

	// 3. 450초 이후, 딸을 데려오지 않았을 때 (연령 무관하게 자연스러운 텍스트)
	if (!bIsDaughterFound)
	{
		OutDenyMessage = FText::FromString(TEXT("먼저 딸을 데려와야 한다..."));
		return false;
	}

	// 4. 이미 재웠을 때
	if (bIsDaughterAsleep)
	{
		OutDenyMessage = FText::FromString(TEXT("딸은 이미 새근새근 자고 있다."));
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
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("🔍 스케줄에서 해금할 무기를 발견했습니다!"));
			
			if (ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0))
			{
				if (UEncyclopediaComponent* EncyclopediaComp = PlayerCharacter->FindComponentByClass<UEncyclopediaComponent>())
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("✅ 도감 컴포넌트 찾음! 해금을 시도합니다."));
					for (UItemDataAsset* WeaponToUnlock : TodayScheduleCache.WeaponsToUnlock)
					{
						if (WeaponToUnlock)
							EncyclopediaComp->UnlockItem(WeaponToUnlock);
					}
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("❌ 에러: 캐릭터에 도감 컴포넌트가 부착되어 있지 않습니다!"));
				}
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("❌ 에러: 플레이어 캐릭터를 찾을 수 없습니다!"));
			}
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("⚠️ 오늘자 스케줄에는 해금할 무기가 없습니다."));
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

	// 🟢 5. 아침 상태 및 딸 관련 변수 초기화
	CurrentTimeOfDay = 0.0f; 
	bIsDaughterAwake = false; 
	bIsDaughterFound = false;  // (추가) 다음 날이 되었으니 찾음 상태 초기화
	bIsDaughterAsleep = false; // (추가) 다음 날이 되었으니 수면 상태 초기화

	// 🟢 6. 맵에 있는 딸을 찾아서 투명화(수면 상태)를 해제하고 멈춰 세웁니다.
	if (AActor* DaughterActor = UGameplayStatics::GetActorOfClass(this, ADaughterNPC::StaticClass()))
	{
		if (ADaughterNPC* Daughter = Cast<ADaughterNPC>(DaughterActor))
		{
			// 전쟁터 파병 기간이 아닐 때만 모습을 켭니다.
			if (Daughter->CurrentPhase != EDaughterPhase::War)
			{
				Daughter->SetActorHiddenInGame(false);
				Daughter->SetActorEnableCollision(true);
			}
			Daughter->StopMoving();
		}
	}

	// 🟢 7. 블루프린트로 "새 아침이 밝았음" 신호를 발사합니다! (침대 위 텔레포트용)
	OnMorningResetEvent();
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

void ABlacksmithGameMode::BeginPlay()
{
	Super::BeginPlay();

	UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance());
	// 🔴 (주의) 블루프린트에서 DaughterClass를 안 넣었으면 여기서 막혀서 스폰 안 됨!
	if (!GI || !DaughterClass) return; 

	FString CurrentLevel = UGameplayStatics::GetCurrentLevelName(this);
	ADaughterNPC* ExistingDaughter = Cast<ADaughterNPC>(UGameplayStatics::GetActorOfClass(this, ADaughterNPC::StaticClass()));

	// 🟢 핵심 추가: 벽이나 바닥에 약간 겹쳐도 무조건 안전한 곳으로 밀어내서 스폰하도록 강제합니다!
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	if (GI->bIsDaughterFollowing)
	{
		ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0);
		if (Player)
		{
			FVector SpawnLoc = Player->GetActorLocation() + (Player->GetActorForwardVector() * -150.0f); 
			
			if (!ExistingDaughter) 
			{
				// 스폰 시 SpawnParams 옵션을 추가로 넘겨줍니다.
				ExistingDaughter = GetWorld()->SpawnActor<ADaughterNPC>(DaughterClass, SpawnLoc, Player->GetActorRotation(), SpawnParams);
			}
			else 
			{
				ExistingDaughter->SetActorLocation(SpawnLoc);
			}

			if (ExistingDaughter) ExistingDaughter->FollowPlayer(150.0f); 
		}
	}
	else if (GI->DaughterSavedLevel.ToString() == CurrentLevel)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsWithTag(this, GI->DaughterSavedLocationTag, FoundActors);
		if (FoundActors.Num() > 0)
		{
			if (!ExistingDaughter) 
			{
				ExistingDaughter = GetWorld()->SpawnActor<ADaughterNPC>(DaughterClass, FoundActors[0]->GetActorLocation(), FoundActors[0]->GetActorRotation(), SpawnParams);
			}
			else 
			{
				ExistingDaughter->SetActorLocation(FoundActors[0]->GetActorLocation());
			}
		}
	}
	else
	{
		if (GI->DaughterSavedLevel != NAME_None)
		{
			if (ExistingDaughter) ExistingDaughter->Destroy();
		}
	}
}