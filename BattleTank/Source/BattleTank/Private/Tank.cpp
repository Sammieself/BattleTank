// Hello my doggies.
#include "Tank.h"
#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponenet = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}
// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) {
	TankAimingComponenet->SetTurretReference(TurretToSet);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponenet->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponenet->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire() {
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded) {
	// Spawn a projectile at the socket location
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
	);
	Projectile->LaunchProjectile(LaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
	}
} 