// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DA_FXData.h"
#include "DA_NumericData.h"

#include "ProjectileData.generated.h"


USTRUCT(BlueprintType)
struct FProjectileData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PoolableObjectData|OLD")
	FText PoolableObjectName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PoolableObjectData")
	UDA_FXData* FXDataAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PoolableObjectData")
	UDA_NumericData* NumericDataAsset;
};
