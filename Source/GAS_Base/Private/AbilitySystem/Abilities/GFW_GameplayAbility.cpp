// Copyright Kerem Avcil - ToTW Derin Works


#include "AbilitySystem/Abilities/GFW_GameplayAbility.h"

UGFW_GameplayAbility::UGFW_GameplayAbility()
{
	// Ensure a single ability instance per actor so cached ActorInfo remains valid across respawn/state resets
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

bool UGFW_GameplayAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags,
	const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	if (!ActorInfo || !ActorInfo->AvatarActor.IsValid() || !ActorInfo->OwnerActor.IsValid() || !ActorInfo->AbilitySystemComponent.IsValid())
	{
		UE_LOG(LogTemp, Verbose, TEXT("%s CanActivateAbility: invalid ActorInfo/actors/ASC"), *GetName());
		return false;
	}

	// If a skeletal mesh is expected for montage-driven abilities, ensure an AnimInstance exists
	const USkeletalMeshComponent* SkeletalMesh = ActorInfo->SkeletalMeshComponent.Get();
	if (SkeletalMesh == nullptr)
	{
		UE_LOG(LogTemp, Verbose, TEXT("%s CanActivateAbility: SkeletalMeshComponent is null"), *GetName());
		return false;
	}

	if (SkeletalMesh->GetAnimInstance() == nullptr)
	{
		UE_LOG(LogTemp, Verbose, TEXT("%s CanActivateAbility: AnimInstance is null"), *GetName());
		return false;
	}

	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UGFW_GameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	// Defend against invalid pointers after revive/ASC re-init
	if (!ActorInfo || !ActorInfo->AvatarActor.IsValid() || !ActorInfo->OwnerActor.IsValid())
	{
		UE_LOG(LogTemp, Verbose, TEXT("%s ActivateAbility: invalid ActorInfo/actors; aborting"), *GetName());
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	// Some Blueprint abilities may be marked Non-Instanced and won't have CurrentActorInfo set.
	// Avoid calling into base if that would dereference a null CurrentActorInfo.
	if (GetCurrentActorInfo() == nullptr)
	{
		if (bDrawDebugs && IsValid(GEngine))
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red,
				FString::Printf(TEXT("%s aborted: CurrentActorInfo is null (check Instancing Policy)"), *GetName()));
		}
		UE_LOG(LogTemp, Verbose, TEXT("%s ActivateAbility: CurrentActorInfo is null; aborting"), *GetName());
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	// Final preflight: if montage/anim-dependent and no AnimInstance, abort before BP nodes run
	const USkeletalMeshComponent* SkeletalMesh = ActorInfo->SkeletalMeshComponent.Get();
	if (SkeletalMesh == nullptr || SkeletalMesh->GetAnimInstance() == nullptr)
	{
		if (bDrawDebugs && IsValid(GEngine))
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red,
				FString::Printf(TEXT("%s aborted: Missing SkeletalMesh/AnimInstance"), *GetName()));
		}
		UE_LOG(LogTemp, Verbose, TEXT("%s ActivateAbility: Missing SkeletalMesh/AnimInstance; aborting"), *GetName());
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (bDrawDebugs && IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("%s Activated"), *GetName()));
	}
}
