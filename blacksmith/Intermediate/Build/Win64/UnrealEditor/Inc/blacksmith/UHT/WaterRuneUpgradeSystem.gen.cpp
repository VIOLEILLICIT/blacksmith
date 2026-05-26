// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/WaterRuneUpgradeSystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWaterRuneUpgradeSystem() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_AWaterRuneUpgradeSystem();
BLACKSMITH_API UClass* Z_Construct_UClass_AWaterRuneUpgradeSystem_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin Class AWaterRuneUpgradeSystem Function UpdateNodePositionFromViewport
struct Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics
{
	struct WaterRuneUpgradeSystem_eventUpdateNodePositionFromViewport_Parms
	{
		FVector2D InputMousePos;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InputMousePos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::NewProp_InputMousePos = { "InputMousePos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WaterRuneUpgradeSystem_eventUpdateNodePositionFromViewport_Parms, InputMousePos), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::NewProp_InputMousePos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWaterRuneUpgradeSystem, nullptr, "UpdateNodePositionFromViewport", nullptr, nullptr, Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::WaterRuneUpgradeSystem_eventUpdateNodePositionFromViewport_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::WaterRuneUpgradeSystem_eventUpdateNodePositionFromViewport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWaterRuneUpgradeSystem::execUpdateNodePositionFromViewport)
{
	P_GET_STRUCT(FVector2D,Z_Param_InputMousePos);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateNodePositionFromViewport(Z_Param_InputMousePos);
	P_NATIVE_END;
}
// End Class AWaterRuneUpgradeSystem Function UpdateNodePositionFromViewport

// Begin Class AWaterRuneUpgradeSystem
void AWaterRuneUpgradeSystem::StaticRegisterNativesAWaterRuneUpgradeSystem()
{
	UClass* Class = AWaterRuneUpgradeSystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "UpdateNodePositionFromViewport", &AWaterRuneUpgradeSystem::execUpdateNodePositionFromViewport },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWaterRuneUpgradeSystem);
UClass* Z_Construct_UClass_AWaterRuneUpgradeSystem_NoRegister()
{
	return AWaterRuneUpgradeSystem::StaticClass();
}
struct Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "WaterRuneUpgradeSystem.h" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsActive_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsDragging_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HoveredNodeName_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStageStep_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PointerProgress_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSpeed_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorTolerance_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeA_Pos_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeB_Pos_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeC_Pos_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImagePointer_Pos_MetaData[] = {
		{ "Category", "Water Rune" },
		{ "ModuleRelativePath", "WaterRuneUpgradeSystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
	static void NewProp_bIsDragging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDragging;
	static const UECodeGen_Private::FNamePropertyParams NewProp_HoveredNodeName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStageStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PointerProgress;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ErrorTolerance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NodeA_Pos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NodeB_Pos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NodeC_Pos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImagePointer_Pos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AWaterRuneUpgradeSystem_UpdateNodePositionFromViewport, "UpdateNodePositionFromViewport" }, // 2256772642
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaterRuneUpgradeSystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsActive_SetBit(void* Obj)
{
	((AWaterRuneUpgradeSystem*)Obj)->bIsActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWaterRuneUpgradeSystem), &Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsActive_MetaData), NewProp_bIsActive_MetaData) };
void Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsDragging_SetBit(void* Obj)
{
	((AWaterRuneUpgradeSystem*)Obj)->bIsDragging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsDragging = { "bIsDragging", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWaterRuneUpgradeSystem), &Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsDragging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsDragging_MetaData), NewProp_bIsDragging_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_HoveredNodeName = { "HoveredNodeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, HoveredNodeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HoveredNodeName_MetaData), NewProp_HoveredNodeName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_CurrentStageStep = { "CurrentStageStep", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, CurrentStageStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStageStep_MetaData), NewProp_CurrentStageStep_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_PointerProgress = { "PointerProgress", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, PointerProgress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PointerProgress_MetaData), NewProp_PointerProgress_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_CurrentSpeed = { "CurrentSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, CurrentSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSpeed_MetaData), NewProp_CurrentSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_ErrorTolerance = { "ErrorTolerance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, ErrorTolerance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorTolerance_MetaData), NewProp_ErrorTolerance_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_NodeA_Pos = { "NodeA_Pos", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, NodeA_Pos), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeA_Pos_MetaData), NewProp_NodeA_Pos_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_NodeB_Pos = { "NodeB_Pos", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, NodeB_Pos), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeB_Pos_MetaData), NewProp_NodeB_Pos_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_NodeC_Pos = { "NodeC_Pos", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, NodeC_Pos), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeC_Pos_MetaData), NewProp_NodeC_Pos_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_ImagePointer_Pos = { "ImagePointer_Pos", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaterRuneUpgradeSystem, ImagePointer_Pos), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImagePointer_Pos_MetaData), NewProp_ImagePointer_Pos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_bIsDragging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_HoveredNodeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_CurrentStageStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_PointerProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_CurrentSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_ErrorTolerance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_NodeA_Pos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_NodeB_Pos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_NodeC_Pos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::NewProp_ImagePointer_Pos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::ClassParams = {
	&AWaterRuneUpgradeSystem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::Class_MetaDataParams), Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWaterRuneUpgradeSystem()
{
	if (!Z_Registration_Info_UClass_AWaterRuneUpgradeSystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWaterRuneUpgradeSystem.OuterSingleton, Z_Construct_UClass_AWaterRuneUpgradeSystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWaterRuneUpgradeSystem.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<AWaterRuneUpgradeSystem>()
{
	return AWaterRuneUpgradeSystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWaterRuneUpgradeSystem);
AWaterRuneUpgradeSystem::~AWaterRuneUpgradeSystem() {}
// End Class AWaterRuneUpgradeSystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_WaterRuneUpgradeSystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWaterRuneUpgradeSystem, AWaterRuneUpgradeSystem::StaticClass, TEXT("AWaterRuneUpgradeSystem"), &Z_Registration_Info_UClass_AWaterRuneUpgradeSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWaterRuneUpgradeSystem), 1138984021U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_WaterRuneUpgradeSystem_h_4112241571(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_WaterRuneUpgradeSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_WaterRuneUpgradeSystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
