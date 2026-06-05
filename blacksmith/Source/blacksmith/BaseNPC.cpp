#include "BaseNPC.h"
#include "DialogueWidget.h" // UI 제어를 위해 필수
#include "Components/WidgetComponent.h"
#include "BlacksmithGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h" 
#include "TimerManager.h"

ABaseNPC::ABaseNPC()
{
	PrimaryActorTick.bCanEverTick = false;

	NPCComponent = CreateDefaultSubobject<UNPCComponent>(TEXT("NPCComponent"));
	SpeechBubbleWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("SpeechBubbleWidget"));

	SpeechBubbleWidget->SetupAttachment(RootComponent);
	SpeechBubbleWidget->SetWidgetSpace(EWidgetSpace::Screen); 
	SpeechBubbleWidget->SetRelativeLocation(FVector(0, 0, 100.0f)); 
	SpeechBubbleWidget->SetVisibility(false); 
}

void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();

	// 🟢 1. 내 고유 ID가 있다면, GameInstance 사물함에서 내 대화 횟수와 기억을 꺼내옵니다.
	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		if (!NPC_ID.IsNone() && GI->SavedNPCStates.Contains(NPC_ID))
		{
			FNPCSavedState LoadedState = GI->SavedNPCStates[NPC_ID];
			this->NPCComponent->InteractionCount = LoadedState.InteractionCount;
			this->ActiveScheduleDateKey = LoadedState.SavedDateKey;
			this->ActiveTimeScheduleIndex = LoadedState.SavedScheduleIndex;
		}
	}

	// 🟢 2. 맵이 켜지자마자 즉시!! 내가 지금 시간에 맵에 보여야 하는지 판단하고 숨거나 나타납니다.
	CheckScheduleAndVisibility();

	// 🟢 3. 그 이후부터는 1초마다 변동사항이 있는지 확인합니다.
	GetWorld()->GetTimerManager().SetTimer(ScheduleCheckTimer, this, &ABaseNPC::CheckScheduleAndVisibility, 1.0f, true);
}

void ABaseNPC::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

/* =================================================================
 * 스케줄 자동화 로직
 * ================================================================= */
void ABaseNPC::CheckScheduleAndVisibility()
{
	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	if (!GM) return;

	FNPCTimeSchedule NewSchedule;
	int32 NewDateKey = -1;
	int32 NewSchedIndex = -1;
	
	if (NPCComponent->GetCurrentSchedule(GM->CurrentDay, GM->CurrentTimeOfDay, NewSchedule, NewDateKey, NewSchedIndex))
	{
		CurrentActiveSchedule = NewSchedule;
		
		SetActorHiddenInGame(!CurrentActiveSchedule.bIsVisible);
		SetActorEnableCollision(CurrentActiveSchedule.bIsVisible);

		if (ActiveScheduleDateKey != NewDateKey || ActiveTimeScheduleIndex != NewSchedIndex)
		{
			ActiveScheduleDateKey = NewDateKey;
			ActiveTimeScheduleIndex = NewSchedIndex;
			NPCComponent->InteractionCount = 0; 
		}

		if (CurrentActiveSchedule.bIsVisible && CurrentActiveSchedule.AutoSpeechBubbles.Num() > 0)
		{
			if (!GetWorld()->GetTimerManager().IsTimerActive(SpeechBubbleTimer))
			{
				CurrentSpeechIndex = 0; 
				UpdateAutoSpeechBubble(); 
				GetWorld()->GetTimerManager().SetTimer(SpeechBubbleTimer, this, &ABaseNPC::UpdateAutoSpeechBubble, CurrentActiveSchedule.SpeechInterval, true);
			}
		}
		else
		{
			GetWorld()->GetTimerManager().ClearTimer(SpeechBubbleTimer);
			SpeechBubbleWidget->SetVisibility(false);
		}
	}
	// 🟢 [맨 아랫부분에 추가] 매초마다 갱신된 나의 상태(대화 횟수 등)를 GameInstance 사물함에 실시간 백업!
	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		if (!NPC_ID.IsNone())
		{
			FNPCSavedState StateToSave;
			StateToSave.InteractionCount = this->NPCComponent->InteractionCount;
			StateToSave.SavedDateKey = this->ActiveScheduleDateKey;
			StateToSave.SavedScheduleIndex = this->ActiveTimeScheduleIndex;

			GI->SavedNPCStates.Add(NPC_ID, StateToSave); // 사물함에 넣기!
		}
	}
}

void ABaseNPC::UpdateAutoSpeechBubble()
{
	if (CurrentActiveSchedule.AutoSpeechBubbles.Num() == 0) return;
	SpeechBubbleWidget->SetVisibility(true);

	FText TextToShow = CurrentActiveSchedule.AutoSpeechBubbles[CurrentSpeechIndex];
	OnUpdateSpeechBubble(TextToShow); 

	CurrentSpeechIndex++;
	if (CurrentSpeechIndex >= CurrentActiveSchedule.AutoSpeechBubbles.Num())
	{
		CurrentSpeechIndex = 0; 
	}
}

/* =================================================================
 * 상호작용 (F키) 로직 - 대화 시작
 * ================================================================= */
void ABaseNPC::Interact_Implementation(AActor* Interactor)
{
	if (!CurrentActiveSchedule.bIsVisible || CurrentActiveSchedule.InteractionDialogues.Num() == 0) return;

	int32 SequenceIndex = NPCComponent->InteractionCount;

	if (SequenceIndex >= CurrentActiveSchedule.InteractionDialogues.Num()) return; 

	NPCComponent->IncrementInteractionCount(); // 대화 횟수 증가

	// 🟢 [추가] 말을 걸어서 횟수가 올랐으니, 즉시 GameInstance에 저장해 줍니다! (중간에 맵을 나가도 기억함)
	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		if (!NPC_ID.IsNone() && GI->SavedNPCStates.Contains(NPC_ID))
		{
			GI->SavedNPCStates[NPC_ID].InteractionCount = NPCComponent->InteractionCount;
		}
	}
	
	StartDialogueUI(CurrentActiveSchedule.InteractionDialogues[SequenceIndex]);
}

/* =================================================================
 * 💬 C++ 기반 대화창 및 마우스 제어 자동화
 * ================================================================= */
void ABaseNPC::StartDialogueUI(const FDialogueSequence& SequenceToPlay)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (!PC || !DialogueWidgetClass) return;

	SpawnedDialogueWidget = CreateWidget<UDialogueWidget>(PC, DialogueWidgetClass);
	if (SpawnedDialogueWidget)
	{
		SpawnedDialogueWidget->StartDialogue(SequenceToPlay);
		SpawnedDialogueWidget->AddToViewport();

		SpawnedDialogueWidget->OnDialogueFinished.AddDynamic(this, &ABaseNPC::HandleDialogueFinished);

		// 🟢 대화 중 캐릭터 이동을 완벽 차단하고 UI에만 입력을 가둡니다!
		FInputModeUIOnly InputMode; 
		InputMode.SetWidgetToFocus(SpawnedDialogueWidget->TakeWidget());
		PC->SetInputMode(InputMode);
		
		// 🟢 이전 키보드 눌림 상태를 깔끔하게 지워줍니다.
		PC->FlushPressedKeys(); 
		
		PC->SetShowMouseCursor(true);
	}
}

void ABaseNPC::HandleDialogueFinished()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		// 캐릭터 조작 복귀 및 마우스 숨김
		FInputModeGameOnly InputMode;
		PC->SetInputMode(InputMode);
		PC->SetShowMouseCursor(false);
	}

	// 대화 종료 후 행동(자식 클래스 덮어쓰기용) 실행
	OnDialogueEndAction();
}

void ABaseNPC::OnDialogueEndAction()
{
	// 기본 NPC는 빈 함수입니다.
}

/* =================================================================
 * AI 이동 및 제어
 * ================================================================= */
void ABaseNPC::FollowPlayer(float StopDistance)
{
	CachedFollowRadius = StopDistance;
	
	GetWorld()->GetTimerManager().SetTimer(FollowTimerHandle, this, &ABaseNPC::UpdateFollowTarget, 0.5f, true);
	UpdateFollowTarget(); 
}

void ABaseNPC::UpdateFollowTarget()
{
	if (AActor* Player = UGameplayStatics::GetPlayerCharacter(this, 0))
	{
		if (AAIController* AI = Cast<AAIController>(GetController()))
		{
			AI->MoveToActor(Player, CachedFollowRadius);
		}
	}
}

void ABaseNPC::StopMoving()
{
	GetWorld()->GetTimerManager().ClearTimer(FollowTimerHandle);
	
	if (AAIController* AI = Cast<AAIController>(GetController())) 
	{
		AI->StopMovement();
	}
}

void ABaseNPC::TeleportToLocation(FVector NewLocation)
{
	StopMoving();
	SetActorLocation(NewLocation, false, nullptr, ETeleportType::TeleportPhysics);
}