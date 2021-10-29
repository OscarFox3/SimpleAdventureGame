// Fill out your copyright notice in the Description page of Project Settings.


#include "Collider.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ColliderMovementComponent.h"


// Sets default values
ACollider::ACollider()
{
 	// Set this pawn to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Creating a sphere comonpent and set as root
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);

	// Set collision radius for sphere component
	SphereComponent->InitSphereRadius(40.f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// Set a mesh to the root component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	
	// If ConstructorHelpers::ObjectFinder finds a static mesh at the path
	if (MeshComponentAsset.Succeeded())
	{
		// Member variable Object of StaticMesh is set to MeshComponent
		MeshComponent->SetStaticMesh(MeshComponentAsset.Object);
		// MeshComponent is centered with respect to collison sphere component
		MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
		MeshComponent->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));
	}

	// Create SpringArm component with rotation
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// Create camera and attach to SpringArm socket
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// Create collider component for root
	OurMovementComponent = CreateDefaultSubobject<UColliderMovementComponent>(TEXT("OurMovementComponent"));
	OurMovementComponent->UpdatedComponent = RootComponent;

	CameraInput = FVector2D(0.f, 0.f);

	// AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ACollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Set actor rotation from camera input
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += CameraInput.X;
	SetActorRotation(NewRotation);
	
	// Set a new SpringArm rotation
	FRotator NewSpringArmRotation = SpringArm->GetComponentRotation();
	// Ensure NewSpringArmRotation pitch will be angled 
	NewSpringArmRotation.Pitch = FMath::Clamp(NewSpringArmRotation.Pitch += CameraInput.Y, -80.f, -15.f);

	// SpringArm rotation with respect to world axis
	SpringArm->SetWorldRotation(NewSpringArmRotation);

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind input from keyboard
	PlayerInputComponent->BindAxis(TEXT("MoveFoward"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);

	// Bind input from mouse
	PlayerInputComponent->BindAxis(TEXT("CameraPitch"), this, &ACollider::PitchCamera);
	PlayerInputComponent->BindAxis(TEXT("CameraYaw"), this, &ACollider::YawCamera);

}

// Move forward function for collider pawn
void ACollider::MoveForward(float input)
{
	FVector Forward = GetActorForwardVector();

	if (OurMovementComponent)
	{
		// Scale forward movement component by user input
		OurMovementComponent->AddInputVector(Forward * input);
	}
}

// Move right function for collider pawn
void ACollider::MoveRight(float input)
{
	FVector Right = GetActorRightVector();

	if (OurMovementComponent)
	{
		OurMovementComponent->AddInputVector(Right * input);
	}
}

// Function for camera input from mouse x axis
void ACollider::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

// Function for camera input from mouse y axis
void ACollider::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

// 
UPawnMovementComponent* ACollider::GetMovementComponent() const
{
	// derive from UPawn Movement Component
	return OurMovementComponent;
}
