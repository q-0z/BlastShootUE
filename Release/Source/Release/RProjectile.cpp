

#include "RProjectile.h"

ARProjectile::ARProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	RSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = RSceneComponent;

	RSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Capsule"));
	RSphereComponent->AttachTo(RSceneComponent);
	RStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RStaticMeshComponent->AttachTo(RSphereComponent);

	OnActorBeginOverlap.AddDynamic(this,&ARProjectile::OnActorBeginOverlapCallback);
	//RSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ARProjectile::OnCompBeginOverlapCallback);
}

void ARProjectile::BeginPlay()
{
	Super::BeginPlay();//
	float randx = FMath::RandRange(1, 10) % 2 == 0 ? -5 : 5;
	float randy = FMath::RandRange(1, 10) % 2 == 0 ? -5 : 5; 
	//FVector(randx, randy, 0);
	//SetActorRotation(FQuat::MakeFromEuler(FVector(0, 0, 90)));
	//RSphereComponent->AddForce( GetWorld()->GetFirstPlayerController()->GetPawn()-> GetActorForwardVector() *5000000);
}

void ARProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARProjectile::OnActorBeginOverlapCallback(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Enemy"))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,  "Enemy " + OtherActor->GetName());
		ARAIEnemy* Enemy= Cast<ARAIEnemy>(OtherActor);
		if (Enemy)
		{
			Enemy->ChangeHealth(.01);
		}
	}


	


	//UE_LOG(LogTemp, Error, TEXT("Horizontal %s %s"), *OverlappedActor->GetName(), *OtherActor->GetName());

}



void ARProjectile::OnCompBeginOverlapCallback(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Error, TEXT("Horizontal %s %s"), *OverlappedComponent->GetName(), *OtherActor->GetName());

}



