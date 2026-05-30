#include "BlacksmithGameMode.h"
#include "TimerManager.h" 

ABlacksmithGameMode::ABlacksmithGameMode()
{
}

/* =================================================================
 * 🪑 상호작용 검사: 휴식 의자 (기존 로직 유지)
 * ================================================================= */
bool ABlacksmithGameMode::CheckCanUseRestChair(FText& OutDenyMessage)
{
	// 1. 공통 룰: 7분 30초 (450초) 이상이면 무조건 사용 불가
	if (CurrentTimeOfDay >= 450.0f)
	{
		// 🟢 [추가 및 수정] 43일 이후 (딸이 전장에 가거나 납치된 이후)의 대사 분기
		if (CurrentDay >= 43)
		{
			OutDenyMessage = FText::FromString(TEXT("지금은 쉬고 싶지 않다..."));
		}
		else
		{
			OutDenyMessage = FText::FromString(TEXT("슬슬 딸을 찾아봐야 할 시간이다. 쉴 수 없다."));
		}
		return false;
	}

	// 2. 공통 룰: 28일 이전 && 3분(180초) 이전이면 사용 불가 (딸이 따라다님)
	if (CurrentDay <= 28 && CurrentTimeOfDay < 180.0f)
	{
		OutDenyMessage = FText::FromString(TEXT("딸이 아직 곁에 있어서 쉴 수 없다."));
		return false;
	}

	// 3. 커스텀 룰: 오늘 날짜의 특별 스케줄 검사
	if (DailyScheduleMap.Contains(CurrentDay))
	{
		const FDailySchedule& TodaySchedule = DailyScheduleMap[CurrentDay];
		
		if (!TodaySchedule.bCanUseRestChair)
		{
			OutDenyMessage = TodaySchedule.ChairDenyMessage; 
			return false;
		}
	}

	return true;
}

/* =================================================================
 * 🛏️ 상호작용 검사: 침대 (수면)
 * ================================================================= */
bool ABlacksmithGameMode::CheckCanUseBed(FText& OutDenyMessage)
{
	// 밤(600초)이 되지 않았다면 잘 수 없음
	if (CurrentTimeOfDay < 600.0f)
	{
		OutDenyMessage = FText::FromString(TEXT("아직 해가 떠 있다. 지금 잘 수는 없다."));
		return false;
	}

	// 42일 이하(딸이 집에 있음)일 때만 딸을 재웠는지 검사! (43일부터는 혼자 잠듦)
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
	// 28일 이하(딸의 어린 시절)일 때, 아침에 딸을 깨우지 않았다면 외출 불가
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
	// 아침이 밝았을 때 시간 및 상태 초기화
	CurrentTimeOfDay = 0.0f;
	bIsTimeToGoHome = false;
	bIsDaughterFound = false;
	bIsDaughterAsleep = false; 

	// 1초에 한 번씩 AdvanceTimeOneSecond 무한 반복 실행
	GetWorld()->GetTimerManager().SetTimer(
		DailyTimerHandle, this, &ABlacksmithGameMode::AdvanceTimeOneSecond, 1.0f, true);
}

void ABlacksmithGameMode::AdvanceTimeOneSecond()
{
	CurrentTimeOfDay += 1.0f; // 1초 증가

	// 오늘 날짜의 커스텀 타이머 이벤트 검사
	if (DailyScheduleMap.Contains(CurrentDay))
	{
		const FDailySchedule& TodaySchedule = DailyScheduleMap[CurrentDay];
		
		for (const FTimerEventData& TEvent : TodaySchedule.TimerEvents)
		{
			if (FMath::IsNearlyEqual(CurrentTimeOfDay, TEvent.TriggerSecond))
			{
				OnTriggerCustomTimeEvent(TEvent.EventID, TEvent.WidgetToShow);
			}
		}
	}

	// 1. 3분(180초) 숨바꼭질 이벤트: 28일(어린 시절)까지만 발생
	if (CurrentDay <= 28 && CurrentTimeOfDay == 180.0f) 
	{
		OnDaughterHideEvent();
	}
	
	// 2. 7.5분(450초) 귀가 시간 이벤트: 42일(마을 체류)까지만 발생
	if (CurrentDay <= 42 && CurrentTimeOfDay == 450.0f) 
	{
		bIsTimeToGoHome = true;
		OnTimeToGoHomeEvent();
	}

	// 3. 10분(600초) 하루 종료: 매일 발생
	if (CurrentTimeOfDay >= 600.0f) 
	{
		GetWorld()->GetTimerManager().ClearTimer(DailyTimerHandle);
		OnDayOverEvent();
	}
}

// 타임 워프 (시간 건너뛰기)
void ABlacksmithGameMode::WarpTimeTo(float TargetSeconds)
{
	if (CurrentTimeOfDay < TargetSeconds)
	{
		// 워프 중 스킵되는 이벤트 강제 발동 (날짜 조건 동일하게 적용)
		if (CurrentDay <= 28 && CurrentTimeOfDay < 180.0f && TargetSeconds >= 180.0f)
		{
			OnDaughterHideEvent();
		}
		
		if (CurrentDay <= 42 && CurrentTimeOfDay < 450.0f && TargetSeconds >= 450.0f)
		{
			bIsTimeToGoHome = true;
			OnTimeToGoHomeEvent();
		}

		CurrentTimeOfDay = TargetSeconds;
	}
}

// 수면 후 다음 날 처리
void ABlacksmithGameMode::SleepAndNextDay()
{
	CurrentDay++; // 날짜 1 증가
	DaysUntilDeadline--; // 의뢰 기한 1 감소

	// 🟢 [추가] 다음 날 아침이 되었으므로 시간을 0초로 초기화!
	CurrentTimeOfDay = 0.0f;

	// 다음 날이 되었으니 딸 기상 상태 초기화
	bIsDaughterAwake = false; 
}

// 🟢 [추가] 까방권(유예 기간) 발동 로직
FText ABlacksmithGameMode::ActivateGracePeriod()
{
	// =========================================================
	// 1. 기존 스케줄들을 7일씩 뒤로 밀어버리기
	// =========================================================
	int32 MaxDay = 0;
	// 맵에 등록된 가장 마지막 날짜 찾기
	for (auto& Pair : DailyScheduleMap)
	{
		if (Pair.Key > MaxDay) MaxDay = Pair.Key;
	}

	// 현재 날짜(CurrentDay) 다음 날부터 제일 끝 날짜까지 역순으로 돌면서 7일 뒤로 이사시킵니다.
	for (int32 i = MaxDay; i > CurrentDay; i--)
	{
		if (DailyScheduleMap.Contains(i))
		{
			DailyScheduleMap.Add(i + 7, DailyScheduleMap[i]);
			DailyScheduleMap.Remove(i);
		}
	}

	// =========================================================
	// 2. 현재 메인 퀘스트 무기의 '해금 조건 숫자' 가져오기
	// =========================================================
	int32 MainWeaponUnlockNum = 0;
	if (CurrentMainQuest.TargetItem)
	{
		// FString으로 적힌 해금조건("3", "5" 등)을 실제 숫자(int)로 변환합니다.
		MainWeaponUnlockNum = FCString::Atoi(*CurrentMainQuest.TargetItem->UnlockCondition);
	}

	// 조건에 맞는(메인 무기 숫자 이하인) 무기들만 따로 골라냅니다.
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

	// =========================================================
	// 3. 밀어낸 7일(유예 기간) 동안의 일일 서브 퀘스트 채우기
	// =========================================================
	for (int32 i = 1; i <= 7; i++)
	{
		int32 GraceDay = CurrentDay + i;
		FDailySchedule GraceSchedule;
		GraceSchedule.bHasMainQuest = false; // 유예 기간이므로 메인 퀘스트는 없음
		
		// 유효한 무기가 하나라도 있다면 랜덤으로 뽑습니다.
		if (ValidWeapons.Num() > 0)
		{
			int32 RandomIndex = FMath::RandRange(0, ValidWeapons.Num() - 1);
			UItemDataAsset* SelectedWeapon = ValidWeapons[RandomIndex];
			int32 SelectedUnlockNum = FCString::Atoi(*SelectedWeapon->UnlockCondition);

			FQuestData GraceQuest;
			GraceQuest.bIsMainQuest = false;
			GraceQuest.QuestName = TEXT("유예 기간 특별 의뢰");
			GraceQuest.TargetItem = SelectedWeapon;
			
			// [기획 규칙] 메인 무기와 해금 숫자가 같으면 5개, 낮으면 10개
			if (SelectedUnlockNum == MainWeaponUnlockNum)
			{
				GraceQuest.TargetQuantity = 5;
			}
			else
			{
				GraceQuest.TargetQuantity = 10;
			}

			// [기획 규칙] 의뢰 내용: "{아이템 이름}을(를) 만들어 주세요."
			GraceQuest.QuestDescription = FText::Format(
				FText::FromString(TEXT("{0}을(를) 만들어 주세요.")),
				FText::FromString(SelectedWeapon->ItemName)
			);

			// 완성된 유예 퀘스트를 그날의 스케줄에 추가
			GraceSchedule.SubQuests.Add(GraceQuest);
		}

		// 맵에 유예 기간 스케줄(GraceDay) 등록
		DailyScheduleMap.Add(GraceDay, GraceSchedule);
	}

	// =========================================================
	// 4. 마감일 7일 연장 및 대사 반환
	// =========================================================
	DaysUntilDeadline += 7;

	// 블루프린트에서 화면에 바로 띄울 수 있도록 인스펙터에 적어둔 텍스트를 반환합니다.
	return GracePeriodUseText;
}