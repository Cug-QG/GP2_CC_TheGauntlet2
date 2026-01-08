// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OrderReceiver.h"
#include "GameFramework/Actor.h"
#include "TimedObject.generated.h"

UCLASS()
class THEGAUNTLET2_API ATimedObject : public AActor, public IOrderReceiver
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimedObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void NativeReact(float ActivationTime) override;
	
	FTimerHandle TimerHandle_Activation;
	
	void Activate();
	
	void Deactivate();
};
