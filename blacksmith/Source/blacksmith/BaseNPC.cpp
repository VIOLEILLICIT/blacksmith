#include "BaseNPC.h"
#include "DialogueWidget.h" // UI 제어를 위해 필수
#include "Components/WidgetComponent.h"
#include "BlacksmithGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h" 
#include "TimerManager.h"
#include "GameFramework/CharacterMovementComponent.h"

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

	// 🟢 [추가] 에디터에서 드래그한 마커(상대 좌표)를 맵의 절대 좌표로 변환해서 저장해 둡니다!
	for (const FVector& LocalPoint : PatrolPoints)
	{
		WorldPatrolPoints.Add(GetActorTransform().TransformPosition(LocalPoint));
	}

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
			
			GetWorld()->GetTimerManager().ClearTimer(SpeechBubbleTimer);
			CurrentSpeechIndex = 0; 
		}

		if (CurrentActiveSchedule.bIsVisible && CurrentActiveSchedule.AutoSpeechBubbles.Num() > 0)
		{
			if (!GetWorld()->GetTimerManager().IsTimerActive(SpeechBubbleTimer))
			{
				float SafeInterval = FMath::Max(0.1f, CurrentActiveSchedule.SpeechInterval);
				UpdateAutoSpeechBubble(); 
				GetWorld()->GetTimerManager().SetTimer(SpeechBubbleTimer, this, &ABaseNPC::UpdateAutoSpeechBubble, SafeInterval, true);
			}
		}
		else
		{
			GetWorld()->GetTimerManager().ClearTimer(SpeechBubbleTimer);
			SpeechBubbleWidget->SetVisibility(false);
		}
	}
	
	if (UBlacksmithGameInstance* GI = Cast<UBlacksmithGameInstance>(GetGameInstance()))
	{
		if (!NPC_ID.IsNone())
		{
			FNPCSavedState StateToSave;
			StateToSave.InteractionCount = this->NPCComponent->InteractionCount;
			StateToSave.SavedDateKey = this->ActiveScheduleDateKey;
			StateToSave.SavedScheduleIndex = this->ActiveTimeScheduleIndex;
			GI->SavedNPCStates.Add(NPC_ID, StateToSave); 
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

	// 🟢 따라갈 때는 빠른 걸음이나 뛰는 속도로 복구!
	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		MoveComp->MaxWalkSpeed = 400.0f; // 뛰는 속도 (원하는 대로 조절)
	}
	
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
	GetWorld()->GetTimerManager().ClearTimer(PatrolTimerHandle); // 🟢 패트롤 타이머도 확실하게 정지!
	
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

/* =================================================================
 * 🚶 NPC 순찰(Patrol) 로직
 * ================================================================= */
void ABaseNPC::StartPatrol()
{
	if (WorldPatrolPoints.Num() == 0) return;

	StopMoving(); 

	// 🟢 1. NPC의 이동 속도를 '걷기(Walk)' 속도로 늦춰줍니다 (기본 600 -> 150)
	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		MoveComp->MaxWalkSpeed = 150.0f; // 이 숫자를 조절해서 원하는 걷기 속도를 맞추세요!
	}

	CurrentPatrolIndex = 0; 
	
	// 🟢 2. 타이머를 0.5초 -> 0.1초로 줄여서, 도착하자마자 바로 다음 곳으로 부드럽게 꺾게 만듭니다.
	GetWorld()->GetTimerManager().SetTimer(PatrolTimerHandle, this, &ABaseNPC::UpdatePatrol, 0.1f, true);
	UpdatePatrol(); 
}

void ABaseNPC::UpdatePatrol()
{
	if (WorldPatrolPoints.Num() == 0) return;

	FVector TargetLoc = WorldPatrolPoints[CurrentPatrolIndex];
	float Distance = FVector::Dist2D(GetActorLocation(), TargetLoc);
	
	// 🟢 3. 완전히 멈추기 전(거리 50 이하)에 다음 목적지로 인덱스를 미리 바꿉니다. (자연스러운 코너링)
	if (Distance <= 50.0f) 
	{
		CurrentPatrolIndex++;
		if (CurrentPatrolIndex >= WorldPatrolPoints.Num())
		{
			CurrentPatrolIndex = 0; 
		}
		
		// 타겟을 다음 마커로 즉시 갱신!
		TargetLoc = WorldPatrolPoints[CurrentPatrolIndex]; 
	}

	// 4. 부드럽게 이동 (목적지가 계속 갱신되므로 멈추지 않고 스무스하게 이어집니다)
	if (AAIController* AI = Cast<AAIController>(GetController()))
	{
		AI->MoveToLocation(TargetLoc, 10.0f); 
	}
}