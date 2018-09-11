// Hello my doggies.
#include "Tank.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank() {
	PrimaryActorTick.bCanEverTick = false;
}
// Called when the game starts or when spawned
void ATank::BeginPlay() {Super::BeginPlay();}

void ATank::AimAt(FVector HitLocation) {
	if (!ensure(TankAimingComponenet)) { return; }
	TankAimingComponenet->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire() {
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded) {
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