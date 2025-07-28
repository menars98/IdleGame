// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Texture2DDynamic.h"
#include "IdleGameTypes.h"
#include "IGCivilizationManager.generated.h"

USTRUCT(BlueprintType)
struct FMapRow
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Row;

	FMapRow() {}
};

UCLASS()
class IDLEGAME_API AIGCivilizationManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIGCivilizationManager();
	
	UFUNCTION(BlueprintCallable, Category = "DEBUG")
	void DiagnoseMapDataAtPoint(FIntPoint PointToTest);

	// --- MAIN FUNCTIONS TO BE CALLED FROM BLUEPRINT ---

	// Sadece maske texture'larýný okuyup temel harita dizilerini (MapArray, RegionMap) oluþturur.
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void SetupMapFromTextures();

	// Sadece YENÝ BÝR OYUN için sahiplik haritasýný ve diðer oyun durumlarýný sýfýrlar.
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void InitializeForNewGame(const TArray<FS_CivilizationStructures>& StartingCivs);

	// Geniþleme timer'ýný baþlatýr. Hem yeni oyunda hem de yüklemeden sonra çaðrýlýr.
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void StartExpansionTimer();

	void TimerTick();

	//UFUNCTION(BlueprintCallable, Category = "Map Interaction")
	//void ClaimInitialAreaForCivilization(FIntPoint Center, int32 Radius, int32 CivID);

	// Allows Blueprint to claim a cell on behalf of a civilization.
	// Used to place the starting cells.
	UFUNCTION(BlueprintCallable, Category = "Map Interaction")
	void ClaimTileForCivilization(FIntPoint Location, int32 CivID);

	// To send color information from Blueprint to C++.
	UFUNCTION(BlueprintCallable, Category = "Map Interaction")
	void UpdateCivilizationData(const TMap<int32, FColor>& CivColorMap);

	// --- AUXILIARY FUNCTIONS FOR BLUEPRINT ---
	// --- GETTERS ---
	UFUNCTION(BlueprintCallable, Category = "Map")
	FIntPoint GetRandomSpawnableLocation();

	UFUNCTION(BlueprintPure, Category = "Map Information")
	int32 GetRegionIDAtLocation(FIntPoint Location);

	UFUNCTION(BlueprintPure, Category = "SaveLoad|GetData")
	const TArray<FS_CivilizationStructures>& GetCivilizationsData() const { return Civilizations; };

	UFUNCTION(BlueprintPure, Category = "GetData")
	const TArray<FMapRow>& GetCivilizationMap() const { return CivilizationMap; }

	UFUNCTION(BlueprintPure, Category = "GetData")
	const TArray<FMapRow>& GetMapArray() const { return MapArray; }

	UFUNCTION(BlueprintPure, Category = "GetData")
	const TArray<FMapRow>& GetRegionMap() const { return RegionMap; }

	UFUNCTION(BlueprintPure, Category = "SaveLoad|GetData")
	TArray<FOwnedTilesSaveData> GetOwnedTilesForSaving() const;

	UFUNCTION(BlueprintPure, Category = "GetData")
	int32 GetCivilizationMapSize() const;

	UFUNCTION(BlueprintPure, Category = "GetData")
	int32 GetOwnedTilesMapSize() const;
	// --- END ----
	// Save & Load

	// --- Setters START ---
	UFUNCTION(BlueprintCallable, Category = "SaveLoad|Internal")
	void ApplyCivilizationMapData(const TArray<FMapRow>& LoadedMapData);

	UFUNCTION(BlueprintCallable, Category = "SaveLoad|ApplyData")
	void ApplyOwnedTilesData(const TArray<FOwnedTilesSaveData>& LoadedOwnedTiles);

	UFUNCTION(BlueprintCallable, Category = "SaveLoad|ApplyData")
	void ApplyCivilizationsData(const TArray<FS_CivilizationStructures>& LoadedCivs);

	UFUNCTION(BlueprintPure, Category = "GetData")
	TMap<int32, FColor> GetCurrentColors() const { return CurrentCivColors; };

	// --- Setters END ---
	// Tüm haritayý mevcut C++ verilerine göre yeniden çizer.
	UFUNCTION(BlueprintCallable, Category = "SaveLoad|Internal")
	void RedrawEntireMap();

	

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetExpansionPaused(bool bIsPaused);

	/*UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void ExpandCivilizations();*/

	UFUNCTION(BlueprintCallable)
	void UpdateExpansionProgress(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void PlaceCivilizations();
public:
	// Dynamic Texture on which we will draw colors
	UPROPERTY(BlueprintReadOnly, Category = "Map")
	UTexture2DDynamic* DynamicMapTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	UTexture2D* MaskTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map Initialization")
	TObjectPtr<UTexture2D> RegionMaskTexture;
	

private:
	// Map Data
	TArray<FMapRow> MapArray;
	// Holds the civilization to which each tile belongs (CivID). 0 = unclaimed.
	TArray<FMapRow> CivilizationMap;
	TArray<FS_CivilizationStructures> Civilizations;
	TArray<FIntPoint> UnownedLandCells;
	// A Map that keeps a list of all tiles owned by each civilization.
	TMap<int32, TArray<FIntPoint>> CivilizationOwnedTiles;
	// Timer that periodically triggers the expansion logic
	FTimerHandle ExpansionTimerHandle;
	// Map that holds which CivID has which color.
	TMap<int32, FColor> CurrentCivColors;

	// NEW: Added for region system
	// Holds the region to which each tile belongs (RegionID).
	TArray<FMapRow> RegionMap;
	// Bu dizinin indeksi, bölge ID'sini belirleyecek (Index 0 = RegionID 1, vs.)
	TArray<FColor> PureRegionColors;

	// C++ Functions
	// Main function that is called periodically and runs the expansion logic for all civilizations.
	
	void RebuildColorMap();

	// Updates specific regions of the dynamic texture.
	void UpdateMultipleTilesWithColor(const TArray<TPair<FIntPoint, FColor>>& TilesToUpdate);

	UFUNCTION(BlueprintCallable, Category = "Map")
	void FindAllSpawnableLocations();

	bool bIsExpansionActive = true;

	bool FindBestExpansionTarget_Internal(int32 CivID, FIntPoint& OutBestTarget);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UFUNCTION(BlueprintCallable, Category = "Map")
	//FIntPoint GetRandomLandCell();

	UPROPERTY(BlueprintReadOnly, Category = "Map")
	int32 MapWidth=0;
	UPROPERTY(BlueprintReadOnly, Category = "Map")
	int32 MapHeight=0;
	UPROPERTY(BlueprintReadWrite, Category = "Civilization")
	FIntPoint StartPoint;
};
