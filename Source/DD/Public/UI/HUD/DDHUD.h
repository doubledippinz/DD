// Copyright DoubleDippinz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DDHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UDDOverlayWidgetController;
class UDDUserWidget;
struct FWidgetControllerParams;

UCLASS()
class DD_API ADDHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TObjectPtr<UDDUserWidget>  OverlayWidget;

	UDDOverlayWidgetController* GetDDOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:


private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDDUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UDDOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDDOverlayWidgetController> OverlayWidgetControllerClass;
};
