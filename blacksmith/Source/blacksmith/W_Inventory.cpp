#include "W_Inventory.h"
#include "Components/WrapBox.h"
#include "W_ItemSlot.h"
#include "InventoryComponent.h" // 진짜 가방 컴포넌트

void UW_Inventory::RefreshInventory(UInventoryComponent* InventoryComp)
{
	// 에러 방지용 체크
	if (!InventoryComp || !ItemSlotClass || !InventoryWrapBox) return;

	// 1. 기존에 그려진 타일들 싹 다 지우기 (초기화)
	InventoryWrapBox->ClearChildren();

	// 2. 가방 내용물 개수만큼 반복문(For 문) 돌리기
	// ★ 에러 원인 수정: 이름 충돌을 피하기 위해 'Slot' 대신 'InvItem'으로 이름 변경!
	for (const FInventoryItem& InvItem : InventoryComp->Inventory)
	{
		if (InvItem.Quantity > 0)
		{
			// 3. 타일 위젯 생성
			UW_ItemSlot* NewSlot = CreateWidget<UW_ItemSlot>(GetWorld(), ItemSlotClass);
			
			if (NewSlot)
			{
				// 4. 데이터 밀어넣기
				NewSlot->UpdateSlot(InvItem.ItemAsset, InvItem.Quantity);
				
				// 5. 바구니에 담기
				InventoryWrapBox->AddChildToWrapBox(NewSlot);
			}
		}
	}
}