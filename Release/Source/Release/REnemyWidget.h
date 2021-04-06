// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "REnemyWidget.generated.h"

/**
 * 
 */
UCLASS()
class RELEASE_API UREnemyWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UREnemyWidget(const FObjectInitializer& ObjectInitializer);


	virtual void NativeConstruct()override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	UPROPERTY(EditAnyWhere,BlueprintReadWrite,meta=(BindWidget))
	UProgressBar* RProgressBar;
	void ChangeProgressBarValue(float value);

	//virtual void Tick(float DeltaTime) override;

};
