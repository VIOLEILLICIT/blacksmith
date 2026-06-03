#include "NPCComponent.h"

UNPCComponent::UNPCComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// 🟢 게임 시간(초)에 맞춰 가장 정확한 스케줄을 찾아내는 두뇌 로직
bool UNPCComponent::GetCurrentSchedule(int32 CurrentDay, float CurrentTimeOfDay, FNPCTimeSchedule& OutSchedule, int32& OutDateKey, int32& OutScheduleIndex)
{
	// 1. 현재 Phase 판별
	ETimePhase CurrentPhase = ETimePhase::Morning;
	if (CurrentTimeOfDay > 0.0f && CurrentTimeOfDay < 600.0f) CurrentPhase = ETimePhase::DayTimer;
	else if (CurrentTimeOfDay >= 600.0f) CurrentPhase = ETimePhase::Night;

	// 2. 오늘 날짜(Key) 찾기 (없으면 -1 매일 적용 스케줄 사용)
	int32 TargetKey = CurrentDay;
	if (!DailySchedules.Contains(TargetKey))
	{
		TargetKey = -1; 
	}

	// 3. 해당 날짜 스케줄이 존재한다면, 현재 시간(초)에 가장 알맞은 세트 찾기
	if (DailySchedules.Contains(TargetKey))
	{
		const FNPCDaySchedule& DayData = DailySchedules[TargetKey];
		int32 BestIndex = -1;
		float MaxSec = -1.0f;

		for (int32 i = 0; i < DayData.TimeSchedules.Num(); i++)
		{
			const FNPCTimeSchedule& Sched = DayData.TimeSchedules[i];
			if (Sched.TargetPhase == CurrentPhase)
			{
				if (CurrentPhase == ETimePhase::DayTimer)
				{
					// 타이머 진행 중일 땐 TriggerSecond를 비교하여 가장 최근에 지난 스케줄을 적용
					if (CurrentTimeOfDay >= Sched.TriggerSecond && Sched.TriggerSecond >= MaxSec)
					{
						MaxSec = Sched.TriggerSecond;
						BestIndex = i;
					}
				}
				else
				{
					BestIndex = i;
				}
			}
		}

		// 적절한 스케줄을 찾았다면 반환!
		if (BestIndex != -1)
		{
			OutSchedule = DayData.TimeSchedules[BestIndex];
			OutDateKey = TargetKey;
			OutScheduleIndex = BestIndex;
			return true;
		}
	}

	return false; 
}

void UNPCComponent::IncrementInteractionCount()
{
	InteractionCount++;
}