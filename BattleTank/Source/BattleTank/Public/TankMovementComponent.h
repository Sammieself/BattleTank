// Hello my doggies.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * Responsible for driving the tank traks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent {
	GENERATED_BODY()
	
public:
	UFUNCTION(Blueprintcallable, Category = "Setup")
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(Blueprintcallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(Blueprintcallable, Category = "Input")
	void IntendTurnRight(float Throw);

private:
	// Called from pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
