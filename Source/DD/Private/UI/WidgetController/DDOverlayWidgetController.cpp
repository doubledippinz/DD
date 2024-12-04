// Copyright DoubleDippinz


#include "UI/WidgetController/DDOverlayWidgetController.h"

#include "AbilitySystem/DDAttributeSet.h"

void UDDOverlayWidgetController::BroadcastInitialValues()
{
	const UDDAttributeSet* AuraAttributeSet = CastChecked<UDDAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());


}

void UDDOverlayWidgetController::BindCallbacksToDependencies()
{
	const UDDAttributeSet* DDAttributeSet = CastChecked<UDDAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DDAttributeSet->GetHealthAttribute()).AddUObject(this, &UDDOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	DDAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UDDOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	DDAttributeSet->GetManaAttribute()).AddUObject(this, &UDDOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	DDAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UDDOverlayWidgetController::MaxManaChanged);
	
}

void UDDOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UDDOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UDDOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UDDOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}