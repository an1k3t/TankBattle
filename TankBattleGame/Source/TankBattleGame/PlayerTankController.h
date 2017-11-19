// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPawn.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "PlayerTankController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLEGAME_API APlayerTankController : public APlayerController
{
	GENERATED_BODY()

public:
		APlayerTankController();
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		FHitResult GetAimInfo() const;
private:
		ATankPawn *GetControlledTank() const;
		void AimCannon();
		float AimXLoc = 0.5f;
		float AimYLoc = 0.34f;
		float RangeLimit = 1000000.0f;
};
