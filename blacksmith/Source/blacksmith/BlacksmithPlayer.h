#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractableInterface.h"
#include "BlacksmithPlayer.generated.h"

UCLASS()
class BLACKSMITH_API ABlacksmithPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ABlacksmithPlayer();

protected:
	virtual void BeginPlay() override;

	void RequestInteract();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 입력 액션 에셋 할당칸
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* InteractAction;

	// 상호작용 감지 반경
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractionRange = 250.0f;

	// 디버그 구체 시각화 옵션
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Debug")
	bool bShowDebugSphere = false;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Currency")
	int32 Gold = 0;
};