// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Brick.h"
#include "strangeBrick.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AstrangeBrick : public ABrick
{
	GENERATED_BODY()
		AstrangeBrick();
	
public:
	virtual void Tick(float DeltaTime);
	virtual void behavior();
};
