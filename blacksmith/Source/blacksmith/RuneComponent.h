#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemDataAsset.h" 
#include "RuneComponent.generated.h"

// 🟢 [추가됨] UHT가 헷갈리지 않도록 미리 "클래스"라고 선언해 줍니다!
class UItemDataAsset;

// 🟢 룬 해금 시 UI 등에 신호를 쏘는 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRuneUnlocked, UItemDataAsset*, UnlockedRune);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLACKSMITH_API URuneComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	URuneComponent();

	/* =================================================================
	 * 🌟 룬 해금(도감) 시스템
	 * ================================================================= */
	// 해금된 룬 목록 (중복 방지를 위해 Set 사용)
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Rune")
	TSet<UItemDataAsset*> UnlockedRunes;

	// 룬 해금 시 발생하는 이벤트 (블루프린트 UI 연동용)
	UPROPERTY(BlueprintAssignable, Category = "Rune|Events")
	FOnRuneUnlocked OnRuneUnlocked;

	// 1. 룬 해금하기 (블루프린트에서 데이터 에셋을 꽂아주면 됨!)
	UFUNCTION(BlueprintCallable, Category = "Rune")
	bool UnlockRune(UItemDataAsset* NewRune);

	// 2. 이 룬이 이미 해금되었는지 검사
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Rune")
	bool IsRuneUnlocked(UItemDataAsset* Rune) const;
};