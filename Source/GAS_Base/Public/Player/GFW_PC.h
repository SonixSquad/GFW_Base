// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GFW_PC.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
struct FGameplayTag;
/**
 * 
 */
UCLASS()
class GAS_BASE_API AGFW_PC : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent();

private:
	
	UPROPERTY(EditDefaultsOnly, Category = "GFW|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Input|Movement")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Input|Movement")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Input|Movement")
	TObjectPtr<UInputAction> LookAction;
	
	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Input|Abilities")
	TObjectPtr<UInputAction> PrimaryAction;
	
	void Primary();
	void Secondary();
	void Tertiary();
	void ActivateAbility(const FGameplayTag& AbilityTag) const;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Input|Abilities")
	TObjectPtr<UInputAction> SecondaryAction;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Input|Abilities")
	TObjectPtr<UInputAction> TertiaryAction;
};
