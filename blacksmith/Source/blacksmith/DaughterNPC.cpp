#include "DaughterNPC.h"
#include "Blueprint/UserWidget.h"
#include "BlacksmithGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "BlacksmithGameInstance.h"

ADaughterNPC::ADaughterNPC() {}

void ADaughterNPC::BeginPlay()
{
	Super::BeginPlay();
	
	// 🟢 [추가] 맵이 시작되자마자, 백업된 대화 횟수와 스케줄을 가져와서 덮어씌움!
	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		this->ActiveScheduleDateKey = GI->DaughterSavedDateKey;
		this->ActiveTimeScheduleIndex = GI->DaughterSavedScheduleIndex;
		this->NPCComponent->InteractionCount = GI->DaughterInteractionCount;
	}

	GetWorld()->GetTimerManager().SetTimer(DaughterRoutineTimer, this, &ADaughterNPC::UpdateDaughterRoutine, 0.5f, true);
}

// 딸 전용 예외 처리 자동화 (성장 페이즈 및 전쟁터 강제 숨김)
void ADaughterNPC::UpdateDaughterRoutine()
{
	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	if (!GM) return;

	// 🟢 [추가] 0.5초마다 딸의 대화 진행 상태를 GameInstance에 실시간으로 갱신(백업)!
	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		GI->DaughterSavedDateKey = this->ActiveScheduleDateKey;
		GI->DaughterSavedScheduleIndex = this->ActiveTimeScheduleIndex;
		GI->DaughterInteractionCount = this->NPCComponent->InteractionCount;
	}

	EDaughterPhase NewPhase;
	if (GM->CurrentDay >= WarStartDay) NewPhase = EDaughterPhase::War;
	else if (GM->CurrentDay >= AdultStartDay) NewPhase = EDaughterPhase::Adult;
	else NewPhase = EDaughterPhase::Child;

	CurrentPhase = NewPhase;

	// 방어 코드: 전쟁터 페이즈 시 부모의 스케줄 개입 차단
	if (CurrentPhase == EDaughterPhase::War)
	{
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
		GetWorld()->GetTimerManager().PauseTimer(ScheduleCheckTimer); 
	}
	else
	{
		GetWorld()->GetTimerManager().UnPauseTimer(ScheduleCheckTimer);
	}
}

// 상호작용 로직 (대화 띄우기 및 상태 플래그 켜기)
void ADaughterNPC::Interact_Implementation(AActor* Interactor)
{
	if (CurrentPhase == EDaughterPhase::War || IsHidden()) return;

	Super::Interact_Implementation(Interactor);
	StopMoving();

	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	
	// 🟢 게임 인스턴스를 가져옵니다.
	UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()); 

	if (GM && CurrentPhase == EDaughterPhase::Child)
	{
		if (!GM->bIsDaughterAwake) 
		{
			GM->bIsDaughterAwake = true;
			if (GI) GI->bIsDaughterAwake = true; // 🟢 백업!
		}

		if (GM->CurrentTimeOfDay < 180.0f)
		{
			FollowPlayer(150.0f);
		}
		else if (GM->CurrentTimeOfDay >= 180.0f && GM->CurrentTimeOfDay < 450.0f)
		{
			StopMoving();
		}
		else if (GM->CurrentTimeOfDay >= 450.0f)
		{
			if (!GM->bIsDaughterFound) 
			{
				GM->bIsDaughterFound = true;
				if (GI) GI->bIsDaughterFound = true; // 🟢 백업!
			}
			FollowPlayer(150.0f);
		}
	}
}

void ADaughterNPC::OnDialogueEndAction()
{
	Super::OnDialogueEndAction();

	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance());

	if (!GM || CurrentPhase != EDaughterPhase::Child) return;

	if (GM->CurrentTimeOfDay < 180.0f)
	{
		FollowPlayer(150.0f); 
		if (GI) GI->bIsDaughterFollowing = true; // 🟢 GameInstance에 따라간다고 쾅 박음!
	}
	else if (GM->CurrentTimeOfDay >= 180.0f && GM->CurrentTimeOfDay < 450.0f)
	{
		StopMoving();         
		if (GI) GI->bIsDaughterFollowing = false; // 🟢 따라오기 멈춤
	}
	else if (GM->CurrentTimeOfDay >= 450.0f)
	{
		FollowPlayer(150.0f); 
		if (GI) GI->bIsDaughterFollowing = true;
	}
}

void ADaughterNPC::TeleportToRandomHideout()
{
	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	if (!GM) return;

	FName TargetLevel;
	FName TargetTag;
	TSubclassOf<class UUserWidget> BubbleWidget;
	FText SpeechText;

	if (CurrentPhase == EDaughterPhase::Child && ChildHideoutList.Num() > 0)
	{
		int32 RandomIndex = FMath::RandRange(0, ChildHideoutList.Num() - 1);
		TargetLevel = ChildHideoutList[RandomIndex].TargetLevelName;
		TargetTag = ChildHideoutList[RandomIndex].TargetPointTag;
		BubbleWidget = ChildHideoutList[RandomIndex].BubbleWidgetClass;
		SpeechText = ChildHideoutList[RandomIndex].SpeechText;
	}
	else if (CurrentPhase == EDaughterPhase::Adult && AdultHideoutList.Num() > 0)
	{
		int32 RandomIndex = FMath::RandRange(0, AdultHideoutList.Num() - 1);
		TargetLevel = AdultHideoutList[RandomIndex].TargetLevelName;
		TargetTag = AdultHideoutList[RandomIndex].TargetPointTag;
		BubbleWidget = AdultHideoutList[RandomIndex].LetterWidgetClass;
		SpeechText = AdultHideoutList[RandomIndex].LetterText;
	}
	else if (CurrentPhase == EDaughterPhase::War)
	{
		// 전쟁터 파병 처리는 편지 남기기만
		if (WarLettersByDay.Contains(GM->CurrentDay))
		{
			FWarLetterData TodayLetter = WarLettersByDay[GM->CurrentDay];
			if (TodayLetter.LetterWidgetClass) 
				OnLeaveLetterAtDesk(TodayLetter.LetterWidgetClass, TodayLetter.LetterText);
		}
		return;
	}

	if (TargetLevel.IsNone() || TargetTag.IsNone()) return;

	// 1. 게임 인스턴스에 딸의 목표 레벨과 태그 저장 (목적지가 어딘지 기록)
	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		GI->bIsDaughterFollowing = false; 
		GI->DaughterSavedLevel = TargetLevel;
		GI->DaughterSavedLocationTag = TargetTag;
	}

	// 2. 현재 맵이 딸이 이동해야 할 맵과 동일한가?
	if (UGameplayStatics::GetCurrentLevelName(this) == TargetLevel.ToString())
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsWithTag(this, TargetTag, FoundActors);
		if (FoundActors.Num() > 0)
		{
			TeleportToLocation(FoundActors[0]->GetActorLocation());
			if (BubbleWidget)
			{
				if (CurrentPhase == EDaughterPhase::Child) OnShowTeleportBubble(BubbleWidget, SpeechText);
				else if (CurrentPhase == EDaughterPhase::Adult) OnLeaveLetterAtDesk(BubbleWidget, SpeechText);
			}
		}
	}
	else
	{
		// 3. 다른 맵으로 가야 한다면? 지금 맵에선 모습을 지워버림! (목표 맵으로 가면 게임모드가 알아서 스폰해 줌)
		Destroy();
	}
}