// Copyright Kerem Avcil - ToTW Derin Works


#include "Player/GFW_PS.h"

#include "AbilitySystem/GFW_ASC.h"
#include "AbilitySystem/Attributes/GFW_AttributeSet.h"

AGFW_PS::AGFW_PS()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UGFW_ASC>("GFW_ASC");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	

	AttributeSet = CreateDefaultSubobject<UGFW_AttributeSet>("AttributeSet");
	
}

UAbilitySystemComponent* AGFW_PS::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
