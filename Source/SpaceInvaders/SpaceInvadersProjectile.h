// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceInvadersProjectile.generated.h"

class UShapeComponent;

UCLASS(config=Game)
class ASpaceInvadersProjectile : public AActor
{
	GENERATED_BODY()

public:
	ASpaceInvadersProjectile();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere)
		float Speed = 4000.f;

	UPROPERTY(EditAnywhere)
		float TimeBeforeDestroy = 10.f;

	float TimeLived{ 0 };

	UPROPERTY(EditAnywhere)
		UShapeComponent* RootSphere = nullptr;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};

