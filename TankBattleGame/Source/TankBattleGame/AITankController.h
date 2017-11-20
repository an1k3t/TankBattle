// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "AITankController.generated.h"

class ATankPawn;

UCLASS()
class TANKBATTLEGAME_API AAITankController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	ATankPawn *GetControlledTank() const;
	ATankPawn *GetPlayerTank() const;
	void SendAimLoc();
};
