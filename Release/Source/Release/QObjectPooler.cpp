// Fill out your copyright notice in the Description page of Project Settings.


#include "QObjectPooler.h"

AQObjectPooler::AQObjectPooler()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AQObjectPooler::BeginPlay()
{
	Super::BeginPlay();
	//Init();
}

void AQObjectPooler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQObjectPooler::Init()
{
	if (PooledObject)
	{
		for (int i = 0; i < MaxNumberOfPool; i++)
		{
			FVector Location(0.0f, 0.0f, 0.0f);
			FRotator Rotation(0.0f, 0.0f, 0.f);
			FActorSpawnParameters SpawnInfo;
			auto SpawnedObj = GetWorld()->SpawnActor<AActor>(PooledObject, Location, Rotation, SpawnInfo);
			SpawnedObj-> SetActorHiddenInGame(true);
			SpawnedObj->SetActorEnableCollision(false);
			SpawnedObj->SetActorTickEnabled(false);
			RPooledObjectQueue.Enqueue(SpawnedObj);
		}
	}
}

AActor* AQObjectPooler::DequeueObject()
{

	//if (RPooledObjectQueue.IsEmpty())return nullptr;

	AActor* ObjectToReturn;
	RPooledObjectQueue.Dequeue(ObjectToReturn);
	return ObjectToReturn;
}


void AQObjectPooler::EnqueueObject(AActor* Actor)
{
	FTimerHandle timerHandle;

	//GetWorldTimerManager().SetTimer(timerHandle, this, &ARPawn::DelayTimer, FMath::RandRange(.05f, .07f), false);
	Actor->SetActorTickEnabled(false);

	RPooledObjectQueue.Enqueue(Actor);
}