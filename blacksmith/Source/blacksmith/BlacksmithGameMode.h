#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ItemDataAsset.h"
#include "Engine/DataTable.h" // 데이터 테이블 필수 헤더
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="2. RestChair") FText ChairDenyMessage; // 못 쓸 때 출력할 대사

	// [스토리 이벤트 설정]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") TArray<FGeneralEventData> MorningEvents; // 아침 컷신/이벤트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") TArray<FTimerEventData> TimerEvents;     // 타이머 도중 컷신/이벤트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") TArray<FGeneralEventData> NightEvents;   // 야간 자유시간 컷신/이벤트
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

	/* =================================================================
	 * 10분 타이머 & 딸 상태 변수
	 * ================================================================= */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Time")
	float CurrentTimeOfDay = 0.0f; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Daughter")
	bool bIsTimeToGoHome = false; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Daughter")
	bool bIsDaughterFound = false; 

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

	// 휴식 의자 사용 가능한지 통합 검사하는 함수
	UFUNCTION(BlueprintCallable, Category = "Game|Time")
	bool CheckCanUseRestChair(FText& OutDenyMessage);

	/* =================================================================
	 * 블루프린트 이벤트 노드들
	 * ================================================================= */
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events")
	void OnDaughterHideEvent(); 

	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events")
	void OnTimeToGoHomeEvent(); 

	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events")
	void OnDayOverEvent(); 

	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events")
	void OnTriggerCustomTimeEvent(FName EventID, TSubclassOf<class UUserWidget> WidgetClass);
};