// Copyright DoubleDippinz

#pragma once

#include "CoreMinimal.h"
#include "Character/DDCharacterBase.h"
#include "DDCharacter.generated.h"

UCLASS()
class DD_API ADDCharacter : public ADDCharacterBase
{
	GENERATED_BODY()

public:
	ADDCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
