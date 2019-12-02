// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HordeGameMode.generated.h"


enum class EWaveState : uint8;

/**
 * 
 */
UCLASS()
class THIRDPERSRON_API AHordeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

protected: 
	FTimerHandle TimerHandle_BotSpawner;
	FTimerHandle TimerHandle_NextWaveStart;

	// Number of bots to spawn in the wave
	int32 BotsToSpawn;


	UPROPERTY(EditDefaultsOnly, Category = "Gamemode")
	float TimeBetweenWaves;


protected:

	//Hook for blueprint to spawn a single bot
	UFUNCTION(BlueprintImplementableEvent, Category = "Gamemode")
	void SpawnNewBot();

	void SpawnBotTimerElapsed();

	//Start spawning bots 
	void StartWave();

	//Stop spawning bots
	void EndWave();

	//set timer for next wave to start
	void PrepareForNextWave();

	void CheckWaveState();

	void CheckPlayerAlive();

	void GameOver();


public: 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
	bool bGameOver = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
		bool bWin = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
		bool bLose = false;

	//The wave that the player is on
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
	int32 WaveCount;

	UPROPERTY(EditDefaultsOnly, Category = "Game Mode")
	int32 MaxWaves;

	AHordeGameMode();

	virtual void StartPlay() override;

	virtual void Tick(float DeltaSeconds) override;
};
