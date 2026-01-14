// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class THEGAUNTLET2_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Subsystem")
	void MyFunction();

	// Un evento che puoi implementare nel Blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = "Subsystem")
	void OnSomethingHappened();
};
