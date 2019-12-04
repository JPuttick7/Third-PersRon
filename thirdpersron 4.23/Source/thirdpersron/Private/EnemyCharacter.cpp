#include "EnemyCharacter.h" //includes the header file for this cpp file
#include "Components/CapsuleComponent.h"//includes the capsule component of the character
#include "Components/SkeletalMeshComponent.h"//includes the mesh components of the skeleton
#include "Components/EnemyHealthComponent.h" //inludes the health component
#include "GameFramework/CharacterMovementComponent.h" //includes the character movement component

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creates the health component for the Enemy
	EnemyHealthComp = CreateDefaultSubobject<UEnemyHealthComponent>(TEXT("EnemyHealthComp"));

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//On start, the health comp is initialised to receive damage
	EnemyHealthComp->OnEnemyHealthChanged.AddDynamic(this, &AEnemyCharacter::OnEnemyHealthChanged);
}

void AEnemyCharacter::OnEnemyHealthChanged(UEnemyHealthComponent* OwningHealthComp, float EnemyHealth, float EnemyHealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	// If the enemy has less than 1 health, it dies
	if (EnemyHealth < 1.0f) 
	{
		EnemyHealth = 1.0f;
	}
	if (EnemyHealth <= 1.0f && !bDied)
	{
		KillBot(); //call function to kill the bot
	}
}

void AEnemyCharacter::KillBot()
{
	//Enemy is dead		
	bDied = true;

	GetMovementComponent()->StopMovementImmediately(); //Stops the movement of the bot

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); //Disables the collision of the enemy mesh

	DetachFromControllerPendingDestroy(); //Detach the character from its AI controller

	SetLifeSpan(1.0f); //Deletes character after a set amount of time.
}


