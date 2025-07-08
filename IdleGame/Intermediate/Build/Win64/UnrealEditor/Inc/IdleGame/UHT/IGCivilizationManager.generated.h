// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Managers/IGCivilizationManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 struct FColor;
struct FColor;
struct FMapRow;
struct FS_CivilizationStructures;
#ifdef IDLEGAME_IGCivilizationManager_generated_h
#error "IGCivilizationManager.generated.h already included, missing '#pragma once' in IGCivilizationManager.h"
#endif
#define IDLEGAME_IGCivilizationManager_generated_h

#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMapRow_Statics; \
	IDLEGAME_API static class UScriptStruct* StaticStruct();


template<> IDLEGAME_API UScriptStruct* StaticStruct<struct FMapRow>();

#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindAllSpawnableLocations); \
	DECLARE_FUNCTION(execRedrawEntireMap); \
	DECLARE_FUNCTION(execApplyCivilizationMapData); \
	DECLARE_FUNCTION(execGetCivilizationMap); \
	DECLARE_FUNCTION(execLoadGame); \
	DECLARE_FUNCTION(execSaveGame); \
	DECLARE_FUNCTION(execGetRegionIDAtLocation); \
	DECLARE_FUNCTION(execGetRandomSpawnableLocation); \
	DECLARE_FUNCTION(execUpdateCivilizationData); \
	DECLARE_FUNCTION(execClaimTileForCivilization); \
	DECLARE_FUNCTION(execClaimInitialAreaForCivilization); \
	DECLARE_FUNCTION(execInitializeMapArray); \
	DECLARE_FUNCTION(execDiagnoseMapDataAtPoint);


#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAIGCivilizationManager(); \
	friend struct Z_Construct_UClass_AIGCivilizationManager_Statics; \
public: \
	DECLARE_CLASS(AIGCivilizationManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IdleGame"), NO_API) \
	DECLARE_SERIALIZER(AIGCivilizationManager)


#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AIGCivilizationManager(AIGCivilizationManager&&); \
	AIGCivilizationManager(const AIGCivilizationManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AIGCivilizationManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AIGCivilizationManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AIGCivilizationManager) \
	NO_API virtual ~AIGCivilizationManager();


#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_23_PROLOG
#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_26_INCLASS_NO_PURE_DECLS \
	FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IDLEGAME_API UClass* StaticClass<class AIGCivilizationManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_Managers_IGCivilizationManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
