#include "EnemyHealthComponent.h"

// Sets default values for this component's properties
UEnemyHealthComponent::UEnemyHealthComponent()
{
	DefaultEnemyHealth = 1000;
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

	EnemyHealth = DefaultEnemyHealth;
}

void UEnemyHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f)
	{
		return;
	}

	EnemyHealth = FMath::Clamp(EnemyHealth - Damage, 0.0f, DefaultEnemyHealth);

	UE_LOG(LogTemp, Log, TEXT("Health Changed: %s"), *FString::SanitizeFloat(EnemyHealth));

	OnEnemyHealthChanged.Broadcast(this, EnemyHealth, Damage, DamageType, InstigatedBy, DamageCauser);
}