// Copyright DoubleDippinz


#include "AbilitySystem/DDAttributeSet.h"

#include "Net/UnrealNetwork.h"

UDDAttributeSet::UDDAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
	InitBoost(100.f);
	InitMaxBoost(100.f);
}

// Register variables for replication
void UDDAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UDDAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDDAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDDAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDDAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDDAttributeSet, Boost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDDAttributeSet, MaxBoost, COND_None, REPNOTIFY_Always);
}

// OnRep Functions
void UDDAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDDAttributeSet, Health, OldHealth);
}
void UDDAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDDAttributeSet, MaxHealth, OldMaxHealth);
}
void UDDAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDDAttributeSet, Mana, OldMana);
}
void UDDAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDDAttributeSet, MaxMana, OldMaxMana);
}

void UDDAttributeSet::OnRep_Boost(const FGameplayAttributeData& OldBoost) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDDAttributeSet, Boost, OldBoost);
}
void UDDAttributeSet::OnRep_MaxBoost(const FGameplayAttributeData& OldMaxBoost) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDDAttributeSet, MaxBoost, OldMaxBoost);
}
