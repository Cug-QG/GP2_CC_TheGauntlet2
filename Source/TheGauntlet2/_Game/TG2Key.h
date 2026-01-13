// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "TheGauntlet2Character.h"
#include "GameFramework/Actor.h"
#include "TG2Key.generated.h"

UCLASS()
class THEGAUNTLET2_API ATG2Key : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATG2Key();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void NativeInteract(AActor* Interactor) override;
	
	void AttachToSocket(ATheGauntlet2Character* Character);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* BasicMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInterface* ActivateMaterial;

	UMaterialInstanceDynamic* BasicDynamicMaterial;
	
	UMaterialInstanceDynamic* ActivateDynamicMaterial;
};
