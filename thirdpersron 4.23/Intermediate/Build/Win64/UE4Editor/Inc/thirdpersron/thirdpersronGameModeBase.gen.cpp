// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "thirdpersron/thirdpersronGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodethirdpersronGameModeBase() {}
// Cross Module References
	THIRDPERSRON_API UClass* Z_Construct_UClass_AthirdpersronGameModeBase_NoRegister();
	THIRDPERSRON_API UClass* Z_Construct_UClass_AthirdpersronGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_thirdpersron();
// End Cross Module References
	void AthirdpersronGameModeBase::StaticRegisterNativesAthirdpersronGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AthirdpersronGameModeBase_NoRegister()
	{
		return AthirdpersronGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AthirdpersronGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AthirdpersronGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_thirdpersron,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AthirdpersronGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "thirdpersronGameModeBase.h" },
		{ "ModuleRelativePath", "thirdpersronGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AthirdpersronGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AthirdpersronGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AthirdpersronGameModeBase_Statics::ClassParams = {
		&AthirdpersronGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_AthirdpersronGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AthirdpersronGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AthirdpersronGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AthirdpersronGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AthirdpersronGameModeBase, 3728635047);
	template<> THIRDPERSRON_API UClass* StaticClass<AthirdpersronGameModeBase>()
	{
		return AthirdpersronGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AthirdpersronGameModeBase(Z_Construct_UClass_AthirdpersronGameModeBase, &AthirdpersronGameModeBase::StaticClass, TEXT("/Script/thirdpersron"), TEXT("AthirdpersronGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AthirdpersronGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
