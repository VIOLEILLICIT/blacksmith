#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_Inventory.generated.h"

class UWrapBox;
class UInventoryComponent;

UCLASS()
class BLACKSMITH_API UW_Inventory : public UUserWidget
{
	GENERATED_BODY()

public:
	// ⭐️ 블루프린트의 랩 박스 이름과 똑같아야 합니다.
	UPROPERTY(meta = (BindWidget))
	UWrapBox* InventoryWrapBox;

	// 바구니에 찍어낼 타일의 '설계도(클래스)' 정보
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UW_ItemSlot> ItemSlotClass;

	// 인벤토리를 다시 그리는 함수
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RefreshInventory(UInventoryComponent* InventoryComp);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory")
    void UpdateDetailView(class UItemDataAsset* Asset, int32 Count);
};