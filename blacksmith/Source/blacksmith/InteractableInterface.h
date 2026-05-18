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
	// 누군가 F키를 눌렀을 때 실행될 함수
	virtual void Interact(AActor* Interactor) = 0;
};