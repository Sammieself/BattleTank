// Hello my doggies.
#pragma once
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

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
	virtual void BeginPlay() override;
	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
	void DriveTrack();
	float CurrentThrottle = 0;
};