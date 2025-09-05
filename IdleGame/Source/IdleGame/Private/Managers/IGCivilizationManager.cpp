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
    PureRegionColors.Add(FColor(255, 0, 0));      // 3: West Europe (Red)
    PureRegionColors.Add(FColor(255, 100, 0));    // 4: East Europe (Orange)
    PureRegionColors.Add(FColor(150, 0, 255));    // 5: Middle East (Purple)
    PureRegionColors.Add(FColor(255, 255, 0));    // 6: Africa (Yellow)
    PureRegionColors.Add(FColor(255, 0, 255));    // 7: Asia (Pink)
    PureRegionColors.Add(FColor(100, 0, 255));    // 8: India-IndoChina (Purple-Blueish)
    PureRegionColors.Add(FColor(100, 0, 255));    // 8: Ocenia(Turquoise)
	// --------------------------------------------
    // This numbers has to match with DT_Regions row names.
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
	// Check if the textures are set
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
        OnDynamicTextureReady.Broadcast(DynamicMapTexture);
        UE_LOG(LogTemp, Warning, TEXT("Map textures set up successfully."));
        // To ensure that Texture does not start with “dirty” data from previous sessions,
        // let's completely clear it when it is created.
        RedrawEntireMap();
    }
}

void AIGCivilizationManager::PrecomputeRegionPixelLists()
{
    AllPixelsPerRegion.Empty();
    if (RegionMap.Num() == 0) return;

    UE_LOG(LogTemp, Warning, TEXT("Starting to precompute pixel lists for all regions..."));

    // Tüm haritayý SADECE BÝR KEZ TARA
    for (int32 y = 0; y < MapHeight; ++y)
    {
        for (int32 x = 0; x < MapWidth; ++x)
        {
            const int32 RegionID = RegionMap[y].Row[x];
            if (RegionID != -1)
            {
                // O anki pikseli, ilgili RegionID'nin listesine ekle.
                AllPixelsPerRegion.FindOrAdd(RegionID).Add(FIntPoint(x, y));
            }
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("...Precomputing finished."));
}

// BP_IdleGM'nin BeginPlay'inde, SetupMapFromTextures'tan sonra çaðýracaðýnýz yeni bir public fonksiyon:
void AIGCivilizationManager::FinalizeMapSetup()
{
    PrecomputeRegionPixelLists();
}

void AIGCivilizationManager::InitializeForNewGame(const TArray<FS_CivilizationStructures>& StartingCivs)
{
    // 1. Reset all old game data
    CivilizationMap.SetNum(MapHeight);
    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        CivilizationMap[Y].Row.Init(-1, MapWidth);
    }
    CivilizationOwnedTiles.Empty();
    CurrentCivColors.Empty();

    // 2. Get the initial data from GameMode
    this->Civilizations = StartingCivs;

    // 3. Create the color map based on this new data
    RebuildColorMap();

    // 4. Find starting points
    FindAllSpawnableLocations();

    UE_LOG(LogTemp, Warning, TEXT("Manager Initialized for New Game. Color Map has %d entries. Ready for placement."), CurrentCivColors.Num());
}

void AIGCivilizationManager::PlaceCivilizations()
{
    if (Civilizations.Num() == 0) return;

    for (int32 i = 0; i < Civilizations.Num(); ++i)
    {
        const FS_CivilizationStructures& CivToPlace = Civilizations[i];
        const FIntPoint StartCenter = CivToPlace.Location; // We get this variable from bpw_earth and call it from bp_gamemode
        const int32 CivID = i + 1; // We assume that IDs start from 1.
        const int32 Radius = 3; // Starting area size (3 = a 7x7 square).
        if (StartCenter.X == -1)
        {
            // If there is no place to start, break the loop.
            UE_LOG(LogTemp, Warning, TEXT("No more spawnable locations left to place civilizations."));
            break;
        }
        // Scan the area around this center point.
        for (int32 y = -Radius; y <= Radius; ++y)
        {
            for (int32 x = -Radius; x <= Radius; ++x)
            {
                FIntPoint CurrentPoint(StartCenter.X + x, StartCenter.Y + y);

                // --- ALL VALIDITY CHECKS ---
                if (
                    // 1. Within the limits?
                    CurrentPoint.Y >= 0 && CurrentPoint.Y < MapHeight && CurrentPoint.X >= 0 && CurrentPoint.X < MapWidth &&

                    // 2. Is it a piece of land?
                    MapArray[CurrentPoint.Y].Row[CurrentPoint.X] == 1 &&

                    // 3. Is it unclaimed?
                    CivilizationMap[CurrentPoint.Y].Row[CurrentPoint.X] == -1

                    // 4. Is it a valid region? This check is already performed in GetRandomSpawnableLocation,
                    // so there is no need to repeat it here, but it can be added for security purposes.
                    // RegionMap[CurrentPoint.Y].Row[CurrentPoint.X] != -1
                    )
                {
                    // If all conditions are met, claim this tile.
                    CivilizationMap[CurrentPoint.Y].Row[CurrentPoint.X] = CivID;
                    CivilizationOwnedTiles.FindOrAdd(CivID).AddUnique(CurrentPoint);
                }
            }
        }
    }

    // Once all civilizations have been placed, draw the map in one go.
    RedrawEntireMap();
}

bool AIGCivilizationManager::IsLandAtCoordinates(FIntPoint Coordinates)
{
    // First, check whether the coordinates are valid (within the boundaries)
    if (Coordinates.Y >= 0 && Coordinates.Y < MapHeight && Coordinates.X >= 0 && Coordinates.X < MapWidth)
    {
        // Returns the value in MapArray. Returns true if it is 1, false if it is 0.
        return MapArray[Coordinates.Y].Row[Coordinates.X] == 1;
    }

    // If it is outside the boundaries, it is definitely not land.
    return false;
}

void AIGCivilizationManager::InitializeResourceNodes(UDataTable* ResourceNodeLocationsTable, UDataTable* ResourceDataTable)
{
    if (!ResourceNodeLocationsTable || !ResourceDataTable)
    {
        UE_LOG(LogTemp, Error, TEXT("InitializeResourceNodes: One or both Data Tables are null!"));
        return;
    }

    LiveResourceNodes.Empty();
    const TArray<FName> RowNames = ResourceNodeLocationsTable->GetRowNames();

    for (const FName& RowName : RowNames)
    {
        // 1. Read location data (from DT_ResourceNodes)
        FS_ResourceNodeLocation* LocationData = ResourceNodeLocationsTable->FindRow<FS_ResourceNodeLocation>(RowName, TEXT(""));
        if (!LocationData) continue;

        // 2. Read the source properties from the master database using the source ID (from DT_Resources)
        FS_ResourceData* ResourceData = ResourceDataTable->FindRow<FS_ResourceData>(LocationData->ResourceID, TEXT(""));
        if (!ResourceData) continue;

        // 3. Create and populate a new “Live Source” object
        FS_LiveResourceNode NewLiveNode;
        NewLiveNode.ResourceTypeID = LocationData->ResourceID;
        NewLiveNode.Location = LocationData->Location;
        NewLiveNode.MaxAmount = ResourceData->MaxAmount;
        NewLiveNode.CurrentAmount = ResourceData->MaxAmount; 

        // 4. Add this new live source to TMap using its location as the key.
        LiveResourceNodes.Add(NewLiveNode.Location, NewLiveNode);
    }

    UE_LOG(LogTemp, Warning, TEXT("Initialized %d live resource nodes on the map."), LiveResourceNodes.Num());
}

float AIGCivilizationManager::ConsumeResourceAtLocation(FIntPoint Location, float AmountToConsume, UDataTable* ResourceDataTable)
{
    if (!ResourceDataTable) return 0.0f;

    FS_LiveResourceNode* FoundNode = LiveResourceNodes.Find(Location);
    if (FoundNode && FoundNode->CurrentAmount > 0)
    {
        // Calculate how much will be consumed (cannot exceed what remains in the source)
        const float ActualConsumedAmount = FMath::Min(FoundNode->CurrentAmount, AmountToConsume);
        FoundNode->CurrentAmount -= ActualConsumedAmount;

        // Look at the main database to calculate the score generated
        FS_ResourceData* ResourceData = ResourceDataTable->FindRow<FS_ResourceData>(FoundNode->ResourceTypeID, TEXT(""));
        if (ResourceData)
        {
            // A simple calculation: Amount consumed * resource point yield
            //@TODO We can make this formula more complex.
            return ActualConsumedAmount * ResourceData->BonusValue;
        }
    }

    return 0.0f; // If there is no source or it has been exhausted, no points will be generated.
}

void AIGCivilizationManager::CacheResourceNodeLocations(UDataTable* ResourceNodeDataTable)
{
    if (!ResourceNodeDataTable) return;
    ResourceNodeLocations.Empty();

    const TArray<FName> RowNames = ResourceNodeDataTable->GetRowNames();
    for (const FName& RowName : RowNames)
    {
        FS_ResourceNodeLocation* RowData = ResourceNodeDataTable->FindRow<FS_ResourceNodeLocation>(RowName, "");
        if (RowData)
        {
            ResourceNodeLocations.Add(RowData->Location, RowName);
        }
    }
}

void AIGCivilizationManager::StartExpansionTimer()
{
	// Start the timer that will periodically call the expansion logic.
    //GetWorld()->GetTimerManager().SetTimer(ExpansionTimerHandle, this, &AIGCivilizationManager::ExpandCivilizations, 0.1f, true, 2.0f);
    GetWorld()->GetTimerManager().SetTimer(ExpansionTimerHandle, this, &AIGCivilizationManager::TimerTick, 1.0f, true);
}

void AIGCivilizationManager::TimerTick()
{
    UpdateExpansionProgress(1.0f); // We assume that 1 second passes with each tick.
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
                PixelColor.A = CivilizationAlpha; // We can change the alpha value if we want
            }

            else 
            {
                PixelColor = FColor(0, 0, 0, 0); // 
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

bool AIGCivilizationManager::GetLiveResourceNodeData(FIntPoint Location, FS_LiveResourceNode& OutNodeData) const
{
    const FS_LiveResourceNode* FoundNode = LiveResourceNodes.Find(Location);
    if (FoundNode)
    {
        OutNodeData = *FoundNode;
        return true;
    }
    return false;
}

void AIGCivilizationManager::ReplenishResourceAtLocation(FIntPoint Location)
{
    FS_LiveResourceNode* FoundNode = LiveResourceNodes.Find(Location);
    if (FoundNode)
    {
        FoundNode->CurrentAmount = FoundNode->MaxAmount;
        UE_LOG(LogTemp, Log, TEXT("Resource at %s replenished."), *Location.ToString());
    }
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

void AIGCivilizationManager::ApplyCivilizationsData(const TArray<FS_CivilizationStructures>& LoadedCivs)
{
    this->Civilizations = LoadedCivs;
	// After applying the new civilizations, we need to rebuild the color map.
    RebuildColorMap();
}

bool AIGCivilizationManager::ExpandInRegion(int32 RegionID, int32 PixelsToAdd)
{
    const int32 PlayerCivID = 1;
    if (!CurrentCivColors.Contains(PlayerCivID)) return false;
    FColor PlayerColor = CurrentCivColors[PlayerCivID];

    // --- ADIM 1: BÝTÝÞÝK KOMÞULARI BUL (NORMAL BÜYÜME) ---
    TSet<FIntPoint> Candidates;
    if (CivilizationOwnedTiles.Contains(PlayerCivID))
    {
        // Medeniyetin sahip olduðu ve bu bölgeye ait olan karolarý dön
        for (const FIntPoint& ownedTile : CivilizationOwnedTiles[PlayerCivID])
        {
            if (RegionMap[ownedTile.Y].Row[ownedTile.X] != RegionID) continue;

            // --- ÝÞTE DOLDURULMUÞ KISIM ---

            // ownedTile'ýn 4 komþusunu (Yukarý, Aþaðý, Sol, Sað) tanýmla
            const FIntPoint Neighbors[] = {
                FIntPoint(ownedTile.X, ownedTile.Y - 1), // Yukarý
                FIntPoint(ownedTile.X, ownedTile.Y + 1), // Aþaðý
                FIntPoint(ownedTile.X - 1, ownedTile.Y), // Sol
                FIntPoint(ownedTile.X + 1, ownedTile.Y)  // Sað
            };

            // Bu komþularý tek tek kontrol et
            for (const FIntPoint& neighbor : Neighbors)
            {
                // Bu komþu, geniþlemek için geçerli bir aday mý?
                if (
                    // 1. Harita sýnýrlarý içinde mi?
                    neighbor.Y >= 0 && neighbor.Y < MapHeight && neighbor.X >= 0 && neighbor.X < MapWidth &&

                    // 2. Kara parçasý mý?
                    MapArray[neighbor.Y].Row[neighbor.X] == 1 &&

                    // 3. Sahipsiz mi?
                    CivilizationMap[neighbor.Y].Row[neighbor.X] == -1 &&

                    // 4. Geniþlediðimiz bölgeye mi ait?
                    RegionMap[neighbor.Y].Row[neighbor.X] == RegionID
                    )
                {
                    // Eðer tüm koþullar saðlandýysa, bu komþuyu aday listesine ekle.
                    Candidates.Add(neighbor);
                }
            }
            // --- DOLDURULMUÞ KISIM SONU ---
        }
    }

    // --- ADIM 2: "TIKANMA" TESPÝTÝ VE "KOLONÝZASYON" MODU ---
    // Eðer bitiþik geniþleyecek hiç yer bulamadýysak...
    if (Candidates.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No adjacent tiles found. Attempting colonization mode..."));

        // ...o zaman bu bölgedeki henüz sahip olunmayan TÜM pikselleri bulalým.
        if (AllPixelsPerRegion.Contains(RegionID))
        {
            for (const FIntPoint& pixel : AllPixelsPerRegion[RegionID])
            {
                if (CivilizationMap[pixel.Y].Row[pixel.X] == -1)
                {
                    // Sahipsiz pikselleri aday listesine ekle.
                    Candidates.Add(pixel);
                }
            }
        }
    }

    // Eðer hala geniþleyecek hiç yer yoksa (bölge %100 doluysa), baþarýsýz ol.
    if (Candidates.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("ExpandInRegion: Region %d is completely full."), RegionID);
        return false;
    }

    // --- ADIM 3: SEÇÝM, SAHÝPLENME VE BOYAMA ---
    TArray<FIntPoint> CandidatesArray = Candidates.Array();
    TArray<TPair<FIntPoint, FColor>> TilesToPaint;

    for (int i = 0; i < FMath::Min(PixelsToAdd, CandidatesArray.Num()); ++i)
    {
        int32 RandIndex = FMath::RandRange(0, CandidatesArray.Num() - 1);
        FIntPoint PixelToClaim = CandidatesArray[RandIndex];

        ClaimTileForCivilization(PixelToClaim, PlayerCivID);

        CandidatesArray.RemoveAt(RandIndex);
    }
    return true;
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

void AIGCivilizationManager::UpdateExpansionProgress(float DeltaTime)
{
    if (!bIsExpansionActive) return;

    bool bMapStateChanged = false; // Has there been a change in the map?

    for (int32 i = 0; i < Civilizations.Num(); ++i)
    {
        FS_CivilizationStructures& CurrentCiv = Civilizations[i];
        const int32 CivID = i + 1;

        
        while (CurrentCiv.ExpansionProgress >= CurrentCiv.ExpansionCost)
        {
            FIntPoint BestTarget;
            if (FindBestExpansionTarget_Internal(CivID, BestTarget))
            {
                // Only update the C++ DATA. Do not paint.
                ClaimTileForCivilization(BestTarget, CivID);

                CurrentCiv.ExpansionProgress -= CurrentCiv.ExpansionCost;
                CurrentCiv.ExpansionCost *= 1.0f;

                bMapStateChanged = true; // There has been a change, raise the flag.
            }
            else
            {
                break;
            }
        }
        // Always update Progress
        CurrentCiv.ExpansionProgress += CurrentCiv.GrowthRate * DeltaTime;
    }

    // If at least one civilization expanded during this tick...
    if (bMapStateChanged)
    {
        // ...redraw the entire map.
        RedrawEntireMap();
    }
}

/*
void AIGCivilizationManager::ExpandCivilizations()
{
    if (!bIsExpansionActive) return;
    if (CurrentCivColors.Num() == 0 || CivilizationOwnedTiles.Num() == 0) return;

    TArray<int32> CivIDs;
    CivilizationOwnedTiles.GetKeys(CivIDs);
    if (CivIDs.Num() == 0) return;

    const int32 ExpandingCivID = CivIDs[FMath::RandRange(0, CivIDs.Num() - 1)];
    const TArray<FIntPoint>& OwnedTiles = CivilizationOwnedTiles[ExpandingCivID];
    if (OwnedTiles.Num() == 0) return;

    const int32 CivHomeRegionID = GetRegionIDAtLocation(OwnedTiles[0]);
    if (CivHomeRegionID == -1) return;

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

    if (AllPossibleExpansions.Num() == 0)
    {
        return;
    }

    
    const int32 ExpansionsThisTick = FMath::Min(5, AllPossibleExpansions.Num()); // En fazla 5 tane veya listede ne kadar varsa.

    TArray<TPair<FIntPoint, FColor>> TilesToPaint;

    for (int i = 0; i < ExpansionsThisTick; ++i)
    {
      
        int32 ChoiceIndex = FMath::RandRange(0, AllPossibleExpansions.Num() - 1);
        FIntPoint NewTile = AllPossibleExpansions[ChoiceIndex];

        ClaimTileForCivilization(NewTile, ExpandingCivID);
 
        FColor CivColor = CurrentCivColors[ExpandingCivID];
        TilesToPaint.Add(TPair<FIntPoint, FColor>(NewTile, CivColor));

        AllPossibleExpansions.RemoveAt(ChoiceIndex);
    }


    if (TilesToPaint.Num() > 0)
    {
        UpdateMultipleTilesWithColor(TilesToPaint);
    }
}
*/

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

bool AIGCivilizationManager::FindBestExpansionTarget_Internal(int32 CivID, FIntPoint& OutBestTarget)
{
    // 1. Find the tiles owned by the expanding civilization.
    // Since CivilizationOwnedTiles TMap is a member of this class, we can access it directly.
    if (!CivilizationOwnedTiles.Contains(CivID) || CivilizationOwnedTiles[CivID].Num() == 0)
    {
        return false; // This civilization has no tiles.
    }
    const TArray<FIntPoint>& OwnedTilesForThisCiv = CivilizationOwnedTiles[CivID];

    // 2. Find the homeland (region) of civilization.
    // RegionMap is a member of this class.
    const int32 HomeRegionID = RegionMap[OwnedTilesForThisCiv[0].Y].Row[OwnedTilesForThisCiv[0].X];
    if (HomeRegionID == -1)
    {
        return false;
    }

    // 3. Find all possible targets.
    TArray<FIntPoint> AllPossibleTargets;
    for (const FIntPoint& CurrentTile : OwnedTilesForThisCiv)
    {
        const FIntPoint Neighbors[] = {
            {CurrentTile.X, CurrentTile.Y - 1}, {CurrentTile.X, CurrentTile.Y + 1},
            {CurrentTile.X - 1, CurrentTile.Y}, {CurrentTile.X + 1, CurrentTile.Y}
        };
        for (const FIntPoint& Neighbor : Neighbors)
        {
            if (Neighbor.Y >= 0 && Neighbor.Y < MapHeight && Neighbor.X >= 0 && Neighbor.X < MapWidth &&
                MapArray[Neighbor.Y].Row[Neighbor.X] == 1 &&
                CivilizationMap[Neighbor.Y].Row[Neighbor.X] == -1 &&
                RegionMap[Neighbor.Y].Row[Neighbor.X] == HomeRegionID)
            {
                AllPossibleTargets.AddUnique(Neighbor);
            }
        }
    }

    // 4. Return the result.
    if (AllPossibleTargets.Num() > 0)
    {
        OutBestTarget = AllPossibleTargets[FMath::RandRange(0, AllPossibleTargets.Num() - 1)];
        return true;
    }

    return false;
}

void AIGCivilizationManager::ClaimTileForCivilization(FIntPoint Location, int32 CivID)
{
    if (CivID < 0 || !CivilizationMap.IsValidIndex(Location.Y) || !CivilizationMap[Location.Y].Row.IsValidIndex(Location.X) || CivilizationMap[Location.Y].Row[Location.X] != -1)
    {
        return;
    }
    CivilizationMap[Location.Y].Row[Location.X] = CivID;
    CivilizationOwnedTiles.FindOrAdd(CivID).AddUnique(Location);

    // Is this location that was just captured a resource center?
    if (ResourceNodeLocations.Contains(Location))
    {
        const FName NodeRowName = ResourceNodeLocations[Location];

        // Evet! Sinyali gönder.
        OnResourceNodeCaptured.Broadcast(NodeRowName);

        // Bu kaynaðýn tekrar tetiklenmemesi için haritadan kaldýr.
        ResourceNodeLocations.Remove(Location);
    }

}

/*
void AIGCivilizationManager::ClaimInitialAreaForCivilization(FIntPoint Center, int32 Radius, int32 CivID)
{
   if (CivID < 0 || !CurrentCivColors.Contains(CivID)) return;

    TArray<TPair<FIntPoint, FColor>> TilesToPaint;
    FColor CivColor = CurrentCivColors[CivID];

    for (int32 y = -Radius; y <= Radius; ++y)
    {
        for (int32 x = -Radius; x <= Radius; ++x)
        {
            FIntPoint CurrentPoint(Center.X + x, Center.Y + y);
            if (CurrentPoint.Y >= 0 && CurrentPoint.Y < MapHeight && CurrentPoint.X >= 0 && CurrentPoint.X < MapWidth &&
                MapArray[CurrentPoint.Y].Row[CurrentPoint.X] == 1 &&
                CivilizationMap[CurrentPoint.Y].Row[CurrentPoint.X] == -1)
            {
                ClaimTileForCivilization(CurrentPoint, CivID);
                TilesToPaint.Add(TPair<FIntPoint, FColor>(CurrentPoint, CivColor));
            }
        }
    }
    if (TilesToPaint.Num() > 0)
    {
        UpdateMultipleTilesWithColor(TilesToPaint);
    }
}
*/

void AIGCivilizationManager::UpdateCivilizationData(const TMap<int32, FColor>& CivColorMap)
{
    CurrentCivColors = CivColorMap;
}

void AIGCivilizationManager::RebuildColorMap()
{
    CurrentCivColors.Empty();
    if (Civilizations.Num() == 0) return;

    for (int32 i = 0; i < Civilizations.Num(); ++i)
    {
        // We could add CIVID maybe
        // CurrentCivColors.Add(Civilizations[i].CivID, Civilizations[i].Color);
        CurrentCivColors.Add(i + 1, Civilizations[i].Color);
    }
    UE_LOG(LogTemp, Warning, TEXT("Color Map rebuilt. Found %d colors."), CurrentCivColors.Num());
}

void AIGCivilizationManager::UpdateMultipleTilesWithColor(const TArray<TPair<FIntPoint, FColor>>& TilesToUpdate)
{
    if (!DynamicMapTexture || !DynamicMapTexture->GetResource() || TilesToUpdate.Num() == 0) return;

    FTexture2DDynamicResource* TextureResource = static_cast<FTexture2DDynamicResource*>(DynamicMapTexture->GetResource());
    uint32 Stride = 0;

    // Lock the texture ONLY ONCE
    uint8* MipData = (uint8*)RHILockTexture2D(TextureResource->GetTexture2DRHI(), 0, RLM_WriteOnly, Stride, false);
    if (!MipData) return;

    // Gelen listedeki TÜM pikselleri boya
    for (const TPair<FIntPoint, FColor>& TileData : TilesToUpdate)
    {
        const FIntPoint& Location = TileData.Key;
        const FColor& Color = TileData.Value;

        const int32 Index = (Location.Y * Stride) + (Location.X * 4);
        MipData[Index]     = Color.B;
        MipData[Index + 1] = Color.G;
        MipData[Index + 2] = Color.R;
        MipData[Index + 3] = Color.A; // Now alpha has a value
    }

    // Open the texture ONLY ONCE
    RHIUnlockTexture2D(TextureResource->GetTexture2DRHI(), 0, false);
}


