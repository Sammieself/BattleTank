// Hello my doggies.
#pragma once
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM(BlueprintType)
enum class EFiringState : uint8 {
	Locked UMETA(DisplayName="Locked"),
	Aiming UMETA(DisplayName="Aiming"),
	Reloading UMETA(DisplayName="Reloading"),
	OutOfAmmo UMETA(DisplayName="OutOfAmmo")
};

// Forward Declaration
class UTankTurret;
class UTankBarrel;
class AProjectile;

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();
	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsLeft() const;

	EFiringState GetFiringState() const;
	void AimAt(FVector HitLocation);
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 7000;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;
	int RoundsLeft = 3;
	FVector AimDirection;

	UTankAimingComponent();
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();
};
