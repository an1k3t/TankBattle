// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class UTankAimingComponent;
class UMeshBarrel;
class UMeshTurret;
class AMeshCannonShell;

UCLASS()
class TANKBATTLEGAME_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Sets the turret reference, via TankAimingComponent
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurret(UMeshTurret *TurretToSet);
	//Sets the barrel reference, via TankAimingComponent
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrel(UMeshBarrel *BarrelToSet);
	//Send Aim Info to TankAimingComponent
	void SetAimInfo(FVector);
	//Shoots Cannon
	UFUNCTION(BlueprintCallable)
		void ShootCannon();
	//Creates a property in the Pawn BP to ref the projectile BP
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AMeshCannonShell> CannonShellBP;
private:
	//Pointers
	UTankAimingComponent *TankAimingComponent = nullptr;
	UMeshBarrel *Barrel = nullptr;
	//Variables
	FVector ShotStartLoc;
	FRotator ShotStartRot;
	float ShotForce = 10000;
	float ReloadTime = 2;
	double LastShotTime = 0.0;
	bool bReloaded;
};