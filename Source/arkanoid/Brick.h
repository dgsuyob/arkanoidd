// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "capsuleFactory.h"
#include "Brick.generated.h"

static int BricksLevel = 70;

class UBoxComponent;
UCLASS()
class ARKANOID_API ABrick : public AActor
{
	GENERATED_BODY()
private:
	bool HabilitadoCreacionCapsulas; 
public:	
	
	ABrick();
	void ContBricksLevel(int _Cont); 
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;

	float SpeedModifierOnBounce = 1.01f;

	UPROPERTY()
		class UMaterialInstanceDynamic* MaterialInstance; 

	UPROPERTY()
		class UMaterialInterface* _Dynamic; 

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult);

	void CreateCapsule(FVector Location);

public:	
	
	virtual void Tick(float DeltaTime) override;

	void DestroyBrick();

	virtual AcapsuleFactory* CreateCapsule(int NumCapsule, FVector Location) PURE_VIRTUAL(ABrick::CreateCapsule, return nullptr;); 

	AcapsuleFactory* OrdenCapsule(int NumCategory, FVector Spawn); 
	
};
