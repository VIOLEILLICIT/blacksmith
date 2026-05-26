// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "W_Inventory.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInventoryComponent;
class UItemDataAsset;
#ifdef BLACKSMITH_W_Inventory_generated_h
#error "W_Inventory.generated.h already included, missing '#pragma once' in W_Inventory.h"
#endif
#define BLACKSMITH_W_Inventory_generated_h

#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRefreshInventory);


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_CALLBACK_WRAPPERS
#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUW_Inventory(); \
	friend struct Z_Construct_UClass_UW_Inventory_Statics; \
public: \
	DECLARE_CLASS(UW_Inventory, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/blacksmith"), NO_API) \
	DECLARE_SERIALIZER(UW_Inventory)


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UW_Inventory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UW_Inventory(UW_Inventory&&); \
	UW_Inventory(const UW_Inventory&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UW_Inventory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UW_Inventory); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UW_Inventory) \
	NO_API virtual ~UW_Inventory();


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_10_PROLOG
#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_CALLBACK_WRAPPERS \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class UW_Inventory>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
