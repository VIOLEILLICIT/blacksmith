#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NPCComponent.h"

// ⭐️ 무조건 모든 #include의 가장 마지막 줄에 있어야 합니다!
#include "DialogueWidget.generated.h" 

// 🟢 델리게이트 매크로는 반드시 generated.h 파일 아래, UCLASS() 위에 적어야 합니다!
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogueFinished);

class UTextBlock;
class UImage;

UCLASS()
class BLACKSMITH_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// 위젯이 키보드 입력을 받을 수 있도록 기본 설정하는 함수
	virtual bool Initialize() override;

	// NPC가 호출할 시작 함수
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void StartDialogue(const FDialogueSequence& NewSequence);

	// 블루프린트에서 노드로 묶을 수 있는 대화 종료 신호
	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
	FOnDialogueFinished OnDialogueFinished;

protected:
	// 🖱️ 마우스 클릭 감지 엔진 내장 함수 오버라이드
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	// ⌨️ 키보드 입력이 엔진이나 다른 UI에 뺏기기 전에 무조건 먼저 가로채는 함수
	virtual FReply NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	// 화면 갱신
	void UpdateDialogueUI();
	
	// 다음 대사로 넘어가는 실제 로직
	void AdvanceDialogue();
	
	// 쿨타임이 끝났을 때 호출될 함수
	void EnableNextDialogue();

private:
	/* =================================================================
	 * 🎨 위젯 바인딩
	 * ================================================================= */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Txt_SpeakerName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Txt_Dialogue;

	UPROPERTY(meta = (BindWidget))
	UImage* Img_Display;

	/* =================================================================
	 * 🧠 내부 논리 데이터
	 * ================================================================= */
	FDialogueSequence CurrentSequence;
	int32 CurrentIndex = 0;

	// ⏳ 쿨타임 제어용 변수들
	bool bCanGoNext = false;
	FTimerHandle CooldownTimerHandle;
};