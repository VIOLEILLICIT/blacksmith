#include "BlacksmithGameMode.h"
#include "TimerManager.h" 

ABlacksmithGameMode::ABlacksmithGameMode()
{
}

// 🪑 휴식 의자 상호작용 가능 여부를 완벽하게 계산해 주는 함수
bool ABlacksmithGameMode::CheckCanUseRestChair(FText& OutDenyMessage)
{
	// 1. 공통 룰: 7분 30초 (450초) 이상이면 무조건 사용 불가 (기획 요구사항)
	if (CurrentTimeOfDay >= 450.0f)
	{
		OutDenyMessage = FText::FromString(TEXT("슬슬 딸을 찾아봐야 할 시간이다. 쉴 수 없다."));
		return false;
	}

	// 2. 공통 룰: 28일 이전 && 3분(180초) 이전이면 사용 불가 (딸이 따라다님)
	if (CurrentDay <= 28 && CurrentTimeOfDay < 180.0f)
	{
		OutDenyMessage = FText::FromString(TEXT("딸이 아직 곁에 있어서 쉴 수 없다."));
		return false;
	}

	// 3. 커스텀 룰: 오늘(CurrentDay) 날짜에 특별한 세팅이 있는지 검사
	if (DailyScheduleMap.Contains(CurrentDay))
	{
		const FDailySchedule& TodaySchedule = DailyScheduleMap[CurrentDay];
		
		// 오늘 스케줄에 휴식 의자 강제 금지(bCanUseRestChair = false)가 걸려있다면?
		if (!TodaySchedule.bCanUseRestChair)
		{
			// 인스펙터에 적어둔 커스텀 대사를 내보내고 거부
			OutDenyMessage = TodaySchedule.ChairDenyMessage; 
			return false;
		}
	}

	// 위 3단계를 모두 통과했다면 사용 가능!
	return true;
}

void ABlacksmithGameMode::StartDailyTimer()
{
	// 시간 및 상태 초기화
	CurrentTimeOfDay = 0.0f;
	bIsTimeToGoHome = false;
	bIsDaughterFound = false;

	// 1초에 한 번씩 AdvanceTimeOneSecond 함수를 무한 반복 실행!
	GetWorld()->GetTimerManager().SetTimer(
		DailyTimerHandle, this, &ABlacksmithGameMode::AdvanceTimeOneSecond, 1.0f, true);
}

void ABlacksmithGameMode::AdvanceTimeOneSecond()
{
	CurrentTimeOfDay += 1.0f; // 1초 증가

	// 오늘 날짜의 커스텀 타이머 이벤트가 있는지 검사!
	if (DailyScheduleMap.Contains(CurrentDay))
	{
		const FDailySchedule& TodaySchedule = DailyScheduleMap[CurrentDay];
		
		// 오늘 등록된 모든 타이머 이벤트들을 훑어봄
		for (const FTimerEventData& TEvent : TodaySchedule.TimerEvents)
		{
			// 타이머 초(Second)가 일치하면 블루프린트로 이벤트 쏴주기!
			if (FMath::IsNearlyEqual(CurrentTimeOfDay, TEvent.TriggerSecond))
			{
				OnTriggerCustomTimeEvent(TEvent.EventID, TEvent.WidgetToShow);
			}
		}
	}

	// 기존 고정 이벤트들 (3분, 7.5분, 10분 등)
	if (CurrentTimeOfDay == 180.0f) 
	{
		OnDaughterHideEvent();
	}
	else if (CurrentTimeOfDay == 450.0f) 
	{
		bIsTimeToGoHome = true;
		OnTimeToGoHomeEvent();
	}
	else if (CurrentTimeOfDay >= 600.0f) 
	{
		GetWorld()->GetTimerManager().ClearTimer(DailyTimerHandle);
		OnDayOverEvent();
	}
}

// 휴식 의자에서 타임워프를 불렀을 때 (TargetSeconds = 450.0f 로 호출)
void ABlacksmithGameMode::WarpTimeTo(float TargetSeconds)
{
	if (CurrentTimeOfDay < TargetSeconds)
	{
		// 워프를 함으로써 스킵하게 되는 이벤트들을 강제로 발동시켜줍니다. (오류 방지)
		if (CurrentTimeOfDay < 180.0f && TargetSeconds >= 180.0f)
		{
			OnDaughterHideEvent();
		}
		
		if (CurrentTimeOfDay < 450.0f && TargetSeconds >= 450.0f)
		{
			bIsTimeToGoHome = true;
			OnTimeToGoHomeEvent();
		}

		// 시간을 원하는 만큼 점프!
		CurrentTimeOfDay = TargetSeconds;
	}
}

void ABlacksmithGameMode::SleepAndNextDay()
{
	CurrentDay++; // 날짜 1 증가
	DaysUntilDeadline--; // 의뢰 기한 1 감소
}