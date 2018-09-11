// Hello my doggies.
#pragma once
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM(BlueprintType)
enum class EFiringState : uint8 {
	Locked UMETA(DisplayName="Locked"),
	Aiming UMETA(DisplayName="Aiming"),
	Reloading UMETA(DisplayName="Reloading")
};

// Forward Declaration
class UTankTurret;
class UTankBarrel;

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	//void SetTurretReference(UTankTurret* TurretToSet);
	//void SetBarrelReference(UTankBarrel* BarrelToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

	virtual void BeginPlay() override;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
