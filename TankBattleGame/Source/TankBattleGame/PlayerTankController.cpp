// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTankController.h"

APlayerTankController::APlayerTankController()
{
	//Enables the Tick() function
	PrimaryActorTick.bCanEverTick = true;
}

//Called once at the beginning
void APlayerTankController::BeginPlay()
{
	Super::BeginPlay();
}

//Called every second
void APlayerTankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimCannon();
}

//Acquires the pawn of the player
ATankPawn *APlayerTankController::GetControlledTank() const
{
	return Cast<ATankPawn>(GetPawn());
}

//Moves turret and barrel appropriately to aim at crosshair
void APlayerTankController::AimCannon()
{
	FVector HitLoc = GetAimInfo().Location;
}

//Acquire aim information
FHitResult APlayerTankController::GetAimInfo() const
{
	bool bWithinRange = false;
	int32 VPSizeX, VPSizeY;
	FVector2D CrossHairLoc;
	FVector RayStartLoc;
	FVector RayEndLoc;
	FHitResult Hit;
	FVector CannonRange;

	//Acquires viewport size and stores it
	GetViewportSize(VPSizeX, VPSizeY);
	//Finds Crosshair location on screen
	CrossHairLoc = FVector2D(VPSizeX * AimXLoc, VPSizeY * AimYLoc);
	//Acquires and stores direction crosshair is pointed in
	DeprojectScreenPositionToWorld(CrossHairLoc.X, CrossHairLoc.Y, RayStartLoc, RayEndLoc);
	//Sets the range of the cannon
	CannonRange = RayStartLoc + (RayEndLoc * RangeLimit);
	//Creates raycast for aiming
	GetWorld()->LineTraceSingleByChannel(Hit, RayStartLoc, CannonRange, ECollisionChannel::ECC_Visibility);

	return Hit;
}




