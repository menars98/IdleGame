#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h" // FTableRowBase i�in
#include "ProjeTypes.generated.h" // Dosya ad�yla e�le�meli

USTRUCT(BlueprintType)
struct FS_CivilizationStructure : public FTableRowBase
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

    // ... Di�er t�m de�i�kenler (Score, GrowthRate, Color, Location vs.)
}; #pragma once
