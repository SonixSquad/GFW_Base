// Copyright Kerem Avcil - ToTW Derin Works


#include "AbilitySystem/Abilities/GFW_AbilityTemplate.h"

UGFW_AbilityTemplate::UGFW_AbilityTemplate()
{

	// Instancing and Net Execution methods
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
}
