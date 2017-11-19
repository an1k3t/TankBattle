// Fill out your copyright notice in the Description page of Project Settings.

#include "AITankController.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
}

//Called every second
void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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