// Copyright DoubleDippinz


#include "Character/DDCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/DDPlayerController.h"
#include "Player/DDPlayerState.h"
#include "UI/HUD/DDHUD.h"

ADDCharacter::ADDCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	
	
}

void ADDCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAbilityActorInfo();
}

void ADDCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the client
	InitAbilityActorInfo();
}

void ADDCharacter::InitAbilityActorInfo()
{
	ADDPlayerState* DDPlayerState = GetPlayerState<ADDPlayerState>();
	check(DDPlayerState);
	DDPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(DDPlayerState, this);
	AbilitySystemComponent = DDPlayerState->GetAbilitySystemComponent();
	AttributeSet = DDPlayerState->GetAttributeSet();

	if (ADDPlayerController* DDPlayerController = Cast<ADDPlayerController> (GetController()))
	{
		if (ADDHUD* DDHUD = Cast<ADDHUD>(DDPlayerController->GetHUD()))
		{
			DDHUD->InitOverlay(DDPlayerController, DDPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	
}
