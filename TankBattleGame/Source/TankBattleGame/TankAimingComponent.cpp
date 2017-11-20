// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "MeshBarrel.h"
#include "MeshTurret.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	//Enables Tick function
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

//Sets the barrel pointer
void UTankAimingComponent::SetBarrel(UMeshBarrel *BarrelToSet)
{
	Barrel = BarrelToSet;
}

//Sets the turret pointer
void UTankAimingComponent::SetTurret(UMeshTurret *TurretToSet)
{
	Turret = TurretToSet;
}

//Calculates aiming direction & projectile path
void UTankAimingComponent::CalcProjectile(FVector AimLocation)
{
	//Sets the starting point of the projectile
	ShotStartLoc = Barrel->GetSocketLocation(FName("BarrelEnd"));
	//Calculate Projectile characteristics
	UGameplayStatics::SuggestProjectileVelocity(this, CurShotVelocity, ShotStartLoc, AimLocation, ShotForce, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace);
	//Changes the direction vector into a unit vector so it only determines a direction
	auto CurAimDirection = CurShotVelocity.GetSafeNormal().Rotation();
	//Aquires and stores the current direction of the barrel
	auto CurBarrelDirection = Barrel->GetForwardVector().Rotation();
	//Determines the direction the barrel needs to move 1 = up, -1 = down
	auto BarrelDirDiff = CurAimDirection - CurBarrelDirection;
	if ((BarrelDirDiff.Pitch) >= 1.0f) { ElevationDirection = 1.0f; }
	else  if ((BarrelDirDiff.Pitch) <= -1.0f) { ElevationDirection = -1.0f; }
	else { ElevationDirection = 0.0f; }
	//Adjusts barrel elevation acording to where crosshair is pointing
	Barrel->AimBarrel(ElevationDirection);
	//Acquires and stores the current turret direction
	auto CurTurretDirection = Turret->GetForwardVector().Rotation();
	//Determines the direction the turret needs to move 1 = right, -1 = left
	auto TurretDirDiff = CurAimDirection - CurTurretDirection;
	if ((TurretDirDiff.Yaw) >= 1.0f) { TurnDirection = 1.0f; }
	else  if ((TurretDirDiff.Yaw) <= -1.0f) { TurnDirection = -1.0f; }
	else { TurnDirection = 0.0f; }
	//Adjusts turret rotation acording to where crosshair is pointing
	if (FMath::Abs(TurretDirDiff.Yaw) < 180) { Turret->AimTurret(TurnDirection); }
	else { Turret->AimTurret(-TurnDirection); }

}