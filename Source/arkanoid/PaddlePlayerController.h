// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */
class ABall;
UCLASS()
class ARKANOID_API APaddlePlayerController : public APlayerController
{
	GENERATED_BODY()
		APaddlePlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override;
public:
	void SpawnNewBall();
protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);
	UFUNCTION()
		void Launch();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

};
