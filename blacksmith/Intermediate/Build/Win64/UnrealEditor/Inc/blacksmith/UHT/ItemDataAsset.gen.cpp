// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/ItemDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemDataAsset() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_UItemDataAsset();
BLACKSMITH_API UClass* Z_Construct_UClass_UItemDataAsset_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Class UItemDataAsset Function GetItemElement
struct Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics
{
	struct ItemDataAsset_eventGetItemElement_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Item Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 10\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xec\x86\x8d\xec\x84\xb1: 1=\xeb\xb6\x88, 2=\xeb\xac\xbc, 3=\xed\x92\x80)\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "10\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xec\x86\x8d\xec\x84\xb1: 1=\xeb\xb6\x88, 2=\xeb\xac\xbc, 3=\xed\x92\x80)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemDataAsset_eventGetItemElement_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UItemDataAsset, nullptr, "GetItemElement", nullptr, nullptr, Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::ItemDataAsset_eventGetItemElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::ItemDataAsset_eventGetItemElement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UItemDataAsset_GetItemElement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UItemDataAsset_GetItemElement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UItemDataAsset::execGetItemElement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetItemElement();
	P_NATIVE_END;
}
// End Class UItemDataAsset Function GetItemElement

// Begin Class UItemDataAsset Function GetItemMaterial
struct Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics
{
	struct ItemDataAsset_eventGetItemMaterial_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Item Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xec\x9e\xac\xec\xa7\x88: 1=\xec\xb2\xa0, 2=\xed\x95\xa9\xea\xb8\x88)\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xec\x9e\xac\xec\xa7\x88: 1=\xec\xb2\xa0, 2=\xed\x95\xa9\xea\xb8\x88)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemDataAsset_eventGetItemMaterial_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UItemDataAsset, nullptr, "GetItemMaterial", nullptr, nullptr, Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::PropPointers), sizeof(Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::ItemDataAsset_eventGetItemMaterial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::Function_MetaDataParams), Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::ItemDataAsset_eventGetItemMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UItemDataAsset_GetItemMaterial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UItemDataAsset_GetItemMaterial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UItemDataAsset::execGetItemMaterial)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetItemMaterial();
	P_NATIVE_END;
}
// End Class UItemDataAsset Function GetItemMaterial

// Begin Class UItemDataAsset Function GetItemTier
struct Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics
{
	struct ItemDataAsset_eventGetItemTier_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Item Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 100\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xeb\xac\xb4\xea\xb8\xb0 \xeb\x8b\xa8\xea\xb3\x84: 1=1\xeb\x8b\xa8\xea\xb3\x84, 2=2\xeb\x8b\xa8\xea\xb3\x84)\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "100\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xeb\xac\xb4\xea\xb8\xb0 \xeb\x8b\xa8\xea\xb3\x84: 1=1\xeb\x8b\xa8\xea\xb3\x84, 2=2\xeb\x8b\xa8\xea\xb3\x84)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemDataAsset_eventGetItemTier_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UItemDataAsset, nullptr, "GetItemTier", nullptr, nullptr, Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::PropPointers), sizeof(Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::ItemDataAsset_eventGetItemTier_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::Function_MetaDataParams), Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::ItemDataAsset_eventGetItemTier_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UItemDataAsset_GetItemTier()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UItemDataAsset_GetItemTier_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UItemDataAsset::execGetItemTier)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetItemTier();
	P_NATIVE_END;
}
// End Class UItemDataAsset Function GetItemTier

// Begin Class UItemDataAsset Function GetWeaponType
struct Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics
{
	struct ItemDataAsset_eventGetWeaponType_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Item Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* =================================================================\n\x09 * [\xec\x9e\x90\xeb\x8f\x99 \xeb\xb6\x84\xed\x95\xb4 \xed\x95\xa8\xec\x88\x98] \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xec\x89\xbd\xea\xb2\x8c \xec\x9e\x90\xeb\xa6\xbf\xec\x88\x98\xeb\xa5\xbc \xeb\xb6\x84\xeb\xa6\xac\xed\x95\xb4\xec\x84\x9c \xec\x93\xb8 \xec\x88\x98 \xec\x9e\x88\xea\xb2\x8c \xed\x95\xb4\xec\xa4\x8d\xeb\x8b\x88\xeb\x8b\xa4.\n\x09 * ================================================================= */// 1000\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xeb\xac\xb4\xea\xb8\xb0 \xec\xa2\x85\xeb\xa5\x98: 1=\xea\xb2\x80, 2=\xec\xb0\xbd / 0\xec\x9d\xb4\xeb\xa9\xb4 \xec\x9e\xac\xeb\xa3\x8c)\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* [\xec\x9e\x90\xeb\x8f\x99 \xeb\xb6\x84\xed\x95\xb4 \xed\x95\xa8\xec\x88\x98] \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xec\x89\xbd\xea\xb2\x8c \xec\x9e\x90\xeb\xa6\xbf\xec\x88\x98\xeb\xa5\xbc \xeb\xb6\x84\xeb\xa6\xac\xed\x95\xb4\xec\x84\x9c \xec\x93\xb8 \xec\x88\x98 \xec\x9e\x88\xea\xb2\x8c \xed\x95\xb4\xec\xa4\x8d\xeb\x8b\x88\xeb\x8b\xa4.\n* ================================================================= // 1000\xec\x9d\x98 \xec\x9e\x90\xeb\xa6\xac \xec\xb6\x94\xec\xb6\x9c (\xeb\xac\xb4\xea\xb8\xb0 \xec\xa2\x85\xeb\xa5\x98: 1=\xea\xb2\x80, 2=\xec\xb0\xbd / 0\xec\x9d\xb4\xeb\xa9\xb4 \xec\x9e\xac\xeb\xa3\x8c)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemDataAsset_eventGetWeaponType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UItemDataAsset, nullptr, "GetWeaponType", nullptr, nullptr, Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::ItemDataAsset_eventGetWeaponType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::ItemDataAsset_eventGetWeaponType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UItemDataAsset_GetWeaponType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UItemDataAsset_GetWeaponType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UItemDataAsset::execGetWeaponType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetWeaponType();
	P_NATIVE_END;
}
// End Class UItemDataAsset Function GetWeaponType

// Begin Class UItemDataAsset
void UItemDataAsset::StaticRegisterNativesUItemDataAsset()
{
	UClass* Class = UItemDataAsset::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetItemElement", &UItemDataAsset::execGetItemElement },
		{ "GetItemMaterial", &UItemDataAsset::execGetItemMaterial },
		{ "GetItemTier", &UItemDataAsset::execGetItemTier },
		{ "GetWeaponType", &UItemDataAsset::execGetWeaponType },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemDataAsset);
UClass* Z_Construct_UClass_UItemDataAsset_NoRegister()
{
	return UItemDataAsset::StaticClass();
}
struct Z_Construct_UClass_UItemDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ItemDataAsset.h" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemID_MetaData[] = {
		{ "Category", "Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1. \xed\x95\xb5\xec\x8b\xac \xea\xb8\xb0\xed\x9a\x8d: 4\xec\x9e\x90\xeb\xa6\xac \xec\x88\xab\xec\x9e\x90 ID (\xec\x98\x88: 1111 -> 1(\xea\xb2\x80) 1(1\xeb\x8b\xa8\xea\xb3\x84) 1(\xeb\xb6\x88) 1(\xec\xb2\xa0))\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1. \xed\x95\xb5\xec\x8b\xac \xea\xb8\xb0\xed\x9a\x8d: 4\xec\x9e\x90\xeb\xa6\xac \xec\x88\xab\xec\x9e\x90 ID (\xec\x98\x88: 1111 -> 1(\xea\xb2\x80) 1(1\xeb\x8b\xa8\xea\xb3\x84) 1(\xeb\xb6\x88) 1(\xec\xb2\xa0))" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "Item Data" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDescription_MetaData[] = {
		{ "Category", "Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac\xec\x9a\xa9 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x84\xa4\xeb\xaa\x85 \xec\xb6\x94\xea\xb0\x80\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac\xec\x9a\xa9 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x84\xa4\xeb\xaa\x85 \xec\xb6\x94\xea\xb0\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemIcon_MetaData[] = {
		{ "Category", "Item Data" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStackSize_MetaData[] = {
		{ "Category", "Item Data|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c\xec\x9a\xa9: \xed\x95\x9c \xec\xb9\xb8\xec\x97\x90 \xea\xb2\xb9\xec\xb9\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xec\xb5\x9c\xeb\x8c\x80 \xea\xb0\x9c\xec\x88\x98 (\xeb\xac\xb4\xea\xb8\xb0=1, \xec\x9e\xac\xeb\xa3\x8c=99 \xeb\x93\xb1)\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c\xec\x9a\xa9: \xed\x95\x9c \xec\xb9\xb8\xec\x97\x90 \xea\xb2\xb9\xec\xb9\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xec\xb5\x9c\xeb\x8c\x80 \xea\xb0\x9c\xec\x88\x98 (\xeb\xac\xb4\xea\xb8\xb0=1, \xec\x9e\xac\xeb\xa3\x8c=99 \xeb\x93\xb1)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCurrencyDisplay_MetaData[] = {
		{ "Category", "Item Data|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb8\xb0\xec\xa1\xb4 \xea\xb8\xb0\xed\x9a\x8d \xec\x9c\xa0\xec\xa7\x80: \xed\x9a\x8d\xeb\x93\x9d \xec\x8b\x9c \xed\x99\x94\xeb\xa9\xb4\xec\x97\x90 \xec\x9e\xac\xed\x99\x94\xec\xb2\x98\xeb\x9f\xbc \xeb\x9d\x84\xec\x9a\xb8\xec\xa7\x80 \xec\x97\xac\xeb\xb6\x80\n" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb8\xb0\xec\xa1\xb4 \xea\xb8\xb0\xed\x9a\x8d \xec\x9c\xa0\xec\xa7\x80: \xed\x9a\x8d\xeb\x93\x9d \xec\x8b\x9c \xed\x99\x94\xeb\xa9\xb4\xec\x97\x90 \xec\x9e\xac\xed\x99\x94\xec\xb2\x98\xeb\x9f\xbc \xeb\x9d\x84\xec\x9a\xb8\xec\xa7\x80 \xec\x97\xac\xeb\xb6\x80" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ItemDescription;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemIcon;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStackSize;
	static void NewProp_bIsCurrencyDisplay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCurrencyDisplay;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UItemDataAsset_GetItemElement, "GetItemElement" }, // 689778923
		{ &Z_Construct_UFunction_UItemDataAsset_GetItemMaterial, "GetItemMaterial" }, // 660172719
		{ &Z_Construct_UFunction_UItemDataAsset_GetItemTier, "GetItemTier" }, // 2718043894
		{ &Z_Construct_UFunction_UItemDataAsset_GetWeaponType, "GetWeaponType" }, // 572344183
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemID = { "ItemID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemID_MetaData), NewProp_ItemID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemDescription = { "ItemDescription", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemDescription), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDescription_MetaData), NewProp_ItemDescription_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemIcon = { "ItemIcon", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemIcon_MetaData), NewProp_ItemIcon_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_MaxStackSize = { "MaxStackSize", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, MaxStackSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStackSize_MetaData), NewProp_MaxStackSize_MetaData) };
void Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay_SetBit(void* Obj)
{
	((UItemDataAsset*)Obj)->bIsCurrencyDisplay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay = { "bIsCurrencyDisplay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UItemDataAsset), &Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCurrencyDisplay_MetaData), NewProp_bIsCurrencyDisplay_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemDescription,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_MaxStackSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UItemDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemDataAsset_Statics::ClassParams = {
	&UItemDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UItemDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemDataAsset()
{
	if (!Z_Registration_Info_UClass_UItemDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemDataAsset.OuterSingleton, Z_Construct_UClass_UItemDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemDataAsset.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<UItemDataAsset>()
{
	return UItemDataAsset::StaticClass();
}
UItemDataAsset::UItemDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemDataAsset);
UItemDataAsset::~UItemDataAsset() {}
// End Class UItemDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemDataAsset, UItemDataAsset::StaticClass, TEXT("UItemDataAsset"), &Z_Registration_Info_UClass_UItemDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemDataAsset), 3296623953U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_115586081(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
