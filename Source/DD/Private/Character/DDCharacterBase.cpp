// Copyright DoubleDippinz


#include "Character/DDCharacterBase.h"

ADDCharacterBase::ADDCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Skateboard = CreateDefaultSubobject<USkeletalMeshComponent>("Skateboard");
	Skateboard->SetupAttachment(GetMesh(), FName("SkateboardHandSocket"));
	Skateboard->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ADDCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ADDCharacterBase::BeginPlay()
{
	Super::BeginPlay();


	
}
