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
#ifdef THIRDPERSRON_EnemyHealthComponent_generated_h
#error "EnemyHealthComponent.generated.h already included, missing '#pragma once' in EnemyHealthComponent.h"
#endif
#define THIRDPERSRON_EnemyHealthComponent_generated_h

#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_9_DELEGATE \
struct _Script_thirdpersron_eventOnEnemyHealthChanged_Parms \
{ \
	UEnemyHealthComponent* EnemyHealthComp; \
	float EnemyHealth; \
	float EnemyHealthDelta; \
	const UDamageType* DamageType; \
	AController* InstigatedBy; \
	AActor* DamageCauser; \
}; \
static inline void FOnEnemyHealthChanged_DelegateWrapper(const FMulticastScriptDelegate& OnEnemyHealthChanged, UEnemyHealthComponent* EnemyHealthComp, float EnemyHealth, float EnemyHealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) \
{ \
	_Script_thirdpersron_eventOnEnemyHealthChanged_Parms Parms; \
	Parms.EnemyHealthComp=EnemyHealthComp; \
	Parms.EnemyHealth=EnemyHealth; \
	Parms.EnemyHealthDelta=EnemyHealthDelta; \
	Parms.DamageType=DamageType; \
	Parms.InstigatedBy=InstigatedBy; \
	Parms.DamageCauser=DamageCauser; \
	OnEnemyHealthChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHandleTakeAnyDamage) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamagedActor); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleTakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleTakeAnyDamage) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamagedActor); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleTakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEnemyHealthComponent(); \
	friend struct Z_Construct_UClass_UEnemyHealthComponent_Statics; \
public: \
	DECLARE_CLASS(UEnemyHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(UEnemyHealthComponent)


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUEnemyHealthComponent(); \
	friend struct Z_Construct_UClass_UEnemyHealthComponent_Statics; \
public: \
	DECLARE_CLASS(UEnemyHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(UEnemyHealthComponent)


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEnemyHealthComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEnemyHealthComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEnemyHealthComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEnemyHealthComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEnemyHealthComponent(UEnemyHealthComponent&&); \
	NO_API UEnemyHealthComponent(const UEnemyHealthComponent&); \
public:


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEnemyHealthComponent(UEnemyHealthComponent&&); \
	NO_API UEnemyHealthComponent(const UEnemyHealthComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEnemyHealthComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEnemyHealthComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEnemyHealthComponent)


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__DefaultEnemyHealth() { return STRUCT_OFFSET(UEnemyHealthComponent, DefaultEnemyHealth); }


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_11_PROLOG
#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_RPC_WRAPPERS \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_INCLASS \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_INCLASS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> THIRDPERSRON_API UClass* StaticClass<class UEnemyHealthComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID thirdpersron_4_23_Source_thirdpersron_Public_Components_EnemyHealthComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
