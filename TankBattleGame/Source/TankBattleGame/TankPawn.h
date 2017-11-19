// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "TankPawn.generated.h"

UCLASS()
class TANKBATTLEGAME_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Sets the barrel reference, via TankAimingComponent
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UStaticMeshComponent *BarrelToSet);
private:
	//Pointer to effeciently access TankAimingComponent
	UTankAimingComponent *TankAimingComponent = nullptr;
	float CurShotVelocity;
	float ShotForce = 5000;
	FVector ShotStartLoc;
};
