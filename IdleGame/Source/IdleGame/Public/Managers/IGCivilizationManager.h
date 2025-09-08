// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Texture2DDynamic.h"
#include "IdleGameTypes.h"
#include "IGCivilizationManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDynamicTextureReady, UTexture2DDynamic*, DynamicTexture);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResourceNodeCaptured, FName, NodeRowName);

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

	// Only reads mask textures and creates basic map arrays (MapArray, RegionMap).
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void SetupMapFromTextures();

	void PrecomputeRegionPixelLists();

	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void FinalizeMapSetup();

	// Only resets the ownership map and other game states for a NEW GAME.
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void InitializeForNewGame(const TArray<FS_CivilizationStructures>& StartingCivs);

	// Geniþleme timer'ýný baþlatýr. Hem yeni oyunda hem de yüklemeden sonra çaðrýlýr.
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void StartExpansionTimer();

	void TimerTick();

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

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	bool GetLiveResourceNodeData(FIntPoint Location, FS_LiveResourceNode& OutNodeData) const;

	// Resets the current amount of the resource at a given location to the maximum.
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void ReplenishResourceAtLocation(FIntPoint Location);

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
	// Redraws the entire map based on the current C++ data.
	UFUNCTION(BlueprintCallable, Category = "SaveLoad|Internal")
	void RedrawEntireMap();

	// Belirtilen bölgeye, belirtilen sayýda yeni piksel ekler.
   // Baþarýya ulaþýp ulaþmadýðýný bir bool ile döndürür.
	UFUNCTION(BlueprintCallable, Category = "Expansion")
	bool ExpandInRegion(int32 RegionID, int32 PixelsToAdd);

	UFUNCTION(BlueprintCallable, Category = "Expansion")
	bool ClaimRandomTileInRegion(int32 RegionID);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetExpansionPaused(bool bIsPaused);

	UFUNCTION(BlueprintCallable)
	void UpdateExpansionProgress(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void PlaceCivilizations();

	// Checks whether the given coordinates are on land
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Map Query")
	bool IsLandAtCoordinates(FIntPoint Coordinates);

	// --- Resources ---
	
	// Called by the GM at the start of the game. Reads DT_ResourceNodes
	// and fills the LiveResourceNodes TMap above with the initial data.
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void InitializeResourceNodes(UDataTable* ResourceNodeLocationsTable, UDataTable* ResourceDataTable);

	// Reduces the amount of a resource at a specific location and returns how many points were generated.
	UFUNCTION(BlueprintCallable, Category = "Resources")
	float ConsumeResourceAtLocation(FIntPoint Location, float AmountToConsume, UDataTable* ResourceDataTable);

	// Called from GameMode.
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void CacheResourceNodeLocations(UDataTable* ResourceNodeDataTable);

	//--- Resources END ---
public:
	// Dynamic Texture on which we will draw colors
	UPROPERTY(BlueprintReadOnly, Category = "Map")
	UTexture2DDynamic* DynamicMapTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	UTexture2D* MaskTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map Initialization")
	TObjectPtr<UTexture2D> RegionMaskTexture;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drawing", meta = (ClampMin = "0", ClampMax = "255"))
	int32 CivilizationAlpha = 180; // 

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDynamicTextureReady OnDynamicTextureReady;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnResourceNodeCaptured OnResourceNodeCaptured;

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
	// Holds the region to which each tile belongs (RegionID).
	TArray<FMapRow> RegionMap;
	// The index of this array will determine the region ID (Index 0 = RegionID 1, etc.)
	TArray<FColor> PureRegionColors;
	// Key: FIntPoint (Location), Value: FName (row name in DT_ResourceNodes, e.g., “SpawnPoint1”)
	TMap<FIntPoint, FName> ResourceNodeLocations;
	// Our TMap, which keeps track of the live status of all resource regions on the map.	
	TMap<FIntPoint, FS_LiveResourceNode> LiveResourceNodes;
	// Her bölgedeki TÜM piksellerin bir listesini tutar. Oyun baþýnda bir kez doldurulur.
	TMap<int32, TArray<FIntPoint>> AllPixelsPerRegion;
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

	UPROPERTY(BlueprintReadOnly, Category = "Map")
	int32 MapWidth=0;
	UPROPERTY(BlueprintReadOnly, Category = "Map")
	int32 MapHeight=0;
	UPROPERTY(BlueprintReadWrite, Category = "Civilization")
	FIntPoint StartPoint;
};
