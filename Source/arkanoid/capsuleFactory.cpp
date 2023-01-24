
#include "capsuleFactory.h"
#include "Paddle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AcapsuleFactory::AcapsuleFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("StaticMesh'/Game/Meshes/shape.shape'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Materials/bonus/materialCapsule.materialCapsule'"));

	SM_capsuleFactory = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("capsuleFactory"));
	SM_capsuleFactory->SetStaticMesh(CapsuleMesh.Object);
	SM_capsuleFactory->SetMaterial(0, MaterialCapsule.Object);
	SetRootComponent(SM_capsuleFactory);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(12.f, 12.f, 12.f));
	BoxCollision->SetHiddenInGame(true);
	BoxCollision->SetupAttachment(GetRootComponent());


	xMovement = 1.0f;
	speed = 25;

}


// Called when the game starts or when spawned
void AcapsuleFactory::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentHit.AddDynamic(this, &AcapsuleFactory::ComponentHit);

}

void AcapsuleFactory::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("La Capsula tuvo un hit")));


}

// Called every frame
void AcapsuleFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Creo la direccion y el vector movimiento
	const FVector MoveDirection = FVector(0.0f, 0.0f, -xMovement);
	const FVector Movement = MoveDirection * speed * DeltaTime;

	if (Movement.SizeSquared() > 0.0f)
	{
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, FRotator::ZeroRotator, false, &Hit);

		if (GetActorLocation().Z <= -20.0f) {
			this->Destroy();
		}
	}
}