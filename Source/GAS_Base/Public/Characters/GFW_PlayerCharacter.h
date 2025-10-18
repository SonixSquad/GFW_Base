// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "GFW_BaseCharacter.h"
#include "GFW_PlayerCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GAS_BASE_API AGFW_PlayerCharacter : public AGFW_BaseCharacter
{
	GENERATED_BODY()

public:
	
	AGFW_PlayerCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Cams")
	TObjectPtr<USpringArmComponent> TP_CamBoom;

	UPROPERTY(VisibleAnywhere, Category = "Cams")
	TObjectPtr<UCameraComponent> TP_Cam;
	
};
