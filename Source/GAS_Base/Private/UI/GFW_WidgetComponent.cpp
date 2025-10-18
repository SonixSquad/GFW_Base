// Copyright Kerem Avcil - ToTW Derin Works


#include "UI/GFW_WidgetComponent.h"

#include "AbilitySystem/GFW_ASC.h"
#include "AbilitySystem/Attributes/GFW_AttributeSet.h"
#include "Blueprint/WidgetTree.h"

#include "Characters/GFW_BaseCharacter.h"
#include "UI/GFW_AttributeWidget.h"


void UGFW_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();

	if (!IsASCInit())
	{
		GFWCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInit);
		return;
	}

	InitAttributeDelegate();
}

void UGFW_WidgetComponent::InitAbilitySystemData()
{
	GFWCharacter = Cast<AGFW_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UGFW_AttributeSet>(GFWCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UGFW_ASC>(GFWCharacter->GetAbilitySystemComponent());
}

bool UGFW_WidgetComponent::IsASCInit() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UGFW_WidgetComponent::InitAttributeDelegate()
{
	if (!AttributeSet->bAttributesInit)
	{
		AttributeSet->OnAttributesInit.AddDynamic(this, &ThisClass::BindToAttributeChanges);
	}
	else
	{
		BindToAttributeChanges();
	}
}



void UGFW_WidgetComponent::OnASCInit(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UGFW_ASC>(ASC);
	AttributeSet = Cast<UGFW_AttributeSet>(AS);

	if (!IsASCInit()) return;
	InitAttributeDelegate();
}

void UGFW_WidgetComponent::BindToAttributeChanges()
{
	for (const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges(GetUserWidgetObject(), Pair); // for checking the owned widget object.
		
		GetUserWidgetObject()->WidgetTree->ForEachWidget([this, &Pair](UWidget* ChildWidget)
		{
			BindWidgetToAttributeChanges(ChildWidget, Pair);
		});
	}
}

void UGFW_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject,
	const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	UGFW_AttributeWidget* AttributeWidget = Cast<UGFW_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget)) return; // We only care about CC Attribute Widgets
	if (!AttributeWidget->MatchesAttributes(Pair)) return; // Only subscribe for matching Attributes

	AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // for initial values.

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this, AttributeWidget, &Pair](const FOnAttributeChangeData& AttributeChangeData)
	{
		AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // For changes during the game.
	});
}


