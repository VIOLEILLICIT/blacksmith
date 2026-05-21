// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeblacksmith_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_blacksmith;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_blacksmith()
	{
		if (!Z_Registration_Info_UPackage__Script_blacksmith.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/blacksmith",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x52B83871,
				0xD0665336,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_blacksmith.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_blacksmith.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_blacksmith(Z_Construct_UPackage__Script_blacksmith, TEXT("/Script/blacksmith"), Z_Registration_Info_UPackage__Script_blacksmith, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x52B83871, 0xD0665336));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
