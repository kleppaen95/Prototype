// Copyright 1998-2017 Epic Games, Inc. All Rights Reserve

#include "SpaceInvadersProjectile.h"
#include "SpaceInvaders.h"
#include "Enemy.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ASpaceInvadersProjectile::ASpaceInvadersProjectile() 
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Bullet"));
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &ASpaceInvadersProjectile::OnOverlap);
}

void ASpaceInvadersProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ASpaceInvadersProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(NewLocation);

	TimeLived += DeltaTime;
	if (TimeLived > TimeBeforeDestroy)
	{
		this->Destroy();
	}
}

void ASpaceInvadersProjectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(AEnemy::StaticClass()))
	{
		Cast<AEnemy>(OtherActor)->ImHit();
		Destroy();
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplotionFX, GetTransform(), true);
	}

}