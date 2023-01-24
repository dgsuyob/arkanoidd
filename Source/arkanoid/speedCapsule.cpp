// Fill out your copyright notice in the Description page of Project Settings.


#include "speedCapsule.h"

AspeedCapsule::AspeedCapsule()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Materials/bonus/M_speed.M_speed'"));
	SM_capsuleFactory->SetMaterial(0, MaterialCapsule.Object);
}

void AspeedCapsule::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 2;
}