// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/W_ItemSlot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeW_ItemSlot() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_UItemDataAsset_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UW_Inventory_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UW_ItemSlot();
BLACKSMITH_API UClass* Z_Construct_UClass_UW_ItemSlot_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Class UW_ItemSlot
void UW_ItemSlot::StaticRegisterNativesUW_ItemSlot()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UW_ItemSlot);
UClass* Z_Construct_UClass_UW_ItemSlot_NoRegister()
{
	return UW_ItemSlot::StaticClass();
}
struct Z_Construct_UClass_UW_ItemSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "W_ItemSlot.h" },
		{ "ModuleRelativePath", "W_ItemSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemIcon_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\xad\x90\xef\xb8\x8f \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x9d\x98 UI \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 \xec\x9d\xb4\xeb\xa6\x84\xea\xb3\xbc '\xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c' \xeb\x98\x91\xea\xb0\x99\xec\x95\x84\xec\x95\xbc \xec\x9e\x90\xeb\x8f\x99 \xec\x97\xb0\xea\xb2\xb0\xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4!\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "W_ItemSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\xad\x90\xef\xb8\x8f \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x9d\x98 UI \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 \xec\x9d\xb4\xeb\xa6\x84\xea\xb3\xbc '\xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c' \xeb\x98\x91\xea\xb0\x99\xec\x95\x84\xec\x95\xbc \xec\x9e\x90\xeb\x8f\x99 \xec\x97\xb0\xea\xb2\xb0\xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "W_ItemSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentInventory_MetaData[] = {
		{ "Category", "Inventory" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "W_ItemSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAsset_MetaData[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x82\xb4\xea\xb0\x80 \xeb\x93\xa4\xea\xb3\xa0 \xec\x9e\x88\xeb\x8a\x94 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0\n" },
#endif
		{ "ModuleRelativePath", "W_ItemSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x82\xb4\xea\xb0\x80 \xeb\x93\xa4\xea\xb3\xa0 \xec\x9e\x88\xeb\x8a\x94 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCount_MetaData[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x82\xb4\xea\xb0\x80 \xeb\x93\xa4\xea\xb3\xa0 \xec\x9e\x88\xeb\x8a\x94 \xea\xb0\x9c\xec\x88\x98\n" },
#endif
		{ "ModuleRelativePath", "W_ItemSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x82\xb4\xea\xb0\x80 \xeb\x93\xa4\xea\xb3\xa0 \xec\x9e\x88\xeb\x8a\x94 \xea\xb0\x9c\xec\x88\x98" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentInventory;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentAsset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UW_ItemSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_ItemIcon = { "ItemIcon", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_ItemSlot, ItemIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemIcon_MetaData), NewProp_ItemIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_QuantityText = { "QuantityText", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_ItemSlot, QuantityText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityText_MetaData), NewProp_QuantityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_ParentInventory = { "ParentInventory", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_ItemSlot, ParentInventory), Z_Construct_UClass_UW_Inventory_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentInventory_MetaData), NewProp_ParentInventory_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_CurrentAsset = { "CurrentAsset", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_ItemSlot, CurrentAsset), Z_Construct_UClass_UItemDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAsset_MetaData), NewProp_CurrentAsset_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_CurrentCount = { "CurrentCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_ItemSlot, CurrentCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCount_MetaData), NewProp_CurrentCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UW_ItemSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_ItemIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_QuantityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_ParentInventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_CurrentAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_ItemSlot_Statics::NewProp_CurrentCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UW_ItemSlot_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UW_ItemSlot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UW_ItemSlot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UW_ItemSlot_Statics::ClassParams = {
	&UW_ItemSlot::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UW_ItemSlot_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UW_ItemSlot_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UW_ItemSlot_Statics::Class_MetaDataParams), Z_Construct_UClass_UW_ItemSlot_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UW_ItemSlot()
{
	if (!Z_Registration_Info_UClass_UW_ItemSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UW_ItemSlot.OuterSingleton, Z_Construct_UClass_UW_ItemSlot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UW_ItemSlot.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<UW_ItemSlot>()
{
	return UW_ItemSlot::StaticClass();
}
UW_ItemSlot::UW_ItemSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UW_ItemSlot);
UW_ItemSlot::~UW_ItemSlot() {}
// End Class UW_ItemSlot

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UW_ItemSlot, UW_ItemSlot::StaticClass, TEXT("UW_ItemSlot"), &Z_Registration_Info_UClass_UW_ItemSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UW_ItemSlot), 706687507U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_422627994(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_W_ItemSlot_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
