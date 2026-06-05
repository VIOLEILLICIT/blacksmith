#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemDataAsset.h" 
#include "EncyclopediaWidget.generated.h"

class UTextBlock;
class UImage;
class UButton;

UCLASS()
class BLACKSMITH_API UEncyclopediaWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	// 🟢 외부에서 배열을 받을 필요 없이, 스스로 플레이어를 찾아 도감 데이터를 가져오는 함수
	UFUNCTION(BlueprintCallable, Category = "Encyclopedia")
	void LoadEncyclopediaData();

protected:
	/* =================================================================
	 * 🎨 위젯 바인딩 (에디터에서 만들 위젯 이름들)
	 * ================================================================= */
	
	// [완성품 묘사]
	UPROPERTY(meta = (BindWidget)) class UImage* Img_ItemIcon;
	UPROPERTY(meta = (BindWidget)) class UTextBlock* Txt_ItemName;
	UPROPERTY(meta = (BindWidget)) class UTextBlock* Txt_AppearanceDesc;

	// [재료 1]
	UPROPERTY(meta = (BindWidget)) class UImage* Img_MatIcon1;
	UPROPERTY(meta = (BindWidget)) class UTextBlock* Txt_MatName1;

	// [재료 2]
	UPROPERTY(meta = (BindWidget)) class UImage* Img_MatIcon2;
	UPROPERTY(meta = (BindWidget)) class UTextBlock* Txt_MatName2;

	// [재료 3]
	UPROPERTY(meta = (BindWidget)) class UImage* Img_MatIcon3;
	UPROPERTY(meta = (BindWidget)) class UTextBlock* Txt_MatName3;

	// [조작 버튼]
	UPROPERTY(meta = (BindWidget)) class UButton* Btn_Prev;
	UPROPERTY(meta = (BindWidget)) class UButton* Btn_Next;
	UPROPERTY(meta = (BindWidget)) class UButton* Btn_Close;

	/* =================================================================
	 * 내부 데이터 및 갱신 로직
	 * ================================================================= */
	UPROPERTY() 
	TArray<UItemDataAsset*> UnlockedList;
	
	int32 CurrentIndex = 0;

	void UpdateUI();

	UFUNCTION() void OnPrevClicked();
	UFUNCTION() void OnNextClicked();
	UFUNCTION() void OnCloseClicked();
};