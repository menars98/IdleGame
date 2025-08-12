// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IdleGameWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UIdleGameWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    
    virtual void NativeConstruct() override;

public:

    UFUNCTION(BlueprintImplementableEvent, Category = "Layout")
    void CreateResourceIcons();

};
