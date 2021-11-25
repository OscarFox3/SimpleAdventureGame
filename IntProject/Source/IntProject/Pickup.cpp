// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "Main.h"


APickup::APickup()
{
	// Coin count value when picked up
	CoinCount = 1;
}

void APickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapBegin()"));

	if (OtherActor)
	{
		// casting
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			// Increment coins with count count
			Main->IncrementCoins(CoinCount);
			Main->PickupLocations.Add(GetActorLocation());

			// Destory asset after pickup
			Destroy();
		}
	}
}

void APickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Super type to OnOverlapEnd
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapEnd()"));

}