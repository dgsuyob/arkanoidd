// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "paddle.generated.h"
class UFloatingPawnMovement;
UCLASS()
class ARKANOID_API Apaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Apaddle();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Paddle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void MoveHorizontal(float AxisValue);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
