#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_ItemSlot.generated.h"

// 전방 선언 (헤더 파일 가벼워짐)
class UImage;
class UTextBlock;
class UItemDataAsset;

UCLASS()
class BLACKSMITH_API UW_ItemSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	// ⭐️ 블루프린트의 UI 컴포넌트 이름과 '반드시' 똑같아야 자동 연결됩니다!
	UPROPERTY(meta = (BindWidget))
	UImage* ItemIcon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* QuantityText;

	// 외부에서 데이터와 개수를 던져주면 업데이트하는 함수
	void UpdateSlot(UItemDataAsset* Asset, int32 Count);
};