// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class THEGAUNTLET2_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	// Un evento che puoi implementare nel Blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Subsystem")
	void CompleteQuest(FVector Position, FDataTableRowHandle QuestName);
	
	//UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Subsystem")
	virtual UWorld* GetWorld() const override;
};
