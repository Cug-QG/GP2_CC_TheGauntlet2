// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OrderReceiver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UOrderReceiver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEGAUNTLET2_API IOrderReceiver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	void React(float ActivationTime) { NativeReact(ActivationTime); }

	// activate to implement in c++
	virtual void NativeReact(float ActivationTime)
	{
		UObject* Object = Cast<UObject>(this);
		Execute_BP_React(Object, ActivationTime);
	}

	// ===== Functions to implement =====
	// activate to implement in blueprint
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Reaction")
	void BP_React(float ActivationTime);
};
