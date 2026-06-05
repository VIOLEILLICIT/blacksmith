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

/* =================================================================
 * 📖 도감 UI 연동용 헬퍼 함수
 * ================================================================= */
void UEncyclopediaComponent::FormatEncyclopediaUI(
	UItemDataAsset* InItem,
	UTexture2D*& OutItemIcon, FString& OutItemName, FString& OutAppearanceDesc,
	UTexture2D*& OutMatIcon1, FString& OutMatName1,
	UTexture2D*& OutMatIcon2, FString& OutMatName2,
	UTexture2D*& OutMatIcon3, FString& OutMatName3)
{
	// 1. 기본값 초기화 (재료가 없을 경우를 대비해 싹 비워둡니다)
	OutItemIcon = nullptr; OutMatIcon1 = nullptr; OutMatIcon2 = nullptr; OutMatIcon3 = nullptr;
	OutItemName = TEXT(""); OutAppearanceDesc = TEXT("");
	OutMatName1 = TEXT(""); OutMatName2 = TEXT(""); OutMatName3 = TEXT("");

	if (!InItem) return;

	// 2. 완성품 정보 세팅
	OutItemIcon = InItem->ItemIcon;
	OutItemName = InItem->ItemName;
	OutAppearanceDesc = InItem->AppearanceDescription;

	// 3. 재료 정보 추출 (최대 3개까지만 뽑아냅니다)
	int32 MatIndex = 0;
	for (const TPair<UItemDataAsset*, int32>& MatPair : InItem->CraftingMaterials)
	{
		UItemDataAsset* MatItem = MatPair.Key;
		if (!MatItem) continue;

		if (MatIndex == 0) 
		{
			OutMatIcon1 = MatItem->ItemIcon;
			OutMatName1 = MatItem->ItemName;
		} 
		else if (MatIndex == 1) 
		{
			OutMatIcon2 = MatItem->ItemIcon;
			OutMatName2 = MatItem->ItemName;
		} 
		else if (MatIndex == 2) 
		{
			OutMatIcon3 = MatItem->ItemIcon;
			OutMatName3 = MatItem->ItemName;
		}
		
		MatIndex++;
		if (MatIndex >= 3) break; // 3개를 다 채웠으면 멈춤!
	}
}