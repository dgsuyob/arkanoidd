// Copyright Epic Games, Inc. All Rights Reserved.


#include "arkanoidGameModeBase.h"
#include "strangeBrick.h"
void AarkanoidGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	AstrangeBrick* strangeBrick = GetWorld() -> SpawnActor<AstrangeBrick>(AstrangeBrick::StaticClass());
	lad = strangeBrick;
	strangeBrick->behavior();

}

void AarkanoidGameModeBase::Tick(float DeltaTime)
{
}
