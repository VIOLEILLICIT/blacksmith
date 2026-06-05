#include "TimeHUDWidget.h"
#include "Components/TextBlock.h"
#include "BlacksmithGameMode.h" // 시간 정보가 있는 게임모드 포함
#include "Kismet/GameplayStatics.h"

void UTimeHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// Txt_day 텍스트 블록이 없으면 에러가 나지 않게 멈춤
	if (!Txt_day) return;

	// 현재 작동 중인 게임모드를 찾아옵니다.
	if (ABlacksmithGameMode* GM = Cast<ABlacksmithGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		int32 CurrentDay = GM->CurrentDay;
		float CurrentSeconds = GM->CurrentTimeOfDay;

		// 🟢 시간대에 따른 아침/낮/밤 텍스트 판별 (NPC 로직과 동일하게 맞춤)
		FString PhaseString = TEXT("아침");
		if (CurrentSeconds > 0.0f && CurrentSeconds < 600.0f)
		{
			PhaseString = TEXT("낮");
		}
		else if (CurrentSeconds >= 600.0f)
		{
			PhaseString = TEXT("밤");
		}

		// 🟢 문자열 합성 (예: "1일차 - 낮 - 120초")
		FString FinalText = FString::Printf(TEXT("%d일차 - %s - %d초"), CurrentDay, *PhaseString, FMath::FloorToInt(CurrentSeconds));

		// 텍스트 블록에 적용!
		Txt_day->SetText(FText::FromString(FinalText));
	}
}