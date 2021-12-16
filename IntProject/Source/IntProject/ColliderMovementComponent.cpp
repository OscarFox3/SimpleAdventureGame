// Fill out your copyright notice in the Description page of Project Settings.
/** @file ColliderMovementComponent.cpp

 *  @brief This file has functionallity for collider movement of in-game components.

 *  @author Oscar Fox

 *  @bug No known bugs.

 */

#include "ColliderMovementComponent.h"

// override TickComponent
void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// Call to parent of TickComponent
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Conditional to check if 
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	// how much to move in a given frame
	// consume, clear contents of InputVector
	// clamp vector, scale to size 1.0
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f);

	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		// declare struct hit
		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

		// condition if hit something
		// slide along side of it
		if (Hit.IsValidBlockingHit())
		{
			// where to move pawn if slide along surface
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
			UE_LOG(LogTemp, Warning, TEXT("Valid Blocking Hit"));
		}
	}
}