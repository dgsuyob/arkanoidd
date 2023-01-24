// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine.h"
#include "Ball.h"
#include "capsuleOperator.h"
#include "Brick.h"
#include "paddle.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMesh(TEXT("StaticMesh'/Game/Materials/bonus/SM_Brick.SM_Brick'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialMesh(TEXT("Material'/Game/Materials/ColorRandom.ColorRandom'"));
	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetStaticMesh(BrickMesh.Object);
	SetRootComponent(SM_Brick);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.5f, 12.0f, 12.0f));
	BoxCollision->SetupAttachment(GetRootComponent());

	if (MaterialMesh.Object != NULL) {
		_Dynamic = (UMaterial*)MaterialMesh.Object;
	}

	HabilitadoCreacionCapsulas = false;

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	if (_Dynamic) {
		MaterialInstance = UMaterialInstanceDynamic::Create(_Dynamic, this);
	}

	if (MaterialInstance) {
		SM_Brick->SetMaterial(0, MaterialInstance);
	}
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);
	}

}
void ABrick::CreateCapsule(FVector Location)
{
	int RandCapsules = FMath::RandRange(1, 6);
	ABrick* CapsuleCreator = GetWorld()->SpawnActor<AcapsuleOperator>(AcapsuleOperator::StaticClass(), FVector(0.0f, 0.0f, -100.0f), FRotator::ZeroRotator);
	AcapsuleFactory* Capsule = CapsuleCreator->OrdenCapsule(RandCapsules, Location);
}

void ABrick::DestroyBrick()
{
	ContBricksLevel(1);
	this->Destroy();

	int RandScore = FMath::RandRange(1, 5);
	Apaddle* Paddle = Cast<Apaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HabilitadoCreacionCapsulas = FMath::FRandRange(0, 9) <= 4 ? true : false;


}


AcapsuleFactory* ABrick::OrdenCapsule(int NumCategory, FVector Spawn)
{
	AcapsuleFactory* Capsules = CreateCapsule(NumCategory, Spawn);
	return Capsules;
}

AcapsuleFactory* OrdenCapsule(int NumCategory, FVector Spawn)
{
	return nullptr;
}
void ABrick::ContBricksLevel(int _Cont)
{
	BricksLevel = BricksLevel - _Cont;
}