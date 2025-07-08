// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IdleGame/Public/IdleGameSave.h"
#include "IdleGame/Public/IdleGameTypes.h"
#include "IdleGame/Public/Managers/IGCivilizationManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIdleGameSave() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
ENGINE_API UClass* Z_Construct_UClass_USaveGame();
IDLEGAME_API UClass* Z_Construct_UClass_UIdleGameSave();
IDLEGAME_API UClass* Z_Construct_UClass_UIdleGameSave_NoRegister();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FMapRow();
IDLEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FS_CivilizationStructures();
UPackage* Z_Construct_UPackage__Script_IdleGame();
// End Cross Module References

// Begin Class UIdleGameSave
void UIdleGameSave::StaticRegisterNativesUIdleGameSave()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UIdleGameSave);
UClass* Z_Construct_UClass_UIdleGameSave_NoRegister()
{
	return UIdleGameSave::StaticClass();
}
struct Z_Construct_UClass_UIdleGameSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "IdleGameSave.h" },
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedCivilizations_MetaData[] = {
		{ "Category", "SaveData|Civilizations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//-- Data For Civilizations ---\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "-- Data For Civilizations ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedCivilizationMapData_MetaData[] = {
		{ "Category", "SaveData|Civilizations|Map" },
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCivColors_MetaData[] = {
		{ "Category", "SaveData|Civilizations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Map that holds which CivID has which color.\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map that holds which CivID has which color." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedPoints_MetaData[] = {
		{ "Category", "SaveData|Player|Points" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Data for PlayerState ---\n// ... Add fields here for all other important variables in PlayerState.\n// For example: float SavedClickerPoints; float SavedPointsPerSecond;\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Data for PlayerState ---\n... Add fields here for all other important variables in PlayerState.\nFor example: float SavedClickerPoints; float SavedPointsPerSecond;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedTotalPoints_MetaData[] = {
		{ "Category", "SaveData|Player|Points" },
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayedPoints_MetaData[] = {
		{ "Category", "SaveData|Player|Points" },
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedPointsPerSecond_MetaData[] = {
		{ "Category", "SaveData|Player|Points" },
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedPointsPerClick_MetaData[] = {
		{ "Category", "SaveData|Player|Points" },
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedKardashevScale_MetaData[] = {
		{ "Category", "SaveData|Player|Points" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//ClickerPoints\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ClickerPoints" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedLevel_MetaData[] = {
		{ "Category", "SaveData|Player|Level" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Now we dont use right now but we can add scale points later.\n//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = \"SaveData|Player|Points\")\n//float SavedPointsPerClickMultiplier; \n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Now we dont use right now but we can add scale points later.\nUPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = \"SaveData|Player|Points\")\nfloat SavedPointsPerClickMultiplier;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedCurrentLevelMap_MetaData[] = {
		{ "Category", "SaveData|Player|Level" },
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedLastScreenIndex_MetaData[] = {
		{ "Category", "SaveData|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- UI Durumu -\n" },
#endif
		{ "ModuleRelativePath", "Public/IdleGameSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- UI Durumu -" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedCivilizations_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedCivilizations;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedCivilizationMapData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedCivilizationMapData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentCivColors_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCivColors_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_CurrentCivColors;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SavedPoints;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SavedTotalPoints;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DisplayedPoints;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SavedPointsPerSecond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SavedPointsPerClick;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SavedKardashevScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SavedLevel;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SavedCurrentLevelMap_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SavedCurrentLevelMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SavedCurrentLevelMap;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SavedLastScreenIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIdleGameSave>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizations_Inner = { "SavedCivilizations", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FS_CivilizationStructures, METADATA_PARAMS(0, nullptr) }; // 761573513
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizations = { "SavedCivilizations", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedCivilizations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedCivilizations_MetaData), NewProp_SavedCivilizations_MetaData) }; // 761573513
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizationMapData_Inner = { "SavedCivilizationMapData", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMapRow, METADATA_PARAMS(0, nullptr) }; // 3300761288
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizationMapData = { "SavedCivilizationMapData", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedCivilizationMapData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedCivilizationMapData_MetaData), NewProp_SavedCivilizationMapData_MetaData) }; // 3300761288
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_CurrentCivColors_ValueProp = { "CurrentCivColors", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_CurrentCivColors_Key_KeyProp = { "CurrentCivColors_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_CurrentCivColors = { "CurrentCivColors", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, CurrentCivColors), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCivColors_MetaData), NewProp_CurrentCivColors_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedPoints = { "SavedPoints", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedPoints_MetaData), NewProp_SavedPoints_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedTotalPoints = { "SavedTotalPoints", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedTotalPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedTotalPoints_MetaData), NewProp_SavedTotalPoints_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_DisplayedPoints = { "DisplayedPoints", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, DisplayedPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayedPoints_MetaData), NewProp_DisplayedPoints_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedPointsPerSecond = { "SavedPointsPerSecond", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedPointsPerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedPointsPerSecond_MetaData), NewProp_SavedPointsPerSecond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedPointsPerClick = { "SavedPointsPerClick", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedPointsPerClick), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedPointsPerClick_MetaData), NewProp_SavedPointsPerClick_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedKardashevScale = { "SavedKardashevScale", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedKardashevScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedKardashevScale_MetaData), NewProp_SavedKardashevScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedLevel = { "SavedLevel", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedLevel_MetaData), NewProp_SavedLevel_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCurrentLevelMap_ValueProp = { "SavedCurrentLevelMap", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCurrentLevelMap_Key_KeyProp = { "SavedCurrentLevelMap_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCurrentLevelMap = { "SavedCurrentLevelMap", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedCurrentLevelMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedCurrentLevelMap_MetaData), NewProp_SavedCurrentLevelMap_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedLastScreenIndex = { "SavedLastScreenIndex", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIdleGameSave, SavedLastScreenIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedLastScreenIndex_MetaData), NewProp_SavedLastScreenIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UIdleGameSave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizationMapData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCivilizationMapData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_CurrentCivColors_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_CurrentCivColors_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_CurrentCivColors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedTotalPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_DisplayedPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedPointsPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedPointsPerClick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedKardashevScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCurrentLevelMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCurrentLevelMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedCurrentLevelMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIdleGameSave_Statics::NewProp_SavedLastScreenIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIdleGameSave_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UIdleGameSave_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USaveGame,
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIdleGameSave_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UIdleGameSave_Statics::ClassParams = {
	&UIdleGameSave::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UIdleGameSave_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UIdleGameSave_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIdleGameSave_Statics::Class_MetaDataParams), Z_Construct_UClass_UIdleGameSave_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UIdleGameSave()
{
	if (!Z_Registration_Info_UClass_UIdleGameSave.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIdleGameSave.OuterSingleton, Z_Construct_UClass_UIdleGameSave_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UIdleGameSave.OuterSingleton;
}
template<> IDLEGAME_API UClass* StaticClass<UIdleGameSave>()
{
	return UIdleGameSave::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UIdleGameSave);
UIdleGameSave::~UIdleGameSave() {}
// End Class UIdleGameSave

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameSave_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UIdleGameSave, UIdleGameSave::StaticClass, TEXT("UIdleGameSave"), &Z_Registration_Info_UClass_UIdleGameSave, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIdleGameSave), 3042954646U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameSave_h_2207095675(TEXT("/Script/IdleGame"),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameSave_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameSave_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
