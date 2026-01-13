// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_NumericData.generated.h"

/**
 * 
 */
UCLASS()
class THEGAUNTLET2_API UDA_NumericData : public UDataAsset
{
	GENERATED_BODY()
private:
	
	UPROPERTY(EditDefaultsOnly, Category = "DamageData")
	float speed = 1000;
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FXData|Initialization")
	float GetSpeed() const { return speed; }
};
