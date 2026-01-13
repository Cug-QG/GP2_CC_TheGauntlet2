// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ObjectPoolInterface.generated.h"

USTRUCT(BlueprintType)
struct FObjectPoolActivationData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Object Pool Data")
	FTransform ObjectPoolTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Object Pool Data")
	FName ObjectPoolName;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UObjectPoolInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEGAUNTLET2_API IObjectPoolInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	//Active version to call in c++
	void Activate(FObjectPoolActivationData ObjectPoolData) { NativeActivate(ObjectPoolData); };

	//Deactive version to call in c++
	void Deactivate() { NativeDeactive(); }

	// Functions to implement

	// Active to implement in blueprint
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Object Pool Interface")
	void BP_Activate(FObjectPoolActivationData ObjectPoolData);

	// Active to implement in c++
	virtual void NativeActivate(FObjectPoolActivationData ObjectPoolData)
	{
		UObject* Object = Cast<UObject>(this);

		if (IsValid(Object))
		{
			Execute_BP_Activate(Object, ObjectPoolData);
		}		
	};

	// Deactive to implement in blueprint
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Object Pool Interface")
	void BP_Deactivate();

	// Deactive to implemente in c++
	virtual void NativeDeactive()
	{
		UObject* Object = Cast<UObject>(this);

		if (IsValid(Object))
		{
			Execute_BP_Deactivate(Object);
		}		
	};
};
