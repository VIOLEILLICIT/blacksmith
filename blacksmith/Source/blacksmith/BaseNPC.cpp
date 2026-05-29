#include "BaseNPC.h"
#include "NPCComponent.h"

ABaseNPC::ABaseNPC()
{
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 생성 및 장착
	NPCComponent = CreateDefaultSubobject<UNPCComponent>(TEXT("NPCComponent"));
}

void ABaseNPC::BeginPlay() { Super::BeginPlay(); }
void ABaseNPC::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ABaseNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }

void ABaseNPC::Interact_Implementation(AActor* Interactor)
{
	// 플레이어가 다가와서 F를 누르면 실행됩니다.
	FString TargetName = DisplayName.IsEmpty() ? TEXT("이름 없는 NPC") : DisplayName;
	UE_LOG(LogTemp, Warning, TEXT("%s: 안녕하세요! 무엇을 도와드릴까요?"), *TargetName);
}