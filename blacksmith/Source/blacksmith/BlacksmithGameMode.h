#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ItemDataAsset.h"
#include "Engine/DataTable.h" 
#include "DaughterNPC.h"
#include "BlacksmithGameMode.generated.h" // ⭐️ 무조건 맨 마지막 줄!


// =====================================================================
// 🟢 보수 종류 (재화인지, 아이템인지 구분)
// =====================================================================
UENUM(BlueprintType)
enum class ERewardType : uint8
{
	Currency UMETA(DisplayName = "재화 (돈)"),
	Item UMETA(DisplayName = "아이템")
};

// =====================================================================
// 🟢 개별 퀘스트 보수 정보 구조체
// =====================================================================
USTRUCT(BlueprintType)
struct FQuestReward
{
	GENERATED_BODY()

	// 퀘스트 완료 시 지급할 보수 타입을 선택합니다. (재화 또는 아이템)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="보수 종류"))
	ERewardType RewardType = ERewardType::Currency;

	// '보수 종류'를 [아이템]으로 선택했을 때만 나타납니다. 지급할 데이터 에셋을 지정하세요.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="지급할 아이템", EditCondition="RewardType == ERewardType::Item", EditConditionHides))
	UItemDataAsset* RewardItem = nullptr;

	// 보수가 재화면 지급할 [금액]을, 아이템이면 지급할 [개수]를 의미합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="수량 및 금액"))
	int32 RewardAmount = 1;
};

// =====================================================================
// 1. 퀘스트(의뢰) 데이터 구조체
// =====================================================================
USTRUCT(BlueprintType)
struct FQuestData
{
	GENERATED_BODY()
	
	// 플레이어에게 보여질 의뢰의 제목입니다. (예: 마을 수비대장의 부탁)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	FString QuestName;

	// 플레이어가 수행할 의뢰의 상세 스토리 및 내용입니다. UI에 출력됩니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	FText QuestDescription;

	// 제작해서 납품해야 할 목표 아이템(데이터 에셋)을 지정합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	UItemDataAsset* TargetItem;

	// 납품해야 할 목표 아이템의 요구 개수입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	int32 TargetQuantity;

	// 이 의뢰가 스토리 진행에 필수적인 '메인 퀘스트'인지 여부를 체크합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	bool bIsMainQuest;

	// (서브 퀘스트 전용) 퀘스트를 수락한 후 며칠 내에 깨야 하는지 기한을 설정합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="서브 퀘스트 기한(일)")) 
	int32 DeadlineDays = 3;

	// 이 퀘스트를 성공적으로 완료했을 때 플레이어에게 지급할 보수 목록입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Reward", meta=(DisplayName="퀘스트 완료 보수 목록"))
	TArray<FQuestReward> QuestRewards;
};

// =====================================================================
// 2. 타이머 도중(특정 초)에 발생하는 이벤트 구조체
// =====================================================================
USTRUCT(BlueprintType)
struct FTimerEventData
{
	GENERATED_BODY()
	
	// 낮 타이머가 이 시간(초)에 도달하면 이벤트가 발동합니다. (예: 180 = 3분)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="발동할 시간(초)")) 
	float TriggerSecond = 0.0f; 
	
	// 블루프린트에서 어떤 이벤트를 실행할지 구분하기 위한 고유 ID 문자열입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="이벤트 ID (분기용)")) 
	FName EventID;
	
	// 이벤트 발생 시 화면에 띄울 UI 위젯 클래스입니다. (선택 사항)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="띄울 WBP (선택사항)")) 
	TSubclassOf<class UUserWidget> WidgetToShow;
};

// =====================================================================
// 3. 일반 시간대(아침, 밤 등)에 발생하는 이벤트 구조체
// =====================================================================
USTRUCT(BlueprintType)
struct FGeneralEventData
{
	GENERATED_BODY()
	
	// 이벤트 발생을 위한 고유 ID입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="이벤트 ID")) 
	FName EventID;
	
	// 이벤트 발생 시 화면에 띄울 UI 위젯 클래스입니다. (선택 사항)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="띄울 WBP (선택사항)")) 
	TSubclassOf<class UUserWidget> WidgetToShow;
};

// =====================================================================
// 4. 하루 전체의 설정을 담는 "일일 스케줄" 구조체
// =====================================================================
USTRUCT(BlueprintType)
struct FDailySchedule
{
	GENERATED_BODY()

	// 개발자가 인스펙터에서 스케줄을 쉽게 파악하기 위해 적어두는 메모입니다. 플레이에는 영향을 주지 않습니다.
	UPROPERTY(EditAnywhere, Category="0. Memo", meta=(DisplayName="스케줄 요약 메모", MultiLine="true"))
	FString ScheduleMemo;

	// 오늘 아침에 '새로운 메인 퀘스트'를 플레이어에게 발급할지 결정하는 스위치입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="1. Quest") 
	bool bHasMainQuest = false;
	
	// 위 스위치가 켜졌을 때 발급될 메인 퀘스트의 상세 정보입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="1. Quest") 
	FQuestData MainQuest;
	
	// 오늘 하루 동안 추가로 주어지는 서브 퀘스트들의 목록입니다. (누적됨)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="1. Quest") 
	TArray<FQuestData> SubQuests;

	// 오늘 하루 동안 휴식 의자를 사용하여 시간을 건너뛸 수 있는지 여부입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="2. RestChair") 
	bool bCanUseRestChair = true;
	
	// 의자 사용이 금지되었을 때 출력할 핑계/거절 대사입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="2. RestChair") 
	FText ChairDenyMessage; 

	// 아침 0초가 될 때 즉시 발생할 컷신/이벤트 목록입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") 
	TArray<FGeneralEventData> MorningEvents; 
	
	// 낮 시간(10분) 중 특정 시간에 맞춰 발생하는 타이머 이벤트 목록입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") 
	TArray<FTimerEventData> TimerEvents;     
	
	// 밤이 되어 일과가 끝나고 자율 활동 시간이 되었을 때 발생하는 이벤트 목록입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="3. Events") 
	TArray<FGeneralEventData> NightEvents;   

	// 오늘 아침이 밝았을 때, 플레이어의 도감에 자동으로 해금될 무기(레시피) 데이터 목록입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="4. Unlocks") 
	TArray<class UItemDataAsset*> WeaponsToUnlock;
};


UCLASS()
class BLACKSMITH_API ABlacksmithGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABlacksmithGameMode();

	// 🟢 여기에 쏙 넣어주세요!
	virtual void BeginPlay() override;

	// 🟢 [추가] 현재 진행 중인 모든 의뢰(메인+서브)를 하나의 배열로 합쳐서 반환합니다.
	UFUNCTION(BlueprintCallable, Category = "Game|Quest")
	TArray<FQuestData> GetAllActiveQuests();

	// 🟢 [추가] 아까 우편함에 썼던 [메인/서브] 태그와 보수 텍스트 변환 로직을 메뉴에서도 쓰기 위해 분리!
// 🟢 [수정] 맨 뒤에 남은 기한(OutDeadlineInfo)을 뽑아줄 수 있도록 추가!
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Game|Quest")
	void FormatQuestForUI(const FQuestData& InQuest, FString& OutTitle, FText& OutDescription, FString& OutRewardInfo, FString& OutDeadlineInfo);	/* =================================================================
	 * 📬 우편함 (의뢰 및 편지 대기열 시스템)
	 * ================================================================= */
	
	// 🟢 인스펙터에서 선택할 UI 위젯 클래스들
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game|Mail", meta=(DisplayName="의뢰 우편 WBP 클래스"))
	TSubclassOf<class UMailQuestWidget> QuestMailWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game|Mail", meta=(DisplayName="딸 편지 WBP 클래스"))
	TSubclassOf<class UMailLetterWidget> WarLetterWidgetClass;

	// 남은 의뢰들을 순서대로 담아둘 대기열[cite: 12]
	UPROPERTY(BlueprintReadWrite, Category = "Game|Mail")
	TArray<FQuestData> MailQuestQueue;

	// 딸의 편지가 대기 중인지 여부
	UPROPERTY(BlueprintReadWrite, Category = "Game|Mail")
	bool bHasPendingWarLetter = false;

	// 대기 중인 편지 데이터[cite: 12]
	UPROPERTY(BlueprintReadWrite, Category = "Game|Mail")
	FWarLetterData PendingWarLetter;

	// 우편함에서 F키를 누르면 호출할 핵심 함수
	UFUNCTION(BlueprintCallable, Category = "Game|Mail")
	void OpenMailbox();

	// 현재 창이 닫혔을 때, 다음 우편물을 꺼내오라고 지시하는 함수
	UFUNCTION(BlueprintCallable, Category = "Game|Mail")
	void ShowNextMail();

	

	/* --- 블루프린트에서 UI를 띄우기 위해 발사하는 이벤트들 --- */
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Mail")
	void OnShowQuestMailUI(const FQuestData& QuestData);

	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Mail")
	void OnShowWarLetterUI(const FWarLetterData& LetterData);

	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Mail")
	void OnMailSequenceFinished();

	// 🟢 레벨 이동 시 모든 데이터를 인스턴스에 백업하는 함수
	UFUNCTION(BlueprintCallable, Category = "Game|SaveLoad")
	void SaveGlobalData();

	// 🟢 맵이 켜졌을 때 인스턴스에서 데이터를 다시 가져오는 함수
	UFUNCTION(BlueprintCallable, Category = "Game|SaveLoad")
	void RestoreGlobalData();

	UPROPERTY(EditDefaultsOnly, Category = "Daughter Spawner")
	TSubclassOf<class ADaughterNPC> DaughterClass;

	/* =================================================================
	 * 게임 전체 루프 및 기본 설정 (Global Settings)
	 * ================================================================= */
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Settings", meta=(DisplayName="총 진행 가능 일수 (엔딩 날짜)"))
	int32 MaxGameDays = 43;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Settings", meta=(DisplayName="시작 기본 의뢰 기한(일)"))
	int32 DefaultStartingDeadline = 7;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Settings", meta=(DisplayName="까방권 연장 일수"))
	int32 GracePeriodDays = 7;

	

	/* =================================================================
	 * 게임 진행 변수들 (State)
	 * ================================================================= */
	
	// 현재 게임 내 진행 중인 날짜(일차)입니다. 잠을 잘 때마다 1씩 증가합니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Date")
	int32 CurrentDay = 1;

	// 메인 의뢰 납품까지 남은 유예 기한(일수)입니다. 0이 되면 까방권 발동 또는 게임 오버가 됩니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	int32 DaysUntilDeadline = 7; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	bool bHasShield = true; 

	// 플레이어가 현재 수행 중인 메인 퀘스트의 정보입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	FQuestData CurrentMainQuest;

	// ⚠️ 현재 진행 중인 메인 퀘스트를 완료했는지 여부입니다. (납품 성공 시 블루프린트에서 True로 바꿔주세요!)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	bool bIsMainQuestCompleted = false;

	// 현재 마감일이 존재하는 메인 퀘스트를 '진행 중'인지 여부입니다. (없을 땐 억울한 실패 방지)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	bool bHasActiveMainQuest = false;

	// 까방권(스케줄 연장 기회)을 이미 사용했는지 기록하는 변수입니다. (단 1회 제한)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	bool bIsGracePeriodUsed = false;

	// 플레이어가 기한 내에 해결해야 하는 서브 퀘스트들의 진행 목록(퀘스트 로그)입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	TArray<FQuestData> ActiveSubQuests;

	// 까방권 발동 시 화면에 출력할 알림 대사입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	FText GracePeriodUseText; 

	// 까방권 발동 시 대체할 서브 퀘스트를 뽑아오기 위한 '모든 무기 데이터 에셋'의 참조 창고입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Quest")
	TArray<UItemDataAsset*> WeaponDatabase; 

	UFUNCTION(BlueprintCallable, Category = "Game|Quest")
	FText ActivateGracePeriod();
	
	/* =================================================================
	 * 까방권 및 메인 실패 관련 커스텀 이벤트 등록 배열
	 * ================================================================= */
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="까방권 발동 이벤트 목록"))
	TArray<FGeneralEventData> GracePeriodEvents; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="메인 퀘스트 실패(게임오버) 이벤트 목록"))
	TArray<FGeneralEventData> GameOverEvents;

	/* =================================================================
	 * 10분 타이머 & 딸 상태 변수
	 * ================================================================= */
	// 🟢 [추가] 오늘 우편함을 열어서 타이머가 돌아가고 있는지 확인하는 스위치
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Time")
	bool bIsDailyTimerStarted = false;

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
	
	// 🟢 딸 수면 누적 경고 횟수
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Daughter")
	int32 DaughterSleepWarningCount = 0;

	FTimerHandle DailyTimerHandle;

	/* =================================================================
	 * 딸 수면 미수행(경고/오버) 이벤트 등록 배열 (찾음 vs 못찾음 분리)
	 * ================================================================= */
	
	// [찾았지만 안 재웠을 때]
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="1차 경고 (찾음/안재움) 이벤트"))
	TArray<FGeneralEventData> Warning1_FoundEvents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="2차 경고 (찾음/안재움) 이벤트"))
	TArray<FGeneralEventData> Warning2_FoundEvents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="3차 게임오버 (찾음/안재움) 이벤트"))
	TArray<FGeneralEventData> GameOver_FoundEvents;

	// [아예 찾지도 않았을 때]
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="1차 경고 (못찾음) 이벤트"))
	TArray<FGeneralEventData> Warning1_NotFoundEvents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="2차 경고 (못찾음) 이벤트"))
	TArray<FGeneralEventData> Warning2_NotFoundEvents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Events", meta=(DisplayName="3차 게임오버 (못찾음) 이벤트"))
	TArray<FGeneralEventData> GameOver_NotFoundEvents;

	/* =================================================================
	 * 날짜별 스케줄 리스트
	 * ================================================================= */
	
	// 🟢 날짜를 접었을 때 요약 메모가 제목으로 보이도록 TitleProperty 적용
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game|Schedule", meta=(DisplayName="날짜별 전체 스케줄", TitleProperty="ScheduleMemo"))
	TMap<int32, FDailySchedule> DailyScheduleMap;

	// [최적화용] 오늘자 스케줄 캐싱
	UPROPERTY()
	bool bHasTodaySchedule = false;

	UPROPERTY()
	FDailySchedule TodayScheduleCache;

	/* =================================================================
	 * 외부에서 호출할 로직 함수들
	 * ================================================================= */
	UFUNCTION(BlueprintCallable, Category = "Game|Time") void StartDailyTimer(); 
	UFUNCTION(BlueprintCallable, Category = "Game|Time") void AdvanceTimeOneSecond(); 
	UFUNCTION(BlueprintCallable, Category = "Game|Time") void WarpTimeTo(float TargetSeconds);
	UFUNCTION(BlueprintCallable, Category = "Game|Date") void SleepAndNextDay(); 

	// 상호작용 가능 여부 판별 함수들
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseRestChair(FText& OutDenyMessage);
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseBed(FText& OutDenyMessage);
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseDoor(FText& OutDenyMessage);
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseDaughterBed(FText& OutDenyMessage);
	// 🟢 [추가] 밖에서 집으로 들어올 때 검사할 함수
	UFUNCTION(BlueprintCallable, Category = "Game|Interaction") bool CheckCanUseReturnDoor(FText& OutDenyMessage);

	/* =================================================================
	 * 블루프린트 통신용 이벤트 노드들
	 * ================================================================= */
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnDaughterHideEvent(); 
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnTimeToGoHomeEvent(); 
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnFreeTimeStartEvent();
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnDayOverEvent(); 
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") void OnGameOverEvent();

	// 🟢 새로 추가! 다음 날 아침이 밝았을 때 딸의 위치를 초기화하라고 보내는 신호
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") 
	void OnMorningResetEvent();

	// 인스펙터에 등록해둔 일반 이벤트를 블루프린트에서 ID로 꺼내 쓸 수 있도록 쏴주는 만능 실행 노드
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") 
	void OnTriggerGeneralEvent(FName EventID, TSubclassOf<class UUserWidget> WidgetClass);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Game|Events") 
	void OnTriggerCustomTimeEvent(FName EventID, TSubclassOf<class UUserWidget> WidgetClass);
};