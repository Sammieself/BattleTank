// Hello my doggies.
#include "TankTrack.h"
#include "BattleTank.h"

void UTankTrack::SetThrottle(float Throttle) {
    auto ForceApplied = GetForwardVector() * Throttle * TrackDrivingMaxForce;
    auto ForceAppliedLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceAppliedLocation);
}