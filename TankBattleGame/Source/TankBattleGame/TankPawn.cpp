// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPawn.h"
#include "TankAimingComponent.h"
#include "MeshBarrel.h"

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


//Delegates the act of seeting the turret ref to TankAimingComponet
void ATankPawn::SetTurret(UStaticMeshComponent *TurretToSet)
{
	TankAimingComponent->SetTurret(TurretToSet);
}

//Delegates the act of seeting the barrel ref to TankAimingComponet
void ATankPawn::SetBarrel(UMeshBarrel *BarrelToSet)
{
	TankAimingComponent->SetBarrel(BarrelToSet);
}

//Delegates the management of aiming and firing the barrel to the TankAimingComponent class
void ATankPawn::SetAimInfo(FVector AimInfo)
{
	TankAimingComponent->CalcProjectile(AimInfo);
}