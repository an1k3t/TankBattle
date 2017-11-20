// Fill out your copyright notice in the Description page of Project Settings.

#include "MeshBarrel.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

void UMeshBarrel::AimBarrel(float ElevationDirection)
{
	auto ElevationChange = ElevationDirection* (ElevationSpeed * GetWorld()->DeltaTimeSeconds);
	auto NewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(NewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(ClampedElevation, 0.0f, 0.0f));
}