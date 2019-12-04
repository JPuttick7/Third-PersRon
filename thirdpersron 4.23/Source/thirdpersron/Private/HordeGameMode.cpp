
#include "HordeGameMode.h"//includes the header for this file
#include "TimerManager.h"//includes the timer manager files
#include "EnemyHealthComponent.h"//includes the enemy's health component
#include "SHealthComponent.h"//includes the player's health component
#include <Runtime\Engine\Classes\Engine\World.h>//includes the world

AHordeGameMode::AHordeGameMode()
{
	TimeBetweenWaves = 5.0f; //sets the time between enemy waves

	PrimaryActorTick.bCanEverTick = true; //allows the primary actor to tick
	PrimaryActorTick.TickInterval = 1.0f; //sets the tick time to tick every second
}

void AHordeGameMode::StartWave()
{
	WaveCount++; //increases the wavecount

	if (WaveCount <= MaxWaves) //if the wave count is less than the max amount of waves, spawn the enemies
	{
		BotsToSpawn = WaveCount; //increases each wave

		GetWorldTimerManager().SetTimer(TimerHandle_BotSpawner, this, &AHordeGameMode::SpawnBotTimerElapsed, 1.0f, true, 0.0f); //spawns the bots every second
	}
	if (WaveCount == MaxWaves + 1) // if the wave count has reached the max amount of waves
	{
		bWin = true;//you have won!
		GameOver(); //end the game
		
	}
}

void AHordeGameMode::EndWave()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_BotSpawner); //clears the spawn timer

}

void AHordeGameMode::PrepareForNextWave()
{   //sets the timer to count down to the next wave
	GetWorldTimerManager().SetTimer(TimerHandle_NextWaveStart, this, &AHordeGameMode::StartWave, TimeBetweenWaves, false); 
}

void AHordeGameMode::CheckWaveState()
{	
	bool IsPreparingForWave = GetWorldTimerManager().IsTimerActive(TimerHandle_NextWaveStart); //checks if the timer is active

	if (BotsToSpawn > 0 || IsPreparingForWave) //returns if there are still bots to spawn
	{
		return;
	}

	bool IsAnyBotAlive = false;

	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; It++)
	{
	/*checks if there are still enemies left to kill*/
		APawn* EnemyPawn = It->Get();
		if (EnemyPawn == nullptr || EnemyPawn->IsPlayerControlled())
		{
			continue;
		}
		UEnemyHealthComponent* EnemyHealthComp = Cast<UEnemyHealthComponent>(EnemyPawn->GetComponentByClass(UEnemyHealthComponent::StaticClass()));
		if (EnemyHealthComp && EnemyHealthComp->GetHealth() > 0.0f)
		{
			IsAnyBotAlive = true;
			break;
		}
	}
	if (!IsAnyBotAlive)
	{
		PrepareForNextWave();
	}

}

void AHordeGameMode::CheckPlayerAlive()
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{	//checks if any player is alive
		APlayerController* PC = It->Get();
		if (PC && PC->GetPawn())
		{
			APawn* MyPawn = PC->GetPawn();
			USHealthComponent* HealthComp = Cast<USHealthComponent>(MyPawn->GetComponentByClass(USHealthComponent::StaticClass()));
			if (ensure(HealthComp) && HealthComp->GetHealth() > 0.0f)
			{
				return;
			}
		}
	}
	//Player is dead
	bLose = true;
	GameOver();	
}

void AHordeGameMode::GameOver()
{
	EndWave(); //calls the endwave function

	bGameOver = true; //game is over
	 
	UE_LOG(LogTemp, Log, TEXT("GAME OVER -- PLAYER DIED")); //DevOutputLog data for testing
}


void AHordeGameMode::StartPlay()
{
	//called when the program starts running
	Super::StartPlay();

	PrepareForNextWave();
	
}

void AHordeGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//checks the state and player condition every tick
	CheckWaveState(); 
	CheckPlayerAlive();
}


void AHordeGameMode::SpawnBotTimerElapsed()
{
	SpawnNewBot(); //calls the blueprint function  and runs EQS to spawn a bot

	BotsToSpawn--;

	if (BotsToSpawn <= 0) //ends the wave when there are no more bots to spawn
	{
		EndWave();
	}
}