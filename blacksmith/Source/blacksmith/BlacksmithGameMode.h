#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ItemDataAsset.h"
#include "Engine/DataTable.h" 
#include "BlacksmithGameMode.generated.h" // ⭐️ 무조건 맨 마지막 줄!

// 1. 기존 의뢰(Quest) 구조체
USTRUCT(BlueprintType)
struct FQuestData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString QuestName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText QuestDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UItemDataAsset* TargetItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 TargetQuantity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bIsMainQuest;
};

// 2. 타이머 도중(특정 초)에 발생하는 이벤트 구조체
USTRUCT(BlueprintType)
struct FTimerEventData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="발동할 시간(초)")) 
	float TriggerSecond = 0.0f; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="이벤트 ID (분기용)")) 
	FName EventID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="띄울 WBP (선택사항)")) 
	TSubclassOf<class UUserWidget> WidgetToShow;
};

// 3. 일반 시간대(아침, 밤 등)에 발생하는 이벤트 구조체
USTRUCT(BlueprintType)
struct FGeneralEventData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="이벤트 ID")) 
	FName EventID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="띄울 WBP (선택사항)")) 
	TSubclassOf<class UUserWidget> WidgetToShow;
};

// 4. 하루 전체의 설정을 담는 "일일 스케줄" 구조체
USTRUCT(BlueprintType)
struct FDailySchedule
{
	GENERATED_BODY()

	// [의뢰 설정]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="1. Quest") bool bHasMainQuest = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="1. Quest") FQuestData MainQuest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="1. Quest") TArray<FQuestData> SubQuests;

	// [휴식 의자 커스텀 설정]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="2. RestChair") bool bCanUseRestChair = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="2. RestChair") FText ChairDenyMessage; 

	// [스토리 이벤트 설정]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") TArray<FGeneralEventData> MorningEvents; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") TArray<FTimerEventData> TimerEvents;     
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") TArray<FGeneralEventData> NightEvents;   
};

UCLASS()
class BLACKSMITH_API ABlacksmithGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABlacksmithGameMode();

	/* =================================================================
	 * 게임 진행 변수들
	 * ================================================================= */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Date")
	int32 CurrentDay = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	int32 DaysUntilDeadline = 7; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	bool bHasShield = true; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	FQuestData CurrentMainQuest;

	// 🟢 [추가] 까방권 발동 시 화면에 출력할 텍스트 (인스펙터에서 작성)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	FText GracePeriodUseText; 

	// 🟢 [추가] 유예 기간 서브 퀘스트를 랜덤으로 뽑기 위한 모든 아이템 DB
	// (블루프린트 인스펙터에서 게임 내 존재하는 모든 무기 데이터 에셋을 넣어주시면 됩니다)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	TArray<UItemDataAsset*> WeaponDatabase; 

	// 🟢 [추가] 까방권(유예 기간) 발동 함수! (호출 시 화면에 띄울 텍스트를 반환합니다)
	UFUNCTION(BlueprintCallable, Category = "Game|Quest")
	FText ActivateGracePeriod();
	/* =================================================================
	 * 10분 타이머 & 딸 상태 변수
	 * ================================================================= */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Time")
	float CurrentTimeOfDay = 0.0f; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Daughter")
	bool bIsTimeToGoHome = false; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Daughter")
	bool bIsDaughterFound = false; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Daughter")
	bool bIsDaughterAsleep = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Daughter")
	bool bIsDaughterAwake = false;

	FTimerHandle DailyTimerHandle;

	/* =================================================================
	 * 날짜별 스케줄 리스트 (인스펙터 커스텀용)
	 * ================================================================= */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Schedule", meta=(DisplayName="날짜별 전체 스케줄"))
	TMap<int32, FDailySchedule> DailyScheduleMap;

	/* =================================================================
	 * 외부에서 호출할 함수들
	 * ================================================================= */
	UFUNCTION(BlueprintCallable, Category = "Game|Time") void StartDailyTimer(); 
	UFUNCTION(BlueprintCallable, Category = "Game|Time") void AdvanceTimeOneSecond(); 
	UFUNCTION(BlueprintCallable, Category = "Game|Time") void WarpTimeTo(float TargetSeconds);
	UFUNCTION(BlueprintCallable, Category = "Game|Date") void SleepAndNextDay(); 

	// 상호작용 가능 여부 판별 함수들
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseRestChair(FText& OutDenyMessage);
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseBed(FText& OutDenyMessage);
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseDoor(FText& OutDenyMessage);

	/* =================================================================
	 * 블루프린트 이벤트 노드들
	 * ================================================================= */
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnDaughterHideEvent(); 
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnTimeToGoHomeEvent(); 
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnDayOverEvent(); 
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnTriggerCustomTimeEvent(FName EventID, TSubclassOf<class UUserWidget> WidgetClass);
};