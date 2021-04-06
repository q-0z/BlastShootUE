// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "RPlayerWidget.h"

#include "RPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class RELEASE_API ARPlayerHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds)override;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<URPlayerWidget>RPlayerWidgetClass;
private:
	URPlayerWidget* RPlayerWidgetInstance;
};
