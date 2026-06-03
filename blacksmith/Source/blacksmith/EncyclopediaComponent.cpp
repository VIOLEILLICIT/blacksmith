#include "EncyclopediaComponent.h"
#include "Engine/Engine.h"

UEncyclopediaComponent::UEncyclopediaComponent()
{
	// 도감은 매 프레임 업데이트(Tick)될 필요가 없으므로 꺼줍니다. (성능 최적화)
	PrimaryComponentTick.bCanEverTick = false; 
}

bool UEncyclopediaComponent::UnlockItem(UItemDataAsset* NewItem)
{
	if (!NewItem || UnlockedItems.Contains(NewItem))
	{
		return false;
	}

	UnlockedItems.Add(NewItem);
	OnItemUnlocked.Broadcast(NewItem);

	// =================================================================
	// 🟢 [로그 출력] 무기 해금 성공 시 화면과 로그 창에 띄우기
	// =================================================================
	
	// 출력할 메시지 만들기 (예: "✨ 도감 해금 완료: 목철검")
	FString LogMsg = FString::Printf(TEXT("✨ 도감 해금 완료: %s"), *NewItem->ItemName);
	
	// 1. 플레이 화면(좌측 상단)에 청록색(Cyan)으로 5초 동안 띄우기
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, LogMsg);
	}

	// 2. 언리얼 에디터의 '출력 로그(Output Log)' 창에 기록 남기기
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogMsg);
	// =================================================================

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