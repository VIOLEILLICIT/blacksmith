#include "W_Inventory.h"
#include "Components/WrapBox.h"
#include "W_ItemSlot.h"
#include "InventoryComponent.h" // 진짜 가방 컴포넌트

void UW_Inventory::RefreshInventory(UInventoryComponent* InventoryComp, bool bShowWeapons, bool bShowSellWeapon)
{
	CachedInventoryComp = InventoryComp;

	if (!InventoryComp || !ItemSlotClass || !InventoryWrapBox) return;

	// 1. 기존에 그려진 타일들 싹 다 지우기 (초기화)
	InventoryWrapBox->ClearChildren();

	// 2. 가방 내용물 개수만큼 반복문(For 문) 돌리기
	for (const FInventoryItem& InvItem : InventoryComp->Inventory)
	{
		// ⭐️ 안정성을 위해 InvItem.ItemAsset이 비어있지 않은지 검사 조건 추가
		if (InvItem.Quantity > 0 && InvItem.ItemAsset) 
		{
			// ==============================================================
			// 🔍 [필터링 로직] 현재 탭에 맞는 아이템인지 검사합니다.
			// ==============================================================
			bool bMatchTab = false;
			EItemCategory Category = InvItem.ItemAsset->ItemCategory;

			if (bShowWeapons)
			{
				// [진열대 탭] 무기 또는 특수 무기만 통과!
				if (Category == EItemCategory::Weapon || Category == EItemCategory::SpecialWeapon)
				{
					bMatchTab = true;
				}
			}
			else
			{
				// [소모품 탭] 재료만 통과!
				if (Category == EItemCategory::Material)
				{
					bMatchTab = true;
				}
			}

			// 🟢 [핵심 추가] '판매 가능한 무기만 보기'가 켜져 있다면?
			if (bShowSellWeapon)
			{
				// 현재 아이템이 무기가 아니거나(bMatchTab == false), 
				// 무기이긴 한데 판매가 불가능하다면(bIsSellable == false) 목록에서 탈락시킵니다!
				if (!bMatchTab || !InvItem.ItemAsset->bIsSellable)
				{
					bMatchTab = false;
				}
			}

			// ==============================================================
			// 3. 조건이 맞는 아이템일 때만 타일 위젯 생성!
			if (bMatchTab)
			{
				UW_ItemSlot* NewSlot = CreateWidget<UW_ItemSlot>(GetWorld(), ItemSlotClass);
				
				if (NewSlot)
				{
					NewSlot->ParentInventory = this;
					// 4. 데이터 밀어넣기
					NewSlot->UpdateSlot(InvItem.ItemAsset, InvItem.Quantity);
					
					// 5. 바구니에 담기
					InventoryWrapBox->AddChildToWrapBox(NewSlot);
				}
			}
		}
	}
}
void UW_Inventory::SellSelectedWeapon(UItemDataAsset* Asset)
{
	if (!CachedInventoryComp || !Asset) return;

	if (Asset->ItemCategory == EItemCategory::Weapon ||
		Asset->ItemCategory == EItemCategory::SpecialWeapon)
	{
		if (CachedInventoryComp->RemoveItem(Asset, 1))
		{
			RefreshInventory(CachedInventoryComp, true);
		}
	}
}