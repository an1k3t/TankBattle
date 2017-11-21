// Fill out your copyright notice in the Description page of Project Settings.

#include "AITankController.h"
#include "TankPawn.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
}

//Called every second
void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SendAimLoc();

}

ATankPawn *AAITankController::GetControlledTank() const
{
	return Cast<ATankPawn>(GetPawn());
}

ATankPawn *AAITankController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATankPawn>(PlayerPawn);
}

void AAITankController::SendAimLoc()
{
	//Sends location info of where the AI is aiming(the player) to TankPawn
	GetControlledTank()->SetAimInfo(GetPlayerTank()->GetActorLocation());
	//Fires cannon 
	GetControlledTank()->ShootCannon();
}