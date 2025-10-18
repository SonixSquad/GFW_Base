// Copyright Kerem Avcil - ToTW Derin Works

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "AttributeSet.h"

#include "GFW_WidgetComponent.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGFW_AttributeSet;
class UGFW_ASC;
class AGFW_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAS_BASE_API UGFW_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:


protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TMap<FGameplayAttribute, FGameplayAttribute> AttributeMap;
	
private:
	TWeakObjectPtr<AGFW_BaseCharacter> GFWCharacter;
	TWeakObjectPtr<UGFW_ASC> AbilitySystemComponent;
	TWeakObjectPtr<UGFW_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInit() const;
	void InitAttributeDelegate();
	void BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;
	
	UFUNCTION()
	void OnASCInit(UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UFUNCTION()
	void BindToAttributeChanges();
};
