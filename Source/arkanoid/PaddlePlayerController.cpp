// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "paddle.h"
#include "Ball.h"
APaddlePlayerController::APaddlePlayerController() {

}
void APaddlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddlePlayerController::MoveHorizontal);

	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddlePlayerController::Launch);
	SpawnNewBall();
}
void APaddlePlayerController::SpawnNewBall()
{
	if (!MyBall) {
		MyBall = nullptr;
	}

	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SpawnInfo);
	}

}
void APaddlePlayerController::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void APaddlePlayerController::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<Apaddle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}

}

void APaddlePlayerController::Launch()
{
	MyBall->Launch();
}

