#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDataAsset.generated.h"

UCLASS()
class BLACKSMITH_API UItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// 1. 핵심 기획: 4자리 숫자 ID (예: 1111 -> 1(검) 1(1단계) 1(불) 1(철))
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	int32 ItemID = 0; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	FString ItemName;

	// 인벤토리용 아이템 설명 추가
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	FText ItemDescription; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	class UTexture2D* ItemIcon;

	// 인벤토리 시스템용: 한 칸에 겹칠 수 있는 최대 개수 (무기=1, 재료=99 등)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data|Inventory")
	int32 MaxStackSize = 99;

	// 기존 기획 유지: 획득 시 화면에 재화처럼 띄울지 여부
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data|UI")
	bool bIsCurrencyDisplay = false;


	/* =================================================================
	 * [자동 분해 함수] 블루프린트에서 쉽게 자릿수를 분리해서 쓸 수 있게 해줍니다.
	 * ================================================================= */

	// 1000의 자리 추출 (무기 종류: 1=검, 2=창 / 0이면 재료)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetWeaponType() const { return ItemID / 1000; }

	// 100의 자리 추출 (무기 단계: 1=1단계, 2=2단계)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetItemTier() const { return (ItemID / 100) % 10; }

	// 10의 자리 추출 (속성: 1=불, 2=물, 3=풀)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetItemElement() const { return (ItemID / 10) % 10; }

	// 1의 자리 추출 (재질: 1=철, 2=합금)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Info")
	int32 GetItemMaterial() const { return ItemID % 10; }
};