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
	//timer handles for world timers
	FTimerHandle TimerHandle_BotSpawner;
	FTimerHandle TimerHandle_NextWaveStart;

	// Number of bots to spawn in the wave
	int32 BotsToSpawn;

	//the time to wait before the next wave starts
	UPROPERTY(EditDefaultsOnly, Category = "Gamemode")
	float TimeBetweenWaves;


protected:

	//Hook for blueprint to spawn a single bot
	UFUNCTION(BlueprintImplementableEvent, Category = "Gamemode")
	void SpawnNewBot();

	//function to handle the bot spawns in during the timer
	void SpawnBotTimerElapsed();

	//Start spawning bots 
	void StartWave();

	//Stop spawning bots
	void EndWave();

	//set timer for next wave to start
	void PrepareForNextWave();

	//check the state of the wave
	void CheckWaveState();

	//check if the player is  still alive
	void CheckPlayerAlive();

	//end the game
	void GameOver();


public: 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
	bool bGameOver = false; // is the game over 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
		bool bWin = false; // did you win

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
		bool bLose = false; // did you lose

	//The wave that the player is on
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
	int32 WaveCount; // the wave you are on

	UPROPERTY(EditDefaultsOnly, Category = "Game Mode")
	int32 MaxWaves; // the final wave count

	AHordeGameMode();

	virtual void StartPlay() override;

	virtual void Tick(float DeltaSeconds) override;
};
