// Fill out your copyright notice in the Description page of Project Settings.


#include "capsuleOperator.h"
#include "capsuleFactory.h"
#include "bonusCapsule.h"
#include "speedCapsule.h"

AcapsuleFactory* AcapsuleOperator::CreateCapsule(int NumCapsule, FVector Location)
{
    FVector Spawn2(0.0f, 0.0f, -22.0f);

    if (NumCapsule == 1) {
        return GetWorld()->SpawnActor<AbonusCapsule>(Location + Spawn2, FRotator::ZeroRotator);
    }
    else if (NumCapsule == 2) {
        return GetWorld()->SpawnActor<AspeedCapsule>(Location + Spawn2, FRotator::ZeroRotator);
    }
   
    else return nullptr; 
}
