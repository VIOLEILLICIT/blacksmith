#include "BaseInteractable.h"
#include "BlacksmithGameMode.h" 
#include "DaughterNPC.h" 
#include "Kismet/GameplayStatics.h"
#include "TalkWidget.h"
#include "TimerManager.h" 
#include "Camera/PlayerCameraManager.h" 
#include "Engine/World.h"
#include "Blueprint/WidgetBlueprintLibrary.h" // 🟢 위젯을 찾기 위해 필수!
#include "TimeHUDWidget.h"                    // 🟢 HUD 위젯 헤더 추가
#include "Components/TextBlock.h"             // 🟢 텍스트 블록 제어용

ABaseInteractable::ABaseInteractable()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseInteractable::Interact_Implementation(AActor* Interactor)
{
	if (APawn* InteractorPawn = Cast<APawn>(Interactor))
	{
		APlayerController* PC = Cast<APlayerController>(InteractorPawn->GetController());
		AttemptInteraction(PC);
	}
}

void ABaseInteractable::AttemptInteraction(APlayerController* PC)
{
	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	if (!GM) return;

	FText DenyMessage;
	bool bIsAllowed = false;

	switch (ObjectType)
	{
		case EInteractableType::RestChair:   bIsAllowed = GM->CheckCanUseRestChair(DenyMessage);   break;
		case EInteractableType::Bed:         bIsAllowed = GM->CheckCanUseBed(DenyMessage);         break;
		case EInteractableType::Door:        bIsAllowed = GM->CheckCanUseDoor(DenyMessage);        break;
		case EInteractableType::ReturnDoor:  bIsAllowed = GM->CheckCanUseReturnDoor(DenyMessage);  break;
		case EInteractableType::DaughterBed: bIsAllowed = GM->CheckCanUseDaughterBed(DenyMessage); break;
	}

	if (bIsAllowed)
	{
		if (ObjectType == EInteractableType::RestChair || ObjectType == EInteractableType::Bed)
		{
			if (PC)
			{
				PC->DisableInput(PC); 

				// 1. 카메라 페이드 아웃 (화면 새까맣게)
				if (APlayerCameraManager* CameraManager = PC->PlayerCameraManager)
				{
					CameraManager->StartCameraFade(0.0f, 1.0f, 1.5f, FLinearColor::Black, false, true);
				}

				// 🟢 2. 화면에 떠있는 HUD를 찾아서 캐싱(저장)해둡니다!
				if (!CachedHUDWidget && TimeHUDWidgetClass)
				{
					TArray<UUserWidget*> FoundWidgets;
					UWidgetBlueprintLibrary::GetAllWidgetsOfClass(this, FoundWidgets, TimeHUDWidgetClass, false);
					if (FoundWidgets.Num() > 0) CachedHUDWidget = Cast<UTimeHUDWidget>(FoundWidgets[0]);
				}

				// 3. 1.5초 뒤 시간 변경 및 글자 띄우기 함수 실행
				GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &ABaseInteractable::ExecuteTimeSkip, 1.5f, false);
			}
		}
		else
		{
			switch (ObjectType)
			{
				case EInteractableType::Door:
				case EInteractableType::ReturnDoor:
					if (!TargetLevelName.IsNone())
					{
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
		}

		OnInteractionAllowed();
	}
	else
	{
		if (CurrentTalkWidget && CurrentTalkWidget->IsInViewport()) return; 

		if (TalkWidgetClass && PC)
		{
			CurrentTalkWidget = CreateWidget<UTalkWidget>(PC, TalkWidgetClass);
			if (CurrentTalkWidget)
			{
				CurrentTalkWidget->AddToViewport();
				OnSetupTalkWidget(CurrentTalkWidget, DenyMessage);

				CurrentTalkWidget->OnTalkClosed.AddDynamic(this, &ABaseInteractable::HandleTalkWidgetClosed);

				FInputModeUIOnly InputMode;
				InputMode.SetWidgetToFocus(CurrentTalkWidget->TakeWidget());
				PC->SetInputMode(InputMode);
				PC->FlushPressedKeys(); 
				PC->SetShowMouseCursor(true); 
			}
		}
	}
}

void ABaseInteractable::ExecuteTimeSkip()
{
	ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this));
	if (GM)
	{
		if (ObjectType == EInteractableType::RestChair) GM->WarpTimeTo(WarpTargetTime);
		else if (ObjectType == EInteractableType::Bed) GM->SleepAndNextDay();
	}

	// 🟢 [복구됨] 화면이 까맣게 변했을 때, 화면 정중앙의 글자를 보이게 켭니다!
	if (CachedHUDWidget && CachedHUDWidget->Txt_title)
	{
		FString DisplayText = (ObjectType == EInteractableType::Bed) ? TEXT("다음 날 아침...") : TEXT("충분히 휴식을 가진 뒤....");
		CachedHUDWidget->Txt_title->SetText(FText::FromString(DisplayText));
		CachedHUDWidget->Txt_title->SetVisibility(ESlateVisibility::Visible);
	}

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		// 글자가 떠있는 상태로 다시 뒤쪽 배경 화면을 밝게 만듭니다.
		if (APlayerCameraManager* CameraManager = PC->PlayerCameraManager)
		{
			CameraManager->StartCameraFade(1.0f, 0.0f, 1.5f, FLinearColor::Black, false, false);
		}

		// 1.5초 뒤 글자 끄고 조작 복구
		GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &ABaseInteractable::FinishTransition, 1.5f, false);
	}
}

void ABaseInteractable::FinishTransition()
{
	// 🟢 [복구됨] 화면이 완전히 밝아지면 띄워뒀던 글자를 다시 숨깁니다.
	if (CachedHUDWidget && CachedHUDWidget->Txt_title)
	{
		CachedHUDWidget->Txt_title->SetVisibility(ESlateVisibility::Hidden);
	}

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->EnableInput(PC);
	}
}

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