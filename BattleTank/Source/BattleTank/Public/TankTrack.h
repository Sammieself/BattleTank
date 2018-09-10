// Hello my doggies.
#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Max Force per track, in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float TrackDrivingMaxForce = 40000000; // Assume 40T tank and 1g accelleration

};
