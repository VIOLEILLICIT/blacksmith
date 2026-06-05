#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

// ⭐️ 무조건 마지막 #include 이어야 합니다!
#include "TalkWidget.generated.h"

// 🟢 델리게이트는 반드시 generated.h 아래, UCLASS 위에 작성해야 에러가 안 납니다!
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTalkClosed);

UCLASS()
class BLACKSMITH_API UTalkWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;

	// 거절 메시지가 닫혔음을 상호작용 물체(문, 침대 등)에 알리는 신호
	UPROPERTY(BlueprintAssignable, Category = "Talk")
	FOnTalkClosed OnTalkClosed;

protected:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

private:
	bool bCanClose = false;
	FTimerHandle CooldownTimerHandle;

	void EnableClose();
	void CloseWidget();
};

UCLASS()
class BLACKSMITH_API UMailQuestWidget : public UTalkWidget
{
	GENERATED_BODY()

public:
	// 🟢 [수정됨] 맨 끝에 const FString& DeadlineInfo 가 추가되었습니다!
	UFUNCTION(BlueprintImplementableEvent, Category = "Mail")
	void UpdateMailUI(const FString& Title, const FText& Description, const FString& RewardInfo, const FString& DeadlineInfo);
};

UCLASS()
class BLACKSMITH_API UMailLetterWidget : public UTalkWidget
{
	GENERATED_BODY()

public:
	// 🟢 C++가 딸의 편지 내용을 던져줄 이벤트
	UFUNCTION(BlueprintImplementableEvent, Category = "Mail")
	void UpdateLetterUI(const FText& LetterContent);
};