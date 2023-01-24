// Fill out your copyright notice in the Description page of Project Settings.


#include "bonusCapsule.h"

AbonusCapsule::AbonusCapsule()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Materials/bonus/M_hp.M_hp'"));
	SM_capsuleFactory->SetMaterial(0, MaterialCapsule.Object);
}

void AbonusCapsule::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 1;
}
