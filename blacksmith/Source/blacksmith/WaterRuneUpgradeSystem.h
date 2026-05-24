#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaterRuneUpgradeSystem.generated.h"

UCLASS()
class BLACKSMITH_API AWaterRuneUpgradeSystem : public AActor
{
    GENERATED_BODY()

public:
    AWaterRuneUpgradeSystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Water Rune")
    bool bIsActive;

    UPROPERTY(BlueprintReadWrite, Category = "Water Rune")
    bool bIsDragging;

    UPROPERTY(BlueprintReadWrite, Category = "Water Rune")
    FName HoveredNodeName;

    UPROPERTY(BlueprintReadOnly, Category = "Water Rune")
    int32 CurrentStageStep;

    UPROPERTY(BlueprintReadOnly, Category = "Water Rune")
    float PointerProgress;

    UPROPERTY(EditAnywhere, Category = "Water Rune")
    float CurrentSpeed;

    UPROPERTY(EditAnywhere, Category = "Water Rune")
    float ErrorTolerance;

    UPROPERTY(BlueprintReadWrite, Category = "Water Rune")
    FVector2D NodeA_Pos;

    UPROPERTY(BlueprintReadWrite, Category = "Water Rune")
    FVector2D NodeB_Pos;

    UPROPERTY(BlueprintReadWrite, Category = "Water Rune")
    FVector2D NodeC_Pos;

    UPROPERTY(BlueprintReadOnly, Category = "Water Rune")
    FVector2D ImagePointer_Pos;

    UFUNCTION(BlueprintCallable, Category = "Water Rune")
    void UpdateNodePositionFromViewport(FVector2D InputMousePos);

    void UpdatePointerMovement();
    void CheckRunePurification();
};