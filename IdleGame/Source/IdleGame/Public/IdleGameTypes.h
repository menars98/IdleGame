// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h" // FTableRowBase i�in
#include "IdleGameTypes.generated.h" // Dosya ad�yla e�le�meli

USTRUCT(BlueprintType)
struct FS_CivilizationStructures : public FTableRowBase
{
    GENERATED_BODY()

public:
    // Blueprint'teki t�m de�i�kenlerinizi buraya C++ versiyonlar�yla ta��y�n
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
