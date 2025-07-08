// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IdleGame/Public/Components/IdleCivManagerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIdleCivManagerComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
IDLEGAME_API UClass* Z_Construct_UClass_UIdleCivManagerComponent();
IDLEGAME_API UClass* Z_Construct_UClass_UIdleCivManagerComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_IdleGame();
// End Cross Module References

// Begin Class UIdleCivManagerComponent
void UIdleCivManagerComponent::StaticRegisterNativesUIdleCivManagerComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UIdleCivManagerComponent);
UClass* Z_Construct_UClass_UIdleCivManagerComponent_NoRegister()
{
	return UIdleCivManagerComponent::StaticClass();
}
struct Z_Construct_UClass_UIdleCivManagerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*USTRUCT(BlueprintType)\nstruct FMapRow\n{\n\x09GENERATED_BODY()\n\n\x09UPROPERTY(BlueprintReadOnly)\n\x09TArray<int32> Row;\n};\n*/" },
#endif
		{ "IncludePath", "Components/IdleCivManagerComponent.h" },
		{ "ModuleRelativePath", "Public/Components/IdleCivManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USTRUCT(BlueprintType)\nstruct FMapRow\n{\n       GENERATED_BODY()\n\n       UPROPERTY(BlueprintReadOnly)\n       TArray<int32> Row;\n};" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIdleCivManagerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UIdleCivManagerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_IdleGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIdleCivManagerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UIdleCivManagerComponent_Statics::ClassParams = {
	&UIdleCivManagerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIdleCivManagerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UIdleCivManagerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UIdleCivManagerComponent()
{
	if (!Z_Registration_Info_UClass_UIdleCivManagerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIdleCivManagerComponent.OuterSingleton, Z_Construct_UClass_UIdleCivManagerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UIdleCivManagerComponent.OuterSingleton;
}
template<> IDLEGAME_API UClass* StaticClass<UIdleCivManagerComponent>()
{
	return UIdleCivManagerComponent::StaticClass();
}
UIdleCivManagerComponent::UIdleCivManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UIdleCivManagerComponent);
UIdleCivManagerComponent::~UIdleCivManagerComponent() {}
// End Class UIdleCivManagerComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Components_IdleCivManagerComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UIdleCivManagerComponent, UIdleCivManagerComponent::StaticClass, TEXT("UIdleCivManagerComponent"), &Z_Registration_Info_UClass_UIdleCivManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIdleCivManagerComponent), 1883888725U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Components_IdleCivManagerComponent_h_2314110424(TEXT("/Script/IdleGame"),
	Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Components_IdleCivManagerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Components_IdleCivManagerComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
