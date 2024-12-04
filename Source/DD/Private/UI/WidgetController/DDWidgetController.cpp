// Copyright DoubleDippinz


#include "UI/WidgetController/DDWidgetController.h"

void UDDWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UDDWidgetController::BroadcastInitialValues()
{
}

void UDDWidgetController::BindCallbacksToDependencies()
{
}