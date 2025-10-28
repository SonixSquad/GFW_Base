// Copyright Kerem Avcil - ToTW Derin Works


#include "GameObjects/GFW_HealPad.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Characters/GFW_PlayerCharacter.h"
#include "GameplayTags/GFWTags.h"


// Sets default values
AGFW_HealPad::AGFW_HealPad()
{
	
	PrimaryActorTick.bCanEverTick = false;
}

void AGFW_HealPad::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    AGFW_PlayerCharacter* PlayerCharacter = Cast<AGFW_PlayerCharacter>(OtherActor);
    if (!IsValid(PlayerCharacter)) return;

    // Start visual effects immediately on any client
    OverlapCount++;
    if (OverlapCount == 1)
    {
        // First entrant starts visuals; cancel any pending stop
        GetWorldTimerManager().ClearTimer(StopEffectsTimerHandle);
        SpawnHealEffects();
    }

    UAbilitySystemComponent* AbilitySystemComponent = PlayerCharacter->GetAbilitySystemComponent();
    if (!IsValid(AbilitySystemComponent) || !HasAuthority()) return;

    // If the player is currently not alive, bring them back to alive state on the server
    if (!PlayerCharacter->IsAlive())
    {
        PlayerCharacter->SetAlive(true);
    }

    if (!IsValid(HealEffect))
    {
        UE_LOG(LogTemp, Warning, TEXT("HealPad '%s': HealEffect is not set."), *GetName());
        return;
    }

    FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
    FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(HealEffect, 1.f, ContextHandle);

    if (!SpecHandle.IsValid() || !SpecHandle.Data.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("HealPad '%s': Invalid GameplayEffect SpecHandle."), *GetName());
        return;
    }

    UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GFWTags::SetByCaller::HealPad, Heal);
    
    const FActiveGameplayEffectHandle ActiveHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
    if (!ActiveHandle.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("HealPad '%s': Failed to apply HealEffect."), *GetName());
        return;
    }
}

void AGFW_HealPad::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	AGFW_PlayerCharacter* PlayerCharacter = Cast<AGFW_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter)) return;

    OverlapCount = FMath::Max(0, OverlapCount - 1);
    if (OverlapCount == 0)
    {
        // Delay stopping effects to allow them to play for MinEffectDuration
        GetWorldTimerManager().SetTimer(StopEffectsTimerHandle, this, &ThisClass::StopEffectsAfterDelay, MinEffectDuration, false);
    }
}

void AGFW_HealPad::StopEffectsAfterDelay()
{
    StopHealEffects();
}


