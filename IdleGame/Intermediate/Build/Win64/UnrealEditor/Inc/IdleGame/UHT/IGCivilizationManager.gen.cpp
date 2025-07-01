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
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
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

// Begin Class AIGCivilizationManager Function CollectLandCells
struct Z_Construct_UFunction_AIGCivilizationManager_CollectLandCells_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_CollectLandCells_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "CollectLandCells", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_CollectLandCells_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_CollectLandCells_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AIGCivilizationManager_CollectLandCells()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_CollectLandCells_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execCollectLandCells)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CollectLandCells();
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function CollectLandCells

// Begin Class AIGCivilizationManager Function GetRandomLandCell
struct Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics
{
	struct IGCivilizationManager_eventGetRandomLandCell_Parms
	{
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGCivilizationManager_eventGetRandomLandCell_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "GetRandomLandCell", nullptr, nullptr, Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::PropPointers), sizeof(Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::IGCivilizationManager_eventGetRandomLandCell_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04880401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::IGCivilizationManager_eventGetRandomLandCell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AIGCivilizationManager::execGetRandomLandCell)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->GetRandomLandCell();
	P_NATIVE_END;
}
// End Class AIGCivilizationManager Function GetRandomLandCell

// Begin Class AIGCivilizationManager Function InitializeMapArray
struct Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AIGCivilizationManager, nullptr, "InitializeMapArray", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray_Statics::Function_MetaDataParams) };
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

// Begin Class AIGCivilizationManager
void AIGCivilizationManager::StaticRegisterNativesAIGCivilizationManager()
{
	UClass* Class = AIGCivilizationManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CollectLandCells", &AIGCivilizationManager::execCollectLandCells },
		{ "GetRandomLandCell", &AIGCivilizationManager::execGetRandomLandCell },
		{ "InitializeMapArray", &AIGCivilizationManager::execInitializeMapArray },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapArray_MetaData[] = {
		{ "Category", "Map" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Map Data\n" },
#endif
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map Data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Texture_MetaData[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapWidth_MetaData[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapHeight_MetaData[] = {
		{ "Category", "Map" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartPoint_MetaData[] = {
		{ "Category", "Civilization" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LandCells_MetaData[] = {
		{ "Category", "Civilization" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenPoint_MetaData[] = {
		{ "Category", "Civilization" },
		{ "ModuleRelativePath", "Public/Managers/IGCivilizationManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MapArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MapArray;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MapWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MapHeight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartPoint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LandCells_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LandCells;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChosenPoint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AIGCivilizationManager_CollectLandCells, "CollectLandCells" }, // 2711671651
		{ &Z_Construct_UFunction_AIGCivilizationManager_GetRandomLandCell, "GetRandomLandCell" }, // 564338063
		{ &Z_Construct_UFunction_AIGCivilizationManager_InitializeMapArray, "InitializeMapArray" }, // 2728441281
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AIGCivilizationManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapArray_Inner = { "MapArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMapRow, METADATA_PARAMS(0, nullptr) }; // 3300761288
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapArray = { "MapArray", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, MapArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapArray_MetaData), NewProp_MapArray_MetaData) }; // 3300761288
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Texture_MetaData), NewProp_Texture_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapWidth = { "MapWidth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, MapWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapWidth_MetaData), NewProp_MapWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapHeight = { "MapHeight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, MapHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapHeight_MetaData), NewProp_MapHeight_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_StartPoint = { "StartPoint", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, StartPoint), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartPoint_MetaData), NewProp_StartPoint_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_LandCells_Inner = { "LandCells", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_LandCells = { "LandCells", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, LandCells), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LandCells_MetaData), NewProp_LandCells_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_ChosenPoint = { "ChosenPoint", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIGCivilizationManager, ChosenPoint), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenPoint_MetaData), NewProp_ChosenPoint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AIGCivilizationManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_Texture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_MapHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_StartPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_LandCells_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_LandCells,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIGCivilizationManager_Statics::NewProp_ChosenPoint,
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
		{ Z_Construct_UClass_AIGCivilizationManager, AIGCivilizationManager::StaticClass, TEXT("AIGCivilizationManager"), &Z_Registration_Info_UClass_AIGCivilizationManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AIGCivilizationManager), 222399435U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_2477659013(TEXT("/Script/IdleGame"),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
