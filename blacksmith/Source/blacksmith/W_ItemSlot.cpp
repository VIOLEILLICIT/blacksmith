#include "W_ItemSlot.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ItemDataAsset.h" // 우리가 만든 아이템 설계도

void UW_ItemSlot::UpdateSlot(UItemDataAsset* Asset, int32 Count)
{
	if (Asset)
	{
		// 1. 그림 바꾸기
		if (Asset->ItemIcon)
		{
			ItemIcon->SetBrushFromTexture(Asset->ItemIcon);
		}
		
		// 2. 글자 바꾸기 (숫자를 FText로 변환)
		QuantityText->SetText(FText::AsNumber(Count));
	}
}