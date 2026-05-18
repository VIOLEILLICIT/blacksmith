#include "NPCComponent.h"

UNPCComponent::UNPCComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UNPCComponent::BeginPlay() { Super::BeginPlay(); }

void UNPCComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UNPCComponent::UpdateAffinity(int32 Amount)
{
	Affinity += Amount;
	UE_LOG(LogTemp, Warning, TEXT("현재 친밀도: %d"), Affinity);
}

bool UNPCComponent::ProcessItemEvent(const FItemInteractionEvent& Event, AActor* Interactor)
{
	if (!Event.Item) return false;

	if (Event.bIsGaining)
	{
		UE_LOG(LogTemp, Log, TEXT("아이템 획득 이벤트 발생!"));
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("아이템 소모/확인 이벤트 발생!"));
		return false;
	}
}