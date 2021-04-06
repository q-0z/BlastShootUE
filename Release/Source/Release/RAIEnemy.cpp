

#include "RAIEnemy.h"

ARAIEnemy::ARAIEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	RCapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = RCapsuleComponent;
	RStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RStaticMeshComponent->AttachTo(RootComponent);
	RWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	RWidgetComponent->AttachTo(RStaticMeshComponent);
}

void ARAIEnemy::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, this, &ARAIEnemy::Test, 1, false);
}

void ARAIEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	FVector A = GetActorLocation();
	FVector B = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	 A = FMath::Lerp(A, B, DeltaTime);
	SetActorLocation(FVector(A.X,A.Y,GetActorLocation().Z));
	if (RWidgetComponent)
	{
		FVector WidgetLoc = RWidgetComponent->GetComponentLocation();
		FVector CamLoc = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();

		RWidgetComponent->SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(WidgetLoc, CamLoc));

		auto EnemyWidgetClass = Cast<UREnemyWidget>(RWidgetComponent->GetUserWidgetObject());
		if (EnemyWidgetClass && EnemyWidgetClass->RProgressBar->Percent<=0)
		{
			Destroy();
		}
	}


	//UE_LOG(LogTemp, Warning, TEXT("%s --%d"), *A.ToString(), DeltaTime);
}

void ARAIEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARAIEnemy::ChangeHealth(float value)
{
	if (RWidgetComponent)
	{
		auto EnemyWidgetClass = Cast<UREnemyWidget>(RWidgetComponent->GetUserWidgetObject());
		if (EnemyWidgetClass)
		{

			EnemyWidgetClass->ChangeProgressBarValue(value);
		}
	}
}

void ARAIEnemy::RDestroy()
{
	Destroy();
}

void ARAIEnemy::Test()   // thread test
{
	FTimerHandle timerHandle;
	//ChangeHealth(.1f);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Called");

	//GetWorldTimerManager().SetTimer(timerHandle, this, &ARAIEnemy::Test, 1, false);
}

