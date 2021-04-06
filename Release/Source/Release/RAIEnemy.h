// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "REnemyWidget.h"

#include "RAIEnemy.generated.h"

UCLASS()
class RELEASE_API ARAIEnemy : public APawn
{
	GENERATED_BODY()

public:
	ARAIEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ChangeHealth(float value);
	void RDestroy();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCapsuleComponent* RCapsuleComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* RStaticMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWidgetComponent* RWidgetComponent;


	void Test();
};
