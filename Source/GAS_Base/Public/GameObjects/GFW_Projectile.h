// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GFW_Projectile.generated.h"

class UProjectileMovementComponent;
class UGameplayEffect;

UCLASS()
class GAS_BASE_API AGFW_Projectile : public AActor
{
	GENERATED_BODY()

public:
	
	AGFW_Projectile();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GFW|Damage", meta = (ExposeOnSpawn, ClampMin = "0.0"))
	float Damage{-25.f};

	UFUNCTION(BlueprintImplementableEvent, Category = "GFW|Projectile")
	void SpawnImpactEffects();
private:
	
	UPROPERTY(VisibleAnywhere, Category = "GFW|Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(EditDefaultsOnly, Category = "GFW|Damage")
	TSubclassOf<UGameplayEffect> DamageEffect;
};
