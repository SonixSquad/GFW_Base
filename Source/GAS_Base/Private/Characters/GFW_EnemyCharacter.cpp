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

void AGFW_EnemyCharacter::StopMovementUntilLanded()
{
	//bIsBeingLaunched = true;
	//AAIController* AIController = GetController<AAIController>();
	//if (!IsValid(AIController)) return;
	//AIController->StopMovement();
	//if (!LandedDelegate.IsAlreadyBound(this, &ThisClass::EnableMovementOnLanded))
	//{
	//	LandedDelegate.AddDynamic(this, &ThisClass::EnableMovementOnLanded);
	//}
}

void AGFW_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	OnASCInit.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	
	if (!HasAuthority()) return;
	
		GiveStartupAbilities();
		InitAttributes();
		SetIdentity();
	
	UGFW_AttributeSet* GFW_AttributeSet = Cast<UGFW_AttributeSet>(GetAttributeSet());
	if (!IsValid(GFW_AttributeSet)) return;
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GFW_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
}



