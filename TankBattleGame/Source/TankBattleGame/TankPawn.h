// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class UTankAimingComponent;
class UMeshBarrel;
class UMeshTurret;
class AMeshCannonShell;
class UMeshTankTracks;

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
	//Sets the tracks reference, via TankAimingComponent
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTracks(UMeshTankTracks *LTrackToSet, UMeshTankTracks *RTrackToSet);
	//Shoots Cannon
	UFUNCTION(BlueprintCallable)
		void ShootCannon();
	//Creates a property in the Pawn BP to ref the projectile BP
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AMeshCannonShell> CannonShellBP;
	//Send Aim Info to TankAimingComponent
	void SetAimInfo(FVector);
private:
	//Pointers
	UTankAimingComponent *TankAimingComponent = nullptr;
	UMeshBarrel *Barrel = nullptr;
	UMeshTankTracks *LTrack = nullptr;
	UMeshTankTracks *RTrack = nullptr;
	//Variables
	FVector ShotStartLoc;
	FRotator ShotStartRot;
	float ShotForce = 10000;
	float ReloadTime = 0.1f;
	float LastShotTime = 0.0f;
	bool bReloaded;
};