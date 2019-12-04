//includes vital header files, that allow the code in this file to work

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnEnemyHealthChanged, UEnemyHealthComponent*, EnemyHealthComp, float, EnemyHealth, float, EnemyHealthDelta, const class UDamageType*, DamageType, class AController*, InstigatedBy, AActor*, DamageCauser);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSRON_API UEnemyHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyHealthComponent();

	UPROPERTY(BlueprintReadOnly, Category = "HealthComponent")
	float EnemyHealth; //the enemies' health
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthComponent")
	float DefaultEnemyHealth; //the enemies' base health

	UFUNCTION() //declares the function that controls the tsking of any damage
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
public:	

	float GetHealth() const; //fetches the enemies' health

	//exposes the OnEnemyHealthChanged macro
	UPROPERTY(BlueprintAssignable, Category = "Components")
	FOnEnemyHealthChanged OnEnemyHealthChanged;
		
};
