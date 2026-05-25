#include "WaterRuneUpgradeSystem.h"
#include "Kismet/KismetMathLibrary.h"

AWaterRuneUpgradeSystem::AWaterRuneUpgradeSystem()
{
    PrimaryActorTick.bCanEverTick = true;

    bIsActive = true;
    bIsDragging = false;
    HoveredNodeName = "None";
    CurrentStageStep = 1;
    PointerProgress = 0.0f;
    CurrentSpeed = 0.5f;
    ErrorTolerance = 0.03f;

    NodeA_Pos = FVector2D(200.0f, 200.0f);
    NodeB_Pos = FVector2D(500.0f, 200.0f);
    NodeC_Pos = FVector2D(800.0f, 500.0f);
    ImagePointer_Pos = NodeA_Pos;
}

void AWaterRuneUpgradeSystem::BeginPlay()
{
    Super::BeginPlay();
}

void AWaterRuneUpgradeSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsActive)
    {
        PointerProgress += (CurrentSpeed * DeltaTime);
        if (PointerProgress >= 1.0f)
        {
            PointerProgress = 0.0f;
        }

        UpdatePointerMovement();
        CheckRunePurification();
    }
}

void AWaterRuneUpgradeSystem::UpdateNodePositionFromViewport(FVector2D InputMousePos)
{
    if (!bIsDragging) return;

    if (HoveredNodeName == "Node_A")
    {
        NodeA_Pos = InputMousePos;
    }
    else if (HoveredNodeName == "Node_B")
    {
        NodeB_Pos = InputMousePos;
    }
    else if (HoveredNodeName == "Node_C")
    {
        NodeC_Pos = InputMousePos;
    }
}

void AWaterRuneUpgradeSystem::UpdatePointerMovement()
{
    if (CurrentStageStep == 1)
    {
        ImagePointer_Pos = FMath::Lerp(FVector2D(200.0f, 200.0f), NodeB_Pos, PointerProgress);
    }
    else if (CurrentStageStep == 2)
    {
        ImagePointer_Pos = FMath::Lerp(NodeB_Pos, NodeC_Pos, PointerProgress);
    }
}

void AWaterRuneUpgradeSystem::CheckRunePurification()
{
    float DistanceBetweenNodes = FVector2D::Distance(NodeA_Pos, NodeB_Pos);
    if (DistanceBetweenNodes < 50.0f) return;

    if (FMath::IsNearlyEqual(PointerProgress, 0.25f, ErrorTolerance))
    {
        if (CurrentStageStep == 1)
        {
            CurrentStageStep = 2;
            UE_LOG(LogTemp, Warning, TEXT("★ 1번 물의 룬 노드 정화 성공! 다음 단계 전환."));
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("★ 1번 물의 룬 노드 정화 성공!"));
            }
        }
    }
}