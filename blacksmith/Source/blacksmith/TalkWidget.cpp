#include "TalkWidget.h"
#include "TimerManager.h"

bool UTalkWidget::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	// 키보드 입력을 받을 수 있도록 허용
	SetIsFocusable(true); 
	return true;
}

void UTalkWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	// UI가 화면에 뜰 때 키보드 포커스를 강제로 가져옴
	SetKeyboardFocus();

	// 0.5초 동안은 바로 꺼지지 않도록 쿨타임 가동 (광클 방지)
	bCanClose = false;
	GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &UTalkWidget::EnableClose, 0.5f, false);
}

void UTalkWidget::EnableClose()
{
	bCanClose = true;
}

void UTalkWidget::CloseWidget()
{
	// 0.5초가 안 지났다면 무시
	if (!bCanClose) return;

	// 물체(BaseInteractable)에 닫혔다고 신호를 보내고, 화면에서 삭제!
	OnTalkClosed.Broadcast(); 
	RemoveFromParent();
}

FReply UTalkWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	CloseWidget();
	return FReply::Handled();
}

FReply UTalkWidget::NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	// 꾹 누르고 있는 상태 무시
	if (InKeyEvent.IsRepeat()) return FReply::Handled();
	
	CloseWidget();
	return FReply::Handled();
}