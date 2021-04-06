
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "RProjectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RPlayerController.h"
#include "RProjectile.h"
#include "QObjectPooler.h"

#include "RPawn.generated.h"

UCLASS()
class RELEASE_API ARPawn : public APawn
{
	GENERATED_BODY()

public:
	ARPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCapsuleComponent* RCapsuleComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* RSphereComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* RStaticMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USpringArmComponent* RSpringArmComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* RCameraComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* RStaticMeshBarrelComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* RSceneComponent;


	void MoveRightP();
	void MoveRightR();
	void MoveLeftP();
	void MoveLeftR();

	void MoveVertical(float axisValue);
	void MoveHorizontal(float axisValue);
	void RotationX(float axisValue);

	void DelayTimer();

	void MKey();
	void XAxisKey(float val);

	FVector RPawnPosition;

	bool IsMovingRight,IsMovingLeft,IsMovingUp,IsMovingDown;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<ARProjectile> ProjectileClass;

	AActor* RProjectileToSpawn;

	int m=0;
	int i = 0;

	//UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AQObjectPooler* ObjectPooler;

	void LateEnqueue(AActor * Actor);
};
