// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MeshBarrel.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLEGAME_API UMeshBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void AimBarrel(float);
private:
	float ElevationSpeed = 5.0f;
	float MaxElevation = 50.0f;
	float MinElevation = 0.0f;
};
