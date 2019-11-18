// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"


class UEnemyHealthComponent;

UCLASS()
class THIRDPERSRON_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Enemy")
	bool bDied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UEnemyHealthComponent* EnemyHealthComp;

	UFUNCTION()
	void OnEnemyHealthChanged(UEnemyHealthComponent* OwningHealthComp, float EnemyHealth, float EnemyHealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	
};
