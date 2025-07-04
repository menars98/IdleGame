// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/IGCivilizationManager.h"
#include "Engine/Texture2DDynamic.h"
#include "Engine/Texture2D.h"

// Sets default values
AIGCivilizationManager::AIGCivilizationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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

void AIGCivilizationManager::BeginPlay()
{
    Super::BeginPlay();

}

void AIGCivilizationManager::InitializeMapArray()
{
    if (!MaskTexture || !RegionMaskTexture)
    {
        UE_LOG(LogTemp, Error, TEXT("MaskTexture or RegionMaskTexture is not set!"));
        return;
    }

    // --- BÖLGE RENKLERÝMÝZÝ BURADA TANIMLAYALIM ---
    // Bu, kodumuzun hangi renklere "benzeyenleri" arayacaðýný belirler.
    // Haritanýzdaki renklere göre bu listeyi güncelleyebilirsiniz.
    PureRegionColors.Empty();
    PureRegionColors.Add(FColor(0, 0, 255));      // 1: Kuzey Amerika (Mavi)
    PureRegionColors.Add(FColor(0, 255, 0));      // 2: Güney Amerika (Yeþil)
    PureRegionColors.Add(FColor(255, 0, 0));      // 3: Avrupa (Kýrmýzý - Sizin haritada daha pembemsi)
    PureRegionColors.Add(FColor(255, 255, 0));    // 4: Afrika (Sarý)
    PureRegionColors.Add(FColor(255, 0, 255));    // 5: Asya (Macenta)
    // ... Haritanýzdaki diðer tüm ana renkleri buraya ekleyin.
    // Örneðin: PureRegionColors.Add(FColor(255, 0, 255)); // 5: Asya (Macenta)

    // --- 1. Kara/Deniz Haritasýný Oku (Deðiþiklik yok) ---
    FTexture2DMipMap& Mip = MaskTexture->GetPlatformData()->Mips[0];
    const FColor* FormattedImageData = static_cast<const FColor*>(Mip.BulkData.LockReadOnly());
    MapWidth = Mip.SizeX;
    MapHeight = Mip.SizeY;

    MapArray.SetNum(MapHeight);
    CivilizationMap.SetNum(MapHeight);
    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        MapArray[Y].Row.SetNum(MapWidth);
        CivilizationMap[Y].Row.Init(-1, MapWidth);
        for (int32 X = 0; X < MapWidth; X++)
        {
            MapArray[Y].Row[X] = (FormattedImageData[Y * MapWidth + X].R < 128) ? 1 : 0;
        }
    }
    Mip.BulkData.Unlock();

    // --- 2. BÖLGE HARÝTASINI OKU (AKILLI VERSÝYON) ---
    FTexture2DMipMap& RegionMip = RegionMaskTexture->GetPlatformData()->Mips[0];
    const FColor* RegionFormattedData = static_cast<const FColor*>(RegionMip.BulkData.LockReadOnly());
    RegionMap.SetNum(MapHeight);

    // --- DEBUG ÝÇÝN EKLENEN KISIM ---
    // Sadece birkaç renkli piksel bulup ne okuduðumuzu görelim
    int32 DebugSamplesFound = 0;

    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        RegionMap[Y].Row.SetNum(MapWidth);
        for (int32 X = 0; X < MapWidth; X++)
        {
            FColor PixelColor = RegionFormattedData[Y * MapWidth + X];

            // Eðer piksel siyahsa, burasý kesinlikle bir bölge deðil.
            if (PixelColor.R < 10 && PixelColor.G < 10 && PixelColor.B < 10)
            {
                RegionMap[Y].Row[X] = -1; // -1 = Bölge Yok
                continue;
            }

            // Bu piksele en yakýn olan saf rengi bulalým.
            int32 MinDistanceSq = 20000;
            int32 BestRegionID = -1;

            for (int32 i = 0; i < PureRegionColors.Num(); ++i)
            {
                const FColor& PureColor = PureRegionColors[i];

                // Renkler arasýndaki mesafenin karesini hesapla (daha hýzlý)
                int32 DistSq = FMath::Square(PixelColor.R - PureColor.R) +
                    FMath::Square(PixelColor.G - PureColor.G) +
                    FMath::Square(PixelColor.B - PureColor.B);

                if (DistSq < MinDistanceSq)
                {
                    MinDistanceSq = DistSq;
                    BestRegionID = i + 1; // Region ID'ler 1'den baþlar, dizi indeksi 0'dan.
                }
            }

            RegionMap[Y].Row[X] = BestRegionID;
        }
    }
    RegionMip.BulkData.Unlock();

    // --- 3. Geri Kalan Her Þey Ayný ---
    FindAllSpawnableLocations();
    DynamicMapTexture = UTexture2DDynamic::Create(MapWidth, MapHeight, PF_B8G8R8A8);
    if (DynamicMapTexture)
    {
        DynamicMapTexture->UpdateResource();
        FlushRenderingCommands();
    }
    GetWorld()->GetTimerManager().SetTimer(ExpansionTimerHandle, this, &AIGCivilizationManager::ExpandCivilizations, 0.05f, true, 2.0f);
}

FIntPoint AIGCivilizationManager::GetRandomSpawnableLocation()
{
    if (UnownedLandCells.Num() == 0)
    {
        return FIntPoint(-1, -1); // Baþlanacak yer kalmamýþ
    }

    int32 Index = FMath::RandRange(0, UnownedLandCells.Num() - 1);
    FIntPoint ChosenPoint = UnownedLandCells[Index];
    UnownedLandCells.RemoveAtSwap(Index); // Tekrar seçilmesin diye listeden çýkar
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

void AIGCivilizationManager::FindAllSpawnableLocations()
{
    UnownedLandCells.Empty();
    if (RegionMap.Num() == 0) return; // Bölge haritasý yüklenmediyse devam etme

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
    // Sýnýr kontrolü her zaman iyidir.
    if (CivID < 0 || !MapArray.IsValidIndex(Location.Y) || !MapArray[Location.Y].Row.IsValidIndex(Location.X)) return;

    FColor OpaqueColor = CivColor;
    OpaqueColor.A = 255;

    // Deðerleri ata
    CivilizationMap[Location.Y].Row[Location.X] = CivID;
    CivilizationOwnedTiles.FindOrAdd(CivID).AddUnique(Location);

    // Texture'ý boya
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

            // Sýnýr kontrolü
            if (!MapArray.IsValidIndex(CurrentPoint.Y) || !MapArray[CurrentPoint.Y].Row.IsValidIndex(CurrentPoint.X))
            {
                continue; // Bu nokta harita dýþýnda, atla.
            }

            // KARAR ANI: Bu piksel boyanmaya uygun mu?
            const bool bIsLand = (MapArray[CurrentPoint.Y].Row[CurrentPoint.X] == 1);
            const bool bIsUnowned = (CivilizationMap[CurrentPoint.Y].Row[CurrentPoint.X] == -1);

            if (bIsLand && bIsUnowned)
            {
                // Koþul saðlandýysa, boyama emrini ver.
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
    if (CurrentCivColors.Num() == 0 || CivilizationOwnedTiles.Num() == 0) return;

    TArray<int32> CivIDs;
    CivilizationOwnedTiles.GetKeys(CivIDs);
    if (CivIDs.Num() == 0) return;

    const int32 ExpandingCivID = CivIDs[FMath::RandRange(0, CivIDs.Num() - 1)];
    const TArray<FIntPoint>& OwnedTiles = CivilizationOwnedTiles[ExpandingCivID];
    if (OwnedTiles.Num() == 0) return;

    const int32 CivHomeRegionID = GetRegionIDAtLocation(OwnedTiles[0]);
    if (CivHomeRegionID == -1) return;

    // Medeniyetin TÜM sýnýr hattýndaki BÜTÜN geniþleme noktalarýný bul.
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

    // Geniþleyecek bir yer bulduysak, o büyük listeden rastgele birini seçip sahiplen.
    if (AllPossibleExpansions.Num() > 0)
    {
        FIntPoint NewTile = AllPossibleExpansions[FMath::RandRange(0, AllPossibleExpansions.Num() - 1)];
        // Koþul yukarýda zaten kontrol edildiði için, doðrudan boyama emrini ver.
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

    // Texture'ýn tüm bölgesini yazmak için kilitle.
    // Daha karmaþýk senaryolarda sadece güncellenecek bölgeyi kilitlemek mümkündür,
    // ancak bu yöntem en güvenilir olanýdýr.
    uint32 Stride = 0;
    uint8* MipData = (uint8*)RHILockTexture2D(TextureResource->GetTexture2DRHI(), 0, RLM_WriteOnly, Stride, false);

    if (!MipData)
    {
        UE_LOG(LogTemp, Error, TEXT("UpdateTextureWithColor: Failed to lock texture MipData."));
        return;
    }

    // MipData'daki doðru pikselin adresini hesapla.
    // Stride, bir satýrýn byte cinsinden uzunluðudur. Genellikle MapWidth * 4'e eþittir.
    const int32 Index = (Location.Y * Stride) + (Location.X * 4); // 4 byte per pixel (BGRA)

    // Piksel verisini BGRA formatýnda yaz.
    MipData[Index] = Color.B;
    MipData[Index + 1] = Color.G;
    MipData[Index + 2] = Color.R;
    MipData[Index + 3] = Color.A; // Genellikle 255 (opak) olmalý

    // Kilidi kaldýrarak texture'ý GPU'ya geri gönder.
    RHIUnlockTexture2D(TextureResource->GetTexture2DRHI(), 0, false);
}



