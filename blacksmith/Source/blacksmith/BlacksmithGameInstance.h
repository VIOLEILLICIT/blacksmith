#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InventoryComponent.h"     // 🟢 추가: 인벤토리 구조체 인식용
#include "BlacksmithGameMode.h"     // 🟢 추가: 퀘스트 구조체 인식용
#include "BlacksmithGameInstance.generated.h"

// 🟢 [추가] 일반 NPC들의 상태를 기억할 구조체
USTRUCT(BlueprintType)
struct FNPCSavedState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 InteractionCount = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 SavedDateKey = -999;

	UPROPERTY(BlueprintReadWrite)
	int32 SavedScheduleIndex = -1;
};

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
	// 🟢 [추가] 레벨 이동 시 데이터를 백업했는지 확인하는 스위치
	UPROPERTY(BlueprintReadWrite, Category="Global State|System")
	bool bIsDataSaved = false;

	// =================================================================
	// 🎒 플레이어 데이터 백업 (가방, 도감)
	// =================================================================
	UPROPERTY(BlueprintReadWrite, Category="Global State|Player")
	TArray<FInventoryItem> SavedInventory;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Player")
	TSet<UItemDataAsset*> SavedEncyclopedia;

	// =================================================================
	// 📜 게임 진행 데이터 백업 (게임모드 변수들)
	// =================================================================
	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	int32 SavedCurrentDay = 1;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	float SavedCurrentTimeOfDay = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	int32 SavedDaysUntilDeadline = 7;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	bool SavedHasActiveMainQuest = false;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	FQuestData SavedCurrentMainQuest;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	bool SavedIsMainQuestCompleted = false;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	bool SavedIsGracePeriodUsed = false;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	TArray<FQuestData> SavedActiveSubQuests;

	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	int32 SavedDaughterSleepWarningCount = 0;

	// 🟢 [추가] 오늘 우편함 열었는지 상태 백업
	UPROPERTY(BlueprintReadWrite, Category="Global State|Game")
	bool SavedIsDailyTimerStarted = false;

	// 🟢 [추가] NPC들의 고유 ID를 Key로 삼아 각자의 상태를 보관하는 사물함!
	UPROPERTY(BlueprintReadWrite, Category="Global State|NPCs")
	TMap<FName, FNPCSavedState> SavedNPCStates;
};