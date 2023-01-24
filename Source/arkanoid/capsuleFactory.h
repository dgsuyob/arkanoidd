// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "capsuleFactory.generated.h"

UCLASS()
class ARKANOID_API AcapsuleFactory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AcapsuleFactory();
	float xMovement;
	float speed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_capsuleFactory; /

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision; 

	int NumCapsule; 

	FString CapsuleName; 

	UFUNCTION() //Campo de colision
		void ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE int GetIntCapsuleHelps() const { return NumCapsule; } 

	FORCEINLINE FString GetCapsuleNameAntiHelps() const { return CapsuleName; } 

	

};
