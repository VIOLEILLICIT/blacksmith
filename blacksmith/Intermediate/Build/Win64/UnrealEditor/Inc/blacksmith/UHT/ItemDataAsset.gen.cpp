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
BLACKSMITH_API UEnum* Z_Construct_UEnum_blacksmith_EItemCategory();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Enum EItemCategory
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EItemCategory;
static UEnum* EItemCategory_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EItemCategory.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EItemCategory.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_blacksmith_EItemCategory, (UObject*)Z_Construct_UPackage__Script_blacksmith(), TEXT("EItemCategory"));
	}
	return Z_Registration_Info_UEnum_EItemCategory.OuterSingleton;
}
template<> BLACKSMITH_API UEnum* StaticEnum<EItemCategory>()
{
	return EItemCategory_StaticEnum();
}
struct Z_Construct_UEnum_blacksmith_EItemCategory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x8f\x84\xea\xb0\x90 \xed\x83\xad \xeb\xb6\x84\xeb\xa5\x98\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\xb9\xb4\xed\x85\x8c\xea\xb3\xa0\xeb\xa6\xac\n" },
#endif
		{ "Material.DisplayName", "\xec\x9e\xac\xeb\xa3\x8c" },
		{ "Material.Name", "EItemCategory::Material" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
		{ "SpecialWeapon.DisplayName", "\xed\x8a\xb9\xec\x88\x98 \xeb\xac\xb4\xea\xb8\xb0" },
		{ "SpecialWeapon.Name", "EItemCategory::SpecialWeapon" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x8f\x84\xea\xb0\x90 \xed\x83\xad \xeb\xb6\x84\xeb\xa5\x98\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\xb9\xb4\xed\x85\x8c\xea\xb3\xa0\xeb\xa6\xac" },
#endif
		{ "Weapon.DisplayName", "\xeb\xac\xb4\xea\xb8\xb0" },
		{ "Weapon.Name", "EItemCategory::Weapon" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EItemCategory::Material", (int64)EItemCategory::Material },
		{ "EItemCategory::Weapon", (int64)EItemCategory::Weapon },
		{ "EItemCategory::SpecialWeapon", (int64)EItemCategory::SpecialWeapon },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_blacksmith_EItemCategory_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_blacksmith,
	nullptr,
	"EItemCategory",
	"EItemCategory",
	Z_Construct_UEnum_blacksmith_EItemCategory_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_blacksmith_EItemCategory_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_blacksmith_EItemCategory_Statics::Enum_MetaDataParams), Z_Construct_UEnum_blacksmith_EItemCategory_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_blacksmith_EItemCategory()
{
	if (!Z_Registration_Info_UEnum_EItemCategory.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EItemCategory.InnerSingleton, Z_Construct_UEnum_blacksmith_EItemCategory_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EItemCategory.InnerSingleton;
}
// End Enum EItemCategory

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
		{ "ModuleRelativePath", "ItemDataAsset.h" },
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
		{ "ModuleRelativePath", "ItemDataAsset.h" },
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
		{ "ModuleRelativePath", "ItemDataAsset.h" },
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
		{ "Comment", "/* =================================================================\n\x09 * [\xec\x9e\x90\xeb\x8f\x99 \xeb\xb6\x84\xed\x95\xb4 \xed\x95\xa8\xec\x88\x98] 5\xec\x9e\x90\xeb\xa6\xac ID\xeb\xa5\xbc \xeb\xb6\x80\xec\x9c\x84\xeb\xb3\x84\xeb\xa1\x9c \xec\xaa\xbc\xea\xb0\x9c\xec\xa3\xbc\xeb\x8a\x94 \xed\x95\xa8\xec\x88\x98\xeb\x93\xa4\n\x09 * ================================================================= */" },
#endif
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* [\xec\x9e\x90\xeb\x8f\x99 \xeb\xb6\x84\xed\x95\xb4 \xed\x95\xa8\xec\x88\x98] 5\xec\x9e\x90\xeb\xa6\xac ID\xeb\xa5\xbc \xeb\xb6\x80\xec\x9c\x84\xeb\xb3\x84\xeb\xa1\x9c \xec\xaa\xbc\xea\xb0\x9c\xec\xa3\xbc\xeb\x8a\x94 \xed\x95\xa8\xec\x88\x98\xeb\x93\xa4\n* =================================================================" },
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
		{ "BlueprintType", "true" },
		{ "IncludePath", "ItemDataAsset.h" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemID_MetaData[] = {
		{ "Category", "1. Basic Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* =================================================================\n\x09 * 1. \xea\xb8\xb0\xeb\xb3\xb8 \xec\xa0\x95\xeb\xb3\xb4 (Basic Info)\n\x09 * ================================================================= */" },
#endif
		{ "DisplayName", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xea\xb3\xa0\xec\x9c\xa0 ID (5\xec\x9e\x90\xeb\xa6\xac)" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* 1. \xea\xb8\xb0\xeb\xb3\xb8 \xec\xa0\x95\xeb\xb3\xb4 (Basic Info)\n* =================================================================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "1. Basic Info" },
		{ "DisplayName", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x9d\xb4\xeb\xa6\x84" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemCategory_MetaData[] = {
		{ "Category", "1. Basic Info" },
		{ "DisplayName", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\xb6\x84\xeb\xa5\x98" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemIcon_MetaData[] = {
		{ "Category", "1. Basic Info" },
		{ "DisplayName", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryDescription_MetaData[] = {
		{ "Category", "2. Encyclopedia" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* =================================================================\n\x09 * 2. \xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 & \xeb\x8f\x84\xea\xb0\x90 \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c (Descriptions & Encyclopedia)\n\x09 * ================================================================= */" },
#endif
		{ "DisplayName", "\xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac \xec\xa7\xa7\xec\x9d\x80 \xec\x84\xa4\xeb\xaa\x85" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
		{ "MultiLine", "TRUE" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* 2. \xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 & \xeb\x8f\x84\xea\xb0\x90 \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c (Descriptions & Encyclopedia)\n* =================================================================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EncyclopediaDescription_MetaData[] = {
		{ "Category", "2. Encyclopedia" },
		{ "DisplayName", "\xeb\x8f\x84\xea\xb0\x90 \xec\x83\x81\xec\x84\xb8 \xec\x8a\xa4\xed\x86\xa0\xeb\xa6\xac \xec\x84\xa4\xeb\xaa\x85" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppearanceDescription_MetaData[] = {
		{ "Category", "2. Encyclopedia" },
		{ "DisplayName", "\xeb\xac\xb4\xea\xb8\xb0 \xec\x99\xb8\xed\x98\x95 \xeb\xac\x98\xec\x82\xac" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnlockCondition_MetaData[] = {
		{ "Category", "2. Encyclopedia" },
		{ "DisplayName", "\xed\x8a\xb9\xec\x88\x98 \xeb\xac\xb4\xea\xb8\xb0 \xed\x95\xb4\xea\xb8\x88 \xec\xa1\xb0\xea\xb1\xb4" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStackSize_MetaData[] = {
		{ "Category", "3. Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* =================================================================\n\x09 * 3. \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac & \xed\x81\xac\xeb\x9e\x98\xed\x94\x84\xed\x8c\x85 (Inventory & Crafting)\n\x09 * ================================================================= */" },
#endif
		{ "DisplayName", "\xec\xb5\x9c\xeb\x8c\x80 \xea\xb2\xb9\xec\xb9\x98\xea\xb8\xb0 \xea\xb0\x9c\xec\x88\x98 (\xec\x8a\xa4\xed\x83\x9d)" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* 3. \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac & \xed\x81\xac\xeb\x9e\x98\xed\x94\x84\xed\x8c\x85 (Inventory & Crafting)\n* =================================================================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCurrencyDisplay_MetaData[] = {
		{ "Category", "3. Inventory" },
		{ "DisplayName", "\xec\x83\x81\xeb\x8b\xa8 \xec\x9e\xac\xed\x99\x94 UI \xed\x91\x9c\xec\x8b\x9c \xec\x97\xac\xeb\xb6\x80" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CraftingMaterials_MetaData[] = {
		{ "Category", "4. Crafting" },
		{ "DisplayName", "\xed\x95\x84\xec\x9a\x94\xed\x95\x9c \xec\xa0\x9c\xec\x9e\x91 \xec\x9e\xac\xeb\xa3\x8c \xeb\xaa\xa9\xeb\xa1\x9d" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsBuyable_MetaData[] = {
		{ "Category", "5. Economy" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* =================================================================\n\x09 * 4. \xea\xb2\xbd\xec\xa0\x9c \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c (Economy System) - \xe2\x98\x85 \xec\x83\x81\xec\xa0\x90 \xea\xb1\xb0\xeb\x9e\x98 \xea\xb8\xb0\xeb\x8a\xa5 \xec\xb6\x94\xea\xb0\x80\n\x09 * ================================================================= */" },
#endif
		{ "DisplayName", "\xea\xb5\xac\xeb\xa7\xa4 \xea\xb0\x80\xeb\x8a\xa5 \xec\x97\xac\xeb\xb6\x80" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* 4. \xea\xb2\xbd\xec\xa0\x9c \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c (Economy System) - \xe2\x98\x85 \xec\x83\x81\xec\xa0\x90 \xea\xb1\xb0\xeb\x9e\x98 \xea\xb8\xb0\xeb\x8a\xa5 \xec\xb6\x94\xea\xb0\x80\n* =================================================================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuyPrice_MetaData[] = {
		{ "Category", "5. Economy" },
		{ "DisplayName", "\xea\xb5\xac\xeb\xa7\xa4 \xea\xb0\x80\xea\xb2\xa9" },
		{ "EditCondition", "bIsBuyable" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSellable_MetaData[] = {
		{ "Category", "5. Economy" },
		{ "DisplayName", "\xed\x8c\x90\xeb\xa7\xa4 \xea\xb0\x80\xeb\x8a\xa5 \xec\x97\xac\xeb\xb6\x80" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SellPrice_MetaData[] = {
		{ "Category", "5. Economy" },
		{ "DisplayName", "\xed\x8c\x90\xeb\xa7\xa4 \xea\xb0\x80\xea\xb2\xa9" },
		{ "EditCondition", "bIsSellable" },
		{ "ModuleRelativePath", "ItemDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ItemCategory_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ItemCategory;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemIcon;
	static const UECodeGen_Private::FTextPropertyParams NewProp_InventoryDescription;
	static const UECodeGen_Private::FTextPropertyParams NewProp_EncyclopediaDescription;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AppearanceDescription;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UnlockCondition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStackSize;
	static void NewProp_bIsCurrencyDisplay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCurrencyDisplay;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CraftingMaterials_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CraftingMaterials_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_CraftingMaterials;
	static void NewProp_bIsBuyable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBuyable;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BuyPrice;
	static void NewProp_bIsSellable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSellable;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SellPrice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UItemDataAsset_GetItemElement, "GetItemElement" }, // 3060226551
		{ &Z_Construct_UFunction_UItemDataAsset_GetItemMaterial, "GetItemMaterial" }, // 1686209952
		{ &Z_Construct_UFunction_UItemDataAsset_GetItemTier, "GetItemTier" }, // 61891892
		{ &Z_Construct_UFunction_UItemDataAsset_GetWeaponType, "GetWeaponType" }, // 2848005295
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemID = { "ItemID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemID_MetaData), NewProp_ItemID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemCategory_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemCategory = { "ItemCategory", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemCategory), Z_Construct_UEnum_blacksmith_EItemCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemCategory_MetaData), NewProp_ItemCategory_MetaData) }; // 3735756338
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemIcon = { "ItemIcon", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, ItemIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemIcon_MetaData), NewProp_ItemIcon_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_InventoryDescription = { "InventoryDescription", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, InventoryDescription), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryDescription_MetaData), NewProp_InventoryDescription_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_EncyclopediaDescription = { "EncyclopediaDescription", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, EncyclopediaDescription), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EncyclopediaDescription_MetaData), NewProp_EncyclopediaDescription_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_AppearanceDescription = { "AppearanceDescription", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, AppearanceDescription), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppearanceDescription_MetaData), NewProp_AppearanceDescription_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_UnlockCondition = { "UnlockCondition", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, UnlockCondition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnlockCondition_MetaData), NewProp_UnlockCondition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_MaxStackSize = { "MaxStackSize", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, MaxStackSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStackSize_MetaData), NewProp_MaxStackSize_MetaData) };
void Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay_SetBit(void* Obj)
{
	((UItemDataAsset*)Obj)->bIsCurrencyDisplay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay = { "bIsCurrencyDisplay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UItemDataAsset), &Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCurrencyDisplay_MetaData), NewProp_bIsCurrencyDisplay_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_CraftingMaterials_ValueProp = { "CraftingMaterials", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_CraftingMaterials_Key_KeyProp = { "CraftingMaterials_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UItemDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_CraftingMaterials = { "CraftingMaterials", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, CraftingMaterials), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CraftingMaterials_MetaData), NewProp_CraftingMaterials_MetaData) };
void Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsBuyable_SetBit(void* Obj)
{
	((UItemDataAsset*)Obj)->bIsBuyable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsBuyable = { "bIsBuyable", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UItemDataAsset), &Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsBuyable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsBuyable_MetaData), NewProp_bIsBuyable_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_BuyPrice = { "BuyPrice", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, BuyPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuyPrice_MetaData), NewProp_BuyPrice_MetaData) };
void Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsSellable_SetBit(void* Obj)
{
	((UItemDataAsset*)Obj)->bIsSellable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsSellable = { "bIsSellable", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UItemDataAsset), &Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsSellable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSellable_MetaData), NewProp_bIsSellable_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemDataAsset_Statics::NewProp_SellPrice = { "SellPrice", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemDataAsset, SellPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SellPrice_MetaData), NewProp_SellPrice_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemCategory_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_ItemIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_InventoryDescription,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_EncyclopediaDescription,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_AppearanceDescription,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_UnlockCondition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_MaxStackSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsCurrencyDisplay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_CraftingMaterials_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_CraftingMaterials_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_CraftingMaterials,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsBuyable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_BuyPrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_bIsSellable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemDataAsset_Statics::NewProp_SellPrice,
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
struct Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EItemCategory_StaticEnum, TEXT("EItemCategory"), &Z_Registration_Info_UEnum_EItemCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3735756338U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemDataAsset, UItemDataAsset::StaticClass, TEXT("UItemDataAsset"), &Z_Registration_Info_UClass_UItemDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemDataAsset), 2339249901U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_1240269447(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_ItemDataAsset_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
