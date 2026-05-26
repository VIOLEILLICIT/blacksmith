// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/BaseNPC.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseNPC() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_ABaseNPC();
BLACKSMITH_API UClass* Z_Construct_UClass_ABaseNPC_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UInteractableInterface_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UNPCComponent_NoRegister();
BLACKSMITH_API UEnum* Z_Construct_UEnum_blacksmith_ENPCJob();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Class ABaseNPC
void ABaseNPC::StaticRegisterNativesABaseNPC()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseNPC);
UClass* Z_Construct_UClass_ABaseNPC_NoRegister()
{
	return ABaseNPC::StaticClass();
}
struct Z_Construct_UClass_ABaseNPC_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BaseNPC.h" },
		{ "ModuleRelativePath", "BaseNPC.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NPCComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// NPC \xeb\x91\x90\xeb\x87\x8c \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 \xec\x9e\xa5\xec\xb0\xa9\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BaseNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NPC \xeb\x91\x90\xeb\x87\x8c \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 \xec\x9e\xa5\xec\xb0\xa9" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Job_MetaData[] = {
		{ "Category", "NPC Data" },
		{ "ModuleRelativePath", "BaseNPC.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "NPC Data" },
		{ "ModuleRelativePath", "BaseNPC.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Portrait_MetaData[] = {
		{ "Category", "NPC Data" },
		{ "ModuleRelativePath", "BaseNPC.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatrolPoints_MetaData[] = {
		{ "Category", "NPC Data|Patrol" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xa7\xb5\xec\x97\x90\xec\x84\x9c \xec\x9c\x84\xec\xa0\xaf\xec\x9c\xbc\xeb\xa1\x9c \xec\xa1\xb0\xec\xa0\x88\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xec\x88\x9c\xec\xb0\xb0 \xea\xb2\xbd\xeb\xa1\x9c\n" },
#endif
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "BaseNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa7\xb5\xec\x97\x90\xec\x84\x9c \xec\x9c\x84\xec\xa0\xaf\xec\x9c\xbc\xeb\xa1\x9c \xec\xa1\xb0\xec\xa0\x88\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xec\x88\x9c\xec\xb0\xb0 \xea\xb2\xbd\xeb\xa1\x9c" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NPCComponent;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Job_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Job;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Portrait;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PatrolPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PatrolPoints;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseNPC>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseNPC_Statics::NewProp_NPCComponent = { "NPCComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseNPC, NPCComponent), Z_Construct_UClass_UNPCComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NPCComponent_MetaData), NewProp_NPCComponent_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABaseNPC_Statics::NewProp_Job_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ABaseNPC_Statics::NewProp_Job = { "Job", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseNPC, Job), Z_Construct_UEnum_blacksmith_ENPCJob, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Job_MetaData), NewProp_Job_MetaData) }; // 3501210692
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ABaseNPC_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseNPC, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseNPC_Statics::NewProp_Portrait = { "Portrait", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseNPC, Portrait), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Portrait_MetaData), NewProp_Portrait_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABaseNPC_Statics::NewProp_PatrolPoints_Inner = { "PatrolPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABaseNPC_Statics::NewProp_PatrolPoints = { "PatrolPoints", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseNPC, PatrolPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatrolPoints_MetaData), NewProp_PatrolPoints_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABaseNPC_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseNPC_Statics::NewProp_NPCComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseNPC_Statics::NewProp_Job_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseNPC_Statics::NewProp_Job,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseNPC_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseNPC_Statics::NewProp_Portrait,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseNPC_Statics::NewProp_PatrolPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseNPC_Statics::NewProp_PatrolPoints,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseNPC_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABaseNPC_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseNPC_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ABaseNPC_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(ABaseNPC, IInteractableInterface), false },  // 2440175596
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseNPC_Statics::ClassParams = {
	&ABaseNPC::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABaseNPC_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABaseNPC_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseNPC_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseNPC_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseNPC()
{
	if (!Z_Registration_Info_UClass_ABaseNPC.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseNPC.OuterSingleton, Z_Construct_UClass_ABaseNPC_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseNPC.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<ABaseNPC>()
{
	return ABaseNPC::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseNPC);
ABaseNPC::~ABaseNPC() {}
// End Class ABaseNPC

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseNPC, ABaseNPC::StaticClass, TEXT("ABaseNPC"), &Z_Registration_Info_UClass_ABaseNPC, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseNPC), 2319034151U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_3530739459(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_blacksmith_blacksmith_Source_blacksmith_BaseNPC_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
