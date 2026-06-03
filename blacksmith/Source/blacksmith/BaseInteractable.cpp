#include "BaseInteractable.h"
#include "BlacksmithGameMode.h" 
#include "DaughterNPC.h" 
#include "Kismet/GameplayStatics.h"

ABaseInteractable::ABaseInteractable()
{
	PrimaryActorTick.bCanEverTick = false;
}

/* =================================================================
 * 인터페이스 진입점
 * ================================================================= */
void ABaseInteractable::Interact_Implementation(AActor* Interactor)
{
	if (APawn* InteractorPawn = Cast<APawn>(Interactor))
	{
		APlayerController* PC = Cast<APlayerController>(InteractorPawn->GetController());
		AttemptInteraction(PC);
	}
}

/* =================================================================
 * 검사 및 액션 실행
 * ================================================================= */
void ABaseInteractable::AttemptInteraction(APlayerController* PC)
{
	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	if (!GM) return;

	FText DenyMessage;
	bool bIsAllowed = false;

	// 1. 종류별로 허락 여부 검사
	switch (ObjectType)
	{
		case EInteractableType::RestChair:
			bIsAllowed = GM->CheckCanUseRestChair(DenyMessage);
			break;
		case EInteractableType::Bed:
			bIsAllowed = GM->CheckCanUseBed(DenyMessage);
			break;
		case EInteractableType::Door:
			bIsAllowed = GM->CheckCanUseDoor(DenyMessage);
			break;
		case EInteractableType::DaughterBed:
			bIsAllowed = GM->CheckCanUseDaughterBed(DenyMessage);
			break;
	}

	// 2. 허락(성공) 시 ➡️ C++ 자체 하드코딩 로직 실행
	if (bIsAllowed)
	{
		switch (ObjectType)
		{
			case EInteractableType::RestChair:
				// 🪑 시간 건너뛰기 (인스펙터에 지정한 목표 시간으로 즉시 워프!)
				GM->WarpTimeTo(WarpTargetTime);
				break;

			case EInteractableType::Bed:
				// 🛏️ 아빠 취침 (하루 넘기기)
				GM->SleepAndNextDay();
				break;

			case EInteractableType::Door:
				// 🚪 레벨(맵) 이동
				if (!TargetLevelName.IsNone())
				{
					UGameplayStatics::OpenLevel(this, TargetLevelName);
				}
				break;

			case EInteractableType::DaughterBed:
				// 👧 딸 재우기
				GM->bIsDaughterAsleep = true; // 게임모드 상태 변경
				
				// 맵에 있는 딸 NPC 찾아서 정지 및 투명화 (이불 덮기 연출 대체)
				if (AActor* DaughterActor = UGameplayStatics::GetActorOfClass(this, ADaughterNPC::StaticClass()))
				{
					if (ADaughterNPC* Daughter = Cast<ADaughterNPC>(DaughterActor))
					{
						Daughter->StopMoving();
						Daughter->SetActorHiddenInGame(true);
						Daughter->SetActorEnableCollision(false);
					}
				}
				break;
		}

		// 블루프린트 이벤트 발사
		OnInteractionAllowed();
	}
	// 3. 실패 시 ➡️ 거절 대사 UI 띄우기
	else
	{
		if (CurrentTalkWidget && CurrentTalkWidget->IsInViewport()) return; 

		if (TalkWidgetClass && PC)
		{
			CurrentTalkWidget = CreateWidget<UUserWidget>(PC, TalkWidgetClass);
			if (CurrentTalkWidget)
			{
				CurrentTalkWidget->AddToViewport();
				OnSetupTalkWidget(CurrentTalkWidget, DenyMessage);
			}
		}
	}
}