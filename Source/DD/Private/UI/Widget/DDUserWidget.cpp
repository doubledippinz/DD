// Copyright DoubleDippinz


#include "UI/Widget/DDUserWidget.h"

void UDDUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}