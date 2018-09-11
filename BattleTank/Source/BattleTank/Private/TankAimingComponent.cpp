// Hello my doggies.
#include "TankAimingComponent.h"
#include "BattleTank.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}

//void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {
//	if (!TurretToSet) { return; }
//	Turret = TurretToSet;
//}

//void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
//	if (!BarrelToSet) { return; }
//	Barrel = BarrelToSet;
//}

void UTankAimingComponent::Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet) {
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay() {Super::BeginPlay();}
// Called every frame
//void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		);
	if (bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *TankName, *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
	}
	else {
		// No aim solution found
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	if (!Barrel || !Turret) {return;}
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Turret->Rotate(DeltaRotator.Yaw);
	Barrel->Elevate(DeltaRotator.Pitch);
}
