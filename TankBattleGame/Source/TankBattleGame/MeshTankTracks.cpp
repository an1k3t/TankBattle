// Fill out your copyright notice in the Description page of Project Settings.

#include "MeshTankTracks.h"
#include "GameFramework/Actor.h"

void UMeshTankTracks::MoveTracks(float MoveSpeed)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: %f"), *Name,  MoveSpeed);
	//Calculates neccesary force to be applied
	auto ForceApplied = GetForwardVector() * MoveSpeed * TrackForce;
	//Acquires and stores tank body (force will be applied to this)
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//Applies force to tank body
	TankRoot->AddForceAtLocation(ForceApplied, GetComponentLocation());
}