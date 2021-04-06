// Fill out your copyright notice in the Description page of Project Settings.


#include "RPlayerHUD.h"

void ARPlayerHUD::DrawHUD()
{
}

void ARPlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (RPlayerWidgetClass)
	{
		RPlayerWidgetInstance = CreateWidget<URPlayerWidget>(GetWorld(), RPlayerWidgetClass);
		if (RPlayerWidgetInstance)
		{
			RPlayerWidgetInstance->AddToViewport();
		}
	}
}

void ARPlayerHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}
