// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "thirdpersron/Public/HordeGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHordeGameMode() {}
// Cross Module References
	THIRDPERSRON_API UClass* Z_Construct_UClass_AHordeGameMode_NoRegister();
	THIRDPERSRON_API UClass* Z_Construct_UClass_AHordeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_thirdpersron();
	THIRDPERSRON_API UFunction* Z_Construct_UFunction_AHordeGameMode_SpawnNewBot();
// End Cross Module References
	static FName NAME_AHordeGameMode_SpawnNewBot = FName(TEXT("SpawnNewBot"));
	void AHordeGameMode::SpawnNewBot()
	{
		ProcessEvent(FindFunctionChecked(NAME_AHordeGameMode_SpawnNewBot),NULL);
	}
	void AHordeGameMode::StaticRegisterNativesAHordeGameMode()
	{
	}
	struct Z_Construct_UFunction_AHordeGameMode_SpawnNewBot_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHordeGameMode_SpawnNewBot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gamemode" },
		{ "Comment", "//Hook for blueprint to spawn a single bot\n" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
		{ "ToolTip", "Hook for blueprint to spawn a single bot" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHordeGameMode_SpawnNewBot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHordeGameMode, nullptr, "SpawnNewBot", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHordeGameMode_SpawnNewBot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHordeGameMode_SpawnNewBot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHordeGameMode_SpawnNewBot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHordeGameMode_SpawnNewBot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHordeGameMode_NoRegister()
	{
		return AHordeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AHordeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxWaves_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxWaves;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WaveCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_WaveCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLose_MetaData[];
#endif
		static void NewProp_bLose_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLose;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bWin_MetaData[];
#endif
		static void NewProp_bWin_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bWin;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bGameOver_MetaData[];
#endif
		static void NewProp_bGameOver_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bGameOver;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeBetweenWaves_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeBetweenWaves;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHordeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_thirdpersron,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AHordeGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHordeGameMode_SpawnNewBot, "SpawnNewBot" }, // 428955898
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHordeGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HordeGameMode.h" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHordeGameMode_Statics::NewProp_MaxWaves_MetaData[] = {
		{ "Category", "Game Mode" },
		{ "Comment", "// the wave you are on\n" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
		{ "ToolTip", "the wave you are on" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AHordeGameMode_Statics::NewProp_MaxWaves = { "MaxWaves", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHordeGameMode, MaxWaves), METADATA_PARAMS(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_MaxWaves_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_MaxWaves_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHordeGameMode_Statics::NewProp_WaveCount_MetaData[] = {
		{ "Category", "Game Mode" },
		{ "Comment", "//The wave that the player is on\n" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
		{ "ToolTip", "The wave that the player is on" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AHordeGameMode_Statics::NewProp_WaveCount = { "WaveCount", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHordeGameMode, WaveCount), METADATA_PARAMS(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_WaveCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_WaveCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bLose_MetaData[] = {
		{ "Category", "Game Mode" },
		{ "Comment", "// did you win\n" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
		{ "ToolTip", "did you win" },
	};
#endif
	void Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bLose_SetBit(void* Obj)
	{
		((AHordeGameMode*)Obj)->bLose = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bLose = { "bLose", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AHordeGameMode), &Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bLose_SetBit, METADATA_PARAMS(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bLose_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bLose_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bWin_MetaData[] = {
		{ "Category", "Game Mode" },
		{ "Comment", "// is the game over \n" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
		{ "ToolTip", "is the game over" },
	};
#endif
	void Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bWin_SetBit(void* Obj)
	{
		((AHordeGameMode*)Obj)->bWin = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bWin = { "bWin", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AHordeGameMode), &Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bWin_SetBit, METADATA_PARAMS(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bWin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bWin_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bGameOver_MetaData[] = {
		{ "Category", "Game Mode" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
	};
#endif
	void Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bGameOver_SetBit(void* Obj)
	{
		((AHordeGameMode*)Obj)->bGameOver = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bGameOver = { "bGameOver", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AHordeGameMode), &Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bGameOver_SetBit, METADATA_PARAMS(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bGameOver_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bGameOver_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHordeGameMode_Statics::NewProp_TimeBetweenWaves_MetaData[] = {
		{ "Category", "Gamemode" },
		{ "Comment", "//the time to wait before the next wave starts\n" },
		{ "ModuleRelativePath", "Public/HordeGameMode.h" },
		{ "ToolTip", "the time to wait before the next wave starts" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHordeGameMode_Statics::NewProp_TimeBetweenWaves = { "TimeBetweenWaves", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHordeGameMode, TimeBetweenWaves), METADATA_PARAMS(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_TimeBetweenWaves_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::NewProp_TimeBetweenWaves_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHordeGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHordeGameMode_Statics::NewProp_MaxWaves,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHordeGameMode_Statics::NewProp_WaveCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bLose,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bWin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHordeGameMode_Statics::NewProp_bGameOver,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHordeGameMode_Statics::NewProp_TimeBetweenWaves,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHordeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHordeGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHordeGameMode_Statics::ClassParams = {
		&AHordeGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AHordeGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHordeGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHordeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHordeGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHordeGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHordeGameMode, 1740780905);
	template<> THIRDPERSRON_API UClass* StaticClass<AHordeGameMode>()
	{
		return AHordeGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHordeGameMode(Z_Construct_UClass_AHordeGameMode, &AHordeGameMode::StaticClass, TEXT("/Script/thirdpersron"), TEXT("AHordeGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHordeGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
