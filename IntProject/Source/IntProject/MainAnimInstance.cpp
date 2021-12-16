// Fill out your copyright notice in the Description page of Project Settings.
/** @file MainAnimInstance.cpp

 *  @brief This file has functionallity for Main character animations.

 *  @author Oscar Fox

 *  @bug No known bugs.

 */

#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Main.h"


void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner(); // get owner of animation instance
		if (Pawn)
		{
			Main = Cast<AMain>(Pawn);
		}
	}
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	// Assign PawnOwner to Pawn if true
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	// Get animation properties from Pawn
	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();

		if (Main == nullptr)
		{
			Main = Cast<AMain>(Pawn);
		}
	}
}