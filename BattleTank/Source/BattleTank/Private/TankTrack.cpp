// Hello my doggies.
#include "TankTrack.h"
#include "BattleTank.h"

void UTankTrack::SetThrottle(float Throttle) {
    auto Time = GetWorld()->GetTimeSeconds();
    auto Name = GetName();
    auto ForceApplied = GetForwardVector() * Throttle * TrackDrivingMaxForce;
    auto ForceAppliedLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    UE_LOG(LogTemp, Warning, TEXT("%f: %s"), Throttle, *Name);
    TankRoot->AddForceAtLocation(ForceApplied, ForceAppliedLocation);
}