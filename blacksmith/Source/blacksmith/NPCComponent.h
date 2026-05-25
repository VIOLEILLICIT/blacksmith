#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SharedTypes.h"
#include "ItemDataAsset.h"
#include "NPCComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemInteractionEvent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UItemDataAsset* Item = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsGaining = true;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BLACKSMITH_API UNPCComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UNPCComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Affinity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social")
	TMap<TSoftObjectPtr<AActor>, float> SocialCircle;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	void UpdateAffinity(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "NPC")
	bool ProcessItemEvent(const FItemInteractionEvent& Event, AActor* Interactor);
};