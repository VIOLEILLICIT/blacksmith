#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimeHUDWidget.generated.h"

class UTextBlock;

UCLASS()
class BLACKSMITH_API UTimeHUDWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public: // 🟢 외부(Interactable)에서 제어할 수 있도록 public에 둡니다.
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Txt_day;

	// 🟢 평소엔 숨겨둘 화면 전환용 텍스트
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Txt_title;

	UFUNCTION(BlueprintImplementableEvent, Category = "Transition")
	void PlayFadeOut();

	UFUNCTION(BlueprintImplementableEvent, Category = "Transition")
	void PlayFadeIn();
};