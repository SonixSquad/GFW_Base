// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GFW_HealPad.generated.h"

class UGameplayEffect;
UCLASS()
class GAS_BASE_API AGFW_HealPad : public AActor
{
	GENERATED_BODY()

public:
	
	AGFW_HealPad();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GFW|HealPad", meta = (ExposeOnSpawn, ClampMin = "0.0"))
	float Heal{100.f};


	UFUNCTION(BlueprintImplementableEvent, Category = "GFW|HealPad")
	void SpawnHealEffects();

	UFUNCTION(BlueprintImplementableEvent, Category = "GFW|HealPad")
	void StopHealEffects();

	// Minimum time the Niagara effect should play after leaving overlap
	UPROPERTY(EditAnywhere, Category = "GFW|HealPad", meta = (ClampMin = "0.0"))
	float MinEffectDuration{2.0f};

private:
	UPROPERTY(EditDefaultsOnly, Category = "GFW|HealPad")
	TSubclassOf<UGameplayEffect> HealEffect;

	// Track overlapping players to know when to start/stop effects
	int32 OverlapCount{0};

	FTimerHandle StopEffectsTimerHandle;
	void StopEffectsAfterDelay();
};
