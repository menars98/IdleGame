// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h" // FTableRowBase için
#include "IdleGameTypes.generated.h" // Dosya adýyla eþleþmeli

USTRUCT(BlueprintType)
struct FS_CivilizationStructures : public FTableRowBase
{
    GENERATED_BODY()

public:
    // Blueprint'teki tüm deðiþkenlerinizi buraya C++ versiyonlarýyla taþýyýn
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

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float GrowthRate = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint Location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FColor Color;
};
