// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float MoveDistance = 0;

	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = -1;

	UPROPERTY(EditAnywhere)
	bool MyBool = false;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(0, 0, 0);

	FVector CurrentLocation;
	
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn();
	float GetDistanceMove();

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity;
};
