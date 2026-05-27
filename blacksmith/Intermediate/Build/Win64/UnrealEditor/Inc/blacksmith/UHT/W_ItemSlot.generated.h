// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "W_ItemSlot.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BLACKSMITH_W_ItemSlot_generated_h
#error "W_ItemSlot.generated.h already included, missing '#pragma once' in W_ItemSlot.h"
#endif
#define BLACKSMITH_W_ItemSlot_generated_h

#define FID_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUW_ItemSlot(); \
	friend struct Z_Construct_UClass_UW_ItemSlot_Statics; \
public: \
	DECLARE_CLASS(UW_ItemSlot, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/blacksmith"), NO_API) \
	DECLARE_SERIALIZER(UW_ItemSlot)


#define FID_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UW_ItemSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UW_ItemSlot(UW_ItemSlot&&); \
	UW_ItemSlot(const UW_ItemSlot&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UW_ItemSlot); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UW_ItemSlot); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UW_ItemSlot) \
	NO_API virtual ~UW_ItemSlot();


#define FID_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_12_PROLOG
#define FID_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_15_INCLASS_NO_PURE_DECLS \
	FID_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class UW_ItemSlot>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
