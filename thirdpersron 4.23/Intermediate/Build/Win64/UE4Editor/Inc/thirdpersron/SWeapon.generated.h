// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef THIRDPERSRON_SWeapon_generated_h
#error "SWeapon.generated.h already included, missing '#pragma once' in SWeapon.h"
#endif
#define THIRDPERSRON_SWeapon_generated_h

#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_RPC_WRAPPERS
#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASWeapon(); \
	friend struct Z_Construct_UClass_ASWeapon_Statics; \
public: \
	DECLARE_CLASS(ASWeapon, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(ASWeapon)


#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_INCLASS \
private: \
	static void StaticRegisterNativesASWeapon(); \
	friend struct Z_Construct_UClass_ASWeapon_Statics; \
public: \
	DECLARE_CLASS(ASWeapon, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/thirdpersron"), NO_API) \
	DECLARE_SERIALIZER(ASWeapon)


#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASWeapon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASWeapon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASWeapon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASWeapon(ASWeapon&&); \
	NO_API ASWeapon(const ASWeapon&); \
public:


#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASWeapon(ASWeapon&&); \
	NO_API ASWeapon(const ASWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASWeapon)


#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshComp() { return STRUCT_OFFSET(ASWeapon, MeshComp); } \
	FORCEINLINE static uint32 __PPO__DamageType() { return STRUCT_OFFSET(ASWeapon, DamageType); } \
	FORCEINLINE static uint32 __PPO__MuzzleSocketName() { return STRUCT_OFFSET(ASWeapon, MuzzleSocketName); } \
	FORCEINLINE static uint32 __PPO__TracerTargetName() { return STRUCT_OFFSET(ASWeapon, TracerTargetName); } \
	FORCEINLINE static uint32 __PPO__MuzzleEffect() { return STRUCT_OFFSET(ASWeapon, MuzzleEffect); } \
	FORCEINLINE static uint32 __PPO__DefaultImpactEffect() { return STRUCT_OFFSET(ASWeapon, DefaultImpactEffect); } \
	FORCEINLINE static uint32 __PPO__EnemyDefaultEffect() { return STRUCT_OFFSET(ASWeapon, EnemyDefaultEffect); } \
	FORCEINLINE static uint32 __PPO__EnemyVulnerableEffect() { return STRUCT_OFFSET(ASWeapon, EnemyVulnerableEffect); } \
	FORCEINLINE static uint32 __PPO__EnemyMetalEffect() { return STRUCT_OFFSET(ASWeapon, EnemyMetalEffect); } \
	FORCEINLINE static uint32 __PPO__TracerEffect() { return STRUCT_OFFSET(ASWeapon, TracerEffect); } \
	FORCEINLINE static uint32 __PPO__FireCameraShake() { return STRUCT_OFFSET(ASWeapon, FireCameraShake); } \
	FORCEINLINE static uint32 __PPO__BaseDamage() { return STRUCT_OFFSET(ASWeapon, BaseDamage); } \
	FORCEINLINE static uint32 __PPO__RateOfFire() { return STRUCT_OFFSET(ASWeapon, RateOfFire); }


#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_15_PROLOG
#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_RPC_WRAPPERS \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_INCLASS \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_PRIVATE_PROPERTY_OFFSET \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_INCLASS_NO_PURE_DECLS \
	thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> THIRDPERSRON_API UClass* StaticClass<class ASWeapon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID thirdpersron_4_23_Source_thirdpersron_Public_SWeapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
