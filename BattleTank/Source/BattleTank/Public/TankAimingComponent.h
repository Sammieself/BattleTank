// Hello my doggies.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	UStaticMeshComponent* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};