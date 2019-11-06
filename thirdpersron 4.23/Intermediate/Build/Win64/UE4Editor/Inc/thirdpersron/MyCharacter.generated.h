// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USHealthComponent;
class UDamageType;
class AController;
class AActor;
#ifdef THIRDPERSRON_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define THIRDPERSRON_MyCharacter_generated_h

#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHealthChanged) \
	{ \
		P_GET_OBJECT(USHealthComponent,Z_Param_OwningHealthComp); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Health); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealthDelta); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHealthChanged(Z_Param_OwningHealthComp,Z_Param_Health,Z_Param_HealthDelta,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHealthChanged) \
	{ \
		P_GET_OBJECT(USHealthComponent,Z_Param_OwningHealthComp); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Health); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealthDelta); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHealthChanged(Z_Param_OwningHealthComp,Z_Param_Health,Z_Param_HealthDelta,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public:


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraComp() { return STRUCT_OFFSET(AMyCharacter, CameraComp); } \
	FORCEINLINE static uint32 __PPO__SpringArmComp() { return STRUCT_OFFSET(AMyCharacter, SpringArmComp); } \
	FORCEINLINE static uint32 __PPO__SHealthComp() { return STRUCT_OFFSET(AMyCharacter, SHealthComp); } \
	FORCEINLINE static uint32 __PPO__ZoomedFOV() { return STRUCT_OFFSET(AMyCharacter, ZoomedFOV); } \
	FORCEINLINE static uint32 __PPO__ZoomInterpSpeed() { return STRUCT_OFFSET(AMyCharacter, ZoomInterpSpeed); } \
	FORCEINLINE static uint32 __PPO__StarterWeaponClass() { return STRUCT_OFFSET(AMyCharacter, StarterWeaponClass); } \
	FORCEINLINE static uint32 __PPO__WeaponAttachSocketName() { return STRUCT_OFFSET(AMyCharacter, WeaponAttachSocketName); } \
	FORCEINLINE static uint32 __PPO__bDied() { return STRUCT_OFFSET(AMyCharacter, bDied); }


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_17_PROLOG
#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_RPC_WRAPPERS \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_INCLASS \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_INCLASS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> THIRDPERSRON_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID thirdpersron_4_23_Source_thirdpersron_Public_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
