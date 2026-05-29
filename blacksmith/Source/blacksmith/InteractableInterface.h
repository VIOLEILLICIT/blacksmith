#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

class BLACKSMITH_API IInteractableInterface
{
	GENERATED_BODY()

public:
	// ⭐️ [핵심] 이 매크로 한 줄이 들어가야 블루프린트에서 노드로 꺼낼 수 있습니다!
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Interact(AActor* Interactor); 
};