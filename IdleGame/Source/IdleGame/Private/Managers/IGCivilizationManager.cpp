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

void AIGCivilizationManager::BeginPlay()
{
    Super::BeginPlay();

}

void AIGCivilizationManager::InitializeMapArray()
{
    if (!MaskTexture)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIGCivilizationManager: MaskTexture is not set!"));
        return;
    }

    FTexture2DMipMap& Mip = MaskTexture->GetPlatformData()->Mips[0];
    const FByteBulkData* RawImageData = &Mip.BulkData;
    const FColor* FormattedImageData = static_cast<const FColor*>(RawImageData->LockReadOnly());

    MapWidth = Mip.SizeX;
    MapHeight = Mip.SizeY;

    if (MapWidth == 0 || MapHeight == 0)
    {
        RawImageData->Unlock();
        return;
    }

    MapArray.SetNum(MapHeight);
    CivilizationMap.SetNum(MapHeight);
    UnownedLandCells.Empty();

    for (int32 Y = 0; Y < MapHeight; Y++)
    {
        MapArray[Y].Row.SetNum(MapWidth);
        CivilizationMap[Y].Row.Init(-1, MapWidth); // T�m de�erleri -1 (SAH�PS�Z) olarak ba�lat

        for (int32 X = 0; X < MapWidth; X++)
        {
            FColor Pixel = FormattedImageData[Y * MapWidth + X];
            if (Pixel.R > 128) // Beyaz = Kara
            {
                MapArray[Y].Row[X] = 1; // Kara
                UnownedLandCells.Add(FIntPoint(X, Y));
            }
            else
            {
                MapArray[Y].Row[X] = 0; //Deniz
            }
        }
    }
    RawImageData->Unlock();

    DynamicMapTexture = UTexture2DDynamic::Create(MapWidth, MapHeight, PF_B8G8R8A8);
    if (DynamicMapTexture)
    {
        DynamicMapTexture->UpdateResource();
        FlushRenderingCommands();
    }

    GetWorld()->GetTimerManager().SetTimer(ExpansionTimerHandle, this, &AIGCivilizationManager::ExpandCivilizations, 0.05f, true, 2.0f); // Timer'� biraz h�zland�ral�m
}

void AIGCivilizationManager::CollectLandCells()
{
    UnownedLandCells.Empty();
    for (int32 Y = 0; Y < MapArray.Num(); Y++)
    {
        for (int32 X = 0; X < MapArray[Y].Row.Num(); X++)
        {
            if (MapArray[Y].Row[X] == 1) // Land
            {
                UnownedLandCells.Add(FIntPoint(X, Y));
            }
        }
    }
}

/*FIntPoint AIGCivilizationManager::GetRandomUnownedLandCell()
{
    if (UnownedLandCells.Num() == 0)
    {
        return FIntPoint(-1, -1); // Sahipsiz kara kalmam��
    }

    // Listeden rastgele bir indeks se�
    int32 Index = FMath::RandRange(0, UnownedLandCells.Num() - 1);
    // Se�ilen noktay� al
    FIntPoint ChosenPoint = UnownedLandCells[Index];
    // Bu noktay� art�k sahipsizler listesinden ��kar ki tekrar se�ilmesin
    UnownedLandCells.RemoveAtSwap(Index); // RemoveAtSwap, RemoveAt'ten daha h�zl�d�r.

    return ChosenPoint;
}*/

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

void AIGCivilizationManager::FindAllSpawnableLocations()
{
    UnownedLandCells.Empty();
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
    if (CivID < 0) return;

    // --- N�HA� KANIT TEST� ---
    // Bu fonksiyon �a�r�ld���nda, MapArray'in o konum i�in ne d���nd���n� LOG'A YAZDIRALIM.
    int32 LandOrSeaValue = -999; // Varsay�lan hata de�eri
    if (Location.Y >= 0 && Location.Y < MapHeight && Location.X >= 0 && Location.X < MapWidth)
    {
        LandOrSeaValue = MapArray[Location.Y].Row[Location.X];
    }
    
    // ERROR seviyesinde yazd�ral�m ki k�rm�z� renkle hemen fark edilsin.
    UE_LOG(LogTemp, Error, TEXT("Attempting to place Civ %d at %s. MapArray value at this location is: %d (1=Land, 0=Sea)"), 
        CivID, *Location.ToString(), LandOrSeaValue);
    // --- TEST SONU ---


    FColor OpaqueColor = CivColor;
    OpaqueColor.A = 255;
    
    // Orijinal kontrol�m�z� yapal�m
    if (Location.Y >= 0 && Location.Y < MapHeight && Location.X >= 0 && Location.X < MapWidth &&
        MapArray[Location.Y].Row[Location.X] == 1 &&
        CivilizationMap[Location.Y].Row[Location.X] == -1)
    {
        CivilizationMap[Location.Y].Row[Location.X] = CivID;
        CivilizationOwnedTiles.FindOrAdd(CivID).AddUnique(Location);
        UpdateTextureWithColor(Location, OpaqueColor);
    }
    else
    {
        // E�er yerle�tirme BA�ARISIZ olursa, nedenini de yazd�ral�m.
        UE_LOG(LogTemp, Warning, TEXT(" -> Placement FAILED for Civ %d. Condition not met."), CivID);
    }
}

void AIGCivilizationManager::UpdateCivilizationData(const TMap<int32, FColor>& CivColorMap)
{
    CurrentCivColors = CivColorMap;
}

void AIGCivilizationManager::ExpandCivilizations()
{
    if (CurrentCivColors.Num() == 0 || CivilizationOwnedTiles.Num() == 0) return;

    // Geni�leyecek bir medeniyet se�
    TArray<int32> CivIDs;
    CivilizationOwnedTiles.GetKeys(CivIDs);
    if (CivIDs.Num() == 0) return;
    int32 ExpandingCivID = CivIDs[FMath::RandRange(0, CivIDs.Num() - 1)];

    // --- YEN� MANTIK BA�LIYOR ---

    // 1. Ad�m: Bu medeniyetin sadece SINIRDA olan karolar�n� bul.
    TArray<FIntPoint> BorderTiles;
    if (CivilizationOwnedTiles.Contains(ExpandingCivID))
    {
        for (const FIntPoint& OwnedTile : CivilizationOwnedTiles[ExpandingCivID])
        {
            // Bu karonun kom�ular�ndan en az biri geni�lemeye uygunsa, bu bir s�n�r karosudur.
            const FIntPoint Neighbors[] = {
                {OwnedTile.X, OwnedTile.Y - 1}, {OwnedTile.X, OwnedTile.Y + 1},
                {OwnedTile.X - 1, OwnedTile.Y}, {OwnedTile.X + 1, OwnedTile.Y}
            };
            for (const FIntPoint& Neighbor : Neighbors)
            {
                if (Neighbor.Y >= 0 && Neighbor.Y < MapHeight && Neighbor.X >= 0 && Neighbor.X < MapWidth &&
                    MapArray[Neighbor.Y].Row[Neighbor.X] == 1 &&
                    CivilizationMap[Neighbor.Y].Row[Neighbor.X] == -1)
                {
                    BorderTiles.Add(OwnedTile);
                    break; // Bir tane bulmak yeterli, di�er kom�ulara bakmaya gerek yok.
                }
            }
        }
    }

    // E�er geni�leyecek s�n�r karosu yoksa, fonksiyondan ��k.
    if (BorderTiles.Num() == 0)
    {
        return;
    }

    // 2. Ad�m: Bulunan s�n�r karolar�ndan rastgele B�R TANE se�. Buras� bizim "b�y�me noktam�z".
    FIntPoint GrowthPoint = BorderTiles[FMath::RandRange(0, BorderTiles.Num() - 1)];

    // 3. Ad�m: Sadece bu "b�y�me noktas�n�n" etraf�ndaki bo� yerleri bul.
    TArray<FIntPoint> PossibleExpansions;
    const FIntPoint NeighborsOfGrowthPoint[] = {
        {GrowthPoint.X, GrowthPoint.Y - 1}, {GrowthPoint.X, GrowthPoint.Y + 1},
        {GrowthPoint.X - 1, GrowthPoint.Y}, {GrowthPoint.X + 1, GrowthPoint.Y}
    };
    for (const FIntPoint& Neighbor : NeighborsOfGrowthPoint)
    {
        if (Neighbor.Y >= 0 && Neighbor.Y < MapHeight && Neighbor.X >= 0 && Neighbor.X < MapWidth &&
            MapArray[Neighbor.Y].Row[Neighbor.X] == 1 &&
            CivilizationMap[Neighbor.Y].Row[Neighbor.X] == -1)
        {
            PossibleExpansions.Add(Neighbor);
        }
    }

    // 4. Ad�m: Bulunan bu kom�u bo� yerlerden birini se� ve sahiplen.
    if (PossibleExpansions.Num() > 0)
    {
        FIntPoint NewTile = PossibleExpansions[FMath::RandRange(0, PossibleExpansions.Num() - 1)];

        CivilizationMap[NewTile.Y].Row[NewTile.X] = ExpandingCivID;
        CivilizationOwnedTiles.FindOrAdd(ExpandingCivID).AddUnique(NewTile);
        UpdateTextureWithColor(NewTile, CurrentCivColors[ExpandingCivID]);
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



