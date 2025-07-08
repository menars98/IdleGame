// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "IdleGameTypes.h"
#include <Managers/IGCivilizationManager.h>
#include "IdleGameSave.generated.h"


/**
 * 
 */
UCLASS()
class IDLEGAME_API UIdleGameSave : public USaveGame
{
	GENERATED_BODY()
	
public:

	// Variables for all data to be saved

	//-- Data For Civilizations ---
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Civilizations")
	TArray<FS_CivilizationStructures> SavedCivilizations;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Civilizations|Map")
	TArray<FMapRow> SavedCivilizationMapData;

	// Map that holds which CivID has which color.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Civilizations")
	TMap<int32, FColor> CurrentCivColors;

	// --- Data for PlayerState ---
	// ... Add fields here for all other important variables in PlayerState.
	// For example: float SavedClickerPoints; float SavedPointsPerSecond;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Points")
	float SavedPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Points")
	float SavedTotalPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Points")
	float DisplayedPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Points")
	float SavedPointsPerSecond;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Points")
	float SavedPointsPerClick; //ClickerPoints

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Points")
	int64 SavedKardashevScale;

	//Now we dont use right now but we can add scale points later.
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Points")
	//float SavedPointsPerClickMultiplier; 

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Level")
	float SavedLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|Player|Level")
	TMap<FString, int64> SavedCurrentLevelMap; // Level Progress for each upgrade
	//--- Player State End---
	
	// UPROPERTY(VisibleAnywhere, Category = "SaveData|Map")
	// TMap<int32, TArray<FIntPoint>> SavedOwnedTilesData;

	// --- UI Durumu -
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData|UI")
	int32 SavedLastScreenIndex;

	// It is good practice to add a constructor to set default values.
	UIdleGameSave();
};
