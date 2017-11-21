// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPawn.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"
#include "MeshBarrel.h"
#include "MeshTurret.h"
#include "MeshCannonShell.h"
#include "MeshTankTracks.h"

// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//Add a default component to blueprint of specified type with specified name
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//Delegates the act of seting the turret ref to TankAimingComponet
void ATankPawn::SetTurret(UMeshTurret *TurretToSet)
{
	TankAimingComponent->SetTurret(TurretToSet);
}

//Delegates the act of seting the barrel ref to TankAimingComponet
void ATankPawn::SetBarrel(UMeshBarrel *BarrelToSet)
{
	TankAimingComponent->SetBarrel(BarrelToSet);
	Barrel = BarrelToSet;
}

//Sets the tracks ref 
void ATankPawn::SetTracks(UMeshTankTracks *LTrackToSet, UMeshTankTracks *RTrackToSet)
{
	LTrack = LTrackToSet;
	RTrack = RTrackToSet;
}

//Delegates the management of aiming and firing the barrel to the TankAimingComponent class
void ATankPawn::SetAimInfo(FVector AimInfo)
{
	TankAimingComponent->CalcProjectile(AimInfo, ShotForce);
}

//Shoots Cannon
void ATankPawn::ShootCannon()
{
	//Fires the shell
	bReloaded = (GetWorld()->GetTimeSeconds() - LastShotTime) > ReloadTime;
	if (bReloaded)
	{
		//Sets the starting location of the projectile
		ShotStartLoc = Barrel->GetSocketLocation(FName("BarrelEnd"));
		//Sets the starting rotation of the projectile
		ShotStartRot = Barrel->GetSocketRotation(FName("BarrelEnd"));
		//Spawns Projectile at end of barrel
		auto Shell = GetWorld()->SpawnActor<AMeshCannonShell>(CannonShellBP, ShotStartLoc, ShotStartRot);
		//Fires Shell
		Shell->LaunchShell(ShotForce);
		//Updates LastShotTime
		LastShotTime = GetWorld()->GetTimeSeconds();
		//Plays Sound Effect

	}
}