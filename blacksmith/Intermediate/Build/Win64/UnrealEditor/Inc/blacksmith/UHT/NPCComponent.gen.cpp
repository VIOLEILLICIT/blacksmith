// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "blacksmith/NPCComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNPCComponent() {}

// Begin Cross Module References
BLACKSMITH_API UClass* Z_Construct_UClass_UItemDataAsset_NoRegister();
BLACKSMITH_API UClass* Z_Construct_UClass_UNPCComponent();
BLACKSMITH_API UClass* Z_Construct_UClass_UNPCComponent_NoRegister();
BLACKSMITH_API UScriptStruct* Z_Construct_UScriptStruct_FItemInteractionEvent();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_blacksmith();
// End Cross Module References

// Begin ScriptStruct FItemInteractionEvent
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ItemInteractionEvent;
class UScriptStruct* FItemInteractionEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ItemInteractionEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ItemInteractionEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemInteractionEvent, (UObject*)Z_Construct_UPackage__Script_blacksmith(), TEXT("ItemInteractionEvent"));
	}
	return Z_Registration_Info_UScriptStruct_ItemInteractionEvent.OuterSingleton;
}
template<> BLACKSMITH_API UScriptStruct* StaticStruct<FItemInteractionEvent>()
{
	return FItemInteractionEvent::StaticStruct();
}
struct Z_Construct_UScriptStruct_FItemInteractionEvent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Item_MetaData[] = {
		{ "Category", "ItemInteractionEvent" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Amount_MetaData[] = {
		{ "Category", "ItemInteractionEvent" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsGaining_MetaData[] = {
		{ "Category", "ItemInteractionEvent" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static void NewProp_bIsGaining_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsGaining;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemInteractionEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemInteractionEvent, Item), Z_Construct_UClass_UItemDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Item_MetaData), NewProp_Item_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemInteractionEvent, Amount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Amount_MetaData), NewProp_Amount_MetaData) };
void Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_bIsGaining_SetBit(void* Obj)
{
	((FItemInteractionEvent*)Obj)->bIsGaining = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_bIsGaining = { "bIsGaining", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FItemInteractionEvent), &Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_bIsGaining_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsGaining_MetaData), NewProp_bIsGaining_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_Item,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewProp_bIsGaining,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
	nullptr,
	&NewStructOps,
	"ItemInteractionEvent",
	Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::PropPointers),
	sizeof(FItemInteractionEvent),
	alignof(FItemInteractionEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FItemInteractionEvent()
{
	if (!Z_Registration_Info_UScriptStruct_ItemInteractionEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ItemInteractionEvent.InnerSingleton, Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ItemInteractionEvent.InnerSingleton;
}
// End ScriptStruct FItemInteractionEvent

// Begin Class UNPCComponent Function ProcessItemEvent
struct Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics
{
	struct NPCComponent_eventProcessItemEvent_Parms
	{
		FItemInteractionEvent Event;
		AActor* Interactor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NPC" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Event_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Event;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NPCComponent_eventProcessItemEvent_Parms, Event), Z_Construct_UScriptStruct_FItemInteractionEvent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Event_MetaData), NewProp_Event_MetaData) }; // 845275077
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NPCComponent_eventProcessItemEvent_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((NPCComponent_eventProcessItemEvent_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NPCComponent_eventProcessItemEvent_Parms), &Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_Event,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNPCComponent, nullptr, "ProcessItemEvent", nullptr, nullptr, Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NPCComponent_eventProcessItemEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::NPCComponent_eventProcessItemEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNPCComponent_ProcessItemEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNPCComponent_ProcessItemEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNPCComponent::execProcessItemEvent)
{
	P_GET_STRUCT_REF(FItemInteractionEvent,Z_Param_Out_Event);
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ProcessItemEvent(Z_Param_Out_Event,Z_Param_Interactor);
	P_NATIVE_END;
}
// End Class UNPCComponent Function ProcessItemEvent

// Begin Class UNPCComponent Function UpdateAffinity
struct Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics
{
	struct NPCComponent_eventUpdateAffinity_Parms
	{
		int32 Amount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NPC" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NPCComponent_eventUpdateAffinity_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::NewProp_Amount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNPCComponent, nullptr, "UpdateAffinity", nullptr, nullptr, Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::NPCComponent_eventUpdateAffinity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::NPCComponent_eventUpdateAffinity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNPCComponent_UpdateAffinity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNPCComponent_UpdateAffinity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNPCComponent::execUpdateAffinity)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateAffinity(Z_Param_Amount);
	P_NATIVE_END;
}
// End Class UNPCComponent Function UpdateAffinity

// Begin Class UNPCComponent
void UNPCComponent::StaticRegisterNativesUNPCComponent()
{
	UClass* Class = UNPCComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ProcessItemEvent", &UNPCComponent::execProcessItemEvent },
		{ "UpdateAffinity", &UNPCComponent::execUpdateAffinity },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNPCComponent);
UClass* Z_Construct_UClass_UNPCComponent_NoRegister()
{
	return UNPCComponent::StaticClass();
}
struct Z_Construct_UClass_UNPCComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "NPCComponent.h" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Affinity_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialCircle_MetaData[] = {
		{ "Category", "Social" },
		{ "ModuleRelativePath", "NPCComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Affinity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SocialCircle_ValueProp;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SocialCircle_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SocialCircle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UNPCComponent_ProcessItemEvent, "ProcessItemEvent" }, // 2860706570
		{ &Z_Construct_UFunction_UNPCComponent_UpdateAffinity, "UpdateAffinity" }, // 93339698
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNPCComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNPCComponent_Statics::NewProp_Affinity = { "Affinity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNPCComponent, Affinity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Affinity_MetaData), NewProp_Affinity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNPCComponent_Statics::NewProp_SocialCircle_ValueProp = { "SocialCircle", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UNPCComponent_Statics::NewProp_SocialCircle_Key_KeyProp = { "SocialCircle_Key", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UNPCComponent_Statics::NewProp_SocialCircle = { "SocialCircle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNPCComponent, SocialCircle), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialCircle_MetaData), NewProp_SocialCircle_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNPCComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNPCComponent_Statics::NewProp_Affinity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNPCComponent_Statics::NewProp_SocialCircle_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNPCComponent_Statics::NewProp_SocialCircle_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNPCComponent_Statics::NewProp_SocialCircle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNPCComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNPCComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_blacksmith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNPCComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNPCComponent_Statics::ClassParams = {
	&UNPCComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UNPCComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UNPCComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNPCComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UNPCComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNPCComponent()
{
	if (!Z_Registration_Info_UClass_UNPCComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNPCComponent.OuterSingleton, Z_Construct_UClass_UNPCComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNPCComponent.OuterSingleton;
}
template<> BLACKSMITH_API UClass* StaticClass<UNPCComponent>()
{
	return UNPCComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNPCComponent);
UNPCComponent::~UNPCComponent() {}
// End Class UNPCComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FItemInteractionEvent::StaticStruct, Z_Construct_UScriptStruct_FItemInteractionEvent_Statics::NewStructOps, TEXT("ItemInteractionEvent"), &Z_Registration_Info_UScriptStruct_ItemInteractionEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FItemInteractionEvent), 845275077U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNPCComponent, UNPCComponent::StaticClass, TEXT("UNPCComponent"), &Z_Registration_Info_UClass_UNPCComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNPCComponent), 2080928818U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_451157478(TEXT("/Script/blacksmith"),
	Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wjdqj_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
