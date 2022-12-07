// Fill out your copyright notice in the Description page of Project Settings.


#include "paddle.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
Apaddle::Apaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));
	RootComponent = SM_Paddle;

	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhysicActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

}

// Called when the game starts or when spawned
void Apaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

void Apaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0), 1.0f, false);
}

// Called every frame
void Apaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Apaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

