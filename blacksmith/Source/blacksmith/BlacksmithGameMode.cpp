#include "BlacksmithGameMode.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "EncyclopediaComponent.h"
#include "InventoryComponent.h"
#include "BlacksmithGameInstance.h"
#include "BlacksmithPlayer.h"
#include "DaughterNPC.h"
#include "TalkWidget.h"
#include "TimeHUDWidget.h"
#include "Components/TextBlock.h"

ABlacksmithGameMode::ABlacksmithGameMode()
{
}

/* =================================================================
 * 🪑 상호작용 검사: 휴식 의자
 * ================================================================= */
bool ABlacksmithGameMode::CheckCanUseRestChair(FText& OutDenyMessage)
{
	// 🟢 [추가됨] 우편함을 열어 일과(타이머)를 시작했는지 가장 먼저 검사합니다!
	if (!bIsDailyTimerStarted)
	{
		OutDenyMessage = FText::FromString(TEXT("아직 일과를 시작하지 않았다. 먼저 우편함을 확인하자."));
		return false;
	}
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
	// 🟢 [추가] 이미 우편함을 열어 타이머가 시작되었다면 무시하고 돌아갑니다!
	if (bIsDailyTimerStarted) return;

	bIsDailyTimerStarted = true;

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
	{
		OnDaughterHideEvent();
		if (AActor* DaughterActor = UGameplayStatics::GetActorOfClass(this, ADaughterNPC::StaticClass()))
		{
			if (ADaughterNPC* Daughter = Cast<ADaughterNPC>(DaughterActor))
			{
				Daughter->ShowHideoutDialogueAndTeleport();
			}
		}
	}

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

		// 🟢 [여기에 추가!] 600초가 되어 밤이 시작될 때 '밤 이벤트'들을 모두 발사합니다!
		if (bHasTodaySchedule)
		{
			for (const FGeneralEventData& NEvent : TodayScheduleCache.NightEvents)
			{
				OnTriggerGeneralEvent(NEvent.EventID, NEvent.WidgetToShow);
			}
		}
	}
}

// 🪑 타임 워프 (시간 건너뛰기)
void ABlacksmithGameMode::WarpTimeTo(float TargetSeconds)
{
	if (CurrentTimeOfDay < TargetSeconds)
	{
		if (CurrentDay <= 28 && CurrentTimeOfDay < 180.0f && TargetSeconds >= 180.0f)
		{
			OnDaughterHideEvent();
			if (AActor* DaughterActor = UGameplayStatics::GetActorOfClass(this, ADaughterNPC::StaticClass()))
			{
				if (ADaughterNPC* Daughter = Cast<ADaughterNPC>(DaughterActor))
				{
					Daughter->ShowHideoutDialogueAndTeleport();
				}
			}
		}

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
	bIsDailyTimerStarted = false;
	bIsDaughterAwake = false;
	bIsDaughterFound = false;  // (추가) 다음 날이 되었으니 찾음 상태 초기화
	bIsDaughterAsleep = false; // (추가) 다음 날이 되었으니 수면 상태 초기화

	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		GI->bIsDaughterAwake = false;
		GI->bIsDaughterFound = false;
		GI->bMorningDialogueShownToday = false; // 새 날 → 아침 대사 초기화
	}

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

	// 7. 블루프린트로 "새 아침이 밝았음" 신호를 발사합니다! (침대 위 텔레포트용)
	OnMorningResetEvent();

	// 🟢 아침 대사 배열에서 대사를 확인합니다.
	int32 DialogueIndex = CurrentDay; 

	if (DailyMorningDialogueArray.IsValidIndex(DialogueIndex) && 
		!DailyMorningDialogueArray[DialogueIndex].IsEmpty() && 
		MorningTalkWidgetClass)
	{
		if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
		{
			UTalkWidget* MorningWidget = CreateWidget<UTalkWidget>(PC, MorningTalkWidgetClass);
			if (MorningWidget)
			{
				MorningWidget->AddToViewport();
				
				// =====================================================================
				// 🟢 [수정됨] 블루프린트 이벤트 호출 대신, C++에서 다이렉트로 글자를 꽂아줍니다!
				// =====================================================================
				if (MorningWidget->descript)
				{
					MorningWidget->descript->SetText(DailyMorningDialogueArray[DialogueIndex]);
				}
				
				// 대사 창이 닫히면 기존 스케줄(Morning Events) 실행
				MorningWidget->OnTalkClosed.AddDynamic(this, &ABlacksmithGameMode::ExecuteMorningEvents);

				// UI 조작 모드 활성화
				FInputModeUIOnly InputMode;
				InputMode.SetWidgetToFocus(MorningWidget->TakeWidget());
				PC->SetInputMode(InputMode);
				PC->FlushPressedKeys();
				PC->SetShowMouseCursor(true);

				return; // 대기
			}
		}
	}

	// 해당 일차의 대사가 비어있다면 대기하지 않고 즉시 스케줄 이벤트 실행
	ExecuteMorningEvents();
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

	// 데이터 복구 (현재 CurrentDay 등이 복구됨)
    RestoreGlobalData();

    // 1. 아침 초기화 로직 (대사 띄우기)
	ResetMorningState();

	// 시간 HUD 생성
	if (TimeHUDWidgetClass)
	{
		if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
		{
			UTimeHUDWidget* TimeHUD = CreateWidget<UTimeHUDWidget>(PC, TimeHUDWidgetClass);
			if (TimeHUD)
			{
				TimeHUD->AddToViewport();
			}
		}
	}

	UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance());
	// 🔴 (주의) 블루프린트에서 DaughterClass를 안 넣었으면 여기서 막혀서 스폰 안 됨!
	if (!GI || !DaughterClass) return;

	// 🟢 [핵심 추가] 맵이 새로 켜질 때, 지워진 플래그를 GameInstance에서 가져와 복구합니다!
	this->bIsDaughterAwake = GI->bIsDaughterAwake;
	this->bIsDaughterFound = GI->bIsDaughterFound;

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

void ABlacksmithGameMode::SaveGlobalData()
{
	UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance());
	if (!GI) return;

	// 1. 게임 진행 데이터 백업
	GI->SavedCurrentDay = this->CurrentDay;
	GI->SavedCurrentTimeOfDay = this->CurrentTimeOfDay;
	GI->SavedDaysUntilDeadline = this->DaysUntilDeadline;
	GI->SavedHasActiveMainQuest = this->bHasActiveMainQuest;
	GI->SavedCurrentMainQuest = this->CurrentMainQuest;
	GI->SavedIsMainQuestCompleted = this->bIsMainQuestCompleted;
	GI->SavedIsGracePeriodUsed = this->bIsGracePeriodUsed;
	GI->SavedActiveSubQuests = this->ActiveSubQuests;
	GI->SavedDaughterSleepWarningCount = this->DaughterSleepWarningCount;
	GI->SavedIsDailyTimerStarted = this->bIsDailyTimerStarted;

	// 2. 플레이어 데이터(인벤토리, 도감, 골드) 찾아내서 백업
	if (ABlacksmithPlayer* Player = Cast<ABlacksmithPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0)))
	{
		GI->SavedGold = Player->Gold;

		if (UInventoryComponent* Inv = Player->FindComponentByClass<UInventoryComponent>())
			GI->SavedInventory = Inv->Inventory;

		if (UEncyclopediaComponent* Ency = Player->FindComponentByClass<UEncyclopediaComponent>())
			GI->SavedEncyclopedia = Ency->UnlockedItems;
	}

	GI->bIsDataSaved = true; // 저장 완료 표시!
}

void ABlacksmithGameMode::RestoreGlobalData()
{
	UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance());

	// 저장된 적 없으면 무시 (즉, 게임 맨 처음 시작했을 때는 덮어씌우지 않음)
	if (!GI || !GI->bIsDataSaved) return;

	// 1. 게임 진행 데이터 복원
	this->CurrentDay = GI->SavedCurrentDay;
	this->CurrentTimeOfDay = GI->SavedCurrentTimeOfDay;
	this->DaysUntilDeadline = GI->SavedDaysUntilDeadline;
	this->bHasActiveMainQuest = GI->SavedHasActiveMainQuest;
	this->CurrentMainQuest = GI->SavedCurrentMainQuest;
	this->bIsMainQuestCompleted = GI->SavedIsMainQuestCompleted;
	this->bIsGracePeriodUsed = GI->SavedIsGracePeriodUsed;
	this->ActiveSubQuests = GI->SavedActiveSubQuests;
	this->DaughterSleepWarningCount = GI->SavedDaughterSleepWarningCount;
	this->bIsDailyTimerStarted = GI->SavedIsDailyTimerStarted;

	// 2. 캐시 스케줄 재연결 및 타이머 이어서 돌리기!
	if (DailyScheduleMap.Contains(CurrentDay))
	{
		bHasTodaySchedule = true;
		TodayScheduleCache = DailyScheduleMap[CurrentDay];
	}
	// 🟢 [주의/수정] 우편함을 열어서 타이머가 돌고 있을 때만 타이머를 이어서 돌립니다!
	if (this->bIsDailyTimerStarted)
	{
		GetWorld()->GetTimerManager().SetTimer(DailyTimerHandle, this, &ABlacksmithGameMode::AdvanceTimeOneSecond, 1.0f, true);
	}

	// 3. 플레이어 데이터(인벤토리, 도감) 찾아내서 복원
	if (ABlacksmithPlayer* Player = Cast<ABlacksmithPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0)))
	{
		Player->Gold = GI->SavedGold;

		if (UInventoryComponent* Inv = Player->FindComponentByClass<UInventoryComponent>())
			Inv->Inventory = GI->SavedInventory;

		if (UEncyclopediaComponent* Ency = Player->FindComponentByClass<UEncyclopediaComponent>())
			Ency->UnlockedItems = GI->SavedEncyclopedia;
	}
}

bool ABlacksmithGameMode::CheckCanUseReturnDoor(FText& OutDenyMessage)
{
	// 현재는 집으로 돌아가는 걸 막는 조건이 없으므로 무조건 통과합니다!
	// (나중에 특정 퀘스트나 이벤트를 봐야만 집에 갈 수 있게 하려면 이곳에 추가하세요)
	return true;
}

/* =================================================================
 * 📬 우편함 시스템 로직
 * ================================================================= */
void ABlacksmithGameMode::OpenMailbox()
{
	StartDailyTimer();
	MailQuestQueue.Empty();
	bHasPendingWarLetter = false;

	if (DailyScheduleMap.Contains(CurrentDay))
	{
		const FDailySchedule& TodaySch = DailyScheduleMap[CurrentDay];
		if (TodaySch.bHasMainQuest) MailQuestQueue.Add(TodaySch.MainQuest);
		for (const FQuestData& SQ : TodaySch.SubQuests) MailQuestQueue.Add(SQ);
	}

	if (DaughterClass)
	{
		if (ADaughterNPC* DaughterCDO = Cast<ADaughterNPC>(DaughterClass->GetDefaultObject()))
		{
			if (CurrentDay >= DaughterCDO->WarStartDay && DaughterCDO->WarLettersByDay.Contains(CurrentDay))
			{
				bHasPendingWarLetter = true;
				PendingWarLetter = DaughterCDO->WarLettersByDay[CurrentDay];
			}
		}
	}

	ShowNextMail();
}

void ABlacksmithGameMode::ShowNextMail()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (!PC) return;

	// 1. 대기열에 의뢰가 남아있다면?
	if (MailQuestQueue.Num() > 0)
	{
		FQuestData NextQuest = MailQuestQueue[0];
		MailQuestQueue.RemoveAt(0);

		if (QuestMailWidgetClass)
		{
			UMailQuestWidget* QuestWidget = CreateWidget<UMailQuestWidget>(PC, QuestMailWidgetClass);
			if (QuestWidget)
			{
				FString Prefix = NextQuest.bIsMainQuest ? TEXT("[메인] ") : TEXT("[서브] ");
				FString FinalTitle = Prefix + NextQuest.QuestName;

				FString RewardString = TEXT("보수: ");
				for (int i = 0; i < NextQuest.QuestRewards.Num(); i++)
				{
					if (NextQuest.QuestRewards[i].RewardType == ERewardType::Currency)
						RewardString += FString::Printf(TEXT("%d 골드"), NextQuest.QuestRewards[i].RewardAmount);
					else if (NextQuest.QuestRewards[i].RewardItem)
						RewardString += FString::Printf(TEXT("%s %d개"), *NextQuest.QuestRewards[i].RewardItem->ItemName, NextQuest.QuestRewards[i].RewardAmount);

					if (i < NextQuest.QuestRewards.Num() - 1) RewardString += TEXT(", ");
				}

				// 🟢 [여기 추가됨!] 기한 텍스트 계산
				int32 RemainingDays = NextQuest.bIsMainQuest ? DaysUntilDeadline : NextQuest.DeadlineDays;
				FString DeadlineString = FString::Printf(TEXT("남은 기한: %d일"), RemainingDays);

				// 🟢 [수정됨] 마지막 매개변수로 DeadlineString을 함께 넘겨줍니다!
				QuestWidget->UpdateMailUI(FinalTitle, NextQuest.QuestDescription, RewardString, DeadlineString);

				QuestWidget->AddToViewport();
				QuestWidget->OnTalkClosed.AddDynamic(this, &ABlacksmithGameMode::ShowNextMail);

				FInputModeUIOnly InputMode;
				PC->SetInputMode(InputMode);
				PC->SetShowMouseCursor(true);
			}
		}
		else { ShowNextMail(); }
	}
	// 2. 의뢰는 다 봤고, 딸의 편지가 남아있다면?
	else if (bHasPendingWarLetter)
	{
		bHasPendingWarLetter = false;
		if (WarLetterWidgetClass)
		{
			UMailLetterWidget* LetterWidget = CreateWidget<UMailLetterWidget>(PC, WarLetterWidgetClass);
			if (LetterWidget)
			{
				LetterWidget->UpdateLetterUI(PendingWarLetter.LetterText);
				LetterWidget->AddToViewport();
				LetterWidget->OnTalkClosed.AddDynamic(this, &ABlacksmithGameMode::ShowNextMail);

				FInputModeUIOnly InputMode;
				PC->SetInputMode(InputMode);
				PC->SetShowMouseCursor(true);
			}
		}
		else { ShowNextMail(); }
	}
	// 3. 전부 다 확인 완료 시 조작 복구!
	else
	{
		FInputModeGameOnly InputMode;
		PC->SetInputMode(InputMode);
		PC->SetShowMouseCursor(false);
	}
}

/* =================================================================
 * 📜 메뉴 UI 연동용 퀘스트 헬퍼 함수
 * ================================================================= */

TArray<FQuestData> ABlacksmithGameMode::GetAllActiveQuests()
{
	TArray<FQuestData> AllQuests;

	// 1. 메인 의뢰가 진행 중이라면 가장 첫 페이지(인덱스 0)에 오도록 추가[cite: 12]
	if (bHasActiveMainQuest && !bIsMainQuestCompleted)
	{
		AllQuests.Add(CurrentMainQuest);
	}

	// 2. 진행 중인 서브 의뢰들을 그 뒤에 차례대로 추가[cite: 12]
	for (const FQuestData& SubQuest : ActiveSubQuests)
	{
		AllQuests.Add(SubQuest);
	}

	return AllQuests;
}

void ABlacksmithGameMode::FormatQuestForUI(const FQuestData& InQuest, FString& OutTitle, FText& OutDescription, FString& OutRewardInfo, FString& OutDeadlineInfo)
{
	// 1. [메인/서브] 태그 결합
	FString Prefix = InQuest.bIsMainQuest ? TEXT("[메인] ") : TEXT("[서브] ");
	OutTitle = Prefix + InQuest.QuestName;

	// 2. 설명은 그대로 전달
	OutDescription = InQuest.QuestDescription;

	// 3. 보수 텍스트 예쁘게 합치기
	OutRewardInfo = TEXT("보수: ");
	for (int i = 0; i < InQuest.QuestRewards.Num(); i++)
	{
		if (InQuest.QuestRewards[i].RewardType == ERewardType::Currency)
			OutRewardInfo += FString::Printf(TEXT("%d 골드"), InQuest.QuestRewards[i].RewardAmount);
		else if (InQuest.QuestRewards[i].RewardItem)
			OutRewardInfo += FString::Printf(TEXT("%s %d개"), *InQuest.QuestRewards[i].RewardItem->ItemName, InQuest.QuestRewards[i].RewardAmount);

		if (i < InQuest.QuestRewards.Num() - 1) OutRewardInfo += TEXT(", ");
	}

	// 🟢 4. [새로 추가된 부분] 기한 텍스트 계산
	// 메인 퀘스트면 전체 마감일(DaysUntilDeadline)을, 서브면 자체 기한(DeadlineDays)을 사용합니다!
	int32 RemainingDays = InQuest.bIsMainQuest ? DaysUntilDeadline : InQuest.DeadlineDays;
	OutDeadlineInfo = FString::Printf(TEXT("남은 기한: %d일"), RemainingDays);
}

/* =================================================================
 * 📦 무기 납품 / 퀘스트 클리어 시스템
 * ================================================================= */

FText ABlacksmithGameMode::GetQuestTextForWeapon(UItemDataAsset* Weapon)
{
	if (!Weapon) return FText::GetEmpty();

	// 메인 퀘스트 확인
	if (bHasActiveMainQuest && !bIsMainQuestCompleted && CurrentMainQuest.TargetItem == Weapon)
	{
		FString Text = FString::Printf(TEXT("[메인] %s\n%d / %d"),
			*CurrentMainQuest.QuestName,
			CurrentMainQuest.SubmittedQuantity,
			CurrentMainQuest.TargetQuantity);
		return FText::FromString(Text);
	}

	// 서브 퀘스트 확인
	for (const FQuestData& SubQuest : ActiveSubQuests)
	{
		if (SubQuest.TargetItem == Weapon)
		{
			FString Text = FString::Printf(TEXT("[서브] %s\n%d / %d"),
				*SubQuest.QuestName,
				SubQuest.SubmittedQuantity,
				SubQuest.TargetQuantity);
			return FText::FromString(Text);
		}
	}

	return FText::GetEmpty();
}

FText ABlacksmithGameMode::SubmitWeaponForQuest(UItemDataAsset* Weapon)
{
	if (!Weapon) return FText::GetEmpty();

	ABlacksmithPlayer* Player = Cast<ABlacksmithPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));
	UInventoryComponent* InvComp = Player ? Player->FindComponentByClass<UInventoryComponent>() : nullptr;

	// 보상 지급 + 보상 내역 문자열 생성 람다
	auto GiveRewardsAndGetText = [&](const FQuestData& Quest) -> FString
	{
		FString RewardParts;
		for (int32 i = 0; i < Quest.QuestRewards.Num(); i++)
		{
			const FQuestReward& Reward = Quest.QuestRewards[i];
			if (i > 0) RewardParts += TEXT(", ");

			if (Reward.RewardType == ERewardType::Currency)
			{
				if (Player) Player->Gold += Reward.RewardAmount;
				RewardParts += FString::Printf(TEXT("%d 골드"), Reward.RewardAmount);
			}
			else if (Reward.RewardItem)
			{
				if (InvComp) InvComp->AddItem(Reward.RewardItem, Reward.RewardAmount);
				RewardParts += FString::Printf(TEXT("%s %d개"), *Reward.RewardItem->ItemName, Reward.RewardAmount);
			}
		}
		return RewardParts.IsEmpty() ? TEXT("없음") : RewardParts;
	};

	// 완료 알림 메시지 조합 람다 ([메인/서브] 이름 완료!\n보상: ...)
	auto BuildNotifMessage = [](const FString& Prefix, const FString& QuestName, const FString& RewardText) -> FText
	{
		return FText::FromString(
			FString::Printf(TEXT("%s %s 완료!\n보상: %s"), *Prefix, *QuestName, *RewardText)
		);
	};

	// 메인 퀘스트 납품 확인
	if (bHasActiveMainQuest && !bIsMainQuestCompleted && CurrentMainQuest.TargetItem == Weapon)
	{
		CurrentMainQuest.SubmittedQuantity++;

		if (CurrentMainQuest.SubmittedQuantity >= CurrentMainQuest.TargetQuantity)
		{
			bIsMainQuestCompleted = true;
			FString RewardText = GiveRewardsAndGetText(CurrentMainQuest);
			OnQuestCompleted(CurrentMainQuest, true);
			return BuildNotifMessage(TEXT("[메인 의뢰]"), CurrentMainQuest.QuestName, RewardText);
		}
		return FText::GetEmpty();
	}

	// 서브 퀘스트 납품 확인
	for (int32 i = 0; i < ActiveSubQuests.Num(); i++)
	{
		if (ActiveSubQuests[i].TargetItem == Weapon)
		{
			ActiveSubQuests[i].SubmittedQuantity++;

			if (ActiveSubQuests[i].SubmittedQuantity >= ActiveSubQuests[i].TargetQuantity)
			{
				FQuestData CompletedQuest = ActiveSubQuests[i];
				ActiveSubQuests.RemoveAt(i);
				FString RewardText = GiveRewardsAndGetText(CompletedQuest);
				OnQuestCompleted(CompletedQuest, false);
				return BuildNotifMessage(TEXT("[서브 의뢰]"), CompletedQuest.QuestName, RewardText);
			}
			return FText::GetEmpty();
		}
	}

	return FText::GetEmpty();
}

// 🟢 아침 대사 UI 창이 닫히는 시점에 기존 스케줄(Schedule)의 아침 이벤트들을 작동시키는 함수
void ABlacksmithGameMode::ExecuteMorningEvents()
{
	// 대사 UI가 완전히 닫혔으므로 캐릭터 조작 권한과 마우스 커서를 원상복구합니다.
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		FInputModeGameOnly InputMode;
		PC->SetInputMode(InputMode);
		PC->SetShowMouseCursor(false);
	}

	// 이제 기존 스케줄(Schedule) 카테고리에 등록해두었던 원래 아침 이벤트(rune_1 등)들이 정상 실행됩니다!
	if (DailyScheduleMap.Contains(CurrentDay))
	{
		for (const FGeneralEventData& MEvent : DailyScheduleMap[CurrentDay].MorningEvents)
		{
			OnTriggerGeneralEvent(MEvent.EventID, MEvent.WidgetToShow);
		}
	}
}

void ABlacksmithGameMode::ResetMorningState()
{
    OnMorningResetEvent();

    // 레벨 이동 시 중복 방지: 오늘 이미 아침 대사를 봤으면 건너뜁니다
    UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance());
    if (GI && GI->bMorningDialogueShownToday)
    {
        ExecuteMorningEvents();
        return;
    }

    int32 DialogueIndex = CurrentDay;
    if (DailyMorningDialogueArray.IsValidIndex(DialogueIndex) &&
        !DailyMorningDialogueArray[DialogueIndex].IsEmpty() &&
        MorningTalkWidgetClass)
    {
        if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
        {
            UTalkWidget* MorningWidget = CreateWidget<UTalkWidget>(PC, MorningTalkWidgetClass);
            if (MorningWidget)
            {
                MorningWidget->AddToViewport();
                if (MorningWidget->descript)
                    MorningWidget->descript->SetText(DailyMorningDialogueArray[DialogueIndex]);

                // 오늘 아침 대사 표시 완료 표시
                if (GI) GI->bMorningDialogueShownToday = true;

                MorningWidget->OnTalkClosed.AddDynamic(this, &ABlacksmithGameMode::ExecuteMorningEvents);

                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(MorningWidget->TakeWidget());
                PC->SetInputMode(InputMode);
                PC->SetShowMouseCursor(true);
                return;
            }
        }
    }
    ExecuteMorningEvents();
}