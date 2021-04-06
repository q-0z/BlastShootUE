// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RPlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class RELEASE_API URPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	URPlayerWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct()override;

};
