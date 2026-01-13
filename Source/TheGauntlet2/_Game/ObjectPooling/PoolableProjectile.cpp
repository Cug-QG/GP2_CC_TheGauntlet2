// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/ObjectPooling/PoolableProjectile.h"

#include "ProjectileData.h"

// Sets default values
APoolableProjectile::APoolableProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APoolableProjectile::BeginPlay()
{
	Super::BeginPlay();
	PoolSubsystem = GetWorld()->GetSubsystem<UObjectPoolSubsystem>();
}

// Called every frame
void APoolableProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorLocation(GetActorLocation() + (GetActorForwardVector() * DeltaTime * speed));
}

void APoolableProjectile::NativeActivate(FObjectPoolActivationData ObjectPoolData)
{
	IObjectPoolInterface::NativeActivate(ObjectPoolData);

	SetActorLocation(ObjectPoolData.ObjectPoolTransform.GetLocation());
	SetActorRotation(ObjectPoolData.ObjectPoolTransform.GetRotation());
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);
	
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	FTimerDelegate TimerDel;
	TimerDel.BindUObject(this, &APoolableProjectile::Deactivate);
	TimerManager.SetTimer(
		TimerHandle,
		TimerDel,
		3,
		false
	);
}

void APoolableProjectile::NativeDeactive()
{
	IObjectPoolInterface::NativeDeactive();
	
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
	PoolSubsystem->ReturnObjectToPool(GetClass(),this);
}

