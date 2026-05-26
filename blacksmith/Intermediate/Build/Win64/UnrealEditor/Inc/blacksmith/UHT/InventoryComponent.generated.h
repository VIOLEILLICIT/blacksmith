// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InventoryComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UItemDataAsset;
#ifdef BLACKSMITH_InventoryComponent_generated_h
#error "InventoryComponent.generated.h already included, missing '#pragma once' in InventoryComponent.h"
#endif
#define BLACKSMITH_InventoryComponent_generated_h

#define FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInventoryItem_Statics; \
	BLACKSMITH_API static class UScriptStruct* StaticStruct();


template<> BLACKSMITH_API UScriptStruct* StaticStruct<struct FInventoryItem>();

#define FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAddAllItemsCheat); \
	DECLARE_FUNCTION(execCraftItem); \
	DECLARE_FUNCTION(execGetItemCount); \
	DECLARE_FUNCTION(execRemoveItem); \
	DECLARE_FUNCTION(execAddItem);


#define FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryComponent(); \
	friend struct Z_Construct_UClass_UInventoryComponent_Statics; \
public: \
	DECLARE_CLASS(UInventoryComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/blacksmith"), NO_API) \
	DECLARE_SERIALIZER(UInventoryComponent)


#define FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UInventoryComponent(UInventoryComponent&&); \
	UInventoryComponent(const UInventoryComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventoryComponent) \
	NO_API virtual ~UInventoryComponent();


#define FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_27_PROLOG
#define FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_30_INCLASS_NO_PURE_DECLS \
	FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class UInventoryComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InventoryComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
