// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/InteractableInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractableInterface() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_UInteractableInterface();
BLACKSMITH_API UClass* Z_Construct_UClass_UInteractableInterface_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Interface UInteractableInterface
void UInteractableInterface::StaticRegisterNativesUInteractableInterface()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInteractableInterface);
UClass* Z_Construct_UClass_UInteractableInterface_NoRegister()
{
	return UInteractableInterface::StaticClass();
}
struct Z_Construct_UClass_UInteractableInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "InteractableInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInteractableInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UInteractableInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractableInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInteractableInterface_Statics::ClassParams = {
	&UInteractableInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractableInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UInteractableInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInteractableInterface()
{
	if (!Z_Registration_Info_UClass_UInteractableInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInteractableInterface.OuterSingleton, Z_Construct_UClass_UInteractableInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInteractableInterface.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<UInteractableInterface>()
{
	return UInteractableInterface::StaticClass();
}
UInteractableInterface::UInteractableInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractableInterface);
UInteractableInterface::~UInteractableInterface() {}
// End Interface UInteractableInterface

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInteractableInterface, UInteractableInterface::StaticClass, TEXT("UInteractableInterface"), &Z_Registration_Info_UClass_UInteractableInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteractableInterface), 2440175596U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_213357411(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
