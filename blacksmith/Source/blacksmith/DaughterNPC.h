#pragma once

#include "CoreMinimal.h"
#include "BaseNPC.h" 
#include "Blueprint/UserWidget.h"
#include "DaughterNPC.generated.h"

// 딸의 성장 단계
UENUM(BlueprintType)
enum class EDaughterPhase : uint8
{
	Child UMETA(DisplayName = "어린 시절"),
	Adult UMETA(DisplayName = "성인 시절"),
	War   UMETA(DisplayName = "전쟁터 파병")
};

// =================================================================
// 👧 [어린 시절] 숨는 장소 + 말풍선 세트
// =================================================================
USTRUCT(BlueprintType)
struct FChildHideoutData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="목표 레벨 이름 (예: Inhouse)"))
	FName TargetLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="목표 액터의 태그 (예: DaughterBed)"))
	FName TargetPointTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="띄울 말풍선 WBP"))
	TSubclassOf<class UUserWidget> BubbleWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="숨었을 때 출력할 대사"))
	FText SpeechText;
};

// =================================================================
// 👩 [성인] 외출 장소 + 책상에 남길 편지 세트
// =================================================================
USTRUCT(BlueprintType)
struct FAdultHideoutData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="목표 레벨 이름 (예: Village)"))
	FName TargetLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="목표 액터의 태그 (예: AdultTarget)"))
	FName TargetPointTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="띄울 편지 UI WBP"))
	TSubclassOf<class UUserWidget> LetterWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="책상에 남긴 편지 내용", MultiLine="true"))
	FText LetterText;
};

// =================================================================
// ⚔️ [전쟁터] 파병지에서 온 편지 세트
// =================================================================
USTRUCT(BlueprintType)
struct FWarLetterData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="띄울 편지 UI WBP"))
	TSubclassOf<class UUserWidget> LetterWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="전쟁터에서 온 편지 내용", MultiLine="true"))
	FText LetterText;
};

UCLASS()
class BLACKSMITH_API ADaughterNPC : public ABaseNPC
{
	GENERATED_BODY()

public:
	ADaughterNPC();
	virtual void BeginPlay() override;

	/* =================================================================
	 * 1. 페이즈 자동 전환 날짜 설정
	 * ================================================================= */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Daughter Settings|Phase")
	EDaughterPhase CurrentPhase = EDaughterPhase::Child;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Daughter Settings|Phase", meta=(DisplayName="성인이 되는 날짜 (해당 일차 아침부터)"))
	int32 AdultStartDay = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Daughter Settings|Phase", meta=(DisplayName="전쟁터로 떠나는 날짜 (해당 일차 아침부터)"))
	int32 WarStartDay = 29;

	/* =================================================================
	 * 2. 딸 고유 연출용 장소 및 편지 데이터
	 * ================================================================= */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Daughter Settings|Child") 
	TArray<FChildHideoutData> ChildHideoutList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Daughter Settings|Adult") 
	TArray<FAdultHideoutData> AdultHideoutList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Daughter Settings|War") 
	TMap<int32, FWarLetterData> WarLettersByDay;

	/* =================================================================
	 * 내부 동작 로직
	 * ================================================================= */
	FTimerHandle DaughterRoutineTimer;

	UFUNCTION() 
	void UpdateDaughterRoutine();

	virtual void Interact_Implementation(AActor* Interactor) override;

	UFUNCTION(BlueprintCallable, Category = "Daughter AI") 
	void TeleportToRandomHideout();

	// 🟢 부모의 '대화 끝난 후 행동'을 딸 전용으로 덮어씁니다.
	virtual void OnDialogueEndAction() override;

	/* =================================================================
	 * 블루프린트 통신용 이벤트 노드
	 * ================================================================= */
	UFUNCTION(BlueprintImplementableEvent, Category = "Daughter AI") 
	void OnShowTeleportBubble(TSubclassOf<class UUserWidget> WidgetClass, const FText& SpeechText);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Daughter AI") 
	void OnLeaveLetterAtDesk(TSubclassOf<class UUserWidget> WidgetClass, const FText& LetterText);
};