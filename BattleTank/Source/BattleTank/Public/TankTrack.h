// Hello my doggies.
#pragma once
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"
/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	// Max Force per track, in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float TrackDrivingMaxForce = 400000; // 400000

private:
	UTankTrack();
	// virtual void BeginPlay() override;
	// void ApplySidewaysForce();

	// UFUNCTION()
	// void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	TArray<class ASprungWheel*> GetWheels() const;
	void DriveTrack(float CurrentThrottle);
	// float CurrentThrottle = 0;
};