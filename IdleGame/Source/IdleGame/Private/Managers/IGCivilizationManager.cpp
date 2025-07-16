// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/IGCivilizationManager.h"
#include "Engine/Texture2DDynamic.h"
#include "Engine/Texture2D.h"
#include "Kismet/GameplayStatics.h" 
#include <IdleGameSave.h>

// Sets default values
AIGCivilizationManager::AIGCivilizationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // --- LET'S DEFINE OUR REGION COLORS HERE ---
    // This determines which colors our code will look for "look like".
    // You can update this list according to the colors in your map.
    PureRegionColors.Empty();
    PureRegionColors.Add(FColor(0, 0, 255));      // 1: North America (Blue)
    PureRegionColors.Add(FColor(0, 255, 0));      // 2: South America (Green)
    PureRegionColors.Add(FColor(255, 0, 0));      // 3: Europe (Red)
    PureRegionColors.Add(FColor(255, 255, 0));    // 4: Africa (Yellow)
    PureRegionColors.Add(FColor(255, 0, 255));    // 5: Asia (Purple?)

}

void AIGCivilizationManager::DiagnoseMapDataAtPoint(FIntPoint PointToTest)
{
    if (MapArray.Num() == 0 || RegionMap.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("DIAGNOSIS FAILED: Map arrays are empty!"));
        return;
    }

    if (!MapArray.IsValidIndex(PointToTest.Y) || !MapArray[PointToTest.Y].Row.IsValidIndex(PointToTest.X))
    {
        UE_LOG(LogTemp, Error, TEXT("DIAGNOSIS FAILED: Point %s is out of bounds!"), *PointToTest.ToString());
        return;
    }

    int32 IsLandValue = MapArray[PointToTest.Y].Row[PointToTest.X];
    int32 RegionIDValue = RegionMap[PointToTest.Y].Row[PointToTest.X];

    FString IsLandText = (IsLandValue == 1) ? "YES (Value=1)" : "NO (Value=0)";

    UE_LOG(LogTemp, Error, TEXT("--- DIAGNOSIS FOR POINT %s ---"), *PointToTest.ToString());
    UE_LOG(LogTemp, Warning, TEXT("Is it Land? -> %s"), *IsLandText);
    UE_LOG(LogTemp, Warning, TEXT("What is its Region ID? -> %d"), RegionIDValue);
    UE_LOG(LogTemp, Error, TEXT("------------------------------------"));
}

void AIGCivilizationManager::SetupMapFromTextures()
{
    // Fonksiyonun baþýnda, gerekli texture'larýn atanýp atanmadýðýný kontrol edelim.
    if (!MaskTexture || !RegionMaskTexture)
    {
        UE_LOG(LogTemp, Error, TEXT("SetupMapFromTextures: MaskTexture or RegionMaskTexture is not set in the Civilization Manager!"));
        return;
    }

    // --- 1. Read Land/Sea Map ---
    // We create a MipMap reference to get data from MaskTexture.
    FTexture2DMipMap& LandSeaMip = MaskTexture->GetPlatformData()->Mips[0];
    const FColor* LandSeaImageData = static_cast<const FColor*>(LandSeaMip.BulkData.LockReadOnly());

    MapWidth = LandSeaMip.SizeX;
    MapHeight = LandSeaMip.SizeY;

    // If map dimensions are not valid, stop the operation.
    if (MapWidth == 0 || MapHeight == 0)
    {
        LandSeaMip.BulkData.Unlock();
        return;
    }

    // Fill MapArray.
    MapArray.SetNum(MapHeight);
    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        MapArray[Y].Row.SetNum(MapWidth);
        for (int32 X = 0; X < MapWidth; X++)
        {
            // Land (1) if Black (<128), otherwise Sea (0)
            MapArray[Y].Row[X] = (LandSeaImageData[Y * MapWidth + X].R < 128) ? 1 : 0;
        }
    }
    // Unlock after reading the data.
    LandSeaMip.BulkData.Unlock();

    // --- Read 2nd Region Map ---
    // We create a NEW MipMap reference to get data from RegionMaskTexture.
    // Variable names should be different so that they don't get confused.
    FTexture2DMipMap& RegionTextureMip = RegionMaskTexture->GetPlatformData()->Mips[0];
    const FColor* RegionImageData = static_cast<const FColor*>(RegionTextureMip.BulkData.LockReadOnly());

    RegionMap.SetNum(MapHeight);
    // We assume that the PureRegionColors array is full (this should be filled elsewhere).
    if (PureRegionColors.Num() == 0) UE_LOG(LogTemp, Warning, TEXT("PureRegionColors array is empty!"));

    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        RegionMap[Y].Row.SetNum(MapWidth);
        for (int32 X = 0; X < MapWidth; X++)
        {
            FColor PixelColor = RegionImageData[Y * MapWidth + X];

            if (PixelColor.R < 10 && PixelColor.G < 10 && PixelColor.B < 10)
            {
                RegionMap[Y].Row[X] = -1; // -1 = No Region
                continue;
            }

            int32 MinDistanceSq = 20000;
            int32 BestRegionID = -1;

            for (int32 i = 0; i < PureRegionColors.Num(); ++i)
            {
                const FColor& PureColor = PureRegionColors[i];
                int32 DistSq = FMath::Square(PixelColor.R - PureColor.R) +
                    FMath::Square(PixelColor.G - PureColor.G) +
                    FMath::Square(PixelColor.B - PureColor.B);

                if (DistSq < MinDistanceSq)
                {
                    MinDistanceSq = DistSq;
                    BestRegionID = i + 1;
                }
            }
            RegionMap[Y].Row[X] = BestRegionID;
        }
    }
	// Unlock after reading the data.
    RegionTextureMip.BulkData.Unlock();

	// --- 2. Create Dynamic Texture ---
    DynamicMapTexture = UTexture2DDynamic::Create(MapWidth, MapHeight, PF_B8G8R8A8);
    if (DynamicMapTexture)
    {
        DynamicMapTexture->UpdateResource();
        FlushRenderingCommands();
        UE_LOG(LogTemp, Warning, TEXT("Map textures set up successfully."));
    }
}

void AIGCivilizationManager::InitializeForNewGame()
{
    // This function does everything needed to start a game from ZERO.
    CivilizationMap.SetNum(MapHeight);
    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        CivilizationMap[Y].Row.Init(-1, MapWidth); // Set map to UNOWNED
    }
    CivilizationOwnedTiles.Empty(); // Clear data from previous game

	FindAllSpawnableLocations(); // Find all spawnable locations on the map
}

void AIGCivilizationManager::StartExpansionTimer()
{
	// Start the timer that will periodically call the expansion logic.
    //GetWorld()->GetTimerManager().SetTimer(ExpansionTimerHandle, this, &AIGCivilizationManager::ExpandCivilizations, 0.1f, true, 2.0f);
}

void AIGCivilizationManager::BeginPlay()
{
    Super::BeginPlay();

}

FIntPoint AIGCivilizationManager::GetRandomSpawnableLocation()
{
    if (UnownedLandCells.Num() == 0)
    {
        return FIntPoint(-1, -1); 
    }

    int32 Index = FMath::RandRange(0, UnownedLandCells.Num() - 1);
    FIntPoint ChosenPoint = UnownedLandCells[Index];
    UnownedLandCells.RemoveAtSwap(Index);   // Leave the list to avoid re-election
    return ChosenPoint;
}

int32 AIGCivilizationManager::GetRegionIDAtLocation(FIntPoint Location)
{
    if (RegionMap.IsValidIndex(Location.Y) && RegionMap[Location.Y].Row.IsValidIndex(Location.X))
    {
        return RegionMap[Location.Y].Row[Location.X];
    }
    return -1;
}

bool AIGCivilizationManager::SaveGame(FString SlotName, const TArray<FS_CivilizationStructures>& BPCivilizations)
{
    //Its useless ill delete it probably
    // Now we can call CreateSaveGameObject directly with the C++ class.
    UIdleGameSave* SaveGameObject = Cast<UIdleGameSave>(UGameplayStatics::CreateSaveGameObject(UIdleGameSave::StaticClass()));

    if (!SaveGameObject)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create IdleSaveGame Object."));
        return false;
    }

    // Write the data to the C++ object:
    SaveGameObject->SavedCivilizations = BPCivilizations;
    SaveGameObject->SavedCivilizationMapData = this->CivilizationMap;
    // Write the other data here...

    // Save to disk
    return UGameplayStatics::SaveGameToSlot(SaveGameObject, SlotName, 0);
}

bool AIGCivilizationManager::LoadGame(FString SlotName)
{
    // I will delete that too
    // Load from floppy disk
    UIdleGameSave* LoadedGame = Cast<UIdleGameSave>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));

    if (!LoadedGame)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load game from slot: %s"), *SlotName);
        return false;
    }

    // Import the loaded data back into the game
    // ... This part will assign the data back to the relevant places (Civilizations array in BP, maps in C++)...
    // this->CivilizationMap = LoadedGame->SavedCivilizationMapData;
    // and then call a function to redraw the whole map.

    return true;
}

void AIGCivilizationManager::ApplyCivilizationMapData(const TArray<FMapRow>& LoadedMapData)
{
    // Checking that the size of the incoming data is compatible with the existing map
    // is a good security measure, but for now it is enough to assign directly
    this->CivilizationMap = LoadedMapData;

    // IMPORTANT: Since the ownership map has changed, we need to recreate the list of
    // tiles owned by civilizations according to this new map.
    CivilizationOwnedTiles.Empty();
    for (int32 y = 0; y < CivilizationMap.Num(); ++y)
    {
        for (int32 x = 0; x < CivilizationMap[y].Row.Num(); ++x)
        {
            const int32 CivID = CivilizationMap[y].Row[x];
            if (CivID != -1) // -1 means unowned tile
            {
                CivilizationOwnedTiles.FindOrAdd(CivID).Add(FIntPoint(x, y));
            }
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Civilization Map Data applied. Owned tiles map rebuilt."));
}

void AIGCivilizationManager::RedrawEntireMap()
{
    if (!DynamicMapTexture || CurrentCivColors.Num() == 0) return;

    // Lock Texture
    FTexture2DDynamicResource* TextureResource = static_cast<FTexture2DDynamicResource*>(DynamicMapTexture->GetResource());
    if (!TextureResource) return;
    uint32 Stride = 0;
    uint8* MipData = (uint8*)RHILockTexture2D(TextureResource->GetTexture2DRHI(), 0, RLM_WriteOnly, Stride, false);
    if (!MipData) return;

    // Return EVERY pixel on the map
    for (int32 y = 0; y < MapHeight; ++y)
    {
        for (int32 x = 0; x < MapWidth; ++x)
        {
            const int32 CivID = CivilizationMap[y].Row[x];
            FColor PixelColor = FColor::Transparent; // Default color(invisible)

            if (CivID != -1 && CurrentCivColors.Contains(CivID))
            {
                // If it has an owner and we know the color, paint it that color
                PixelColor = CurrentCivColors[CivID];
                PixelColor.A = 255; // Make it opaque
            }

            // Write pixel to Texture memory (BGRA format)
            const int32 Index = (y * Stride) + (x * 4);
            MipData[Index] = PixelColor.B;
            MipData[Index + 1] = PixelColor.G;
            MipData[Index + 2] = PixelColor.R;
            MipData[Index + 3] = PixelColor.A;
        }
    }

    // Remove lock
    RHIUnlockTexture2D(TextureResource->GetTexture2DRHI(), 0, false);
    UE_LOG(LogTemp, Warning, TEXT("Entire map redrawn based on loaded data."));
}

TArray<FOwnedTilesSaveData> AIGCivilizationManager::GetOwnedTilesForSaving() const
{
    TArray<FOwnedTilesSaveData> SaveData;
    // Return the current TMap and add each element to the new struct array
    for (const auto& Elem : CivilizationOwnedTiles)
    {
        FOwnedTilesSaveData Entry;
        Entry.CivID = Elem.Key;
        Entry.Tiles = Elem.Value;
        SaveData.Add(Entry);
    }
    return SaveData;
}

int32 AIGCivilizationManager::GetCivilizationMapSize() const
{
	return CivilizationMap.Num();
}

int32 AIGCivilizationManager::GetOwnedTilesMapSize() const
{
	return CivilizationOwnedTiles.Num();
}

void AIGCivilizationManager::ApplyOwnedTilesData(const TArray<FOwnedTilesSaveData>& LoadedOwnedTiles)
{
    // Clear current TMap
    CivilizationOwnedTiles.Empty();
    // Return the loaded array and add each element back to TMap
    for (const FOwnedTilesSaveData& Entry : LoadedOwnedTiles)
    {
        CivilizationOwnedTiles.Add(Entry.CivID, Entry.Tiles);
    }
    UE_LOG(LogTemp, Warning, TEXT("Owned Tiles Data applied."));
}

void AIGCivilizationManager::SetExpansionPaused(bool bIsPaused)
{
    bIsExpansionActive = !bIsPaused; // bIsPaused true ise, bIsExpansionActive false olur.

    // Log mesajý ekleyelim ki çalýþtýðýný görelim.
    if (bIsExpansionActive)
    {
        UE_LOG(LogTemp, Log, TEXT("Expansion State set to: ACTIVE"));
        // Before continuing the game, repaint the entire map according to the current state in C++.
        RedrawEntireMap();
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Expansion State set to: PAUSED"));
    }
}



void AIGCivilizationManager::FindAllSpawnableLocations()
{
    UnownedLandCells.Empty();
    if (RegionMap.Num() == 0) return; // Do not continue if the region map is not loaded

    for (int32 Y = 0; Y < MapArray.Num(); Y++)
    {
        for (int32 X = 0; X < MapArray[Y].Row.Num(); X++)
        {
            // FOR A LOCATION TO BE VALID TO START:
            // 1. Must be land.
            // 2. Must have a valid region (Region ID must not be -1).
            if (MapArray[Y].Row[X] == 1 && RegionMap[Y].Row[X] != -1)
            {
                UnownedLandCells.Add(FIntPoint(X, Y));
            }
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("Found %d spawnable locations."), UnownedLandCells.Num());
}

void AIGCivilizationManager::ClaimTileForCivilization(FIntPoint Location, int32 CivID, FColor CivColor)
{
    // Border control 
    if (CivID < 0 || !MapArray.IsValidIndex(Location.Y) || !MapArray[Location.Y].Row.IsValidIndex(Location.X)) return;

    FColor OpaqueColor = CivColor;
    OpaqueColor.A = 255;

    // Assign values
    CivilizationMap[Location.Y].Row[Location.X] = CivID;
    CivilizationOwnedTiles.FindOrAdd(CivID).AddUnique(Location);

    // Paint Texture
    UpdateTextureWithColor(Location, OpaqueColor);
}

void AIGCivilizationManager::ClaimInitialAreaForCivilization(FIntPoint Center, int32 Radius, int32 CivID, FColor CivColor)
{
    if (CivID < 0) return;

    for (int32 y = -Radius; y <= Radius; ++y)
    {
        for (int32 x = -Radius; x <= Radius; ++x)
        {
            FIntPoint CurrentPoint(Center.X + x, Center.Y + y);

            // Border control 
            if (!MapArray.IsValidIndex(CurrentPoint.Y) || !MapArray[CurrentPoint.Y].Row.IsValidIndex(CurrentPoint.X))
            {
                continue; // This point is off the map, skip it.
            }

            //Is this pixel suitable for painting ?
            const bool bIsLand = (MapArray[CurrentPoint.Y].Row[CurrentPoint.X] == 1);
            const bool bIsUnowned = (CivilizationMap[CurrentPoint.Y].Row[CurrentPoint.X] == -1);

            if (bIsLand && bIsUnowned)
            {
                // If the condition is met, order painting.
                ClaimTileForCivilization(CurrentPoint, CivID, CivColor);
            }
        }
    }
}

void AIGCivilizationManager::UpdateCivilizationData(const TMap<int32, FColor>& CivColorMap)
{
    CurrentCivColors = CivColorMap;
}

void AIGCivilizationManager::ExpandCivilizations()
{
    // Eðer geniþleme aktif deðilse, hiçbir þey yapmadan fonksiyondan çýk.
    if (!bIsExpansionActive)
    {
        return;
    }

    if (CurrentCivColors.Num() == 0 || CivilizationOwnedTiles.Num() == 0) return;

    TArray<int32> CivIDs;
    CivilizationOwnedTiles.GetKeys(CivIDs);
    if (CivIDs.Num() == 0) return;

    const int32 ExpandingCivID = CivIDs[FMath::RandRange(0, CivIDs.Num() - 1)];
    const TArray<FIntPoint>& OwnedTiles = CivilizationOwnedTiles[ExpandingCivID];
    if (OwnedTiles.Num() == 0) return;

    const int32 CivHomeRegionID = GetRegionIDAtLocation(OwnedTiles[0]);
    if (CivHomeRegionID == -1) return;

    // Find All the expansion points of civilization on All border lines.
    TArray<FIntPoint> AllPossibleExpansions;
    for (const FIntPoint& OwnedTile : OwnedTiles)
    {
        const FIntPoint Neighbors[] = {
            {OwnedTile.X, OwnedTile.Y - 1}, {OwnedTile.X, OwnedTile.Y + 1},
            {OwnedTile.X - 1, OwnedTile.Y}, {OwnedTile.X + 1, OwnedTile.Y}
        };

        for (const FIntPoint& Neighbor : Neighbors)
        {
            if (Neighbor.Y >= 0 && Neighbor.Y < MapHeight && Neighbor.X >= 0 && Neighbor.X < MapWidth &&
                MapArray[Neighbor.Y].Row[Neighbor.X] == 1 &&
                CivilizationMap[Neighbor.Y].Row[Neighbor.X] == -1 &&
                GetRegionIDAtLocation(Neighbor) == CivHomeRegionID)
            {
                AllPossibleExpansions.AddUnique(Neighbor);
            }
        }
    }

    // If we have found a place to expand, pick one at random from that big list and claim it.
    if (AllPossibleExpansions.Num() > 0)
    {
        FIntPoint NewTile = AllPossibleExpansions[FMath::RandRange(0, AllPossibleExpansions.Num() - 1)];
        // Order painting directly, since the condition has already been checked above.
        ClaimTileForCivilization(NewTile, ExpandingCivID, CurrentCivColors[ExpandingCivID]);
    }

}

void AIGCivilizationManager::UpdateTextureWithColor(FIntPoint Location, FColor Color)
{
    if (!DynamicMapTexture || !DynamicMapTexture->GetResource())
    {
        UE_LOG(LogTemp, Warning, TEXT("UpdateTextureWithColor: DynamicMapTexture is invalid."));
        return;
    }

    FTexture2DDynamicResource* TextureResource = static_cast<FTexture2DDynamicResource*>(DynamicMapTexture->GetResource());

    // Lock to write the entire region of the Texture.
    // In more complex scenarios it is possible to lock only the region to be updated,
    // but this method is the most reliable.
    uint32 Stride = 0;
    uint8* MipData = (uint8*)RHILockTexture2D(TextureResource->GetTexture2DRHI(), 0, RLM_WriteOnly, Stride, false);

    if (!MipData)
    {
        UE_LOG(LogTemp, Error, TEXT("UpdateTextureWithColor: Failed to lock texture MipData."));
        return;
    }

    // Calculate the address of the correct pixel in MipData.
    // Stride is the length of a line in bytes. It is usually equal to MapWidth * 4.
    const int32 Index = (Location.Y * Stride) + (Location.X * 4); // 4 byte per pixel (BGRA)

    // Write pixel data in BGRA format.
    MipData[Index] = Color.B;
    MipData[Index + 1] = Color.G;
    MipData[Index + 2] = Color.R;
    MipData[Index + 3] = Color.A; // Usually should be 255 (opaque)

    // Unlock and send the texture back to the GPU.
    RHIUnlockTexture2D(TextureResource->GetTexture2DRHI(), 0, false);
}



