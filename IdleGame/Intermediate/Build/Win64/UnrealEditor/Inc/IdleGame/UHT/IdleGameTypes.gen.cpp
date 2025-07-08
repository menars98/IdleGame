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
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_CivilizationStructures();
UPackage* Z_Construct_UPackage__Script_IdleGame();
// End Cross Module References

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
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Blueprint'teki t\xef\xbf\xbdm de\xef\xbf\xbdi\xef\xbf\xbdkenlerinizi buraya C++ versiyonlar\xef\xbf\xbdyla ta\xef\xbf\xbd\xef\xbf\xbdy\xef\xbf\xbdn\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint'teki t\xef\xbf\xbdm de\xef\xbf\xbdi\xef\xbf\xbdkenlerinizi buraya C++ versiyonlar\xef\xbf\xbdyla ta\xef\xbf\xbd\xef\xbf\xbdy\xef\xbf\xbdn" },
#endif
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
		{ "Category", "S_CivilizationStructures" },
		{ "ModuleRelativePath", "Public/IdleGameTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "S_CivilizationStructures" },
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

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FS_CivilizationStructures::StaticStruct, Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics::NewStructOps, TEXT("S_CivilizationStructures"), &Z_Registration_Info_UScriptStruct_S_CivilizationStructures, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FS_CivilizationStructures), 761573513U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_918235409(TEXT("/Script/IdleGame"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
