// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "GFW_BaseCharacter.h"
#include "GFW_EnemyCharacter.generated.h"


class UabilitySystemComponent;
class UAttributeSet;

UCLASS()
class GAS_BASE_API AGFW_EnemyCharacter : public AGFW_BaseCharacter
{
	GENERATED_BODY()

public:

	AGFW_EnemyCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const override;

	void StopMovementUntilLanded();
protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category = "GFW|AbilitySystem")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
