// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TheGauntlet2GameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnVictory);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLost);
UCLASS(abstract)
class ATheGauntlet2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	ATheGauntlet2GameMode();
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
	FOnVictory OnVictoryEvent;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
	FOnLost OnLostEvent;
};



