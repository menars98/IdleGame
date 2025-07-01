// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IGCivilizationManager.generated.h"

USTRUCT(BlueprintType)
struct FMapRow
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Row;
};

UCLASS()
class IDLEGAME_API AIGCivilizationManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIGCivilizationManager();
	
	// Map Data
	UPROPERTY(BlueprintReadOnly, Category = "Map")
	TArray<FMapRow> MapArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	UTexture2D* Texture;

	UPROPERTY(BlueprintReadOnly, Category = "Map") 
	int32 MapWidth;
	UPROPERTY(BlueprintReadOnly, Category = "Map") 
	int32 MapHeight;
	UPROPERTY(BlueprintReadWrite, Category = "Civilization") 
	FIntPoint StartPoint;
	UPROPERTY(BlueprintReadWrite, Category = "Civilization") 
	TArray<FIntPoint> LandCells;
	UPROPERTY(BlueprintReadWrite, Category = "Civilization")
	FIntPoint ChosenPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Map")
	void InitializeMapArray();

	UFUNCTION(BlueprintCallable, Category = "Map")
	void CollectLandCells();

	UFUNCTION(BlueprintCallable, Category = "Map")
	FIntPoint GetRandomLandCell();
};
