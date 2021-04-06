

#include "RPawn.h"
#include "RPlayerSetting.h"
#include "EngineUtils.h"

ARPawn::ARPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	RSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = RSceneComponent;
	RCapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RCapsuleComponent->AttachTo(RSceneComponent);
	//RSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Spehere"));
	//RootComponent = RSphereComponent;
	//RSphereComponent->AttachTo(RootComponent);

	RStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RStaticMeshComponent->AttachTo(RCapsuleComponent);
	//RStaticMeshBarrelComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshBarrel"));
	//RStaticMeshBarrelComponent->AttachTo(RStaticMeshComponent);
	RSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	RSpringArmComponent->AttachTo(RCapsuleComponent);
	RCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	RCameraComponent->AttachTo(RSpringArmComponent);

	auto x=Cast<ARPlayerController>(Controller);
	if (x)
	{
		//x->SetVirtualJoystickVisibility(true);
		//UE_LOG(LogTemp, Error, TEXT("Vert ~~~~~~~~~~"));

	}

	//UGameplayStatics::getplayerc
	//Cast<ARPlayerController>(GetWorld()->GetFirstPlayerController())->SetVirtualJoystickVisibility(true);

}

void ARPawn::BeginPlay()
{
	Super::BeginPlay();
	RPawnPosition = GetActorLocation();
	FTimerHandle timerHandle;

	GetWorldTimerManager().SetTimer(timerHandle, this, &ARPawn::DelayTimer, .1f, false);

	//for (TObjectIterator<UObject> ObjectItr; ObjectItr; ++ObjectItr)
	//{
	//	// skip if this object is not associated with our current game world
	//

	//	UObject* Object = *ObjectItr;
	//	// ...
	//}
	//TActorIterator<AActor> Actr();
	for (TActorIterator<AQObjectPooler> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		// Follow iterator object to my actual actor pointer
		ObjectPooler =  *ActorItr;
		if (ObjectPooler)
		{
			ObjectPooler->Init();
		}
	}

	

}

void ARPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(RPawnPosition);
}

void ARPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("VerticalMove", this, &ARPawn::MoveVertical);
	PlayerInputComponent->BindAxis("HorizontalMove", this, &ARPawn::MoveHorizontal);

	PlayerInputComponent->BindAxis("RotateX", this, &ARPawn::RotationX);

	//PlayerInputComponent->BindKey(EKeys::M, IE_Pressed, this, &ARPawn::MKey);
	//PlayerInputComponent->BindAxisKey(EKeys::X,this, &ARPawn::XAxisKey);
}

void ARPawn::RotationX(float axisValue)
{

	RStaticMeshComponent->AddLocalRotation(FQuat::MakeFromEuler(FVector(0, 0, axisValue)));
	//GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,FString::FString("axis ")+FString::SanitizeFloat(axisValue));
	UE_LOG(LogTemp, Error, TEXT("AAB") );

}


void ARPawn::MoveVertical(float axisValue)
{
	if (axisValue == 0)return;
	else axisValue *= RPlayerSetting::GetPlayerSetting()->movementRate;

	//UE_LOG(LogTemp, Error, TEXT("Vert %f"), RPlayerSetting::GetPlayerSetting()->movementRate);
	RPawnPosition = FVector(GetActorLocation().X + axisValue, RPawnPosition.Y , RPawnPosition.Z );

}

void ARPawn::MoveHorizontal(float axisValue)
{
	if (axisValue == 0)return;
	else axisValue *= RPlayerSetting::GetPlayerSetting()->movementRate;

	//UE_LOG(LogTemp, Error, TEXT("Horizontal %f"), RPlayerSetting::GetPlayerSetting()->movementRate);
	RPawnPosition = FVector(RPawnPosition.X, GetActorLocation().Y + axisValue, RPawnPosition.Z);



	
	

}

void ARPawn::DelayTimer()
{
	FTimerHandle timerHandle;
	//int m = FMath::RandRange(-360, 360);
	UE_LOG(LogTemp, Error, TEXT("Calling: %d "),m);
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f,0.0f, 0.f);
	FActorSpawnParameters SpawnInfo;

	//auto SpawnedObj=GetWorld()->SpawnActor<AActor>(ProjectileClass, GetActorLocation(), Rotation, SpawnInfo);
	ARProjectile* projectile = Cast<ARProjectile>(ObjectPooler->DequeueObject());
	//ARProjectile * projectile= Cast<ARProjectile>(SpawnedObj);
	if (projectile && projectile!=nullptr )
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, RStaticMeshComponent->GetForwardVector().ToString());
		projectile->SetActorLocation(GetActorLocation());
		projectile->RSphereComponent->SetWorldRotation(FRotator (0.0f, 0.0f, 0.f));
		projectile->RSphereComponent->SetWorldLocation(GetActorLocation());
		projectile->RSphereComponent->SetRelativeRotation(Rotation);
		projectile->SetActorRotation(Rotation);
		projectile->SetActorHiddenInGame(false);
		projectile->SetActorTickEnabled(true);
		projectile->SetActorEnableCollision(true);
		projectile->RSphereComponent->AddForce(RStaticMeshComponent->GetForwardVector() * (FMath::RandRange(800000, 1000000)));
		ObjectPooler->EnqueueObject(projectile);

	}
	//SpawnedObj
	//SetActorRotation(FQuat::MakeFromEuler(FVector(0, 0, m > 360 ? m = 0 : m = m + 45)));
	//RStaticMeshComponent->AddLocalRotation(FQuat::MakeFromEuler(FVector(0, 0,  m = m + 10.f)));
	GetWorldTimerManager().SetTimer(timerHandle, this, &ARPawn::DelayTimer, FMath::RandRange(.1f,.1f), false);


}

void ARPawn::MKey()
{
	FTimerHandle timerHandle;

	GetWorldTimerManager().SetTimer(timerHandle, this, &ARPawn::DelayTimer, .1f,false);

}

void ARPawn::XAxisKey(float val)
{
}


