// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Brick.h"
#include "capsuleOperator.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AcapsuleOperator : public ABrick
{
	GENERATED_BODY()
public:
	virtual AcapsuleFactory* CreateCapsule(int NumCapsule, FVector Location) override;
};
