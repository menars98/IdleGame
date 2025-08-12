// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IdleGame/Public/Widgets/IdleGameWidgetBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIdleGameWidgetBase() {}

// Begin Cross Module References
IDLEGAME_API UClass* Z_Construct_UClass_UIdleGameWidgetBase();
IDLEGAME_API UClass* Z_Construct_UClass_UIdleGameWidgetBase_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_IdleGame();
// End Cross Module References

// Begin Class UIdleGameWidgetBase Function CreateResourceIcons
static const FName NAME_UIdleGameWidgetBase_CreateResourceIcons = FName(TEXT("CreateResourceIcons"));
void UIdleGameWidgetBase::CreateResourceIcons()
{
	UFunction* Func = FindFunctionChecked(NAME_UIdleGameWidgetBase_CreateResourceIcons);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UIdleGameWidgetBase_CreateResourceIcons_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Layout" },
		{ "ModuleRelativePath", "Public/Widgets/IdleGameWidgetBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UIdleGameWidgetBase_CreateResourceIcons_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIdleGameWidgetBase, nullptr, "CreateResourceIcons", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UIdleGameWidgetBase_CreateResourceIcons_Statics::Function_MetaDataParams), Z_Construct_UFunction_UIdleGameWidgetBase_CreateResourceIcons_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UIdleGameWidgetBase_CreateResourceIcons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UIdleGameWidgetBase_CreateResourceIcons_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class UIdleGameWidgetBase Function CreateResourceIcons

// Begin Class UIdleGameWidgetBase
void UIdleGameWidgetBase::StaticRegisterNativesUIdleGameWidgetBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UIdleGameWidgetBase);
UClass* Z_Construct_UClass_UIdleGameWidgetBase_NoRegister()
{
	return UIdleGameWidgetBase::StaticClass();
}
struct Z_Construct_UClass_UIdleGameWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Widgets/IdleGameWidgetBase.h" },
		{ "ModuleRelativePath", "Public/Widgets/IdleGameWidgetBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UIdleGameWidgetBase_CreateResourceIcons, "CreateResourceIcons" }, // 1679340547
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIdleGameWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UIdleGameWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIdleGameWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UIdleGameWidgetBase_Statics::ClassParams = {
	&UIdleGameWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIdleGameWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UIdleGameWidgetBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UIdleGameWidgetBase()
{
	if (!Z_Registration_Info_UClass_UIdleGameWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIdleGameWidgetBase.OuterSingleton, Z_Construct_UClass_UIdleGameWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UIdleGameWidgetBase.OuterSingleton;
}
template<> IDLEGAME_API UClass* StaticClass<UIdleGameWidgetBase>()
{
	return UIdleGameWidgetBase::StaticClass();
}
UIdleGameWidgetBase::UIdleGameWidgetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UIdleGameWidgetBase);
UIdleGameWidgetBase::~UIdleGameWidgetBase() {}
// End Class UIdleGameWidgetBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Widgets_IdleGameWidgetBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UIdleGameWidgetBase, UIdleGameWidgetBase::StaticClass, TEXT("UIdleGameWidgetBase"), &Z_Registration_Info_UClass_UIdleGameWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIdleGameWidgetBase), 1166837324U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Widgets_IdleGameWidgetBase_h_2293016211(TEXT("/Script/IdleGame"),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Widgets_IdleGameWidgetBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Widgets_IdleGameWidgetBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
