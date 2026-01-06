// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TG2GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class THEGAUNTLET2_API UTG2GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	//function to change map
	UFUNCTION(BlueprintCallable, Category = "Level Management")
	void LoadLevel(TSoftObjectPtr<UWorld> level);
};
