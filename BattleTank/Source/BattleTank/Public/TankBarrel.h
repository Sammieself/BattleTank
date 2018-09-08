// Hello my doggies.
#pragma once
//#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesElevation = 30;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MinDegreesElevation = 0;
};
