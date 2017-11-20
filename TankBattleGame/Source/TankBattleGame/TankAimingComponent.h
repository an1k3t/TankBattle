// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UMeshBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLEGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// Called when the game starts
	virtual void BeginPlay() override;
	//Pointers
	UMeshBarrel *Barrel = nullptr;
	UStaticMeshComponent *Turret = nullptr;
	//Sets the barrel pointer
	void SetBarrel(UMeshBarrel *BarrelToSet);
	//Sets the turret pointer
	void SetTurret(UStaticMeshComponent *TurretToSet);
	//Aims the cannon
	void CalcProjectile(FVector);
private:
	//Variables
	FVector CurShotVelocity;
	float ShotForce = 10000;
	FVector ShotStartLoc;
	float ElevationDirection;
};
