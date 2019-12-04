//includes vital header files, that allow the code in this file to work
#include "EnemyHealthComponent.h"

// Sets default values for this component's properties
UEnemyHealthComponent::UEnemyHealthComponent()
{
	DefaultEnemyHealth = 1000; //sets the base health of the enemies
}


// Called when the game starts
void UEnemyHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UEnemyHealthComponent::HandleTakeAnyDamage);
	}

	EnemyHealth = DefaultEnemyHealth; //resets the enemy health
}

//this function handles any damage taken by the player
void UEnemyHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f)
	{
		return;
	}

	EnemyHealth = FMath::Clamp(EnemyHealth - Damage, 0.0f, DefaultEnemyHealth); //stops health going below 0

	UE_LOG(LogTemp, Log, TEXT("Health Changed: %s"), *FString::SanitizeFloat(EnemyHealth)); //testing log for health changes

	OnEnemyHealthChanged.Broadcast(this, EnemyHealth, Damage, DamageType, InstigatedBy, DamageCauser); // health changed event for handling damage 
}

float UEnemyHealthComponent::GetHealth() const
{
	return EnemyHealth; //gets the health of the enemy
}
