// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "SpaceInvaders.h"
#include "SpaceInvadersGameMode.h"
#include "Components/BoxComponent.h"



// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UShapeComponent* RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Enemy"));
	RootComponent = RootBox;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += (MoveDirection * Speed * DeltaTime);
	SetActorLocation(NewLocation);

	if (NewLocation.X < DestroyPlacement)
	{
		DeleteThisEnemy = true;
	}
}

void AEnemy::ImHit()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy hit!"))
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	DeleteThisEnemy = true;
}
