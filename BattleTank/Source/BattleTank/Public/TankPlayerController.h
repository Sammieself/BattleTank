// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class UTankTankAimingComponent;
/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController {
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.333f;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.0f;

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	void SetPawn(APawn * InPawn);
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);
	UFUNCTION()
		void OnPossedTankDeath();
};