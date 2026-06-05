#include "EncyclopediaWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"      // 🟢 플레이어 탐색용
#include "EncyclopediaComponent.h"        // 🟢 도감 컴포넌트 인식용

void UEncyclopediaWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 1. 버튼 이벤트 연결
	if (Btn_Prev) Btn_Prev->OnClicked.AddDynamic(this, &UEncyclopediaWidget::OnPrevClicked);
	if (Btn_Next) Btn_Next->OnClicked.AddDynamic(this, &UEncyclopediaWidget::OnNextClicked);
	if (Btn_Close) Btn_Close->OnClicked.AddDynamic(this, &UEncyclopediaWidget::OnCloseClicked);

	// 🟢 2. 위젯이 생성(화면에 표시)되자마자 스스로 데이터를 불러옵니다!
	LoadEncyclopediaData();
}

void UEncyclopediaWidget::LoadEncyclopediaData()
{
	UnlockedList.Empty();

	// 🟢 1. ThirdPersonCharacter(플레이어)를 찾아냅니다.
	if (ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0))
	{
		// 🟢 2. 플레이어 몸에 붙어있는 도감 컴포넌트를 떼어옵니다.
		if (UEncyclopediaComponent* EncyComp = PlayerCharacter->FindComponentByClass<UEncyclopediaComponent>())
		{
			// 🟢 3. TSet으로 되어있는 해금 목록을 UI에서 쓰기 편하게 TArray 배열로 변환해서 가져옵니다!
			UnlockedList = EncyComp->UnlockedItems.Array();

			/* (선택 사항) 만약 '무기' 탭처럼 특정 카테고리만 가져오고 싶다면 위 줄 대신 아래 코드를 쓰시면 됩니다:
			 * UnlockedList = EncyComp->GetUnlockedItemsByCategory(EItemCategory::Weapon);
			 */
		}
	}

	// 4. 데이터를 다 가져왔으니 0번 페이지부터 화면을 새로고침합니다.
	CurrentIndex = 0;
	UpdateUI();
}

// =================================================================
// 이하 화면 갱신 및 버튼 조작 로직 (변경 없음!)
// =================================================================

void UEncyclopediaWidget::UpdateUI()
{
	if (UnlockedList.Num() == 0)
	{
		if (Txt_ItemName) Txt_ItemName->SetText(FText::FromString(TEXT("도감에 등록된 항목이 없습니다.")));
		if (Txt_AppearanceDesc) Txt_AppearanceDesc->SetText(FText::GetEmpty());
		if (Img_ItemIcon) Img_ItemIcon->SetVisibility(ESlateVisibility::Hidden);
		
		UImage* MatIcons[3] = { Img_MatIcon1, Img_MatIcon2, Img_MatIcon3 };
		UTextBlock* MatTexts[3] = { Txt_MatName1, Txt_MatName2, Txt_MatName3 };
		for (int i = 0; i < 3; i++)
		{
			if (MatIcons[i]) MatIcons[i]->SetVisibility(ESlateVisibility::Hidden);
			if (MatTexts[i]) MatTexts[i]->SetVisibility(ESlateVisibility::Hidden);
		}
		return;
	}

	UItemDataAsset* CurrentItem = UnlockedList[CurrentIndex];
	if (!CurrentItem) return;

	if (Txt_ItemName) Txt_ItemName->SetText(FText::FromString(CurrentItem->ItemName));
	if (Txt_AppearanceDesc) Txt_AppearanceDesc->SetText(FText::FromString(CurrentItem->AppearanceDescription));
	
	if (Img_ItemIcon && CurrentItem->ItemIcon)
	{
		Img_ItemIcon->SetBrushFromTexture(CurrentItem->ItemIcon);
		Img_ItemIcon->SetVisibility(ESlateVisibility::Visible);
	}

	UImage* MatIcons[3] = { Img_MatIcon1, Img_MatIcon2, Img_MatIcon3 };
	UTextBlock* MatTexts[3] = { Txt_MatName1, Txt_MatName2, Txt_MatName3 };

	for (int i = 0; i < 3; i++)
	{
		if (MatIcons[i]) MatIcons[i]->SetVisibility(ESlateVisibility::Hidden);
		if (MatTexts[i]) MatTexts[i]->SetVisibility(ESlateVisibility::Hidden);
	}

	int32 MatIndex = 0;
	for (const TPair<UItemDataAsset*, int32>& MatPair : CurrentItem->CraftingMaterials)
	{
		UItemDataAsset* MatItem = MatPair.Key;
		if (MatItem && MatIndex < 3)
		{
			if (MatIcons[MatIndex] && MatItem->ItemIcon)
			{
				MatIcons[MatIndex]->SetBrushFromTexture(MatItem->ItemIcon);
				MatIcons[MatIndex]->SetVisibility(ESlateVisibility::Visible); 
			}
			
			if (MatTexts[MatIndex])
			{
				MatTexts[MatIndex]->SetText(FText::FromString(MatItem->ItemName));
				MatTexts[MatIndex]->SetVisibility(ESlateVisibility::Visible); 
			}
			MatIndex++;
		}
	}
}

void UEncyclopediaWidget::OnPrevClicked()
{
	if (UnlockedList.Num() == 0) return;
	
	CurrentIndex--;
	if (CurrentIndex < 0) CurrentIndex = UnlockedList.Num() - 1; 
	
	UpdateUI();
}

void UEncyclopediaWidget::OnNextClicked()
{
	if (UnlockedList.Num() == 0) return;

	CurrentIndex++;
	if (CurrentIndex >= UnlockedList.Num()) CurrentIndex = 0; 
	
	UpdateUI();
}

void UEncyclopediaWidget::OnCloseClicked()
{
	RemoveFromParent();

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		FInputModeGameOnly InputMode;
		PC->SetInputMode(InputMode);
		PC->SetShowMouseCursor(false);
	}
}