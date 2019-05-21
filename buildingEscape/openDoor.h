// Copyroght Ethan Walz 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "openDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UopenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UopenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void CloseDoor();

	void OpenDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;

	float LastDoorOpenTime;

	AActor* Owner; // The owning door

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
};
