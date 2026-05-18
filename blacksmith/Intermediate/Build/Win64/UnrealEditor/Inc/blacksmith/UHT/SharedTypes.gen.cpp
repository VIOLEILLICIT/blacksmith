// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/SharedTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSharedTypes() {}

// Begin Cross Module References
BLACKSMITH_API UEnum* Z_Construct_UEnum_blacksmith_ENPCJob();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Enum ENPCJob
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ENPCJob;
static UEnum* ENPCJob_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ENPCJob.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ENPCJob.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_blacksmith_ENPCJob, (UObject*)Z_Construct_UPackage__Script_blacksmith(), TEXT("ENPCJob"));
	}
	return Z_Registration_Info_UEnum_ENPCJob.OuterSingleton;
}
template<> BLACKSMITH_API UEnum* StaticEnum<ENPCJob>()
{
	return ENPCJob_StaticEnum();
}
struct Z_Construct_UEnum_blacksmith_ENPCJob_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Blacksmith.DisplayName", "\xeb\x8c\x80\xec\x9e\xa5\xec\x9e\xa5\xec\x9d\xb4" },
		{ "Blacksmith.Name", "ENPCJob::Blacksmith" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// NPC \xec\xa7\x81\xec\x97\x85\xea\xb5\xb0 \xec\x97\xb4\xea\xb1\xb0\xed\x98\x95\n" },
#endif
		{ "Merchant.DisplayName", "\xec\x83\x81\xec\x9d\xb8" },
		{ "Merchant.Name", "ENPCJob::Merchant" },
		{ "ModuleRelativePath", "SharedTypes.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ENPCJob::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NPC \xec\xa7\x81\xec\x97\x85\xea\xb5\xb0 \xec\x97\xb4\xea\xb1\xb0\xed\x98\x95" },
#endif
		{ "Villager.DisplayName", "\xeb\xa7\x88\xec\x9d\x84 \xec\xa3\xbc\xeb\xaf\xbc" },
		{ "Villager.Name", "ENPCJob::Villager" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ENPCJob::None", (int64)ENPCJob::None },
		{ "ENPCJob::Blacksmith", (int64)ENPCJob::Blacksmith },
		{ "ENPCJob::Merchant", (int64)ENPCJob::Merchant },
		{ "ENPCJob::Villager", (int64)ENPCJob::Villager },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_blacksmith_ENPCJob_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_blacksmith,
	nullptr,
	"ENPCJob",
	"ENPCJob",
	Z_Construct_UEnum_blacksmith_ENPCJob_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_blacksmith_ENPCJob_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_blacksmith_ENPCJob_Statics::Enum_MetaDataParams), Z_Construct_UEnum_blacksmith_ENPCJob_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_blacksmith_ENPCJob()
{
	if (!Z_Registration_Info_UEnum_ENPCJob.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ENPCJob.InnerSingleton, Z_Construct_UEnum_blacksmith_ENPCJob_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ENPCJob.InnerSingleton;
}
// End Enum ENPCJob

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_SharedTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ENPCJob_StaticEnum, TEXT("ENPCJob"), &Z_Registration_Info_UEnum_ENPCJob, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3501210692U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_SharedTypes_h_147181019(TEXT("/Script/blacksmith"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_SharedTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_SharedTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
