#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	// 인벤토리는 매 프레임 업데이트(Tick)될 필요가 없으므로 꺼서 최적화합니다.
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInventoryComponent::AddItem(UItemDataAsset* ItemToAdd, int32 AmountToAdd)
{
	if (!ItemToAdd || AmountToAdd <= 0) return false;

	// 1. 이미 가방에 똑같은 아이템이 있는지 검사
	for (FInventoryItem& Slot : Inventory)
	{
		if (Slot.ItemAsset == ItemToAdd)
		{
			Slot.Quantity += AmountToAdd; // 겹치기 (수량만 증가)
			return true;
		}
	}

	// 2. 가방에 없는 새로운 아이템이면 새 칸을 만들어서 넣기
	FInventoryItem NewItem;
	NewItem.ItemAsset = ItemToAdd;
	NewItem.Quantity = AmountToAdd;
	Inventory.Add(NewItem);

	return true;
}

bool UInventoryComponent::RemoveItem(UItemDataAsset* ItemToRemove, int32 AmountToRemove)
{
	if (!ItemToRemove || AmountToRemove <= 0) return false;

	for (int32 i = 0; i < Inventory.Num(); ++i)
	{
		if (Inventory[i].ItemAsset == ItemToRemove)
		{
			// 가지고 있는 갯수가 빼려는 갯수보다 많거나 같을 때만 성공
			if (Inventory[i].Quantity >= AmountToRemove)
			{
				Inventory[i].Quantity -= AmountToRemove;
				
				// 만약 갯수가 0이 되면 가방에서 그 칸 자체를 완전히 삭제
				if (Inventory[i].Quantity == 0)
				{
					Inventory.RemoveAt(i);
				}
				return true;
			}
			else
			{
				return false; // 부족하면 실패
			}
		}
	}
	return false; // 아예 안 가지고 있으면 실패
}

int32 UInventoryComponent::GetItemCount(UItemDataAsset* ItemToCheck) const
{
	if (!ItemToCheck) return 0;

	// 기존 Inventory 배열 이름을 그대로 사용하여 개수를 파악합니다.
	for (const FInventoryItem& Slot : Inventory)
	{
		if (Slot.ItemAsset == ItemToCheck)
		{
			return Slot.Quantity;
		}
	}
	return 0;
}

bool UInventoryComponent::CraftItem(UItemDataAsset* TargetWeapon)
{
	if (!TargetWeapon) return false;

	// 1. [검사] 필요한 재료가 가방에 전부 충분히 있는지 확인
	for (const TPair<UItemDataAsset*, int32>& MaterialPair : TargetWeapon->CraftingMaterials)
	{
		UItemDataAsset* RequiredItem = MaterialPair.Key;
		int32 RequiredAmount = MaterialPair.Value;

		if (GetItemCount(RequiredItem) < RequiredAmount)
		{
			return false; // 하나라도 부족하면 제작 실패
		}
	}

	// 2. [차감] 검사를 통과했다면 가방에서 재료를 소모
	for (const TPair<UItemDataAsset*, int32>& MaterialPair : TargetWeapon->CraftingMaterials)
	{
		RemoveItem(MaterialPair.Key, MaterialPair.Value);
	}

	// 3. [지급] 완성된 무기 아이템을 1개 추가
	AddItem(TargetWeapon, 1);

	return true;
}