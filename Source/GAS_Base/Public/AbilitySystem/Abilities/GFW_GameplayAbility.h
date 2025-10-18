// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GFW_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_BASE_API UGFW_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const
		FGameplayAbilityActorInfo* ActorInfo, const
		FGameplayAbilityActivationInfo ActivationInfo, const
		FGameplayEventData* TriggerEventData) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GFW|Debug")
	bool bDrawDebugs = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GFW|Debug")
	bool bDebugAbilityStart = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GFW|Debug")
	bool bDebugAbilityEnd = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GFW|Debug")
	bool bDebugSphere = false;

	
};
