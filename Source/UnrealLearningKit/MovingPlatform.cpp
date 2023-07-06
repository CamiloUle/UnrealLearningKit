// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("jajajaja: %f"), MoveDistance);
	
	FString MyString = GetName();

	UE_LOG(LogTemp, Error, TEXT("here is my string log: %s"), *MyString);
	UE_LOG(LogTemp, Warning, TEXT("jajajaja"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() 
{
	DistanceMoved = GetDistanceMove();
	return GetDistanceMove() > MoveDistance;
	
}

float AMovingPlatform::GetDistanceMove() 
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

