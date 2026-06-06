#include "RuneComponent.h"
#include "Engine/Engine.h"

URuneComponent::URuneComponent()
{
	// 틱(매 프레임 연산)을 꺼서 최적화
	PrimaryComponentTick.bCanEverTick = false;
}

bool URuneComponent::UnlockRune(UItemDataAsset* NewRune)
{
	// 비어있거나 이미 해금된 룬이면 무시합니다.
	if (!NewRune || UnlockedRunes.Contains(NewRune))
	{
		return false;
	}

	// 룬 목록에 추가하고, 이벤트 신호를 발사합니다!
	UnlockedRunes.Add(NewRune);
	OnRuneUnlocked.Broadcast(NewRune);

	// 🟢 [디버그] 해금 성공 시 화면 좌측 상단에 핑크색으로 띄워줍니다.
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("✨ 룬 해금 완료: %s"), *NewRune->ItemName));
	}

	return true;
}

bool URuneComponent::IsRuneUnlocked(UItemDataAsset* Rune) const
{
	return UnlockedRunes.Contains(Rune);
}