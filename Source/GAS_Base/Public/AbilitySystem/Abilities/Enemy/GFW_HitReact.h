// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GFW_GameplayAbility.h"
#include "GFW_HitReact.generated.h"

/**
 * 
 */
UCLASS()
class GAS_BASE_API UGFW_HitReact : public UGFW_GameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "GFW|Abilities")
	void CacheHitDirectionVectors(AActor* Instigator);

	UPROPERTY(BlueprintReadOnly, Category = "GFW|Abilities")
	FVector AvatarForward;

	UPROPERTY(BlueprintReadOnly, Category = "GFW|Abilities")
	FVector ToInstigator;
};
