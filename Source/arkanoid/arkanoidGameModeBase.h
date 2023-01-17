// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "arkanoidGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AarkanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public: 
	

protected:
	virtual void BeginPlay();

public:
	virtual void Tick(float DeltaTime);
};
