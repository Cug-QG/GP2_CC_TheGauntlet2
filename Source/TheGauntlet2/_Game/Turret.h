// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OrderReceiver.h"
#include "GameFramework/Actor.h"
#include "ObjectPooling/ObjectPoolSubsystem.h"
#include "Turret.generated.h"

UCLASS()
class THEGAUNTLET2_API ATurret : public AActor, public IOrderReceiver
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Config")
	float Range = 1500.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Config")
	float FireRate = 1.0f;
	
	UPROPERTY(BlueprintReadOnly, Category = "Config")
	AActor* PlayerTarget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	USceneComponent* FirePoint;
	
	void Shoot();
	
	void Cooldown(float delta);
	
	float CooldownTime;
	
	bool CanSeePlayer();
	
	virtual void NativeReact(float ActivationTime) override;
	
	FTimerHandle TimerHandle_Activation;
	
	void Activate();
	
	void Deactivate();
	
	UObjectPoolSubsystem* PoolSubsystem;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pool")
	TSubclassOf<AActor> projectile;
	
	UPROPERTY(editAnywhere, BlueprintReadWrite, Category="Pool")
	FName projectileName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* BasicMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* ActivateMaterial;

	UMaterialInstanceDynamic* BasicDynamicMaterial;
	
	UMaterialInstanceDynamic* ActivateDynamicMaterial;
};
