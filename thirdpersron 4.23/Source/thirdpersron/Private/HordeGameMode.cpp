
#include "HordeGameMode.h"
#include "TimerManager.h"
#include "EnemyHealthComponent.h"
#include "SHealthComponent.h"
#include <Runtime\Engine\Classes\Engine\World.h>

AHordeGameMode::AHordeGameMode()
{
	TimeBetweenWaves = 5.0f;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.0f;
}

void AHordeGameMode::StartWave()
{
	WaveCount++;

	if (WaveCount <= MaxWaves)
	{
		BotsToSpawn = WaveCount;

		GetWorldTimerManager().SetTimer(TimerHandle_BotSpawner, this, &AHordeGameMode::SpawnBotTimerElapsed, 1.0f, true, 0.0f);
	}
	if (WaveCount == MaxWaves + 1)
	{
		bWin = true;
		GameOver();
		
	}
}

void AHordeGameMode::EndWave()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_BotSpawner);

}

void AHordeGameMode::PrepareForNextWave()
{
	GetWorldTimerManager().SetTimer(TimerHandle_NextWaveStart, this, &AHordeGameMode::StartWave, TimeBetweenWaves, false);
}

void AHordeGameMode::CheckWaveState()
{
	bool IsPreparingForWave = GetWorldTimerManager().IsTimerActive(TimerHandle_NextWaveStart);

	if (BotsToSpawn > 0 || IsPreparingForWave)
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