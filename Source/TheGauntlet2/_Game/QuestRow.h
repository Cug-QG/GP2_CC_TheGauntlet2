// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DA_QuestData.h"

#include "QuestRow.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FQuestRow : public FTableRowBase
{
	
	GENERATED_BODY()
	
public:
	
	UPROPERTY(editanywhere, BlueprintReadOnly, Category = "QuestRow")
	FText Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "QuestRow")
	UDA_QuestData* QuestData;
	
};
