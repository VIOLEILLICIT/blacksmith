#pragma once

#include "CoreMinimal.h"
#include "SharedTypes.generated.h"

// NPC 직업군 열거형
UENUM(BlueprintType)
enum class ENPCJob : uint8
{
	None UMETA(DisplayName = "None"),
	Blacksmith UMETA(DisplayName = "대장장이"),
	Merchant UMETA(DisplayName = "상인"),
	Villager UMETA(DisplayName = "마을 주민")
};