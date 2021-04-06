// Fill out your copyright notice in the Description page of Project Settings.


#include "REnemyWidget.h"

UREnemyWidget::UREnemyWidget(const FObjectInitializer& ObjectInitializer):UUserWidget(ObjectInitializer)
{

}

void UREnemyWidget::NativeConstruct()
{
	Super::NativeConstruct();
}


void UREnemyWidget::ChangeProgressBarValue(float value)
{

	//RProgressBar->Percent -= value;   //doesnt work
	RProgressBar->SetPercent(RProgressBar->Percent - value);   //work

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "?????????????????????????????????????????????????"+ FString::SanitizeFloat( RProgressBar->Percent));
}

void UREnemyWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "????????" );

}
