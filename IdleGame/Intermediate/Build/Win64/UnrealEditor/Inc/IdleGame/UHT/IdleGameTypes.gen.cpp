// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IdleGame/Public/IdleGameTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIdleGameTypes() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
IDLEGAME_API UEnum* Z_Construct_UEnum_IdleGame_E_BonusType();
IDLEGAME_API UEnum* Z_Construct_UEnum_IdleGame_E_ModifierType();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FOwnedTilesSaveData();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_BuildingData();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_CivilizationStructures();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_LiveResourceNode();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_RegionData();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_RegionState();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_ResourceData();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_ResourceNodeLocation();
UPackage* Z_Construct_UPackage__Script_IdleGame();
// End Cross Module References

// Begin Enum E_BonusType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_BonusType;
static UEnum* E_BonusType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_E_BonusType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_E_BonusType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IdleGame_E_BonusType, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("E_BonusType"));
	}
	return Z_Registration_Info_UEnum_E_BonusType.OuterSingleton;
}
template<> IDLEGAME_API UEnum* StaticEnum<E_BonusType>()
{
	return E_BonusType_StaticEnum();
}
struct Z_Construct_UEnum_IdleGame_E_BonusType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AddClickPower.DisplayName", "Add Click Power" },
		{ "AddClickPower.Name", "E_BonusType::AddClickPower" },
		{ "AddPointsPerSecond.DisplayName", "Add Points Per Second" },
		{ "AddPointsPerSecond.Name", "E_BonusType::AddPointsPerSecond" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
		{ "MultiplyAllGains.DisplayName", "Multiply All Gains" },
		{ "MultiplyAllGains.Name", "E_BonusType::MultiplyAllGains" },
		{ "ReduceUpgradeCost.DisplayName", "Reduce Upgrade Cost" },
		{ "ReduceUpgradeCost.Name", "E_BonusType::ReduceUpgradeCost" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "E_BonusType::AddPointsPerSecond", (int64)E_BonusType::AddPointsPerSecond },
		{ "E_BonusType::MultiplyAllGains", (int64)E_BonusType::MultiplyAllGains },
		{ "E_BonusType::ReduceUpgradeCost", (int64)E_BonusType::ReduceUpgradeCost },
		{ "E_BonusType::AddClickPower", (int64)E_BonusType::AddClickPower },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IdleGame_E_BonusType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IdleGame,
	nullptr,
	"E_BonusType",
	"E_BonusType",
	Z_Construct_UEnum_IdleGame_E_BonusType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IdleGame_E_BonusType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IdleGame_E_BonusType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IdleGame_E_BonusType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IdleGame_E_BonusType()
{
	if (!Z_Registration_Info_UEnum_E_BonusType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_BonusType.InnerSingleton, Z_Construct_UEnum_IdleGame_E_BonusType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_E_BonusType.InnerSingleton;
}
// End Enum E_BonusType

// Begin Enum E_ModifierType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_ModifierType;
static UEnum* E_ModifierType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_E_ModifierType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_E_ModifierType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IdleGame_E_ModifierType, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("E_ModifierType"));
	}
	return Z_Registration_Info_UEnum_E_ModifierType.OuterSingleton;
}
template<> IDLEGAME_API UEnum* StaticEnum<E_ModifierType>()
{
	return E_ModifierType_StaticEnum();
}
struct Z_Construct_UEnum_IdleGame_E_ModifierType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Health.DisplayName", "Health" },
		{ "Health.Name", "E_ModifierType::Health" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
		{ "Production.DisplayName", "Production" },
		{ "Production.Name", "E_ModifierType::Production" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "E_ModifierType::Production", (int64)E_ModifierType::Production },
		{ "E_ModifierType::Health", (int64)E_ModifierType::Health },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IdleGame_E_ModifierType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IdleGame,
	nullptr,
	"E_ModifierType",
	"E_ModifierType",
	Z_Construct_UEnum_IdleGame_E_ModifierType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IdleGame_E_ModifierType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IdleGame_E_ModifierType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IdleGame_E_ModifierType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IdleGame_E_ModifierType()
{
	if (!Z_Registration_Info_UEnum_E_ModifierType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_ModifierType.InnerSingleton, Z_Construct_UEnum_IdleGame_E_ModifierType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_E_ModifierType.InnerSingleton;
}
// End Enum E_ModifierType

// Begin ScriptStruct FS_CivilizationStructures
static_assert(std::is_polymorphic<FS_CivilizationStructures>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FS_CivilizationStructures cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_S_CivilizationStructures;
class UScriptStruct* FS_CivilizationStructures::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_S_CivilizationStructures.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_S_CivilizationStructures.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FS_CivilizationStructures, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("S_CivilizationStructures"));
	}
	return Z_Registration_Info_UScriptStruct_S_CivilizationStructures.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FS_CivilizationStructures>()
{
	return FS_CivilizationStructures::StaticStruct();
}
struct Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CivilizationNameStages_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingRegionID_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStageIndex_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerPlayer_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrowthRate_MetaData[] = {
		{ "Category", "Expansion" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpansionProgress_MetaData[] = {
		{ "Category", "Expansion" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpansionCost_MetaData[] = {
		{ "Category", "Expansion" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Location" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSize_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_CivilizationNameStages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CivilizationNameStages;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartingRegionID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStageIndex;
	static void NewProp_OwnerPlayer_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_OwnerPlayer;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Score;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GrowthRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExpansionProgress;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExpansionCost;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FS_CivilizationStructures>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CivilizationNameStages_Inner = { "CivilizationNameStages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CivilizationNameStages = { "CivilizationNameStages", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, CivilizationNameStages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CivilizationNameStages_MetaData), NewProp_CivilizationNameStages_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_StartingRegionID = { "StartingRegionID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, StartingRegionID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingRegionID_MetaData), NewProp_StartingRegionID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CurrentStageIndex = { "CurrentStageIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, CurrentStageIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStageIndex_MetaData), NewProp_CurrentStageIndex_MetaData) };
void Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_OwnerPlayer_SetBit(void* Obj)
{
	((FS_CivilizationStructures*)Obj)->OwnerPlayer = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_OwnerPlayer = { "OwnerPlayer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FS_CivilizationStructures), &Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_OwnerPlayer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerPlayer_MetaData), NewProp_OwnerPlayer_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, Score), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Score_MetaData), NewProp_Score_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_GrowthRate = { "GrowthRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, GrowthRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrowthRate_MetaData), NewProp_GrowthRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_ExpansionProgress = { "ExpansionProgress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, ExpansionProgress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpansionProgress_MetaData), NewProp_ExpansionProgress_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_ExpansionCost = { "ExpansionCost", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, ExpansionCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpansionCost_MetaData), NewProp_ExpansionCost_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, Location), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CurrentSize = { "CurrentSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, CurrentSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSize_MetaData), NewProp_CurrentSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_CivilizationStructures, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Color_MetaData), NewProp_Color_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CivilizationNameStages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CivilizationNameStages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_StartingRegionID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CurrentStageIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_OwnerPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_Score,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_GrowthRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_ExpansionProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_ExpansionCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_CurrentSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"S_CivilizationStructures",
	Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::PropPointers),
	sizeof(FS_CivilizationStructures),
	alignof(FS_CivilizationStructures),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FS_CivilizationStructures()
{
	if (!Z_Registration_Info_UScriptStruct_S_CivilizationStructures.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_S_CivilizationStructures.InnerSingleton, Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_S_CivilizationStructures.InnerSingleton;
}
// End ScriptStruct FS_CivilizationStructures

// Begin ScriptStruct FOwnedTilesSaveData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OwnedTilesSaveData;
class UScriptStruct* FOwnedTilesSaveData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OwnedTilesSaveData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OwnedTilesSaveData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOwnedTilesSaveData, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("OwnedTilesSaveData"));
	}
	return Z_Registration_Info_UScriptStruct_OwnedTilesSaveData.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FOwnedTilesSaveData>()
{
	return FOwnedTilesSaveData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CivID_MetaData[] = {
		{ "Category", "OwnedTilesSaveData" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tiles_MetaData[] = {
		{ "Category", "OwnedTilesSaveData" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CivID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tiles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Tiles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOwnedTilesSaveData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::NewProp_CivID = { "CivID", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOwnedTilesSaveData, CivID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CivID_MetaData), NewProp_CivID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::NewProp_Tiles_Inner = { "Tiles", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::NewProp_Tiles = { "Tiles", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOwnedTilesSaveData, Tiles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tiles_MetaData), NewProp_Tiles_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::NewProp_CivID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::NewProp_Tiles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::NewProp_Tiles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	nullptr,
	&NewStructOps,
	"OwnedTilesSaveData",
	Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::PropPointers),
	sizeof(FOwnedTilesSaveData),
	alignof(FOwnedTilesSaveData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOwnedTilesSaveData()
{
	if (!Z_Registration_Info_UScriptStruct_OwnedTilesSaveData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OwnedTilesSaveData.InnerSingleton, Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OwnedTilesSaveData.InnerSingleton;
}
// End ScriptStruct FOwnedTilesSaveData

// Begin ScriptStruct FS_ResourceData
static_assert(std::is_polymorphic<FS_ResourceData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FS_ResourceData cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_S_ResourceData;
class UScriptStruct* FS_ResourceData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_S_ResourceData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_S_ResourceData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FS_ResourceData, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("S_ResourceData"));
	}
	return Z_Registration_Info_UScriptStruct_S_ResourceData.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FS_ResourceData>()
{
	return FS_ResourceData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FS_ResourceData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResourceName_MetaData[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The name of the source that will appear in the UI (e.g., \xef\xbf\xbdIron Mine\xef\xbf\xbd)\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the source that will appear in the UI (e.g., \xef\xbf\xbdIron Mine\xef\xbf\xbd)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The icon that will appear on the map or in the menu for the source\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The icon that will appear on the map or in the menu for the source" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BonusType_MetaData[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The type of bonus provided by this source (selected from the enum above)\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The type of bonus provided by this source (selected from the enum above)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BonusValue_MetaData[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The numerical value of the bonus (e.g., 5.0, 0.05, etc.)\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The numerical value of the bonus (e.g., 5.0, 0.05, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRenewable_MetaData[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//For Future\n// This can be used in the future for the \xef\xbf\xbd""Declining Yield\xef\xbf\xbd system.\n// Leave it at 0 for now.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For Future\n This can be used in the future for the \xef\xbf\xbd""Declining Yield\xef\xbf\xbd system.\n Leave it at 0 for now." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmount_MetaData[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This is also for future systems.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is also for future systems." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_ResourceName;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BonusType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BonusType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BonusValue;
	static void NewProp_bIsRenewable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRenewable;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FS_ResourceData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_ResourceName = { "ResourceName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_ResourceData, ResourceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResourceName_MetaData), NewProp_ResourceName_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_ResourceData, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_BonusType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_BonusType = { "BonusType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_ResourceData, BonusType), Z_Construct_UEnum_IdleGame_E_BonusType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BonusType_MetaData), NewProp_BonusType_MetaData) }; // 4101986749
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_BonusValue = { "BonusValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_ResourceData, BonusValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BonusValue_MetaData), NewProp_BonusValue_MetaData) };
void Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_bIsRenewable_SetBit(void* Obj)
{
	((FS_ResourceData*)Obj)->bIsRenewable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_bIsRenewable = { "bIsRenewable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FS_ResourceData), &Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_bIsRenewable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRenewable_MetaData), NewProp_bIsRenewable_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_MaxAmount = { "MaxAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_ResourceData, MaxAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmount_MetaData), NewProp_MaxAmount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FS_ResourceData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_ResourceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_BonusType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_BonusType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_BonusValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_bIsRenewable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewProp_MaxAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_ResourceData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FS_ResourceData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"S_ResourceData",
	Z_Construct_UScriptStruct_FS_ResourceData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_ResourceData_Statics::PropPointers),
	sizeof(FS_ResourceData),
	alignof(FS_ResourceData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_ResourceData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FS_ResourceData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FS_ResourceData()
{
	if (!Z_Registration_Info_UScriptStruct_S_ResourceData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_S_ResourceData.InnerSingleton, Z_Construct_UScriptStruct_FS_ResourceData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_S_ResourceData.InnerSingleton;
}
// End ScriptStruct FS_ResourceData

// Begin ScriptStruct FS_ResourceNodeLocation
static_assert(std::is_polymorphic<FS_ResourceNodeLocation>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FS_ResourceNodeLocation cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation;
class UScriptStruct* FS_ResourceNodeLocation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FS_ResourceNodeLocation, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("S_ResourceNodeLocation"));
	}
	return Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FS_ResourceNodeLocation>()
{
	return FS_ResourceNodeLocation::StaticStruct();
}
struct Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResourceID_MetaData[] = {
		{ "Category", "Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The type of this resource point. This must match the name of a row in the DT_Resources Data Table.\n// Example: \xef\xbf\xbd""Forest\xef\xbf\xbd, \xef\xbf\xbdIron\xef\xbf\xbd, \xef\xbf\xbdOil\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The type of this resource point. This must match the name of a row in the DT_Resources Data Table.\nExample: \xef\xbf\xbd""Forest\xef\xbf\xbd, \xef\xbf\xbdIron\xef\xbf\xbd, \xef\xbf\xbdOil\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The exact (X, Y) pixel coordinates of this resource icon on the map.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The exact (X, Y) pixel coordinates of this resource icon on the map." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ResourceID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FS_ResourceNodeLocation>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::NewProp_ResourceID = { "ResourceID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_ResourceNodeLocation, ResourceID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResourceID_MetaData), NewProp_ResourceID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_ResourceNodeLocation, Location), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::NewProp_ResourceID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::NewProp_Location,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"S_ResourceNodeLocation",
	Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::PropPointers),
	sizeof(FS_ResourceNodeLocation),
	alignof(FS_ResourceNodeLocation),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FS_ResourceNodeLocation()
{
	if (!Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation.InnerSingleton, Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation.InnerSingleton;
}
// End ScriptStruct FS_ResourceNodeLocation

// Begin ScriptStruct FS_LiveResourceNode
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_S_LiveResourceNode;
class UScriptStruct* FS_LiveResourceNode::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_S_LiveResourceNode.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_S_LiveResourceNode.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FS_LiveResourceNode, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("S_LiveResourceNode"));
	}
	return Z_Registration_Info_UScriptStruct_S_LiveResourceNode.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FS_LiveResourceNode>()
{
	return FS_LiveResourceNode::StaticStruct();
}
struct Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResourceTypeID_MetaData[] = {
		{ "Category", "Resource Node" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The line name in DT_Resources that specifies the type of this resource.\n// This is set once at the start of the game and does not change.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The line name in DT_Resources that specifies the type of this resource.\nThis is set once at the start of the game and does not change." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Resource Node" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The location of this resource on the map.\n// This is set once at the start of the game and does not change.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The location of this resource on the map.\nThis is set once at the start of the game and does not change." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmount_MetaData[] = {
		{ "Category", "Resource Node" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This is the theoretical maximum amount of this resource.\n// It is set once at the beginning of the game and does not change.\n//Maybe we dont need to set in this variable, because we already have it.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is the theoretical maximum amount of this resource.\nIt is set once at the beginning of the game and does not change.\nMaybe we dont need to set in this variable, because we already have it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAmount_MetaData[] = {
		{ "Category", "Resource Node" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// the only variable that changes during the game\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "the only variable that changes during the game" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ResourceTypeID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FS_LiveResourceNode>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_ResourceTypeID = { "ResourceTypeID", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_LiveResourceNode, ResourceTypeID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResourceTypeID_MetaData), NewProp_ResourceTypeID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_LiveResourceNode, Location), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_MaxAmount = { "MaxAmount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_LiveResourceNode, MaxAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmount_MetaData), NewProp_MaxAmount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_CurrentAmount = { "CurrentAmount", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_LiveResourceNode, CurrentAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAmount_MetaData), NewProp_CurrentAmount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_ResourceTypeID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_MaxAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewProp_CurrentAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	nullptr,
	&NewStructOps,
	"S_LiveResourceNode",
	Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::PropPointers),
	sizeof(FS_LiveResourceNode),
	alignof(FS_LiveResourceNode),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FS_LiveResourceNode()
{
	if (!Z_Registration_Info_UScriptStruct_S_LiveResourceNode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_S_LiveResourceNode.InnerSingleton, Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_S_LiveResourceNode.InnerSingleton;
}
// End ScriptStruct FS_LiveResourceNode

// Begin ScriptStruct FS_BuildingData
static_assert(std::is_polymorphic<FS_BuildingData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FS_BuildingData cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_S_BuildingData;
class UScriptStruct* FS_BuildingData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_S_BuildingData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_S_BuildingData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FS_BuildingData, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("S_BuildingData"));
	}
	return Z_Registration_Info_UScriptStruct_S_BuildingData.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FS_BuildingData>()
{
	return FS_BuildingData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FS_BuildingData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuildingName_MetaData[] = {
		{ "Category", "S_BuildingData" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "S_BuildingData" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseCost_MetaData[] = {
		{ "Category", "S_BuildingData" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PointsPerSecond_MetaData[] = {
		{ "Category", "S_BuildingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The base cost of the building, @TODO which will be multiplied by the level\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The base cost of the building, @TODO which will be multiplied by the level" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModifierType_MetaData[] = {
		{ "Category", "S_BuildingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// How many points a single level of this building produces\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How many points a single level of this building produces" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModifierValue_MetaData[] = {
		{ "Category", "S_BuildingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// New Enum: Health, Production, Culture, etc.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "New Enum: Health, Production, Culture, etc." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredRegionID_MetaData[] = {
		{ "Category", "S_BuildingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Bonus amount (e.g., +5% Production)\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bonus amount (e.g., +5% Production)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_BuildingName;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseCost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PointsPerSecond;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ModifierType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ModifierType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ModifierValue;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequiredRegionID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FS_BuildingData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_BuildingName = { "BuildingName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_BuildingData, BuildingName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuildingName_MetaData), NewProp_BuildingName_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_BuildingData, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_BaseCost = { "BaseCost", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_BuildingData, BaseCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseCost_MetaData), NewProp_BaseCost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_PointsPerSecond = { "PointsPerSecond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_BuildingData, PointsPerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PointsPerSecond_MetaData), NewProp_PointsPerSecond_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_ModifierType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_ModifierType = { "ModifierType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_BuildingData, ModifierType), Z_Construct_UEnum_IdleGame_E_ModifierType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModifierType_MetaData), NewProp_ModifierType_MetaData) }; // 4109729050
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_ModifierValue = { "ModifierValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_BuildingData, ModifierValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModifierValue_MetaData), NewProp_ModifierValue_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_RequiredRegionID = { "RequiredRegionID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_BuildingData, RequiredRegionID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredRegionID_MetaData), NewProp_RequiredRegionID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FS_BuildingData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_BuildingName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_BaseCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_PointsPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_ModifierType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_ModifierType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_ModifierValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewProp_RequiredRegionID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_BuildingData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FS_BuildingData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"S_BuildingData",
	Z_Construct_UScriptStruct_FS_BuildingData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_BuildingData_Statics::PropPointers),
	sizeof(FS_BuildingData),
	alignof(FS_BuildingData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_BuildingData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FS_BuildingData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FS_BuildingData()
{
	if (!Z_Registration_Info_UScriptStruct_S_BuildingData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_S_BuildingData.InnerSingleton, Z_Construct_UScriptStruct_FS_BuildingData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_S_BuildingData.InnerSingleton;
}
// End ScriptStruct FS_BuildingData

// Begin ScriptStruct FS_RegionState
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_S_RegionState;
class UScriptStruct* FS_RegionState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_S_RegionState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_S_RegionState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FS_RegionState, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("S_RegionState"));
	}
	return Z_Registration_Info_UScriptStruct_S_RegionState.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FS_RegionState>()
{
	return FS_RegionState::StaticStruct();
}
struct Z_Construct_UScriptStruct_FS_RegionState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionID_MetaData[] = {
		{ "Category", "S_RegionState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Which region it is (1=North America, 2=Europe, etc.)\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Which region it is (1=North America, 2=Europe, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControlPercentage_MetaData[] = {
		{ "Category", "S_RegionState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Our control ratio in this region. Between 0.0 (0%) and 1.0 (100%).\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Our control ratio in this region. Between 0.0 (0%) and 1.0 (100%)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuildingLevels_MetaData[] = {
		{ "Category", "S_RegionState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Keeps track of how many there are in each building.\n// Key: FName (row name in DT_Buildings), Value: int32 (level/number)\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps track of how many there are in each building.\nKey: FName (row name in DT_Buildings), Value: int32 (level/number)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RegionID;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ControlPercentage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BuildingLevels_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_BuildingLevels_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_BuildingLevels;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FS_RegionState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_RegionID = { "RegionID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_RegionState, RegionID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionID_MetaData), NewProp_RegionID_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_ControlPercentage = { "ControlPercentage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_RegionState, ControlPercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControlPercentage_MetaData), NewProp_ControlPercentage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_BuildingLevels_ValueProp = { "BuildingLevels", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_BuildingLevels_Key_KeyProp = { "BuildingLevels_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_BuildingLevels = { "BuildingLevels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_RegionState, BuildingLevels), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuildingLevels_MetaData), NewProp_BuildingLevels_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FS_RegionState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_RegionID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_ControlPercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_BuildingLevels_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_BuildingLevels_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionState_Statics::NewProp_BuildingLevels,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_RegionState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FS_RegionState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	nullptr,
	&NewStructOps,
	"S_RegionState",
	Z_Construct_UScriptStruct_FS_RegionState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_RegionState_Statics::PropPointers),
	sizeof(FS_RegionState),
	alignof(FS_RegionState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_RegionState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FS_RegionState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FS_RegionState()
{
	if (!Z_Registration_Info_UScriptStruct_S_RegionState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_S_RegionState.InnerSingleton, Z_Construct_UScriptStruct_FS_RegionState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_S_RegionState.InnerSingleton;
}
// End ScriptStruct FS_RegionState

// Begin ScriptStruct FS_RegionData
static_assert(std::is_polymorphic<FS_RegionData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FS_RegionData cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_S_RegionData;
class UScriptStruct* FS_RegionData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_S_RegionData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_S_RegionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FS_RegionData, (UObject*)Z_Construct_UPackage__Script_IdleGame(), TEXT("S_RegionData"));
	}
	return Z_Registration_Info_UScriptStruct_S_RegionData.OuterSingleton;
}
template<> IDLEGAME_API UScriptStruct* StaticStruct<FS_RegionData>()
{
	return FS_RegionData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FS_RegionData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionName_MetaData[] = {
		{ "Category", "Region Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The name of the region that will appear in the UI.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the region that will appear in the UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseProductionRate_MetaData[] = {
		{ "Category", "Region Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// In case we want to add a specific base production rate for this region later.\n// For now, it can be left at 0.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "In case we want to add a specific base production rate for this region later.\nFor now, it can be left at 0." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NeighboringRegionIDs_MetaData[] = {
		{ "Category", "Region Data" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_RegionName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseProductionRate;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NeighboringRegionIDs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NeighboringRegionIDs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FS_RegionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_RegionName = { "RegionName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_RegionData, RegionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionName_MetaData), NewProp_RegionName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_BaseProductionRate = { "BaseProductionRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_RegionData, BaseProductionRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseProductionRate_MetaData), NewProp_BaseProductionRate_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_NeighboringRegionIDs_Inner = { "NeighboringRegionIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_NeighboringRegionIDs = { "NeighboringRegionIDs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FS_RegionData, NeighboringRegionIDs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NeighboringRegionIDs_MetaData), NewProp_NeighboringRegionIDs_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FS_RegionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_RegionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_BaseProductionRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_NeighboringRegionIDs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FS_RegionData_Statics::NewProp_NeighboringRegionIDs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_RegionData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FS_RegionData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"S_RegionData",
	Z_Construct_UScriptStruct_FS_RegionData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_RegionData_Statics::PropPointers),
	sizeof(FS_RegionData),
	alignof(FS_RegionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FS_RegionData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FS_RegionData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FS_RegionData()
{
	if (!Z_Registration_Info_UScriptStruct_S_RegionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_S_RegionData.InnerSingleton, Z_Construct_UScriptStruct_FS_RegionData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_S_RegionData.InnerSingleton;
}
// End ScriptStruct FS_RegionData

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ E_BonusType_StaticEnum, TEXT("E_BonusType"), &Z_Registration_Info_UEnum_E_BonusType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4101986749U) },
		{ E_ModifierType_StaticEnum, TEXT("E_ModifierType"), &Z_Registration_Info_UEnum_E_ModifierType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4109729050U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FS_CivilizationStructures::StaticStruct, Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewStructOps, TEXT("S_CivilizationStructures"), &Z_Registration_Info_UScriptStruct_S_CivilizationStructures, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_CivilizationStructures), 2612190472U) },
		{ FOwnedTilesSaveData::StaticStruct, Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics::NewStructOps, TEXT("OwnedTilesSaveData"), &Z_Registration_Info_UScriptStruct_OwnedTilesSaveData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOwnedTilesSaveData), 133798282U) },
		{ FS_ResourceData::StaticStruct, Z_Construct_UScriptStruct_FS_ResourceData_Statics::NewStructOps, TEXT("S_ResourceData"), &Z_Registration_Info_UScriptStruct_S_ResourceData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_ResourceData), 2062978358U) },
		{ FS_ResourceNodeLocation::StaticStruct, Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics::NewStructOps, TEXT("S_ResourceNodeLocation"), &Z_Registration_Info_UScriptStruct_S_ResourceNodeLocation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_ResourceNodeLocation), 2244829639U) },
		{ FS_LiveResourceNode::StaticStruct, Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics::NewStructOps, TEXT("S_LiveResourceNode"), &Z_Registration_Info_UScriptStruct_S_LiveResourceNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_LiveResourceNode), 1104059021U) },
		{ FS_BuildingData::StaticStruct, Z_Construct_UScriptStruct_FS_BuildingData_Statics::NewStructOps, TEXT("S_BuildingData"), &Z_Registration_Info_UScriptStruct_S_BuildingData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_BuildingData), 43458023U) },
		{ FS_RegionState::StaticStruct, Z_Construct_UScriptStruct_FS_RegionState_Statics::NewStructOps, TEXT("S_RegionState"), &Z_Registration_Info_UScriptStruct_S_RegionState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_RegionState), 3714863697U) },
		{ FS_RegionData::StaticStruct, Z_Construct_UScriptStruct_FS_RegionData_Statics::NewStructOps, TEXT("S_RegionData"), &Z_Registration_Info_UScriptStruct_S_RegionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_RegionData), 285400636U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_1254740967(TEXT("/Script/IdleGame"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
