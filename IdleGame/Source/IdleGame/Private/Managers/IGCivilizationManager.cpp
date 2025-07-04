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

    // --- B�LGE RENKLER�M�Z� BURADA TANIMLAYALIM ---
    // Bu, kodumuzun hangi renklere "benzeyenleri" arayaca��n� belirler.
    // Haritan�zdaki renklere g�re bu listeyi g�ncelleyebilirsiniz.
    PureRegionColors.Empty();
    PureRegionColors.Add(FColor(0, 0, 255));      // 1: Kuzey Amerika (Mavi)
    PureRegionColors.Add(FColor(0, 255, 0));      // 2: G�ney Amerika (Ye�il)
    PureRegionColors.Add(FColor(255, 0, 0));      // 3: Avrupa (K�rm�z� - Sizin haritada daha pembemsi)
    PureRegionColors.Add(FColor(255, 255, 0));    // 4: Afrika (Sar�)
    PureRegionColors.Add(FColor(255, 0, 255));    // 5: Asya (Macenta)
    // ... Haritan�zdaki di�er t�m ana renkleri buraya ekleyin.
    // �rne�in: PureRegionColors.Add(FColor(255, 0, 255)); // 5: Asya (Macenta)

    // --- 1. Kara/Deniz Haritas�n� Oku (De�i�iklik yok) ---
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

    // --- 2. B�LGE HAR�TASINI OKU (AKILLI VERS�YON) ---
    FTexture2DMipMap& RegionMip = RegionMaskTexture->GetPlatformData()->Mips[0];
    const FColor* RegionFormattedData = static_cast<const FColor*>(RegionMip.BulkData.LockReadOnly());
    RegionMap.SetNum(MapHeight);

    // --- DEBUG ���N EKLENEN KISIM ---
    // Sadece birka� renkli piksel bulup ne okudu�umuzu g�relim
    int32 DebugSamplesFound = 0;

    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        RegionMap[Y].Row.SetNum(MapWidth);
        for (int32 X = 0; X < MapWidth; X++)
        {
            FColor PixelColor = RegionFormattedData[Y * MapWidth + X];

            // E�er piksel siyahsa, buras� kesinlikle bir b�lge de�il.
            if (PixelColor.R < 10 && PixelColor.G < 10 && PixelColor.B < 10)
            {
                RegionMap[Y].Row[X] = -1; // -1 = B�lge Yok
                continue;
            }

            // Bu piksele en yak�n olan saf rengi bulal�m.
            int32 MinDistanceSq = 20000;
            int32 BestRegionID = -1;

            for (int32 i = 0; i < PureRegionColors.Num(); ++i)
            {
                const FColor& PureColor = PureRegionColors[i];

                // Renkler aras�ndaki mesafenin karesini hesapla (daha h�zl�)
                int32 DistSq = FMath::Square(PixelColor.R - PureColor.R) +
                    FMath::Square(PixelColor.G - PureColor.G) +
                    FMath::Square(PixelColor.B - PureColor.B);

                if (DistSq < MinDistanceSq)
                {
                    MinDistanceSq = DistSq;
                    BestRegionID = i + 1; // Region ID'ler 1'den ba�lar, dizi indeksi 0'dan.
                }
            }

            RegionMap[Y].Row[X] = BestRegionID;
        }
    }
    RegionMip.BulkData.Unlock();

    // --- 3. Geri Kalan Her �ey Ayn� ---
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
        return FIntPoint(-1, -1); // Ba�lanacak yer kalmam��
    }

    int32 Index = FMath::RandRange(0, UnownedLandCells.Num() - 1);
    FIntPoint ChosenPoint = UnownedLandCells[Index];
    UnownedLandCells.RemoveAtSwap(Index); // Tekrar se�ilmesin diye listeden ��kar
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
    if (RegionMap.Num() == 0) return; // B�lge haritas� y�klenmediyse devam etme

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
    // S�n�r kontrol� her zaman iyidir.
    if (CivID < 0 || !MapArray.IsValidIndex(Location.Y) || !MapArray[Location.Y].Row.IsValidIndex(Location.X)) return;

    FColor OpaqueColor = CivColor;
    OpaqueColor.A = 255;

    // De�erleri ata
    CivilizationMap[Location.Y].Row[Location.X] = CivID;
    CivilizationOwnedTiles.FindOrAdd(CivID).AddUnique(Location);

    // Texture'� boya
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

            // S�n�r kontrol�
            if (!MapArray.IsValidIndex(CurrentPoint.Y) || !MapArray[CurrentPoint.Y].Row.IsValidIndex(CurrentPoint.X))
            {
                continue; // Bu nokta harita d���nda, atla.
            }

            // KARAR ANI: Bu piksel boyanmaya uygun mu?
            const bool bIsLand = (MapArray[CurrentPoint.Y].Row[CurrentPoint.X] == 1);
            const bool bIsUnowned = (CivilizationMap[CurrentPoint.Y].Row[CurrentPoint.X] == -1);

            if (bIsLand && bIsUnowned)
            {
                // Ko�ul sa�land�ysa, boyama emrini ver.
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

    // Medeniyetin T�M s�n�r hatt�ndaki B�T�N geni�leme noktalar�n� bul.
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

    // Geni�leyecek bir yer bulduysak, o b�y�k listeden rastgele birini se�ip sahiplen.
    if (AllPossibleExpansions.Num() > 0)
    {
        FIntPoint NewTile = AllPossibleExpansions[FMath::RandRange(0, AllPossibleExpansions.Num() - 1)];
        // Ko�ul yukar�da zaten kontrol edildi�i i�in, do�rudan boyama emrini ver.
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

    // Texture'�n t�m b�lgesini yazmak i�in kilitle.
    // Daha karma��k senaryolarda sadece g�ncellenecek b�lgeyi kilitlemek m�mk�nd�r,
    // ancak bu y�ntem en g�venilir olan�d�r.
    uint32 Stride = 0;
    uint8* MipData = (uint8*)RHILockTexture2D(TextureResource->GetTexture2DRHI(), 0, RLM_WriteOnly, Stride, false);

    if (!MipData)
    {
        UE_LOG(LogTemp, Error, TEXT("UpdateTextureWithColor: Failed to lock texture MipData."));
        return;
    }

    // MipData'daki do�ru pikselin adresini hesapla.
    // Stride, bir sat�r�n byte cinsinden uzunlu�udur. Genellikle MapWidth * 4'e e�ittir.
    const int32 Index = (Location.Y * Stride) + (Location.X * 4); // 4 byte per pixel (BGRA)

    // Piksel verisini BGRA format�nda yaz.
    MipData[Index] = Color.B;
    MipData[Index + 1] = Color.G;
    MipData[Index + 2] = Color.R;
    MipData[Index + 3] = Color.A; // Genellikle 255 (opak) olmal�

    // Kilidi kald�rarak texture'� GPU'ya geri g�nder.
    RHIUnlockTexture2D(TextureResource->GetTexture2DRHI(), 0, false);
}



