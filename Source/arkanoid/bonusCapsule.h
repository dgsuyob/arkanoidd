// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "capsuleFactory.h"
#include "bonusCapsule.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AbonusCapsule : public AcapsuleFactory
{
	GENERATED_BODY()
public:
	AbonusCapsule();

protected:

	virtual void BeginPlay() override;
};
