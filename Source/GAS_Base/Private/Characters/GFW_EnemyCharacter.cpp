// Copyright Kerem Avcil - ToTW Derin Works


#include "Characters/GFW_EnemyCharacter.h"

#include "AbilitySystem/GFW_ASC.h"
#include "AbilitySystem/Attributes/GFW_AttributeSet.h"

AGFW_EnemyCharacter::AGFW_EnemyCharacter()
{
	
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UGFW_ASC>("GFW_ASC");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UGFW_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AGFW_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGFW_EnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}


void AGFW_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	
	if (!HasAuthority()) return;
	
		GiveStartupAbilities();
		InitializeAttributes();
	
	
}



