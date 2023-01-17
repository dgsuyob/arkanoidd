// Fill out your copyright notice in the Description page of Project Settings.


#include "countPaddle.h"
#include "PaddlePlayerController.h"

// Sets default values
AcountPaddle::AcountPaddle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if(!APaddlePlayerController::Launch)
		count++;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("ladrillos golpeados: %d", count)));
}

// Called when the game starts or when spawned
void AcountPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcountPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

