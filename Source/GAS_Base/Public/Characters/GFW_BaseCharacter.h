// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "GFW_BaseCharacter.generated.h"

namespace GFWTags
{
	extern GAS_BASE_API const FName Player;
}

struct FOnAttributeChangeData;
class UAttributeSet;
class UGameplayAbility;
class UGameplayEffect;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInit, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);

UCLASS(Abstract)
class GAS_BASE_API AGFW_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AGFW_BaseCharacter();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const { return nullptr; }

	bool IsAlive() const { return bAlive; }
	void SetAlive(bool bAliveStatus) { bAlive = bAliveStatus; }
	
	UPROPERTY(BlueprintAssignable)
	FASCInit OnASCInit;

	UFUNCTION(BlueprintCallable, Category = "GFW|Death")
	virtual void HandleRespawn();

	UFUNCTION(BlueprintCallable, Category = "GFW|Attributes")
	void ResetAttributes();

	UPROPERTY(EditAnywhere, Category = "GFW|AI") 
	float SearchRange{1000.f};
	
protected:

	void GiveStartupAbilities();
	void InitAttributes() const;
	void SetIdentity() const;
	
	void OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData);
	virtual void HandleDeath();
	
private:

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Effects")
	TSubclassOf<UGameplayEffect> InitAttributesEffect;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Effects")
	TSubclassOf<UGameplayEffect> ResetAttributesEffect;

	UPROPERTY(EditDefaultsOnly, Category = "GFW|Effects")
	TSubclassOf<UGameplayEffect> SetIdentityEffect;
	
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Replicated)
	bool bAlive = true;

	
};

