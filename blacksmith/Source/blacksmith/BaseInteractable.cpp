#include "BaseInteractable.h"
#include "BlacksmithGameMode.h" 
#include "DaughterNPC.h" 
#include "Kismet/GameplayStatics.h"
#include "TalkWidget.h"
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
			// 🟢 [수정됨] 문을 열 수 있는지(28일 이전 딸 기상 여부 등) 게임모드에 물어봅니다!
			bIsAllowed = GM->CheckCanUseDoor(DenyMessage);
			break;
		case EInteractableType::ReturnDoor: // 🟢 [추가됨]
			bIsAllowed = GM->CheckCanUseReturnDoor(DenyMessage);
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
			case EInteractableType::ReturnDoor:
				// 🚪 레벨(맵) 이동
				if (!TargetLevelName.IsNone())
				{
					// 🟢 맵이 바뀌기 직전에 모든 것을 영구 인스턴스로 대피시킵니다!
					GM->SaveGlobalData(); 
					
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
			// 🟢 UUserWidget 대신 새로 만든 UTalkWidget으로 생성
			CurrentTalkWidget = CreateWidget<UTalkWidget>(PC, TalkWidgetClass);
			if (CurrentTalkWidget)
			{
				CurrentTalkWidget->AddToViewport();
				OnSetupTalkWidget(CurrentTalkWidget, DenyMessage);

				// 🟢 창이 닫혔다는 신호를 받으면 다시 조작 권한을 돌려주도록 연결
				CurrentTalkWidget->OnTalkClosed.AddDynamic(this, &ABaseInteractable::HandleTalkWidgetClosed);

				// 이동 키보드 멈춤 및 UI로 포커스 고정
				FInputModeUIOnly InputMode;
				InputMode.SetWidgetToFocus(CurrentTalkWidget->TakeWidget());
				PC->SetInputMode(InputMode);
				PC->FlushPressedKeys(); 
				PC->SetShowMouseCursor(true); 
			}
		}
	}
}

// 🟢 [수정됨] 수동으로 창이 닫혔을 때 호출되어 조작을 돌려주는 함수
void ABaseInteractable::HandleTalkWidgetClosed()
{
	CurrentTalkWidget = nullptr;

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		FInputModeGameOnly InputMode;
		PC->SetInputMode(InputMode);
		PC->SetShowMouseCursor(false);
	}
}