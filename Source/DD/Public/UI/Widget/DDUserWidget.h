// Copyright DoubleDippinz

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DDUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class DD_API UDDUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject>	WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
