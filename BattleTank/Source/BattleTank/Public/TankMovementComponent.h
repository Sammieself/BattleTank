// Hello my doggies.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible from driving the tank traks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(Blueprintcallable, Category = Setup)
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	UFUNCTION(Blueprintcallable, Category = Input)
	void IntendMoveForward(float Throw);

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
