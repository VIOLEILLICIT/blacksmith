// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/W_Inventory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeW_Inventory() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UItemDataAsset_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UW_Inventory();
BLACKSMITH_API UClass* Z_Construct_UClass_UW_Inventory_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UW_ItemSlot_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UWrapBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Class UW_Inventory Function RefreshInventory
struct Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics
{
	struct W_Inventory_eventRefreshInventory_Parms
	{
		UInventoryComponent* InventoryComp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac\xeb\xa5\xbc \xeb\x8b\xa4\xec\x8b\x9c \xea\xb7\xb8\xeb\xa6\xac\xeb\x8a\x94 \xed\x95\xa8\xec\x88\x98\n" },
#endif
		{ "ModuleRelativePath", "W_Inventory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac\xeb\xa5\xbc \xeb\x8b\xa4\xec\x8b\x9c \xea\xb7\xb8\xeb\xa6\xac\xeb\x8a\x94 \xed\x95\xa8\xec\x88\x98" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryComp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::NewProp_InventoryComp = { "InventoryComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(W_Inventory_eventRefreshInventory_Parms, InventoryComp), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryComp_MetaData), NewProp_InventoryComp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::NewProp_InventoryComp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UW_Inventory, nullptr, "RefreshInventory", nullptr, nullptr, Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::PropPointers), sizeof(Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::W_Inventory_eventRefreshInventory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::W_Inventory_eventRefreshInventory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UW_Inventory_RefreshInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UW_Inventory_RefreshInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UW_Inventory::execRefreshInventory)
{
	P_GET_OBJECT(UInventoryComponent,Z_Param_InventoryComp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshInventory(Z_Param_InventoryComp);
	P_NATIVE_END;
}
// End Class UW_Inventory Function RefreshInventory

// Begin Class UW_Inventory Function UpdateDetailView
struct W_Inventory_eventUpdateDetailView_Parms
{
	UItemDataAsset* Asset;
	int32 Count;
};
static const FName NAME_UW_Inventory_UpdateDetailView = FName(TEXT("UpdateDetailView"));
void UW_Inventory::UpdateDetailView(UItemDataAsset* Asset, int32 Count)
{
	W_Inventory_eventUpdateDetailView_Parms Parms;
	Parms.Asset=Asset;
	Parms.Count=Count;
	UFunction* Func = FindFunctionChecked(NAME_UW_Inventory_UpdateDetailView);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "W_Inventory.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(W_Inventory_eventUpdateDetailView_Parms, Asset), Z_Construct_UClass_UItemDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(W_Inventory_eventUpdateDetailView_Parms, Count), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::NewProp_Asset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::NewProp_Count,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UW_Inventory, nullptr, "UpdateDetailView", nullptr, nullptr, Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::PropPointers), sizeof(W_Inventory_eventUpdateDetailView_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::Function_MetaDataParams), Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::Function_MetaDataParams) };
static_assert(sizeof(W_Inventory_eventUpdateDetailView_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UW_Inventory_UpdateDetailView()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UW_Inventory_UpdateDetailView_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class UW_Inventory Function UpdateDetailView

// Begin Class UW_Inventory
void UW_Inventory::StaticRegisterNativesUW_Inventory()
{
	UClass* Class = UW_Inventory::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "RefreshInventory", &UW_Inventory::execRefreshInventory },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UW_Inventory);
UClass* Z_Construct_UClass_UW_Inventory_NoRegister()
{
	return UW_Inventory::StaticClass();
}
struct Z_Construct_UClass_UW_Inventory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "W_Inventory.h" },
		{ "ModuleRelativePath", "W_Inventory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryWrapBox_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\xad\x90\xef\xb8\x8f \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x9d\x98 \xeb\x9e\xa9 \xeb\xb0\x95\xec\x8a\xa4 \xec\x9d\xb4\xeb\xa6\x84\xea\xb3\xbc \xeb\x98\x91\xea\xb0\x99\xec\x95\x84\xec\x95\xbc \xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "W_Inventory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\xad\x90\xef\xb8\x8f \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x9d\x98 \xeb\x9e\xa9 \xeb\xb0\x95\xec\x8a\xa4 \xec\x9d\xb4\xeb\xa6\x84\xea\xb3\xbc \xeb\x98\x91\xea\xb0\x99\xec\x95\x84\xec\x95\xbc \xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemSlotClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb0\x94\xea\xb5\xac\xeb\x8b\x88\xec\x97\x90 \xec\xb0\x8d\xec\x96\xb4\xeb\x82\xbc \xed\x83\x80\xec\x9d\xbc\xec\x9d\x98 '\xec\x84\xa4\xea\xb3\x84\xeb\x8f\x84(\xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4)' \xec\xa0\x95\xeb\xb3\xb4\n" },
#endif
		{ "ModuleRelativePath", "W_Inventory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x94\xea\xb5\xac\xeb\x8b\x88\xec\x97\x90 \xec\xb0\x8d\xec\x96\xb4\xeb\x82\xbc \xed\x83\x80\xec\x9d\xbc\xec\x9d\x98 '\xec\x84\xa4\xea\xb3\x84\xeb\x8f\x84(\xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4)' \xec\xa0\x95\xeb\xb3\xb4" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryWrapBox;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ItemSlotClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UW_Inventory_RefreshInventory, "RefreshInventory" }, // 3895705266
		{ &Z_Construct_UFunction_UW_Inventory_UpdateDetailView, "UpdateDetailView" }, // 1876802426
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UW_Inventory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UW_Inventory_Statics::NewProp_InventoryWrapBox = { "InventoryWrapBox", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_Inventory, InventoryWrapBox), Z_Construct_UClass_UWrapBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryWrapBox_MetaData), NewProp_InventoryWrapBox_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UW_Inventory_Statics::NewProp_ItemSlotClass = { "ItemSlotClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_Inventory, ItemSlotClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UW_ItemSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemSlotClass_MetaData), NewProp_ItemSlotClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UW_Inventory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_Inventory_Statics::NewProp_InventoryWrapBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_Inventory_Statics::NewProp_ItemSlotClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UW_Inventory_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UW_Inventory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UW_Inventory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UW_Inventory_Statics::ClassParams = {
	&UW_Inventory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UW_Inventory_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UW_Inventory_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UW_Inventory_Statics::Class_MetaDataParams), Z_Construct_UClass_UW_Inventory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UW_Inventory()
{
	if (!Z_Registration_Info_UClass_UW_Inventory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UW_Inventory.OuterSingleton, Z_Construct_UClass_UW_Inventory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UW_Inventory.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<UW_Inventory>()
{
	return UW_Inventory::StaticClass();
}
UW_Inventory::UW_Inventory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UW_Inventory);
UW_Inventory::~UW_Inventory() {}
// End Class UW_Inventory

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UW_Inventory, UW_Inventory::StaticClass, TEXT("UW_Inventory"), &Z_Registration_Info_UClass_UW_Inventory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UW_Inventory), 3801099622U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_2657375646(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_Inventory_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
