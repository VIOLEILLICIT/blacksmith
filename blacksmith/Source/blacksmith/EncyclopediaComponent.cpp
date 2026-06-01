#include "EncyclopediaComponent.h"

UEncyclopediaComponent::UEncyclopediaComponent()
{
	// 도감은 매 프레임 업데이트(Tick)될 필요가 없으므로 꺼줍니다. (성능 최적화)
	PrimaryComponentTick.bCanEverTick = false; 
}

bool UEncyclopediaComponent::UnlockItem(UItemDataAsset* NewItem)
{
	// 비어있는 데이터거나, 이미 도감에 등록된 아이템이면 무시 (false 반환)
	if (!NewItem || UnlockedItems.Contains(NewItem))
	{
		return false;
	}

	// 도감에 새로 추가!
	UnlockedItems.Add(NewItem);

	// "새로운 무기가 도감에 등록되었습니다!" 하고 UI 쪽에 신호(이벤트)를 보냄
	OnItemUnlocked.Broadcast(NewItem);

	return true;
}

bool UEncyclopediaComponent::IsItemUnlocked(UItemDataAsset* Item) const
{
	return UnlockedItems.Contains(Item);
}

TArray<UItemDataAsset*> UEncyclopediaComponent::GetUnlockedItemsByCategory(EItemCategory Category) const
{
	TArray<UItemDataAsset*> FilteredItems;

	// 해금된 전체 아이템 중, 요청한 카테고리와 일치하는 것만 추려냅니다.
	for (UItemDataAsset* Item : UnlockedItems)
	{
		if (Item && Item->ItemCategory == Category)
		{
			FilteredItems.Add(Item);
		}
	}

	return FilteredItems;
}

float UEncyclopediaComponent::GetCompletionPercentage(const TArray<UItemDataAsset*>& TotalWeaponDB) const
{
	if (TotalWeaponDB.Num() == 0) return 0.0f;

	int32 UnlockedCount = 0;
	for (UItemDataAsset* DBItem : TotalWeaponDB)
	{
		if (UnlockedItems.Contains(DBItem))
		{
			UnlockedCount++;
		}
	}

	// 퍼센티지 반환 (예: 10개 중 3개 해금 -> 30.0f)
	return ((float)UnlockedCount / (float)TotalWeaponDB.Num()) * 100.0f;
}