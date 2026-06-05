#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "InteractableInterface.h"
#include "BaseInteractable.generated.h"

class UTalkWidget;
class UTimeHUDWidget; // 🟢 [추가됨] 글자를 띄울 위젯을 알기 위한 전방 선언

// 인스펙터에서 선택할 오브젝트 종류
UENUM(BlueprintType)
enum class EInteractableType : uint8
{
	RestChair   UMETA(DisplayName = "휴식 의자 (특정 시간으로 워프)"),
	Bed         UMETA(DisplayName = "아빠 침대 (다음날로)"),
	Door        UMETA(DisplayName = "외출 문 (집 -> 밖)"),
	ReturnDoor  UMETA(DisplayName = "귀가 문 (밖 -> 집)"),
	DaughterBed UMETA(DisplayName = "딸 침대 (딸 재우기)")
};

UCLASS()
class BLACKSMITH_API ABaseInteractable : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	ABaseInteractable();

	/* =================================================================
	 * 인스펙터 설정 변수들
	 * ================================================================= */
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact Settings", meta=(DisplayName="오브젝트 종류"))
	EInteractableType ObjectType = EInteractableType::RestChair;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interact Settings", meta=(DisplayName="거절 시 띄울 위젯"))
	TSubclassOf<UTalkWidget> TalkWidgetClass;

	// 🟢 [복구됨] 글자를 띄우기 위해 기존 HUD 위젯을 연결할 칸
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interact Settings", meta=(DisplayName="날짜표시 HUD 위젯 클래스"))
	TSubclassOf<UTimeHUDWidget> TimeHUDWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact Settings|Logic", meta=(DisplayName="이동할 레벨 이름", EditCondition="ObjectType == EInteractableType::Door || ObjectType == EInteractableType::ReturnDoor", EditConditionHides))
	FName TargetLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact Settings|Logic", meta=(DisplayName="워프할 목표 시간(초)", EditCondition="ObjectType == EInteractableType::RestChair", EditConditionHides))
	float WarpTargetTime = 450.0f;

	/* =================================================================
	 * C++ 내부 관리 변수
	 * ================================================================= */
	UPROPERTY()
	UTalkWidget* CurrentTalkWidget;

	// 🟢 [복구됨] 화면에 떠 있는 HUD를 기억해둘 변수
	UPROPERTY()
	UTimeHUDWidget* CachedHUDWidget;

	FTimerHandle FadeTimerHandle;

	/* =================================================================
	 * 함수 및 이벤트
	 * ================================================================= */
	
	virtual void Interact_Implementation(AActor* Interactor) override;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void AttemptInteraction(class APlayerController* PC);

	UFUNCTION()
	void HandleTalkWidgetClosed();

	UFUNCTION()
	void ExecuteTimeSkip();

	UFUNCTION()
	void FinishTransition();

	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionAllowed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnSetupTalkWidget(UUserWidget* SpawnedWidget, const FText& DenyMessage);
};