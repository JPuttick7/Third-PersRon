
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
		APawn* TestPawn = It->Get();
		if (TestPawn == nullptr || TestPawn->IsPlayerControlled())
		{
			continue;
		}
		UEnemyHealthComponent* EnemyHealthComp = Cast<UEnemyHealthComponent>(TestPawn->GetComponentByClass(UEnemyHealthComponent::StaticClass()));
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
	{
		APlayerController* PC = It->Get();
		if (PC && PC->GetPawn())
		{
			APawn* MyPawn = PC->GetPawn();
			USHealthComponent* HealthComp = Cast<USHealthComponent>(MyPawn->GetComponentByClass(USHealthComponent::StaticClass()));
			if (ensure(HealthComp) && HealthComp->GetHealth() > 0.0f)
			{
				//checks if player is still alive
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
	EndWave();

	bGameOver = true;

	UE_LOG(LogTemp, Log, TEXT("GAME OVER -- PLAYER DIED"));
}


void AHordeGameMode::StartPlay()
{
	Super::StartPlay();

	PrepareForNextWave();
	
}

void AHordeGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CheckWaveState();
	CheckPlayerAlive();
}


void AHordeGameMode::SpawnBotTimerElapsed()
{
	SpawnNewBot();

	BotsToSpawn--;

	if (BotsToSpawn <= 0)
	{
		EndWave();
	}
}