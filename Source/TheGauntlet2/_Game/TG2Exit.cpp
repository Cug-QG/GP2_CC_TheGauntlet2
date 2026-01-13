// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/TG2Exit.h"

#include "TheGauntlet2Character.h"

// Sets default values
ATG2Exit::ATG2Exit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATG2Exit::BeginPlay()
{
	Super::BeginPlay();
	
	Mesh = FindComponentByClass<UStaticMeshComponent>();
	BasicDynamicMaterial = UMaterialInstanceDynamic::Create(BasicMaterial, this);
	Mesh->SetMaterial(0, BasicDynamicMaterial);
	ActivateDynamicMaterial = UMaterialInstanceDynamic::Create(ActivateMaterial, this);
}

// Called every frame
void ATG2Exit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATG2Exit::NativeInteract(AActor* Interactor)
{
	IInteractable::NativeInteract(Interactor);
	
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, "Being Interacted");
	
	if (Cast<ATheGauntlet2Character>(Interactor)->hasKey == true) Open();
}

void ATG2Exit::Open()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::White, "Exit opened");
	Mesh->SetMaterial(0, ActivateMaterial);
}

