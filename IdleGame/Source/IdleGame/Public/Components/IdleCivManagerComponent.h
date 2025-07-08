// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/Texture2DDynamic.h"
#include "IdleCivManagerComponent.generated.h"

/*USTRUCT(BlueprintType)
struct FMapRow
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Row;
};
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IDLEGAME_API UIdleCivManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	/*
	// Sets default values for this component's properties
	UIdleCivManagerComponent();

	UFUNCTION(BlueprintCallable, Category = "DEBUG")
	void DiagnoseMapDataAtPoint(FIntPoint PointToTest);

	// --- MAIN FUNCTIONS TO BE CALLED FROM BLUEPRINT ---

	UFUNCTION(BlueprintCallable, Category = "Map")
	void InitializeMapArray();

	UFUNCTION(BlueprintCallable, Category = "Map Interaction")
	void ClaimInitialAreaForCivilization(FIntPoint Center, int32 Radius, int32 CivID, FColor CivColor);

	// Allows Blueprint to claim a cell on behalf of a civilization.
	// Used to place the starting cells.
	UFUNCTION(BlueprintCallable, Category = "Map Interaction")
	void ClaimTileForCivilization(FIntPoint Location, int32 CivID, FColor CivColor);

	// To send color information from Blueprint to C++.
	UFUNCTION(BlueprintCallable, Category = "Map Interaction")
	void UpdateCivilizationData(const TMap<int32, FColor>& CivColorMap);

	// --- AUXILIARY FUNCTIONS FOR BLUEPRINT ---
	UFUNCTION(BlueprintCallable, Category = "Map")
	FIntPoint GetRandomSpawnableLocation();

	UFUNCTION(BlueprintPure, Category = "Map Information")
	int32 GetRegionIDAtLocation(FIntPoint Location);

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
	void ExpandCivilizations();
	// Updates specific regions of the dynamic texture.
	void UpdateTextureWithColor(FIntPoint Location, FColor Color);
	UFUNCTION(BlueprintCallable, Category = "Map")
	void FindAllSpawnableLocations();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//UFUNCTION(BlueprintCallable, Category = "Map")
	//FIntPoint GetRandomLandCell();

	UPROPERTY(BlueprintReadOnly, Category = "Map")
	int32 MapWidth = 0;
	UPROPERTY(BlueprintReadOnly, Category = "Map")
	int32 MapHeight = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Civilization")
	FIntPoint StartPoint;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		*/
};
