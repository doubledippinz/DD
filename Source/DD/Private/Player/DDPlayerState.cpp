// Copyright DoubleDippinz


#include "Player/DDPlayerState.h"

#include "AbilitySystem/DDAttributeSet.h"
#include "AbilitySystem/DDAbilitySystemComponent.h"

ADDPlayerState::ADDPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UDDAbilitySystemComponent>("AbilitySystem_Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UDDAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* ADDPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}