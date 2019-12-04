//includes vital header files, that allow the code in this file to work
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
	bool bDied; //has the enemy died?

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UEnemyHealthComponent* EnemyHealthComp; //the inherited health component

	//UFunction event to ahandle when health has been changed, broadcasted from the inherited health component
	UFUNCTION()
	void OnEnemyHealthChanged(UEnemyHealthComponent* OwningHealthComp, float EnemyHealth, float EnemyHealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	void KillBot(); //kills the bot
	
};
