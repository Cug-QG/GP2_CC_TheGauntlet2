// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/PlatformsHandler.h"

// Sets default values
APlatformsHandler::APlatformsHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
}

// Called when the game starts or when spawned
void APlatformsHandler::BeginPlay()
{
	Super::BeginPlay();
	
	BasicDynamicMaterial = UMaterialInstanceDynamic::Create(BasicMaterial, this);
	ChangeMaterials(BasicDynamicMaterial);
	ActivateDynamicMaterial = UMaterialInstanceDynamic::Create(ActivateMaterial, this);
}

// Called every frame
void APlatformsHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = FRotator(0.f, RotationSpeed * DeltaTime, 0.f);
	AddActorLocalRotation(NewRotation);
}

void APlatformsHandler::NativeReact(float ActivationTime)
{
	IOrderReceiver::NativeReact(ActivationTime);
	
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, "Reacting");
	
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();

	if (TimerManager.IsTimerActive(TimerHandle_Activation))
	{
		TimerManager.ClearTimer(TimerHandle_Activation);
	}

	Activate();
	
	TimerManager.SetTimer(
		TimerHandle_Activation,
		this,
		&APlatformsHandler::Deactivate,
		ActivationTime,
		false
	);
}

void APlatformsHandler::Activate()
{
	SetActorTickEnabled(true);
	ChangeMaterials(ActivateDynamicMaterial);
}

void APlatformsHandler::Deactivate()
{
	SetActorTickEnabled(false);
	ChangeMaterials(BasicDynamicMaterial);
}

void APlatformsHandler::ChangeMaterials(UMaterialInstanceDynamic* material)
{
	for (auto Element :  Platforms)
	{
		Element->FindComponentByClass<UStaticMeshComponent>()->SetMaterial(0, material);
	}
}

