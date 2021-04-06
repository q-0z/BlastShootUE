
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RAIEnemy.h"

#include "RProjectile.generated.h"

UCLASS()
class RELEASE_API ARProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ARProjectile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* RSphereComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* RStaticMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* RSceneComponent;
	UFUNCTION()
	void OnActorBeginOverlapCallback(AActor* OverlappedActor,AActor* OtherActor);

	UFUNCTION()
		void OnCompBeginOverlapCallback(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
