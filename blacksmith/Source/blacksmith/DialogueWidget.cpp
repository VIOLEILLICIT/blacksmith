#include "DialogueWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "TimerManager.h" 

bool UDialogueWidget::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	// 변수에 직접 대입하는 대신 SetIsFocusable() 함수를 사용합니다!
	SetIsFocusable(true); 
	
	return true;
}

void UDialogueWidget::StartDialogue(const FDialogueSequence& NewSequence)
{
	CurrentSequence = NewSequence;
	CurrentIndex = 0;
	
	// 대화가 시작되면 이 창으로 포커스를 강제로 가져옵니다. 
	SetKeyboardFocus();

	UpdateDialogueUI();
}

void UDialogueWidget::UpdateDialogueUI()
{
	// 1. 대사 및 이미지 갱신
	if (CurrentSequence.Lines.IsValidIndex(CurrentIndex))
	{
		const FDialogueLine& CurrentLine = CurrentSequence.Lines[CurrentIndex];

		if (Txt_SpeakerName) Txt_SpeakerName->SetText(FText::FromString(CurrentLine.SpeakerName));
		if (Txt_Dialogue) Txt_Dialogue->SetText(CurrentLine.DialogueText);

		if (Img_Display)
		{
			if (CurrentLine.DisplayImage != nullptr)
			{
				Img_Display->SetBrushFromTexture(CurrentLine.DisplayImage);
				Img_Display->SetVisibility(ESlateVisibility::Visible);
			}
			else
			{
				Img_Display->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}

	// 2. 대사가 방금 바뀌었으므로 0.5초 동안 넘기기 금지! (광클 방지)
	bCanGoNext = false;
	GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &UDialogueWidget::EnableNextDialogue, 0.5f, false);
}

// 0.5초 뒤에 타이머가 호출해 줄 함수
void UDialogueWidget::EnableNextDialogue()
{
	bCanGoNext = true;
}

// 다음 대사로 넘기는 공통 핵심 로직
void UDialogueWidget::AdvanceDialogue()
{
	// 아직 0.5초가 안 지났다면 무시!
	if (!bCanGoNext) return;

	CurrentIndex++;

	if (CurrentIndex < CurrentSequence.Lines.Num())
	{
		UpdateDialogueUI();
	}
	else
	{
		// 창을 닫기 직전에 "대화 끝났어!" 라고 소리칩니다.
		OnDialogueFinished.Broadcast(); 
		RemoveFromParent();
	}
}

/* =================================================================
 * 🖱️ 마우스 / ⌨️ 키보드 입력 감지 이벤트
 * ================================================================= */
FReply UDialogueWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// 화면 어디든 마우스를 클릭하면 다음으로 넘어가기 시도
	AdvanceDialogue();
	
	return FReply::Handled();
}

// 🟢 이제 스페이스바나 엔터키를 눌러도 엔진이 엉뚱한 행동을 하지 못합니다.
FReply UDialogueWidget::NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	// 키보드를 꾹 누르고 있는 연속 입력 상태는 무시
	if (InKeyEvent.IsRepeat())
	{
		return FReply::Handled();
	}

	// 오직 새로 키를 '탁' 쳤을 때만 다음 대사로 넘어가기 시도
	AdvanceDialogue();
	
	return FReply::Handled();
}