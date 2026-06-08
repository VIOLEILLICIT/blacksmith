#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_Inventory.generated.h"

class UWrapBox;
class UTextBlock;
class UInventoryComponent;

UCLASS()
class BLACKSMITH_API UW_Inventory : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	UInventoryComponent* CachedInventoryComp;

	UFUNCTION(BlueprintCallable, Category = "Trade")
	void SellSelectedWeapon(UItemDataAsset* Asset);

	// ⭐️ 블루프린트의 랩 박스 이름과 똑같아야 합니다.
	UPROPERTY(meta = (BindWidget))
	UWrapBox* InventoryWrapBox;

	// 의뢰 완료 / 상태 알림 텍스트 (WBP_SellWeapon의 Txt_title과 자동 연결)
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Txt_title;

	// 바구니에 찍어낼 타일의 '설계도(클래스)' 정보
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UW_ItemSlot> ItemSlotClass;

	// 인벤토리를 다시 그리는 함수
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RefreshInventory(UInventoryComponent* InventoryComp, bool bShowWeapons = false, bool bShowSellWeapon = false);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory")
	void UpdateDetailView(class UItemDataAsset* Asset, int32 Count);

	// 블루프린트에서 WBP_SellWeaponRow 목록을 다시 그리도록 신호를 보냅니다.
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void OnSellListRefresh();

	// 의뢰 완료 메시지를 Txt_title에 표시하고 2초 후 숨깁니다.
	void ShowQuestComplete(const FText& Message);

private:
	FTimerHandle TitleHideTimerHandle;

	UFUNCTION()
	void HideTitleText();
};