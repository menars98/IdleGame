#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h" // FTableRowBase için
#include "ProjeTypes.generated.h" // Dosya adýyla eþleþmeli

USTRUCT(BlueprintType)
struct FS_CivilizationStructure : public FTableRowBase
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

    // ... Diðer tüm deðiþkenler (Score, GrowthRate, Color, Location vs.)
}; #pragma once
