// Copyright DoubleDippinz

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "DDCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class DD_API ADDCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	ADDCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:


	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Equipment")
	TObjectPtr<USkeletalMeshComponent> Skateboard;

	UPROPERTY(EditAnywhere, Category = "Equipment")
	TObjectPtr<USkeletalMeshComponent> Helmet;

	UPROPERTY(EditAnywhere, Category = "Equipment")
	TObjectPtr<USkeletalMeshComponent> Gloves;

	UPROPERTY(EditAnywhere, Category = "AbilitySystem")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = "AbilitySystem")
	TObjectPtr<UAttributeSet> AttributeSet;


};
