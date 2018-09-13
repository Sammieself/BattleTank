// Hello my doggies.
#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay() {Super::BeginPlay();}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	if (AimingComponent->GetFiringState() == EFiringState::Locked) {
		AimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn)	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}
}

void ATankAIController::OnPossedTankDeath() {
	if (!ensure(GetPawn())) { return; } // TODO remove ensure if ok
	GetPawn()->DetachFromControllerPendingDestroy();
}