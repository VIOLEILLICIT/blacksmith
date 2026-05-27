// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InteractableInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BLACKSMITH_InteractableInterface_generated_h
#error "InteractableInterface.generated.h already included, missing '#pragma once' in InteractableInterface.h"
#endif
#define BLACKSMITH_InteractableInterface_generated_h

#define FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	BLACKSMITH_API UInteractableInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UInteractableInterface(UInteractableInterface&&); \
	UInteractableInterface(const UInteractableInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(BLACKSMITH_API, UInteractableInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractableInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractableInterface) \
	BLACKSMITH_API virtual ~UInteractableInterface();


#define FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_10_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractableInterface(); \
	friend struct Z_Construct_UClass_UInteractableInterface_Statics; \
public: \
	DECLARE_CLASS(UInteractableInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/blacksmith"), BLACKSMITH_API) \
	DECLARE_SERIALIZER(UInteractableInterface)


#define FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_10_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_10_GENERATED_UINTERFACE_BODY() \
	FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_10_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractableInterface() {} \
public: \
	typedef UInteractableInterface UClassType; \
	typedef IInteractableInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_7_PROLOG
#define FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BLACKSMITH_API UClass* StaticClass<class UInteractableInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_blacksmith_blacksmith_Source_blacksmith_InteractableInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
