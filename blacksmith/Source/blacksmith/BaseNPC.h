#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractableInterface.h"
#include "SharedTypes.h"
#include "BaseNPC.generated.h"

UCLASS()
class BLACKSMITH_API ABaseNPC : public ACharacter, public IInteractableInterface
{
	GENERATED_BODY()

public:
	ABaseNPC();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 인터페이스 상속 함수 구현
	virtual void Interact_Implementation(AActor* Interactor) override;

	// NPC 두뇌 컴포넌트 장착
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UNPCComponent* NPCComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data")
	ENPCJob Job;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data")
	class UTexture2D* Portrait;

	// 맵에서 위젯으로 조절할 수 있는 순찰 경로
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data|Patrol", meta=(MakeEditWidget=true))
	TArray<FVector> PatrolPoints;
};