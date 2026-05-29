#include "BlacksmithPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InteractableInterface.h"
#include "DrawDebugHelpers.h"

ABlacksmithPlayer::ABlacksmithPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABlacksmithPlayer::BeginPlay() { Super::BeginPlay(); }
void ABlacksmithPlayer::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ABlacksmithPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (InteractAction)
		{
			EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ABlacksmithPlayer::RequestInteract);
		}
	}
}

void ABlacksmithPlayer::RequestInteract()
{
	FVector CenterLocation = GetActorLocation();
	TArray<FOverlapResult> OverlapResults;
	FCollisionShape InteractionSphere = FCollisionShape::MakeSphere(InteractionRange);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (bShowDebugSphere)
	{
		DrawDebugSphere(GetWorld(), CenterLocation, InteractionRange, 24, FColor::Magenta, false, 2.0f);
	}

	bool bHasOverlap = GetWorld()->OverlapMultiByChannel(
		OverlapResults,
		CenterLocation,
		FQuat::Identity,
		ECC_Visibility,
		InteractionSphere,
		Params
	);

	if (bHasOverlap)
	{
		AActor* ClosestNPC = nullptr;
		float ClosestDistance = MAX_FLT;

		for (const FOverlapResult& Result : OverlapResults)
		{
			AActor* FoundActor = Result.GetActor();
			if (!FoundActor) continue;

			if (FoundActor->GetClass()->ImplementsInterface(UInteractableInterface::StaticClass()))
			{
				float DistanceToActor = FVector::Dist(CenterLocation, FoundActor->GetActorLocation());
				
				if (DistanceToActor < ClosestDistance)
				{
					ClosestDistance = DistanceToActor;
					ClosestNPC = FoundActor;
				}
			}
		}

		if (ClosestNPC)
		{
			IInteractableInterface::Execute_Interact(ClosestNPC, this);
		}
	}
}