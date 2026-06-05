#include "BaseInteractable.h"
#include "BlacksmithGameMode.h" 
#include "DaughterNPC.h" 
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h" // 🟢 타이머 매니저 필수 포함

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
				GM->WarpTimeTo(WarpTargetTime);
				break;

			case EInteractableType::Bed:
				GM->SleepAndNextDay();
				break;

			case EInteractableType::Door:
				if (!TargetLevelName.IsNone())
				{
					UGameplayStatics::OpenLevel(this, TargetLevelName);
				}
				break;

			case EInteractableType::DaughterBed:
				GM->bIsDaughterAsleep = true; 
				
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

		OnInteractionAllowed();
	}
	// 3. 실패 시 ➡️ 거절 대사 UI 띄우기 및 조작 뺏기
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

				// 🟢 [추가] 플레이어의 이동 키보드 및 마우스 입력을 완전히 뺏어버립니다.
				FInputModeUIOnly InputMode;
				PC->SetInputMode(InputMode);
				PC->FlushPressedKeys(); // 누르고 있던 W, A, S, D 이동키 멈춤
				PC->SetShowMouseCursor(true); // 마우스 켜기

				// 🟢 [추가] 0.5초 뒤에 창을 닫고 조작을 돌려주는 함수를 타이머로 실행합니다.
				// (0.5f 숫자를 1.0f 등으로 바꾸시면 메시지가 떠 있는 시간을 늘릴 수 있습니다!)
				GetWorld()->GetTimerManager().SetTimer(CloseTalkWidgetTimerHandle, this, &ABaseInteractable::CloseTalkWidget, 0.5f, false);
			}
		}
	}
}

// 🟢 [추가] 타이머에 의해 0.5초 뒤 실행되는 함수
void ABaseInteractable::CloseTalkWidget()
{
	// 1. 위젯 삭제
	if (CurrentTalkWidget)
	{
		CurrentTalkWidget->RemoveFromParent();
		CurrentTalkWidget = nullptr;
	}

	// 2. 플레이어 컨트롤러를 찾아 다시 조작 권한(GameOnly)을 돌려주고 마우스를 숨깁니다.
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		FInputModeGameOnly InputMode;
		PC->SetInputMode(InputMode);
		PC->SetShowMouseCursor(false);
	}
}