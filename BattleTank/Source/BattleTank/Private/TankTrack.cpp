// Hello my doggies.
#include "TankTrack.h"
#include "BattleTank.h"

void UTankTrack::SetThrottle(float Throttle) {
    auto Time = GetWorld()->GetTimeSeconds();
    auto Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%f: %s"), Throttle, *Name);
}