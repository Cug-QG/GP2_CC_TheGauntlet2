// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Turret.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "ObjectPooling/ObjectPoolInterface.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	PlayerTarget = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	PoolSubsystem = GetWorld()->GetSubsystem<UObjectPoolSubsystem>();
	PoolSubsystem->AddPool(projectile, 10);
	Mesh = FindComponentByClass<UStaticMeshComponent>();
	BasicDynamicMaterial = UMaterialInstanceDynamic::Create(BasicMaterial, this);
	Mesh->SetMaterial(0, BasicDynamicMaterial);
	ActivateDynamicMaterial = UMaterialInstanceDynamic::Create(ActivateMaterial, this);
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Cooldown(DeltaTime);
}

void ATurret::Shoot()
{
	CooldownTime = 0.0f;
	
	FObjectPoolActivationData data;
	data.ObjectPoolTransform = this->GetTransform();
	data.ObjectPoolTransform.SetRotation(FirePoint->GetRelativeRotation().Quaternion());
	data.ObjectPoolName = projectileName;
	TScriptInterface<IObjectPoolInterface> diskInstance = PoolSubsystem->GetObjectFromPool(projectile);
	if (!diskInstance) return;
	diskInstance.GetInterface()->Activate(data);
}

void ATurret::Cooldown(float delta)
{
	if (CooldownTime >= 1/FireRate)
	{
		if (CanSeePlayer())
		{
			FVector StartLocation = FirePoint->GetComponentLocation();
			FVector TargetLocation = PlayerTarget->GetActorLocation();
			
			// 2. Calcola la rotazione necessaria
			FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(StartLocation, TargetLocation);
			
			// 3. Applica la rotazione (puoi scegliere se applicarla istantaneamente)
			FirePoint->SetWorldRotation(LookAtRotation);
			Shoot();
		}
		return;
	}
	CooldownTime += delta;
}

bool ATurret::CanSeePlayer()
{
	if (!PlayerTarget || !FirePoint) return false;

	FVector Start = FirePoint->GetComponentLocation();
	FVector End = PlayerTarget->GetActorLocation();
    
	float Distance = FVector::Dist(Start, End);
	if (Distance > Range) return false;

	FHitResult Hit;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, QueryParams);

	FColor LineColor = bHit && Hit.GetActor() == PlayerTarget ? FColor::Green : FColor::Red;

	DrawDebugLine(
		GetWorld(), 
		Start, 
		End, 
		LineColor, 
		false,
		-1.0f,
		0,
		2.0f
	);
	
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, QueryParams))
	{
		if (Hit.GetActor() == PlayerTarget)
		{
			return true;
		}
	}
	
	return false;
}

void ATurret::NativeReact(float ActivationTime)
{
	IOrderReceiver::NativeReact(ActivationTime);
	
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Deactivating");
	
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	
	if (TimerManager.IsTimerActive(TimerHandle_Activation))
	{
		TimerManager.ClearTimer(TimerHandle_Activation);
	}

	Deactivate();
	
	TimerManager.SetTimer(
		TimerHandle_Activation,
		this,
		&ATurret::Activate,
		ActivationTime,
		false
	);
}

void ATurret::Activate()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Activate");
	
	SetActorTickEnabled(true);
	Mesh->SetMaterial(0, BasicDynamicMaterial);
}

void ATurret::Deactivate()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Deactivate");
	
	Mesh->SetMaterial(0, ActivateDynamicMaterial);
	SetActorTickEnabled(false);
}

