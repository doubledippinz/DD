// Copyright DoubleDippinz


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/DDAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UDDAttributeSet* DDAttributeSet = CastChecked<UDDAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(DDAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(DDAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(DDAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(DDAttributeSet->GetMaxMana());


}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UDDAttributeSet* DDAttributeSet = CastChecked<UDDAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DDAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	DDAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	DDAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	DDAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}