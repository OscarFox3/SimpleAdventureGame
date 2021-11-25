// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Pickup.generated.h"


/**
 * 
 */
UCLASS()
class INTPROJECT_API APickup : public AItem
{
	GENERATED_BODY()
	

public:

	APickup();

	// Coin count from pickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
	int32 CoinCount;

	// Overlap with coin function
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	// Overlap with coin end function
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};
