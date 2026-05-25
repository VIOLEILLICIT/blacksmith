#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDataAsset.generated.h"

// 도감 탭 분류를 위한 아이템 카테고리
UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	Material UMETA(DisplayName = "재료"),
	Weapon UMETA(DisplayName = "무기"),
	SpecialWeapon UMETA(DisplayName = "특수 무기")
};

UCLASS(BlueprintType)
class BLACKSMITH_API UItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	/* =================================================================
	 * 1. 기본 정보 (Basic Info)
	 * ================================================================= */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "1. Basic Info", meta = (DisplayName = "아이템 고유 ID (5자리)"))
	int32 ItemID = 0; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "1. Basic Info", meta = (DisplayName = "아이템 이름"))
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "1. Basic Info", meta = (DisplayName = "아이템 분류"))
	EItemCategory ItemCategory = EItemCategory::Material;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "1. Basic Info", meta = (DisplayName = "아이템 아이콘"))
	class UTexture2D* ItemIcon;

	/* =================================================================
	 * 2. 텍스트 & 도감 시스템 (Descriptions & Encyclopedia)
	 * ================================================================= */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "2. Encyclopedia", meta=(DisplayName = "인벤토리 짧은 설명", MultiLine=true))
	FText InventoryDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "2. Encyclopedia", meta=(DisplayName = "도감 상세 스토리 설명", MultiLine=true))
	FText EncyclopediaDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "2. Encyclopedia", meta = (DisplayName = "무기 외형 묘사"))
	FString AppearanceDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "2. Encyclopedia", meta = (DisplayName = "특수 무기 해금 조건"))
	FString UnlockCondition;

	/* =================================================================
	 * 3. 인벤토리 & 크래프팅 (Inventory & Crafting)
	 * ================================================================= */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "3. Inventory", meta = (DisplayName = "최대 겹치기 개수 (스택)"))
	int32 MaxStackSize = 99; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "3. Inventory", meta = (DisplayName = "상단 재화 UI 표시 여부"))
	bool bIsCurrencyDisplay = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "4. Crafting", meta = (DisplayName = "필요한 제작 재료 목록"))
	TMap<UItemDataAsset*, int32> CraftingMaterials;

	/* =================================================================
	 * 4. 경제 시스템 (Economy System) - ★ 상점 거래 기능 추가
	 * ================================================================= */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "5. Economy", meta = (DisplayName = "구매 가능 여부"))
	bool bIsBuyable = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "5. Economy", meta = (DisplayName = "구매 가격", EditCondition = "bIsBuyable"))
	int32 BuyPrice = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "5. Economy", meta = (DisplayName = "판매 가능 여부"))
	bool bIsSellable = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "5. Economy", meta = (DisplayName = "판매 가격", EditCondition = "bIsSellable"))
	int32 SellPrice = 0;


	/* =================================================================
	 * [자동 분해 함수] 5자리 ID를 부위별로 쪼개주는 함수들
	 * ================================================================= */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetWeaponType() const { return ItemID / 10000; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetItemTier() const { return (ItemID / 1000) % 10; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetItemElement() const { return (ItemID / 100) % 10; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetItemMaterial() const { return ItemID % 100; }
};