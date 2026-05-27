// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ItemDataAsset.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BLACKSMITH_ItemDataAsset_generated_h
#error "ItemDataAsset.generated.h already included, missing '#pragma once' in ItemDataAsset.h"
#endif
#define BLACKSMITH_ItemDataAsset_generated_h

#define FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetItemMaterial); \
	DECLARE_FUNCTION(execGetItemElement); \
	DECLARE_FUNCTION(execGetItemTier); \
	DECLARE_FUNCTION(execGetWeaponType);


#define FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUItemDataAsset(); \
	friend struct Z_Construct_UClass_UItemDataAsset_Statics; \
public: \
	DECLARE_CLASS(UItemDataAsset, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/blacksmith"), NO_API) \
	DECLARE_SERIALIZER(UItemDataAsset)


#define FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UItemDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UItemDataAsset(UItemDataAsset&&); \
	UItemDataAsset(const UItemDataAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemDataAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemDataAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemDataAsset) \
	NO_API virtual ~UItemDataAsset();


#define FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_16_PROLOG
#define FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_19_INCLASS_NO_PURE_DECLS \
	FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class UItemDataAsset>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h


#define FOREACH_ENUM_EITEMCATEGORY(op) \
	op(EItemCategory::Material) \
	op(EItemCategory::Weapon) \
	op(EItemCategory::SpecialWeapon) 

enum class EItemCategory : uint8;
template<> struct TIsUEnumClass<EItemCategory> { enum { Value = true }; };
template<> BLACKSMITH_API UEnum* StaticEnum<EItemCategory>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
