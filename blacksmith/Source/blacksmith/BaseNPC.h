#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractableInterface.h"
#include "NPCComponent.h" 
#include "BaseNPC.generated.h"

// C++ 전용 UI 제어를 위한 전방 선언
class UDialogueWidget;

UCLASS()
class BLACKSMITH_API ABaseNPC : public ACharacter, public IInteractableInterface
{
	GENERATED_BODY()

public:
	ABaseNPC();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:	
	// 상호작용 인터페이스 구현
	virtual void Interact_Implementation(AActor* Interactor) override;

	// GameInstance가 이 NPC를 알아볼 수 있는 고유 이름표
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data", meta=(DisplayName="NPC 고유 ID (저장용)"))
	FName NPC_ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UNPCComponent* NPCComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UWidgetComponent* SpeechBubbleWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data")
	class UTexture2D* Portrait;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Data|Patrol", meta=(MakeEditWidget=true))
	TArray<FVector> PatrolPoints;

	// 게임 시작 시 계산된 마커들의 절대 좌표(맵 전체 기준 위치)를 기억할 배열
	UPROPERTY()
	TArray<FVector> WorldPatrolPoints;

	// 패트롤 관련 타이머 및 상태 변수
	FTimerHandle PatrolTimerHandle;
	int32 CurrentPatrolIndex = 0;

protected:
	/* =================================================================
	 * 💬 C++ 전용 UI 및 대화 자동화 변수 (블루프린트 대체용)
	 * ================================================================= */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "NPC|Dialogue", meta=(DisplayName="대화창 위젯 클래스"))
	TSubclassOf<UDialogueWidget> DialogueWidgetClass;

	UPROPERTY()
	UDialogueWidget* SpawnedDialogueWidget;

	// C++ 전용 대화 시작 및 UI 세팅 함수
	void StartDialogueUI(const FDialogueSequence& SequenceToPlay);

	// 대화가 끝났을 때 자동으로 불릴 C++ 콜백 함수
	UFUNCTION()
	void HandleDialogueFinished();

	// 자식(딸)이 상속받아서 '대화 끝난 후의 행동'을 정의할 수 있는 가상 함수
	virtual void OnDialogueEndAction();

	/* =================================================================
	 * 스케줄 관리 및 상태 변수
	 * ================================================================= */
	FTimerHandle ScheduleCheckTimer;
	FTimerHandle SpeechBubbleTimer;
	
	int32 CurrentSpeechIndex = 0;
	FNPCTimeSchedule CurrentActiveSchedule;

	// 스케줄 교체를 감지하기 위한 추적 변수
	int32 ActiveScheduleDateKey = -999;
	int32 ActiveTimeScheduleIndex = -1;

	UFUNCTION() void CheckScheduleAndVisibility();
	UFUNCTION() void UpdateAutoSpeechBubble();

	/* =================================================================
	 * 말풍선 전용 블루프린트 통신 (메인 대화창은 C++로 완전히 대체됨)
	 * ================================================================= */
	UFUNCTION(BlueprintImplementableEvent, Category = "NPC|Dialogue")
	void OnUpdateSpeechBubble(const FText& NewText);

public:
	/* =================================================================
	 * AI 이동 및 제어 함수 (누구나 밖에서 명령할 수 있어야 함!)
	 * ================================================================= */
	UFUNCTION(BlueprintCallable, Category = "NPC|AI") void FollowPlayer(float StopDistance = 150.0f);
	UFUNCTION(BlueprintCallable, Category = "NPC|AI") void StopMoving();
	UFUNCTION(BlueprintCallable, Category = "NPC|AI") void TeleportToLocation(FVector NewLocation);
	
	// 외부에서 패트롤을 시작하라고 명령할 함수
	UFUNCTION(BlueprintCallable, Category = "NPC|AI") void StartPatrol();

protected:
	/* =================================================================
	 * 내부 동작용 타이머와 함수 (클래스 안에서만 스스로 부름!)
	 * ================================================================= */
	// 따라오기 유지용 타이머
	FTimerHandle FollowTimerHandle;
	float CachedFollowRadius = 150.0f;

	UFUNCTION()
	void UpdateFollowTarget();

	// 패트롤용 업데이트 함수
	UFUNCTION()
	void UpdatePatrol();
};