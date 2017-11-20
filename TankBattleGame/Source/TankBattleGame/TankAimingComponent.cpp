// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "MeshBarrel.h"

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

//Sets the barrel pointer
void UTankAimingComponent::SetTurret(UStaticMeshComponent *TurretToSet)
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
	auto DirectionDifference = CurAimDirection - CurBarrelDirection;
	if ((DirectionDifference.Pitch) > 1.0f)
	{
		ElevationDirection = 1.0f;
	}
	else
	{
		ElevationDirection = -1.0f;
	}
	//Adjusts barrel elevation acording to where crosshair is pointing
	Barrel->AimBarrel(ElevationDirection);
}