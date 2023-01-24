// Copyright Epic Games, Inc. All Rights Reserved.
#include "arkanoidGameModeBase.h"
#include "Kismet/GameplayStatics.h"
void AarkanoidGameModeBase::BeginPlay()
{
	

	
	FVector Spawn11(-100.0f, 0.0f, 350.0f);
	FVector Spawn12(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn11, FRotator::ZeroRotator);

		Spawn11 = Spawn11 + Spawn12;
	}

	
	FVector Spawn13(-100.0f, 0.0f, 330.0f);
	FVector Spawn14(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn13, FRotator::ZeroRotator);

		Spawn13 = Spawn13 + Spawn14;
	}

	
	FVector Spawn15(-100.0f, 0.0f, 310.0f);
	FVector Spawn16(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

		Spawn15 = Spawn15 + Spawn16;
	}

	FVector Spawn17(-100.0f, 0.0f, 290.0f);
	FVector Spawn18(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn17, FRotator::ZeroRotator);

		Spawn17 = Spawn17 + Spawn18;
	}

	FVector Spawn19(-100.0f, 0.0f, 270.0f);
	FVector Spawn20(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn19, FRotator::ZeroRotator);

		Spawn19 = Spawn19 + Spawn20;
	}

}

void AarkanoidGameModeBase::Tick(float DeltaTime)
{
}
