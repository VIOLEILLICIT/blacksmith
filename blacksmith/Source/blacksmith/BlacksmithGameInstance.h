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

	// 🟢 2. [추가] 딸 상태(문 상호작용 등) 백업
	UPROPERTY(BlueprintReadWrite, Category="Global State")
	bool bIsDaughterAwake = false;

	UPROPERTY(BlueprintReadWrite, Category="Global State")
	bool bIsDaughterFound = false;

	// 🟢 3. [추가] 딸 대화 진행도(초기화 방지) 백업
	UPROPERTY(BlueprintReadWrite, Category="Global State")
	int32 DaughterSavedDateKey = -999;
	
	UPROPERTY(BlueprintReadWrite, Category="Global State")
	int32 DaughterSavedScheduleIndex = -1;

	UPROPERTY(BlueprintReadWrite, Category="Global State")
	int32 DaughterInteractionCount = 0;
};