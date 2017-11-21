#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MeshCannonShell.generated.h"

UCLASS()
class TANKBATTLEGAME_API AMeshCannonShell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeshCannonShell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UProjectileMovementComponent *CannonShellManager = nullptr;
	UFUNCTION(BlueprintCallable)
	void LaunchShell(float ShotForce);
};