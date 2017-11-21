#include "MeshCannonShell.h"

// Sets default values
AMeshCannonShell::AMeshCannonShell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Add a default component to blueprint of specified type with specified name
	CannonShellManager = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Shell Manager"));
	CannonShellManager->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AMeshCannonShell::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMeshCannonShell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMeshCannonShell::LaunchShell(float ShotForce)
{
	CannonShellManager->SetVelocityInLocalSpace(FVector::ForwardVector * ShotForce);
	CannonShellManager->Activate();
}