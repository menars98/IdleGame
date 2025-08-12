// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "IdleGameTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IDLEGAME_IdleGameTypes_generated_h
#error "IdleGameTypes.generated.h already included, missing '#pragma once' in IdleGameTypes.h"
#endif
#define IDLEGAME_IdleGameTypes_generated_h

#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FS_CivilizationStructures_Statics; \
	IDLEGAME_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> IDLEGAME_API UScriptStruct* StaticStruct<struct FS_CivilizationStructures>();

#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_63_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOwnedTilesSaveData_Statics; \
	IDLEGAME_API static class UScriptStruct* StaticStruct();


template<> IDLEGAME_API UScriptStruct* StaticStruct<struct FOwnedTilesSaveData>();

#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_75_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FS_ResourceData_Statics; \
	IDLEGAME_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> IDLEGAME_API UScriptStruct* StaticStruct<struct FS_ResourceData>();

#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_107_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FS_ResourceNodeLocation_Statics; \
	IDLEGAME_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> IDLEGAME_API UScriptStruct* StaticStruct<struct FS_ResourceNodeLocation>();

#define FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h_123_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FS_LiveResourceNode_Statics; \
	IDLEGAME_API static class UScriptStruct* StaticStruct();


template<> IDLEGAME_API UScriptStruct* StaticStruct<struct FS_LiveResourceNode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_muham_Documents_GitHub_IdleGame_IdleGame_Source_IdleGame_Public_IdleGameTypes_h


#define FOREACH_ENUM_E_BONUSTYPE(op) \
	op(E_BonusType::AddPointsPerSecond) \
	op(E_BonusType::MultiplyAllGains) \
	op(E_BonusType::ReduceUpgradeCost) \
	op(E_BonusType::AddClickPower) 

enum class E_BonusType : uint8;
template<> struct TIsUEnumClass<E_BonusType> { enum { Value = true }; };
template<> IDLEGAME_API UEnum* StaticEnum<E_BonusType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
