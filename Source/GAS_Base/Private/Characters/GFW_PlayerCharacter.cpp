// Copyright Kerem Avcil - ToTW Derin Works


#include "GAS_Base/Public/Characters/GFW_PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/Attributes/GFW_AttributeSet.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GFW_PS.h"


class UGameplayAbility;

AGFW_PlayerCharacter::AGFW_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 500.0f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->GravityScale = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;
	

	TP_CamBoom = CreateDefaultSubobject<USpringArmComponent>("TP_CamBoom");
	TP_CamBoom->SetupAttachment(GetRootComponent());
	TP_CamBoom->TargetArmLength = 600.0f;
	TP_CamBoom->bUsePawnControlRotation = true;

	TP_Cam = CreateDefaultSubobject<UCameraComponent>("TP_Cam");
	TP_Cam->SetupAttachment(TP_CamBoom, USpringArmComponent::SocketName);
	TP_Cam->bUsePawnControlRotation = false;
}

UAbilitySystemComponent* AGFW_PlayerCharacter::GetAbilitySystemComponent() const
{
	AGFW_PS* GFW_PLayerState = Cast<AGFW_PS>(GetPlayerState());
	if (!IsValid(GFW_PLayerState)) return nullptr;

	return GFW_PLayerState->GetAbilitySystemComponent();
}

UAttributeSet* AGFW_PlayerCharacter::GetAttributeSet() const
{
	AGFW_PS* GFWPlayerState = Cast<AGFW_PS>(GetPlayerState());
	if (!IsValid(GFWPlayerState)) return nullptr;

	return GFWPlayerState->GetAttributeSet();
}

void AGFW_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!IsValid(GetAbilitySystemComponent()) || !HasAuthority()) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	OnASCInit.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	GiveStartupAbilities();
	InitAttributes();

	UGFW_AttributeSet* GFW_AttributeSet = Cast<UGFW_AttributeSet>(GetAttributeSet());
	if (!IsValid(GFW_AttributeSet)) return;
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GFW_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
}

void AGFW_PlayerCharacter::OnRep_PlayerState()
{
	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	OnASCInit.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());

	UGFW_AttributeSet* GFW_AttributeSet = Cast<UGFW_AttributeSet>(GetAttributeSet());
	if (!IsValid(GFW_AttributeSet)) return;
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GFW_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
}


