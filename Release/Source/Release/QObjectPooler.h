// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QObjectPooler.generated.h"

UCLASS()
class RELEASE_API AQObjectPooler : public AActor
{
	GENERATED_BODY()
	
public:	
	AQObjectPooler();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxNumberOfPool=100;

	UFUNCTION()
		void Init();
	UFUNCTION()
		AActor* DequeueObject();
	UFUNCTION()
		void EnqueueObject(AActor * Actor);

	UPROPERTY(EditAnyWhere,BlueprintReadWrite)
	TSubclassOf<AActor> PooledObject;
private:
	TQueue<AActor*> RPooledObjectQueue;
};
