// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/BlacksmithPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlacksmithPlayer() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_ABlacksmithPlayer();
BLACKSMITH_API UClass* Z_Construct_UClass_ABlacksmithPlayer_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Class ABlacksmithPlayer
void ABlacksmithPlayer::StaticRegisterNativesABlacksmithPlayer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABlacksmithPlayer);
UClass* Z_Construct_UClass_ABlacksmithPlayer_NoRegister()
{
	return ABlacksmithPlayer::StaticClass();
}
struct Z_Construct_UClass_ABlacksmithPlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BlacksmithPlayer.h" },
		{ "ModuleRelativePath", "BlacksmithPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9e\x85\xeb\xa0\xa5 \xec\x95\xa1\xec\x85\x98 \xec\x97\x90\xec\x85\x8b \xed\x95\xa0\xeb\x8b\xb9\xec\xb9\xb8\n" },
#endif
		{ "ModuleRelativePath", "BlacksmithPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x85\xeb\xa0\xa5 \xec\x95\xa1\xec\x85\x98 \xec\x97\x90\xec\x85\x8b \xed\x95\xa0\xeb\x8b\xb9\xec\xb9\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionRange_MetaData[] = {
		{ "Category", "Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9 \xea\xb0\x90\xec\xa7\x80 \xeb\xb0\x98\xea\xb2\xbd\n" },
#endif
		{ "ModuleRelativePath", "BlacksmithPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9 \xea\xb0\x90\xec\xa7\x80 \xeb\xb0\x98\xea\xb2\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugSphere_MetaData[] = {
		{ "Category", "Interaction|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x94\x94\xeb\xb2\x84\xea\xb7\xb8 \xea\xb5\xac\xec\xb2\xb4 \xec\x8b\x9c\xea\xb0\x81\xed\x99\x94 \xec\x98\xb5\xec\x85\x98\n" },
#endif
		{ "ModuleRelativePath", "BlacksmithPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x94\x94\xeb\xb2\x84\xea\xb7\xb8 \xea\xb5\xac\xec\xb2\xb4 \xec\x8b\x9c\xea\xb0\x81\xed\x99\x94 \xec\x98\xb5\xec\x85\x98" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionRange;
	static void NewProp_bShowDebugSphere_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugSphere;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABlacksmithPlayer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlacksmithPlayer, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAction_MetaData), NewProp_InteractAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_InteractionRange = { "InteractionRange", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlacksmithPlayer, InteractionRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionRange_MetaData), NewProp_InteractionRange_MetaData) };
void Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_bShowDebugSphere_SetBit(void* Obj)
{
	((ABlacksmithPlayer*)Obj)->bShowDebugSphere = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_bShowDebugSphere = { "bShowDebugSphere", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlacksmithPlayer), &Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_bShowDebugSphere_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugSphere_MetaData), NewProp_bShowDebugSphere_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABlacksmithPlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_InteractAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_InteractionRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlacksmithPlayer_Statics::NewProp_bShowDebugSphere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlacksmithPlayer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABlacksmithPlayer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlacksmithPlayer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABlacksmithPlayer_Statics::ClassParams = {
	&ABlacksmithPlayer::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABlacksmithPlayer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABlacksmithPlayer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlacksmithPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_ABlacksmithPlayer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABlacksmithPlayer()
{
	if (!Z_Registration_Info_UClass_ABlacksmithPlayer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABlacksmithPlayer.OuterSingleton, Z_Construct_UClass_ABlacksmithPlayer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABlacksmithPlayer.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<ABlacksmithPlayer>()
{
	return ABlacksmithPlayer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABlacksmithPlayer);
ABlacksmithPlayer::~ABlacksmithPlayer() {}
// End Class ABlacksmithPlayer

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABlacksmithPlayer, ABlacksmithPlayer::StaticClass, TEXT("ABlacksmithPlayer"), &Z_Registration_Info_UClass_ABlacksmithPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABlacksmithPlayer), 3662681782U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_3619669424(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_BlacksmithPlayer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
