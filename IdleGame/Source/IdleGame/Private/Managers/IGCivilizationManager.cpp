// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/IGCivilizationManager.h"

// Sets default values
AIGCivilizationManager::AIGCivilizationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIGCivilizationManager::BeginPlay()
{
	Super::BeginPlay();
		
}

void AIGCivilizationManager::InitializeMapArray()
{
	if (!Texture) return;

	FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];
	FByteBulkData* RawImageData = &Mip.BulkData;
	FColor* FormattedImageData = static_cast<FColor*>(RawImageData->Lock(LOCK_READ_ONLY));

	MapWidth = Mip.SizeX;
	MapHeight = Mip.SizeY;

    // Set MapArray Size 
    MapArray.SetNum(MapHeight);
    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        MapArray[Y].Row.SetNum(MapWidth);
        for (int32 X = 0; X < MapWidth; X++)
        {
            FColor Pixel = FormattedImageData[Y * MapWidth + X];
            // Black: Land, White: Sea
            if (Pixel.R > 128 && Pixel.G > 128 && Pixel.B > 128)
                MapArray[Y].Row[X] = 1; // Land
            else
                MapArray[Y].Row[X] = 0; // Sea
        }
    }

    RawImageData->Unlock();
}

void AIGCivilizationManager::CollectLandCells()
{
    LandCells.Empty();
    for (int32 Y = 0; Y < MapArray.Num(); Y++)
    {
        for (int32 X = 0; X < MapArray[Y].Row.Num(); X++)
        {
            if (MapArray[Y].Row[X] == 1) // Land
            {
                LandCells.Add(FIntPoint(X, Y));
            }
        }
    }
}

FIntPoint AIGCivilizationManager::GetRandomLandCell() 
{
    if (LandCells.Num() == 0)
        return FIntPoint(-1, -1);

    int32 Index = FMath::RandRange(0, LandCells.Num() - 1);
    ChosenPoint = LandCells[Index];
    LandCells.RemoveAt(Index);
    return ChosenPoint;
}

// Convert map coordinates to widget coordinates
FVector2D ConvertMapToWidgetCoords(FIntPoint MapCoord, int32 MapWidth, int32 MapHeight, FVector2D WidgetSize)
{
    float X = (float)MapCoord.X / (float)MapWidth * WidgetSize.X;
    float Y = (float)MapCoord.Y / (float)MapHeight * WidgetSize.Y;
    return FVector2D(X, Y);
}