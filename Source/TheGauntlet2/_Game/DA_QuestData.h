// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_QuestData.generated.h"

/**
 * 
 */
UCLASS()
class THEGAUNTLET2_API UDA_QuestData : public UDataAsset
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, Category = "FXData|Initialization")
	TSoftObjectPtr<UParticleSystem> InitParticleSystem;

	UPROPERTY(EditDefaultsOnly, Category = "FXData|Initialization")
	TSoftObjectPtr<USoundBase> InitSound;
	
	UPROPERTY(EditDefaultsOnly, Category = "FXData|Initialization")
	FDataTableRowHandle NextQuest;
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FXData|Initialization")
	TSoftObjectPtr<UParticleSystem> GetInitParticleSystem() { return InitParticleSystem; }
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FXData|Initialization")
	TSoftObjectPtr<USoundBase> GetInitSound() { return InitSound; }
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FXData|Initialization")
	FDataTableRowHandle GetNextQuest() { return NextQuest; }
};
