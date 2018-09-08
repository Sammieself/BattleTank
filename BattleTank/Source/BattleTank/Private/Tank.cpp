// Hello my doggies.
#include "Tank.h"
#include "BattleTank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponenet = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponenet->SetBarrelReference(BarrelToSet);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponenet->AimAt(HitLocation, LaunchSpeed);
}