// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NPCComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FItemInteractionEvent;
#ifdef BLACKSMITH_NPCComponent_generated_h
#error "NPCComponent.generated.h already included, missing '#pragma once' in NPCComponent.h"
#endif
#define BLACKSMITH_NPCComponent_generated_h

#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FItemInteractionEvent_Statics; \
	BLACKSMITH_API static class UScriptStruct* StaticStruct();


template<> BLACKSMITH_API UScriptStruct* StaticStruct<struct FItemInteractionEvent>();

#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execProcessItemEvent); \
	DECLARE_FUNCTION(execUpdateAffinity);


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNPCComponent(); \
	friend struct Z_Construct_UClass_UNPCComponent_Statics; \
public: \
	DECLARE_CLASS(UNPCComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/blacksmith"), NO_API) \
	DECLARE_SERIALIZER(UNPCComponent)


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UNPCComponent(UNPCComponent&&); \
	UNPCComponent(const UNPCComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNPCComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNPCComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UNPCComponent) \
	NO_API virtual ~UNPCComponent();


#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_24_PROLOG
#define FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_27_INCLASS_NO_PURE_DECLS \
	FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class UNPCComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_1_Documents_GitHub_blacksmith_blacksmith_Source_blacksmith_NPCComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
