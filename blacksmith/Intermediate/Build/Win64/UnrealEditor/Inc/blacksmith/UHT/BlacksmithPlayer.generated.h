// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlacksmithPlayer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BLACKSMITH_BlacksmithPlayer_generated_h
#error "BlacksmithPlayer.generated.h already included, missing '#pragma once' in BlacksmithPlayer.h"
#endif
#define BLACKSMITH_BlacksmithPlayer_generated_h

#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlacksmithPlayer(); \
	friend struct Z_Construct_UClass_ABlacksmithPlayer_Statics; \
public: \
	DECLARE_CLASS(ABlacksmithPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/blacksmith"), NO_API) \
	DECLARE_SERIALIZER(ABlacksmithPlayer)


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABlacksmithPlayer(ABlacksmithPlayer&&); \
	ABlacksmithPlayer(const ABlacksmithPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlacksmithPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlacksmithPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlacksmithPlayer) \
	NO_API virtual ~ABlacksmithPlayer();


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_8_PROLOG
#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_11_INCLASS_NO_PURE_DECLS \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class ABlacksmithPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
