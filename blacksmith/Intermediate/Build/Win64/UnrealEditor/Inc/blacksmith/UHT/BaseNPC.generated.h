// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BaseNPC.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BLACKSMITH_BaseNPC_generated_h
#error "BaseNPC.generated.h already included, missing '#pragma once' in BaseNPC.h"
#endif
#define BLACKSMITH_BaseNPC_generated_h

#define FID_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseNPC(); \
	friend struct Z_Construct_UClass_ABaseNPC_Statics; \
public: \
	DECLARE_CLASS(ABaseNPC, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/blacksmith"), NO_API) \
	DECLARE_SERIALIZER(ABaseNPC) \
	virtual UObject* _getUObject() const override { return const_cast<ABaseNPC*>(this); }


#define FID_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABaseNPC(ABaseNPC&&); \
	ABaseNPC(const ABaseNPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseNPC); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseNPC); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseNPC) \
	NO_API virtual ~ABaseNPC();


#define FID_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_9_PROLOG
#define FID_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_12_INCLASS_NO_PURE_DECLS \
	FID_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class ABaseNPC>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
