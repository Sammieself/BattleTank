// Hello my doggies.
#pragma once
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponenet = nullptr;

private:
	ATank();
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 6000;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	double LastFireTime = 0;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	// Local barrel reference for projectile
	UTankBarrel* Barrel = nullptr; // to do remove
};
