// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/PlatformsHandler.h"

// Sets default values
APlatformsHandler::APlatformsHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformsHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformsHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = FRotator(0.f, RotationSpeed * DeltaTime, 0.f);
	AddActorLocalRotation(NewRotation);
}

