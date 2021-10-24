// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// initialize static mesh component to StaticMesh pointer
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	// default initialize floater locations using FVector overload constructor
	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f, 0.0f, 0.0f);

	InitialDirection = FVector(0.0f, 0.0f, 0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	// Get location of Floater and store in PlacedLocation
	PlacedLocation = GetActorLocation();


	if (bInitializeFloaterLocations)
	{
		// Begin play method with vector variable as parameter
		SetActorLocation(InitialLocation);
	}


}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FHitResult HitResult;

		// Change location of actor every tick (frame)
		AddActorLocalOffset(InitialDirection, false, &HitResult);
	}

}

