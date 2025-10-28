// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "GFW_GameplayAbility.h"
#include "GFW_AbilityTemplate.generated.h"

/**
 * 
 */
UCLASS()
class GAS_BASE_API UGFW_AbilityTemplate : public UGFW_GameplayAbility
{
	GENERATED_BODY()

public:
	UGFW_AbilityTemplate();

	//Blueprint Implementable Event
	// does not need to be defined in constructor unless logic required in cpp

	UFUNCTION(BlueprintImplementableEvent)
	void MyCustomEventName(AActor* MyCustomEventName);

	
};
