// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GFW_GameplayAbility.h"
#include "GFW_GA_Primary.generated.h"

/**
 * 
 */
UCLASS()
class GAS_BASE_API UGFW_GA_Primary : public UGFW_GameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "GFW|Abilities")
	TArray<AActor*> HitBoxOverlapTest();

	UFUNCTION(BlueprintCallable, Category = "GFW|Abilities")
	void SendHitReactEventToActors(const TArray<AActor*>& ActorsHit);

private:

	void DrawHitBoxOverlapDebugs(const TArray<FOverlapResult>& OverlapResults, const FVector& HitBoxLocation) const;
	
	UPROPERTY(EditDefaultsOnly, Category = "GFW|Abilities")
	float HitBoxRadius = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Abilities")
	float HitBoxForwardOffset = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Abilities")
	float HitBoxElevationOffset = 20.0f;

	
	
};
