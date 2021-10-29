// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"


void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner(); // get owner of animation instance
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
	}
}