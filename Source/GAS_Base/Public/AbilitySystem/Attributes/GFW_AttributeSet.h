// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "GFW_AttributeSet.generated.h"



#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttributesInit);

UCLASS()
class GAS_BASE_API UGFW_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;


	UPROPERTY(BlueprintAssignable)
	FAttributesInit OnAttributesInit;
	
	UPROPERTY(ReplicatedUsing = OnRep_AttributesInit)
	bool bAttributesInit = false;

	UFUNCTION()
	void OnRep_AttributesInit();
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_NetWorth)
	FGameplayAttributeData NetWorth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxNetWorth)
	FGameplayAttributeData MaxNetWorth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mood)
	FGameplayAttributeData Mood;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMood)
	FGameplayAttributeData MaxMood;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intox)
	FGameplayAttributeData Intox;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxIntox)
	FGameplayAttributeData MaxIntox;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Identity)
	FGameplayAttributeData Identity;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxIdentity)
	FGameplayAttributeData MaxIdentity;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_NetWorth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxNetWorth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Mood(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxMood(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Intox(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxIntox(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Identity(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxIdentity(const FGameplayAttributeData& OldValue);

	ATTRIBUTE_ACCESSORS(ThisClass, Health);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxHealth);
	ATTRIBUTE_ACCESSORS(ThisClass, Mana);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxMana);
	ATTRIBUTE_ACCESSORS(ThisClass, NetWorth);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxNetWorth);
	ATTRIBUTE_ACCESSORS(ThisClass, Mood);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxMood);
	ATTRIBUTE_ACCESSORS(ThisClass, Intox);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxIntox);
	ATTRIBUTE_ACCESSORS(ThisClass, Identity);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxIdentity);
};
