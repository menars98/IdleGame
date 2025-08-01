// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIdleGame_init() {}
	IDLEGAME_API UFunction* Z_Construct_UDelegateFunction_IdleGame_OnDynamicTextureReady__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_IdleGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_IdleGame()
	{
		if (!Z_Registration_Info_UPackage__Script_IdleGame.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_IdleGame_OnDynamicTextureReady__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/IdleGame",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x268709AB,
				0xC404EBDA,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_IdleGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_IdleGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_IdleGame(Z_Construct_UPackage__Script_IdleGame, TEXT("/Script/IdleGame"), Z_Registration_Info_UPackage__Script_IdleGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x268709AB, 0xC404EBDA));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
