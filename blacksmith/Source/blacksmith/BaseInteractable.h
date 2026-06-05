#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "InteractableInterface.h"
#include "BaseInteractable.generated.h"

// 🟢 인스펙터에서 선택할 오브젝트 종류
UENUM(BlueprintType)
enum class EInteractableType : uint8
{
	RestChair   UMETA(DisplayName = "휴식 의자 (특정 시간으로 워프)"),
	Bed         UMETA(DisplayName = "아빠 침대 (다음날로)"),
	Door        UMETA(DisplayName = "외출 문 (레벨 이동)"),
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
	TSubclassOf<UUserWidget> TalkWidgetClass;

	// 🚪 문 전용: 이동할 레벨 이름 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact Settings|Logic", meta=(DisplayName="이동할 레벨 이름", EditCondition="ObjectType == EInteractableType::Door", EditConditionHides))
	FName TargetLevelName;

	// 🪑 의자 전용: 워프할 목표 시간 (기본값 450초 = 7분 30초)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact Settings|Logic", meta=(DisplayName="워프할 목표 시간(초)", EditCondition="ObjectType == EInteractableType::RestChair", EditConditionHides))
	float WarpTargetTime = 450.0f;

	/* =================================================================
	 * C++ 내부 관리 변수
	 * ================================================================= */
	UPROPERTY()
	UUserWidget* CurrentTalkWidget;

	// 🟢 [추가] 0.5초 뒤 창을 닫기 위한 타이머
	FTimerHandle CloseTalkWidgetTimerHandle;

	/* =================================================================
	 * 함수 및 이벤트
	 * ================================================================= */
	
	// 인터페이스 오버라이드
	virtual void Interact_Implementation(AActor* Interactor) override;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void AttemptInteraction(class APlayerController* PC);

	// 🟢 [추가] 시간이 지나면 자동으로 위젯을 닫고 조작을 돌려주는 함수
	UFUNCTION()
	void CloseTalkWidget();

	// 성공 시 블루프린트 신호 발사
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionAllowed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnSetupTalkWidget(UUserWidget* SpawnedWidget, const FText& DenyMessage);
};