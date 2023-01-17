// Fill out your copyright notice in the Description page of Project Settings.


#include "countBrick.h"
#include "Brick.h"


// Sets default values
AcountBrick::AcountBrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (!ABrick::execOnOverlapBegin)
	count++;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("ladrillos golpeados: %d",count)));
}

// Called when the game starts or when spawned
void AcountBrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcountBrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

