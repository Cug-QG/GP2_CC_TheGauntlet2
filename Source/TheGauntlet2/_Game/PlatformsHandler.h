// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OrderReceiver.h"
#include "GameFramework/Actor.h"
#include "PlatformsHandler.generated.h"

UCLASS()
class THEGAUNTLET2_API APlatformsHandler : public AActor, public IOrderReceiver
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformsHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	float RotationSpeed = 40;
	
	virtual void NativeReact(float ActivationTime) override;
	
	FTimerHandle TimerHandle_Activation;
	
	void Activate();
	
	void Deactivate();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	TArray<AActor*> Platforms;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* BasicMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* ActivateMaterial;

	UMaterialInstanceDynamic* BasicDynamicMaterial;
	
	UMaterialInstanceDynamic* ActivateDynamicMaterial;
	
	void ChangeMaterials(UMaterialInstanceDynamic* material);
};
