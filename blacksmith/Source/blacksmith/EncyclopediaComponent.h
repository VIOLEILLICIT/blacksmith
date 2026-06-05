#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemDataAsset.h" // 데이터 에셋 헤더 포함
#include "EncyclopediaComponent.generated.h"

// 새로운 아이템이 해금되었을 때 UI에 알려줄 이벤트(델리게이트)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemUnlocked, UItemDataAsset*, UnlockedItem);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLACKSMITH_API UEncyclopediaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEncyclopediaComponent();

	/* =================================================================
	 * 도감 데이터
	 * ================================================================= */
	// 해금된 아이템 목록 (중복 방지를 위해 TArray 대신 TSet 사용)
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Encyclopedia")
	TSet<UItemDataAsset*> UnlockedItems;

	// 아이템 해금 시 호출되는 이벤트 (UI 업데이트용)
	UPROPERTY(BlueprintAssignable, Category = "Encyclopedia|Events")
	FOnItemUnlocked OnItemUnlocked;

	/* =================================================================
	 * 도감 기능 함수들
	 * ================================================================= */
	// 1. 아이템 해금 시도 (제작 성공 시 호출)
	UFUNCTION(BlueprintCallable, Category = "Encyclopedia")
	bool UnlockItem(UItemDataAsset* NewItem);

	// 2. 해당 아이템이 도감에 있는지(해금되었는지) 확인
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Encyclopedia")
	bool IsItemUnlocked(UItemDataAsset* Item) const;

	// 3. 특정 카테고리(예: 무기, 특수 무기)의 해금 목록만 골라서 반환 (UI 탭 전환용)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Encyclopedia")
	TArray<UItemDataAsset*> GetUnlockedItemsByCategory(EItemCategory Category) const;

	// 4. 전체 도감 달성도(%) 계산 
	// (GameMode에 만들어두신 WeaponDatabase 배열을 넘겨주면 %를 계산해 줍니다)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Encyclopedia")
	float GetCompletionPercentage(const TArray<UItemDataAsset*>& TotalWeaponDB) const;
	// 🟢 [추가] 도감 UI에 아이템 정보와 최대 3개의 재료 정보를 예쁘게 쪼개서 넘겨주는 헬퍼 함수
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Encyclopedia|UI")
	void FormatEncyclopediaUI(
		UItemDataAsset* InItem,
		class UTexture2D*& OutItemIcon, FString& OutItemName, FString& OutAppearanceDesc,
		class UTexture2D*& OutMatIcon1, FString& OutMatName1,
		class UTexture2D*& OutMatIcon2, FString& OutMatName2,
		class UTexture2D*& OutMatIcon3, FString& OutMatName3
	);
};