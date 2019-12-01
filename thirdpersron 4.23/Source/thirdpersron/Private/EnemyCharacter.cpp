// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"//includes the mesh components of the skeleton
#include "Components/EnemyHealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyHealthComp = CreateDefaultSubobject<UEnemyHealthComponent>(TEXT("EnemyHealthComp"));

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	EnemyHealthComp->OnEnemyHealthChanged.AddDynamic(this, &AEnemyCharacter::OnEnemyHealthChanged);
}

void AEnemyCharacter::OnEnemyHealthChanged(UEnemyHealthComponent* OwningHealthComp, float EnemyHealth, float EnemyHealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (EnemyHealth < 1.0f)
	{
		EnemyHealth = 1.0f;
	}
	if (EnemyHealth <= 1.0f && !bDied)
	{
		KillBot();
	}
}

void AEnemyCharacter::KillBot()
{
	//Enemy is dead		
	bDied = true;

	GetMovementComponent()->StopMovementImmediately();

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	DetachFromControllerPendingDestroy();

	SetLifeSpan(1.0f);
}


