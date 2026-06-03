#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NPCComponent.generated.h"

// 🟢 시간대 구분을 위한 열거형
UENUM(BlueprintType)
enum class ETimePhase : uint8
{
	Morning   UMETA(DisplayName = "아침 (타이머 시작 전)"),
	DayTimer  UMETA(DisplayName = "낮 (타이머 진행 중)"),
	Night     UMETA(DisplayName = "밤 (타이머 종료 후, 자율시간)")
};

// =================================================================
// 대화 1줄 및 시퀀스 구조체
// =================================================================
USTRUCT(BlueprintType)
struct FDialogueLine
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="말하는 사람"))
	FString SpeakerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="대사 내용", MultiLine="true"))
	FText DialogueText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="함께 띄울 이미지 (선택)"))
	class UTexture2D* DisplayImage = nullptr; 
};

USTRUCT(BlueprintType)
struct FDialogueSequence
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="대사 목록"))
	TArray<FDialogueLine> Lines;
};

// =================================================================
// ⏰ 1. 특정 시간대(아침, 낮 n초, 밤)의 대화 세트 및 설정
// =================================================================
USTRUCT(BlueprintType)
struct FNPCTimeSchedule
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="적용 시간대"))
	ETimePhase TargetPhase = ETimePhase::DayTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="낮(타이머)일 경우 발동 시간(초)", EditCondition="TargetPhase == ETimePhase::DayTimer", EditConditionHides))
	float TriggerSecond = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="이 시간대에 맵에 보일지 여부"))
	bool bIsVisible = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speech Bubble", meta=(DisplayName="자동 말풍선 대사들 (순서대로 반복)"))
	TArray<FText> AutoSpeechBubbles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speech Bubble", meta=(DisplayName="말풍선 변경 주기(초)"))
	float SpeechInterval = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction", meta=(DisplayName="상호작용 횟수별 대화 세트"))
	TArray<FDialogueSequence> InteractionDialogues; 
};

// =================================================================
// 📅 2. 특정 날짜(하루)의 전체 스케줄 묶음
// =================================================================
USTRUCT(BlueprintType)
struct FNPCDaySchedule
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="시간대별 스케줄 목록", TitleProperty="TargetPhase"))
	TArray<FNPCTimeSchedule> TimeSchedules;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BLACKSMITH_API UNPCComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UNPCComponent();

	// 🟢 [핵심] 인덱스가 아닌 날짜(Key)로 관리하는 맵 시스템!
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Schedule", meta=(DisplayName="날짜별 스케줄 맵 (Key: 날짜 / -1: 매일 적용)"))
	TMap<int32, FNPCDaySchedule> DailySchedules;

	// 플레이어가 이 NPC에게 말을 건 횟수
	UPROPERTY(BlueprintReadWrite, Category = "NPC State")
	int32 InteractionCount = 0;

	// 시간대에 맞는 스케줄과 그 '위치(Key, Index)'를 함께 반환하는 함수
	UFUNCTION(BlueprintCallable, Category = "NPC")
	bool GetCurrentSchedule(int32 CurrentDay, float CurrentTimeOfDay, FNPCTimeSchedule& OutSchedule, int32& OutDateKey, int32& OutScheduleIndex);

	UFUNCTION(BlueprintCallable, Category = "NPC")
	void IncrementInteractionCount();
};