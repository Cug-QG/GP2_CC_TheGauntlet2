// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/TG2GameInstance.h"

#include "Kismet/GameplayStatics.h"

void UTG2GameInstance::LoadLevel(TSoftObjectPtr<UWorld> level)
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(),level);
	
	// if (level)
	// {
	// 	UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(),level);
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("errore caricamento livello"));
	// }
}
