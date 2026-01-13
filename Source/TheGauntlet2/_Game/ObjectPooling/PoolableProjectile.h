// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPoolInterface.h"
#include "ObjectPoolSubsystem.h"
#include "GameFramework/Actor.h"
#include "PoolableProjectile.generated.h"

UCLASS()
class THEGAUNTLET2_API APoolableProjectile : public AActor, public IObjectPoolInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoolableProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NativeActivate(FObjectPoolActivationData ObjectPoolData) override;
	
	virtual void NativeDeactive() override;
	
	FTimerHandle TimerHandle;
	
	UObjectPoolSubsystem* PoolSubsystem;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PoolableObjectData")
	float speed = 1000;
};
