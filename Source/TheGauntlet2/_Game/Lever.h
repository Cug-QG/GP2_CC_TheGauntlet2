// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "OrderReceiver.h"
#include "GameFramework/Actor.h"
#include "Lever.generated.h"

UCLASS()
class THEGAUNTLET2_API ALever : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALever();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void NativeInteract(AActor* Interactor) override;

	UPROPERTY(EditInstanceOnly, Category = "Config")
	TArray<TScriptInterface<IOrderReceiver>> TargetReceivers;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	float ActivationTime = 5;
	
	FTimerHandle TimerHandle_Activation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* BasicMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* ActivateMaterial;

	UMaterialInstanceDynamic* BasicDynamicMaterial;
	
	UMaterialInstanceDynamic* ActivateDynamicMaterial;
	
	void ResetMaterial();
};
