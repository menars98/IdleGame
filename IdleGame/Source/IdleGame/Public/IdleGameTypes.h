// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h" 
#include "IdleGameTypes.generated.h" 

UENUM(BlueprintType)
enum class E_BonusType : uint8
{
    AddPointsPerSecond      UMETA(DisplayName = "Add Points Per Second"),
    MultiplyAllGains        UMETA(DisplayName = "Multiply All Gains"),
    ReduceUpgradeCost       UMETA(DisplayName = "Reduce Upgrade Cost"),
    AddClickPower           UMETA(DisplayName = "Add Click Power")
};

UENUM(BlueprintType)
enum class E_ModifierType : uint8
{
	Production   UMETA(DisplayName = "Production"),
	Health 	     UMETA(DisplayName = "Health"),
};


USTRUCT(BlueprintType)
struct FS_CivilizationStructures : public FTableRowBase
{
    GENERATED_BODY()

public:
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> CivilizationNameStages;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StartingRegionID = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CurrentStageIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool OwnerPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Score = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Expansion")
    float GrowthRate = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Expansion")
    float ExpansionProgress = 0.0f; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Expansion")
    float ExpansionCost = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location")
	FIntPoint Location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FColor Color;
};

USTRUCT(BlueprintType)
struct FOwnedTilesSaveData
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    int32 CivID = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TArray<FIntPoint> Tiles;
};

USTRUCT(BlueprintType)
struct FS_ResourceData : public FTableRowBase
{
    GENERATED_BODY()

public:
    // The name of the source that will appear in the UI (e.g., “Iron Mine”)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
    FText ResourceName;
    // The icon that will appear on the map or in the menu for the source
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
    TSoftObjectPtr<UTexture2D> Icon;

    // The type of bonus provided by this source (selected from the enum above)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
    E_BonusType BonusType;

    // The numerical value of the bonus (e.g., 5.0, 0.05, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
    float BonusValue;

    //For Future
    // This can be used in the future for the “Declining Yield” system.
    // Leave it at 0 for now.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
    bool bIsRenewable = true;

    // This is also for future systems.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
    float MaxAmount = 1000.0f;
};

USTRUCT(BlueprintType)
struct FS_ResourceNodeLocation : public FTableRowBase
{
    GENERATED_BODY()

public:
    // The type of this resource point. This must match the name of a row in the DT_Resources Data Table.
    // Example: “Forest”, ‘Iron’, “Oil”
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    FName ResourceID;

    // The exact (X, Y) pixel coordinates of this resource icon on the map.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    FIntPoint Location;
};

USTRUCT(BlueprintType)
struct FS_LiveResourceNode
{
    GENERATED_BODY()

    // The line name in DT_Resources that specifies the type of this resource.
    // This is set once at the start of the game and does not change.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Resource Node")
    FName ResourceTypeID;

    // The location of this resource on the map.
    // This is set once at the start of the game and does not change.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Resource Node")
    FIntPoint Location;

    // This is the theoretical maximum amount of this resource.
    // It is set once at the beginning of the game and does not change.
    //Maybe we dont need to set in this variable, because we already have it.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Resource Node")
    float MaxAmount = 1000.0f;

    // the only variable that changes during the game
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Resource Node")
    float CurrentAmount = 1000.0f;
};

USTRUCT(BlueprintType)
struct FS_BuildingData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText BuildingName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<UTexture2D> Icon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseCost; // The base cost of the building, @TODO which will be multiplied by the level

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PointsPerSecond; // How many points a single level of this building produces

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    E_ModifierType ModifierType; // New Enum: Health, Production, Culture, etc.

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ModifierValue; // Bonus amount (e.g., +5% Production)

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequiredRegionID = 0; // 0 = Global, 1,2,3... = Region-specific (for the Eiffel Tower)

};

USTRUCT(BlueprintType)
struct FS_RegionState
{
    GENERATED_BODY()

    // Which region it is (1=North America, 2=Europe, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RegionID;

    // Our control ratio in this region. Between 0.0 (0%) and 1.0 (100%).
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ControlPercentage = 0.0f;

    // Keeps track of how many there are in each building.
    // Key: FName (row name in DT_Buildings), Value: int32 (level/number)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, int32> BuildingLevels;
};

USTRUCT(BlueprintType)
struct FS_RegionData : public FTableRowBase
{
    GENERATED_BODY()

public:
    // The name of the region that will appear in the UI.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Region Data")
    FText RegionName;

    // In case we want to add a specific base production rate for this region later.
    // For now, it can be left at 0.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Region Data")
    float BaseProductionRate = 1.0f;
};