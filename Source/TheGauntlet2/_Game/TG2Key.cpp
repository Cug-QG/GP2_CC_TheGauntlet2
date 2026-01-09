// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/TG2Key.h"

#include "TheGauntlet2Character.h"

// Sets default values
ATG2Key::ATG2Key()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATG2Key::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATG2Key::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATG2Key::NativeInteract(AActor* Interactor)
{
	IInteractable::NativeInteract(Interactor);
	
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, "Being Interacted");
	
	ATheGauntlet2Character* Character = Cast<ATheGauntlet2Character>(Interactor);
	Character->hasKey = true;
	
	AttachToSocket(Character);
}

void ATG2Key::AttachToSocket(ATheGauntlet2Character* Character)
{
	DisableComponentsSimulatePhysics();
	SetActorEnableCollision(false);
	
	FAttachmentTransformRules AttachmentRules(
		EAttachmentRule::SnapToTarget, 
		EAttachmentRule::SnapToTarget, 
		EAttachmentRule::KeepWorld, 
		true
	);
	this->AttachToComponent(Character->GetMesh(), AttachmentRules, FName("ArtifactSocket"));
}

