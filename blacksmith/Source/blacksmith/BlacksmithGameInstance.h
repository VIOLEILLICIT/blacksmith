#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BlacksmithGameInstance.generated.h"

UCLASS()
class BLACKSMITH_API UBlacksmithGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// 1. 딸이 현재 플레이어를 쫓아다니고 있는가?
	UPROPERTY(BlueprintReadWrite, Category="Global State")
	bool bIsDaughterFollowing = false;

	// 2. (혼자 있을 때) 딸이 머물러야 할 레벨(맵) 이름
	UPROPERTY(BlueprintReadWrite, Category="Global State")
	FName DaughterSavedLevel;

	// 3. (혼자 있을 때) 딸이 대기할 장소의 액터 태그 (Tag)
	UPROPERTY(BlueprintReadWrite, Category="Global State")
	FName DaughterSavedLocationTag;
};