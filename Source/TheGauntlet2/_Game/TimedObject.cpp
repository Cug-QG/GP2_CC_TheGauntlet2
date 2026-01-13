// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/TimedObject.h"

// Sets default values
ATimedObject::ATimedObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimedObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimedObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ATimedObject::NativeReact(float ActivationTime)
{
	IOrderReceiver::NativeReact(ActivationTime);
	
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Black, "Opening");
	
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();

	if (TimerManager.IsTimerActive(TimerHandle_Activation))
	{
		TimerManager.ClearTimer(TimerHandle_Activation);
	}

	Activate();
	
	TimerManager.SetTimer(
		TimerHandle_Activation,
		this,
		&ATimedObject::Deactivate,
		ActivationTime,
		false
	);
}

void ATimedObject::Activate()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Black, "Opened");
	
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
}

void ATimedObject::Deactivate()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Black, "Closed");
	
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);
}

