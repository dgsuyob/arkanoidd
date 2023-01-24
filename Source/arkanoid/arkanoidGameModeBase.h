// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Brick.h"
#include "arkanoidGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class ARKANOID_API AarkanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public: 
private:
	class ABrick* Brick; //Brick normal


protected:
	virtual void BeginPlay();

public:
	virtual void Tick(float DeltaTime);
};
