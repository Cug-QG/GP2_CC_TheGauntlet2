// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Lever.h"
#include "OrderReceiver.h"

// Sets default values
ALever::ALever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALever::BeginPlay()
{
	Super::BeginPlay();
	Mesh = FindComponentByClass<UStaticMeshComponent>();
	BasicDynamicMaterial = UMaterialInstanceDynamic::Create(BasicMaterial, this);
	Mesh->SetMaterial(0, BasicDynamicMaterial);
	ActivateDynamicMaterial = UMaterialInstanceDynamic::Create(ActivateMaterial, this);
}

// Called every frame
void ALever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALever::NativeInteract(AActor* Interactor)
{
	IInteractable::NativeInteract(Interactor);
	
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, "Being Interacted");

	for (auto Element : TargetReceivers)
	{
		if (IsValid(Element.GetObject()))
		{
			TScriptInterface<IOrderReceiver> Target = Element.GetObject();
			Target->React(ActivationTime);
		}
	}
	
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();

	if (TimerManager.IsTimerActive(TimerHandle_Activation))
	{
		TimerManager.ClearTimer(TimerHandle_Activation);
	}

	Mesh->SetMaterial(0, ActivateMaterial);
	
	TimerManager.SetTimer(
		TimerHandle_Activation,
		this,
		&ALever::ResetMaterial,
		ActivationTime,
		false
	);
}

void ALever::ResetMaterial()
{
	Mesh->SetMaterial(0, BasicDynamicMaterial);
}

