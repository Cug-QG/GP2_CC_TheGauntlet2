// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_FXData.generated.h"

/**
 * 
 */
UCLASS()
class THEGAUNTLET2_API UDA_FXData : public UDataAsset
{
	GENERATED_BODY()
		
private:

	UPROPERTY(EditDefaultsOnly, Category = "FXData|Initialization")
	TSoftObjectPtr<UStaticMesh> InitStaticMesh;

	UPROPERTY(EditDefaultsOnly, Category = "FXData|Initialization")
	TSoftObjectPtr<UMaterialInterface> InitMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "DamageData|Effects")
	FVector ScaleOverride = FVector(1.f, 1.f, 1.f);

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FXData|Initialization")
	TSoftObjectPtr<UStaticMesh> GetInitStaticMesh() const { return InitStaticMesh; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FXData|Initialization")
	TSoftObjectPtr<UMaterialInterface> GetInitMaterial() const { return InitMaterial; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FXData|Initialization")
	FVector GetScaleOverride() const { return ScaleOverride; }
};
