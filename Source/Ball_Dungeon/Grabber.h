// Copyright Vacuda 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

struct PlayerViewPointStruct 
{
	FVector PlayerViewPoint_Location;
	FRotator PlayerViewPoint_Rotation;
	FVector LineTraceEnd;
	FHitResult HitResult;
	UPrimitiveComponent* ComponentToGrab = nullptr;
	FRotator ObjectRotation;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALL_DUNGEON_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:

	PlayerViewPointStruct VP_Structure;

	UPROPERTY(EditAnywhere)
	float Reach = 200.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetInputComponentAndBindings();
	void BuildPlayerViewPointStructure();	
};
