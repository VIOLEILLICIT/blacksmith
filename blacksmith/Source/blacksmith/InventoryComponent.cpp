#include "InventoryComponent.h"
#include "Engine/ObjectLibrary.h"

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

void UInventoryComponent::AddAllItemsCheat(int32 AmountPerItem)
{
	if (AmountPerItem <= 0) return;

	// 1. ItemDataAsset 클래스를 가진 에셋들을 찾아낼 오브젝트 라이브러리 생성
	UObjectLibrary* ObjectLibrary = UObjectLibrary::CreateLibrary(UItemDataAsset::StaticClass(), false, GIsEditor);
	
	// 2. 프로젝트의 Content(/Game) 폴더 전체를 뒤져서 해당 에셋 목록을 로드
	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game"));
	
	// 3. 발견된 에셋 데이터들을 배열로 가져오기
	TArray<FAssetData> AssetDataList;
	ObjectLibrary->GetAssetDataList(AssetDataList);
	
	// 4. 반복문을 돌며 가방에 하나씩 착착 추가하기
	for (const FAssetData& AssetData : AssetDataList)
	{
		// 메모리에 로드되지 않은 에셋이 있다면 안전하게 로드하여 가져옵니다.
		UItemDataAsset* FoundItemAsset = Cast<UItemDataAsset>(AssetData.GetAsset());
		
		if (FoundItemAsset)
		{
			// 기존에 만들어두신 겹치기/신규 생성 로직이 담긴 AddItem을 그대로 활용합니다!
			AddItem(FoundItemAsset, AmountPerItem);
		}
	}
}

bool UInventoryComponent::HasAnyWeapon() const
{
	for (const FInventoryItem& Item : Inventory)
	{
		if (Item.ItemAsset && Item.Quantity > 0)
		{
			if (Item.ItemAsset->ItemCategory == EItemCategory::Weapon ||
				Item.ItemAsset->ItemCategory == EItemCategory::SpecialWeapon)
			{
				return true;
			}
		}
	}

	return false;
}
