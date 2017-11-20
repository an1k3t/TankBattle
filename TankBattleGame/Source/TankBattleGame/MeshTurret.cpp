// Fill out your copyright notice in the Description page of Project Settings.

#include "MeshTurret.h"
#include "GameFramework/Actor.h"

void UMeshTurret::AimTurret(float TurnDirection)
{
	auto RotationChange = TurnDirection * (TurnSpeed * GetWorld()->DeltaTimeSeconds);
	auto NewDirection = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0.0f, NewDirection, 0.0f));
}


