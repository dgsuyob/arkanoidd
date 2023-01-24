// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "capsuleFactory.h"
#include "speedCapsule.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AspeedCapsule : public AcapsuleFactory
{
	GENERATED_BODY()
public:
	AspeedCapsule();
protected:
	virtual void BeginPlay() override;
};
