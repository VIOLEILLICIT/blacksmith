// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SharedTypes.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BLACKSMITH_SharedTypes_generated_h
#error "SharedTypes.generated.h already included, missing '#pragma once' in SharedTypes.h"
#endif
#define BLACKSMITH_SharedTypes_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_blacksmith_blacksmith_Source_blacksmith_SharedTypes_h


#define FOREACH_ENUM_ENPCJOB(op) \
	op(ENPCJob::None) \
	op(ENPCJob::Blacksmith) \
	op(ENPCJob::Merchant) \
	op(ENPCJob::Villager) 

enum class ENPCJob : uint8;
template<> struct TIsUEnumClass<ENPCJob> { enum { Value = true }; };
template<> BLACKSMITH_API UEnum* StaticEnum<ENPCJob>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
