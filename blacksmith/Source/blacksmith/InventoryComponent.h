#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemDataAsset.h" // 우리가 만든 아이템 설계도 불러오기
#include "InventoryComponent.generated.h"

// 인벤토리의 한 '칸(Slot)'을 담당할 구조체입니다.
USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UItemDataAsset* ItemAsset; // 어떤 아이템인가?

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Quantity; // 몇 개인가?

	FInventoryItem()
	{
		ItemAsset = nullptr;
		Quantity = 0;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLACKSMITH_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	// 실제 아이템들이 담기는 가방 배열
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventoryItem> Inventory;

	// 아이템 획득 (블루프린트에서 쉽게 쓰도록 UFUNCTION 처리)
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(UItemDataAsset* ItemToAdd, int32 AmountToAdd);

	// 아이템 사용/판매/제거
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(UItemDataAsset* ItemToRemove, int32 AmountToRemove);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory")
	int32 GetItemCount(UItemDataAsset* ItemToCheck) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool CraftItem(UItemDataAsset* TargetWeapon);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Cheat")
	void AddAllItemsCheat(int32 AmountPerItem = 10);
};