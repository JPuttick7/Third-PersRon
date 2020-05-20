// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UEnemyHealthComponent;
class UDamageType;
class AController;
class AActor;
#ifdef THIRDPERSRON_EnemyCharacter_generated_h
#error "EnemyCharacter.generated.h already included, missing '#pragma once' in EnemyCharacter.h"
#endif
#define THIRDPERSRON_EnemyCharacter_generated_h

#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_SPARSE_DATA
#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEnemyHealthChanged) \
	{ \
		P_GET_OBJECT(UEnemyHealthComponent,Z_Param_OwningHealthComp); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EnemyHealth); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EnemyHealthDelta); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEnemyHealthChanged(Z_Param_OwningHealthComp,Z_Param_EnemyHealth,Z_Param_EnemyHealthDelta,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEnemyHealthChanged) \
	{ \
		P_GET_OBJECT(UEnemyHealthComponent,Z_Param_OwningHealthComp); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EnemyHealth); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EnemyHealthDelta); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEnemyHealthChanged(Z_Param_OwningHealthComp,Z_Param_EnemyHealth,Z_Param_EnemyHealthDelta,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyCharacter(); \
	friend struct Z_Construct_UClass_AEnemyCharacter_Statics; \
public: \
	DECLARE_CLASS(AEnemyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(AEnemyCharacter)


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAEnemyCharacter(); \
	friend struct Z_Construct_UClass_AEnemyCharacter_Statics; \
public: \
	DECLARE_CLASS(AEnemyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(AEnemyCharacter)


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyCharacter(AEnemyCharacter&&); \
	NO_API AEnemyCharacter(const AEnemyCharacter&); \
public:


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyCharacter(AEnemyCharacter&&); \
	NO_API AEnemyCharacter(const AEnemyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyCharacter)


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bDied() { return STRUCT_OFFSET(AEnemyCharacter, bDied); } \
	FORCEINLINE static uint32 __PPO__EnemyHealthComp() { return STRUCT_OFFSET(AEnemyCharacter, EnemyHealthComp); }


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_11_PROLOG
#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_SPARSE_DATA \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_RPC_WRAPPERS \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_INCLASS \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_SPARSE_DATA \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_INCLASS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> THIRDPERSRON_API UClass* StaticClass<class AEnemyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID thirdpersron_4_23_Source_thirdpersron_Public_EnemyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
