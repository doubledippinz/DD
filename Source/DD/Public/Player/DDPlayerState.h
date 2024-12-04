// Copyright DoubleDippinz

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "DDPlayerState.generated.h"

class UAbilitySystemInterface;
class UAttributeSet;

UCLASS()
class DD_API ADDPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ADDPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UAttributeSet> AttributeSet;	
};
