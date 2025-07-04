// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IdleGame/Public/Managers/IGCivilizationManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIGCivilizationManager() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2DDynamic_NoRegister();
IDLEGAME_API UClass* Z_Construct_UClass_AIGCivilizationManager();
IDLEGAME_API UClass* Z_Construct_UClass_AIGCivilizationManager_NoRegister();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FMapRow();
UPackage* Z_Construct_UPackage__Script_IdleGame();
// End Cross Module References

// Begin ScriptStruct FMapRow
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MapRow;
class UScriptStruct* FMapRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MapRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MapRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMapRow, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("MapRow"));
	}
	return Z_Registration_Info_UScriptStruct_MapRow.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FMapRow>()
{
	return FMapRow::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMapRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Row_MetaData[] = {
		{ "Category", "MapRow" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Row_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Row;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMapRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMapRow_Statics::NewProp_Row_Inner = { "Row", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMapRow_Statics::NewProp_Row = { "Row", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMapRow, Row), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Row_MetaData), NewProp_Row_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMapRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMapRow_Statics::NewProp_Row_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMapRow_Statics::NewProp_Row,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMapRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	nullptr,
	&NewStructOps,
	"MapRow",
	Z_Construct_UScriptStruct_FMapRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapRow_Statics::PropPointers),
	sizeof(FMapRow),
	alignof(FMapRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMapRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMapRow()
{
	if (!Z_Registration_Info_UScriptStruct_MapRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MapRow.InnerSingleton, Z_Construct_UScriptStruct_FMapRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MapRow.InnerSingleton;
}
// End ScriptStruct FMapRow

// Begin Class AIGCivilizationManager Function ClaimInitialAreaForCivilization
struct Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics
{
	struct IGCivilizationManager_eventClaimInitialAreaForCivilization_Parms
	{
		FIntPoint Center;
		int32 Radius;
		int32 CivID;
		FColor CivColor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map Interaction" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CivID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CivColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventClaimInitialAreaForCivilization_Parms, Center), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventClaimInitialAreaForCivilization_Parms, Radius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_CivID = { "CivID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventClaimInitialAreaForCivilization_Parms, CivID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_CivColor = { "CivColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventClaimInitialAreaForCivilization_Parms, CivColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_CivID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::NewProp_CivColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "ClaimInitialAreaForCivilization", nullptr, nullptr, Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::PropPointers), sizeof(Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::IGCivilizationManager_eventClaimInitialAreaForCivilization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::IGCivilizationManager_eventClaimInitialAreaForCivilization_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execClaimInitialAreaForCivilization)
{
	P_GET_STRUCT(FIntPoint,Z_Param_Center);
	P_GET_PROPERTY(FIntProperty,Z_Param_Radius);
	P_GET_PROPERTY(FIntProperty,Z_Param_CivID);
	P_GET_STRUCT(FColor,Z_Param_CivColor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClaimInitialAreaForCivilization(Z_Param_Center,Z_Param_Radius,Z_Param_CivID,Z_Param_CivColor);
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function ClaimInitialAreaForCivilization

// Begin Class AIGCivilizationManager Function ClaimTileForCivilization
struct Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics
{
	struct IGCivilizationManager_eventClaimTileForCivilization_Parms
	{
		FIntPoint Location;
		int32 CivID;
		FColor CivColor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Allows Blueprint to claim a cell on behalf of a civilization.\n// Used to place the starting cells.\n" },
#endif
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows Blueprint to claim a cell on behalf of a civilization.\nUsed to place the starting cells." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CivID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CivColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventClaimTileForCivilization_Parms, Location), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::NewProp_CivID = { "CivID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventClaimTileForCivilization_Parms, CivID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::NewProp_CivColor = { "CivColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventClaimTileForCivilization_Parms, CivColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::NewProp_CivID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::NewProp_CivColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "ClaimTileForCivilization", nullptr, nullptr, Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::PropPointers), sizeof(Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::IGCivilizationManager_eventClaimTileForCivilization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::IGCivilizationManager_eventClaimTileForCivilization_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execClaimTileForCivilization)
{
	P_GET_STRUCT(FIntPoint,Z_Param_Location);
	P_GET_PROPERTY(FIntProperty,Z_Param_CivID);
	P_GET_STRUCT(FColor,Z_Param_CivColor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClaimTileForCivilization(Z_Param_Location,Z_Param_CivID,Z_Param_CivColor);
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function ClaimTileForCivilization

// Begin Class AIGCivilizationManager Function DiagnoseMapDataAtPoint
struct Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics
{
	struct IGCivilizationManager_eventDiagnoseMapDataAtPoint_Parms
	{
		FIntPoint PointToTest;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DEBUG" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PointToTest;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::NewProp_PointToTest = { "PointToTest", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventDiagnoseMapDataAtPoint_Parms, PointToTest), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::NewProp_PointToTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "DiagnoseMapDataAtPoint", nullptr, nullptr, Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::PropPointers), sizeof(Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::IGCivilizationManager_eventDiagnoseMapDataAtPoint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::IGCivilizationManager_eventDiagnoseMapDataAtPoint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execDiagnoseMapDataAtPoint)
{
	P_GET_STRUCT(FIntPoint,Z_Param_PointToTest);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DiagnoseMapDataAtPoint(Z_Param_PointToTest);
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function DiagnoseMapDataAtPoint

// Begin Class AIGCivilizationManager Function FindAllSpawnableLocations
struct Z_Construct_UFunction_AIGCivilizationManager_FindAllSpawnableLocations_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_FindAllSpawnableLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "FindAllSpawnableLocations", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_FindAllSpawnableLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_FindAllSpawnableLocations_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AIGCivilizationManager_FindAllSpawnableLocations()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_FindAllSpawnableLocations_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execFindAllSpawnableLocations)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FindAllSpawnableLocations();
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function FindAllSpawnableLocations

// Begin Class AIGCivilizationManager Function GetRandomSpawnableLocation
struct Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics
{
	struct IGCivilizationManager_eventGetRandomSpawnableLocation_Parms
	{
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- AUXILIARY FUNCTIONS FOR BLUEPRINT ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- AUXILIARY FUNCTIONS FOR BLUEPRINT ---" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventGetRandomSpawnableLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "GetRandomSpawnableLocation", nullptr, nullptr, Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::IGCivilizationManager_eventGetRandomSpawnableLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::IGCivilizationManager_eventGetRandomSpawnableLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execGetRandomSpawnableLocation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->GetRandomSpawnableLocation();
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function GetRandomSpawnableLocation

// Begin Class AIGCivilizationManager Function GetRegionIDAtLocation
struct Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics
{
	struct IGCivilizationManager_eventGetRegionIDAtLocation_Parms
	{
		FIntPoint Location;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map Information" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventGetRegionIDAtLocation_Parms, Location), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventGetRegionIDAtLocation_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "GetRegionIDAtLocation", nullptr, nullptr, Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::IGCivilizationManager_eventGetRegionIDAtLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::IGCivilizationManager_eventGetRegionIDAtLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execGetRegionIDAtLocation)
{
	P_GET_STRUCT(FIntPoint,Z_Param_Location);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetRegionIDAtLocation(Z_Param_Location);
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function GetRegionIDAtLocation

// Begin Class AIGCivilizationManager Function InitializeMapArray
struct Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- MAIN FUNCTIONS TO BE CALLED FROM BLUEPRINT ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- MAIN FUNCTIONS TO BE CALLED FROM BLUEPRINT ---" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "InitializeMapArray", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execInitializeMapArray)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeMapArray();
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function InitializeMapArray

// Begin Class AIGCivilizationManager Function UpdateCivilizationData
struct Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics
{
	struct IGCivilizationManager_eventUpdateCivilizationData_Parms
	{
		TMap<int32,FColor> CivColorMap;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// To send color information from Blueprint to C++.\n" },
#endif
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "To send color information from Blueprint to C++." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CivColorMap_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CivColorMap_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CivColorMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_CivColorMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::NewProp_CivColorMap_ValueProp = { "CivColorMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::NewProp_CivColorMap_Key_KeyProp = { "CivColorMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::NewProp_CivColorMap = { "CivColorMap", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventUpdateCivilizationData_Parms, CivColorMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CivColorMap_MetaData), NewProp_CivColorMap_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::NewProp_CivColorMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::NewProp_CivColorMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::NewProp_CivColorMap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "UpdateCivilizationData", nullptr, nullptr, Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::PropPointers), sizeof(Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::IGCivilizationManager_eventUpdateCivilizationData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::IGCivilizationManager_eventUpdateCivilizationData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execUpdateCivilizationData)
{
	P_GET_TMAP_REF(int32,FColor,Z_Param_Out_CivColorMap);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateCivilizationData(Z_Param_Out_CivColorMap);
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function UpdateCivilizationData

// Begin Class AIGCivilizationManager
void AIGCivilizationManager::StaticRegisterNativesAIGCivilizationManager()
{
	UClass* Class = AIGCivilizationManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClaimInitialAreaForCivilization", &AIGCivilizationManager::execClaimInitialAreaForCivilization },
		{ "ClaimTileForCivilization", &AIGCivilizationManager::execClaimTileForCivilization },
		{ "DiagnoseMapDataAtPoint", &AIGCivilizationManager::execDiagnoseMapDataAtPoint },
		{ "FindAllSpawnableLocations", &AIGCivilizationManager::execFindAllSpawnableLocations },
		{ "GetRandomSpawnableLocation", &AIGCivilizationManager::execGetRandomSpawnableLocation },
		{ "GetRegionIDAtLocation", &AIGCivilizationManager::execGetRegionIDAtLocation },
		{ "InitializeMapArray", &AIGCivilizationManager::execInitializeMapArray },
		{ "UpdateCivilizationData", &AIGCivilizationManager::execUpdateCivilizationData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AIGCivilizationManager);
UClass* Z_Construct_UClass_AIGCivilizationManager_NoRegister()
{
	return AIGCivilizationManager::StaticClass();
}
struct Z_Construct_UClass_AIGCivilizationManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Managers/IGCivilizationManager.h" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicMapTexture_MetaData[] = {
		{ "Category", "Map" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Dynamic Texture on which we will draw colors\n" },
#endif
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dynamic Texture on which we will draw colors" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaskTexture_MetaData[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionMaskTexture_MetaData[] = {
		{ "Category", "Map Initialization" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapWidth_MetaData[] = {
		{ "Category", "Map" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UFUNCTION(BlueprintCallable, Category = \"Map\")\n//FIntPoint GetRandomLandCell();\n" },
#endif
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UFUNCTION(BlueprintCallable, Category = \"Map\")\nFIntPoint GetRandomLandCell();" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapHeight_MetaData[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartPoint_MetaData[] = {
		{ "Category", "Civilization" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicMapTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaskTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RegionMaskTexture;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MapWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MapHeight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartPoint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AIGCivilizationManager_ClaimInitialAreaForCivilization, "ClaimInitialAreaForCivilization" }, // 3838263347
		{ &Z_Construct_UFunction_AIGCivilizationManager_ClaimTileForCivilization, "ClaimTileForCivilization" }, // 1842080035
		{ &Z_Construct_UFunction_AIGCivilizationManager_DiagnoseMapDataAtPoint, "DiagnoseMapDataAtPoint" }, // 3841583234
		{ &Z_Construct_UFunction_AIGCivilizationManager_FindAllSpawnableLocations, "FindAllSpawnableLocations" }, // 845169460
		{ &Z_Construct_UFunction_AIGCivilizationManager_GetRandomSpawnableLocation, "GetRandomSpawnableLocation" }, // 548654014
		{ &Z_Construct_UFunction_AIGCivilizationManager_GetRegionIDAtLocation, "GetRegionIDAtLocation" }, // 1302815804
		{ &Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray, "InitializeMapArray" }, // 160164845
		{ &Z_Construct_UFunction_AIGCivilizationManager_UpdateCivilizationData, "UpdateCivilizationData" }, // 2021704657
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AIGCivilizationManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_DynamicMapTexture = { "DynamicMapTexture", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, DynamicMapTexture), Z_Construct_UClass_UTexture2DDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicMapTexture_MetaData), NewProp_DynamicMapTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MaskTexture = { "MaskTexture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, MaskTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaskTexture_MetaData), NewProp_MaskTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_RegionMaskTexture = { "RegionMaskTexture", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, RegionMaskTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionMaskTexture_MetaData), NewProp_RegionMaskTexture_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapWidth = { "MapWidth", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, MapWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapWidth_MetaData), NewProp_MapWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapHeight = { "MapHeight", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, MapHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapHeight_MetaData), NewProp_MapHeight_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_StartPoint = { "StartPoint", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, StartPoint), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartPoint_MetaData), NewProp_StartPoint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AIGCivilizationManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_DynamicMapTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MaskTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_RegionMaskTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_StartPoint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AIGCivilizationManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AIGCivilizationManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AIGCivilizationManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AIGCivilizationManager_Statics::ClassParams = {
	&AIGCivilizationManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AIGCivilizationManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AIGCivilizationManager_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AIGCivilizationManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AIGCivilizationManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AIGCivilizationManager()
{
	if (!Z_Registration_Info_UClass_AIGCivilizationManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AIGCivilizationManager.OuterSingleton, Z_Construct_UClass_AIGCivilizationManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AIGCivilizationManager.OuterSingleton;
}
template<> IDLEGAME_API UClass* StaticClass<AIGCivilizationManager>()
{
	return AIGCivilizationManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AIGCivilizationManager);
AIGCivilizationManager::~AIGCivilizationManager() {}
// End Class AIGCivilizationManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMapRow::StaticStruct, Z_Construct_UScriptStruct_FMapRow_Statics::NewStructOps, TEXT("MapRow"), &Z_Registration_Info_UScriptStruct_MapRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMapRow), 3300761288U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AIGCivilizationManager, AIGCivilizationManager::StaticClass, TEXT("AIGCivilizationManager"), &Z_Registration_Info_UClass_AIGCivilizationManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AIGCivilizationManager), 24908922U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_463875966(TEXT("/Script/IdleGame"),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
