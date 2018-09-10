// Hello my doggies.
#include "TankMovementComponent.h"
#include "BattleTank.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
    if (!LeftTrackToSet || !RightTrackToSet) {return;}
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
    UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"), Throw);

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}