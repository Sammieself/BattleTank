// Hello my doggies.
#pragma once
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController {
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	// How close can the AI tank get
	float AcceptanceRadius = 5000;
};
