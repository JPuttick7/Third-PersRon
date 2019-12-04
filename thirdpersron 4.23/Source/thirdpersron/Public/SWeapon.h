
//includes vital header files, that allow the code in this file to work
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime\Engine\Classes\Camera\CameraModifier_CameraShake.h>
#include "SWeapon.generated.h"

//initialises the classes
class USkeletalMeshComponent;
class UDamageType; 
class UParticleSystem;

UCLASS()
class THIRDPERSRON_API ASWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASWeapon();

protected:
	
	virtual void BeginPlay() override;
	
	//UPROPERTY exposes whatever specified to blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	void PlayFireEffects(FVector TraceEnd); //declares the PlayFireEffects function, with a parameter

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon") //creates a sublass of the damage type class
	TSubclassOf<UDamageType> DamageType; 

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon") //declares MuzzleSocketName
	FName MuzzleSocketName;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon") //declares TracerTargetName
	FName TracerTargetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon") //declares MuzzleEffect
	UParticleSystem* MuzzleEffect;


//Declares the effects to play for the weapons
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* DefaultImpactEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* EnemyDefaultEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* EnemyVulnerableEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* EnemyMetalEffect;

	UPROPERTY(EditDefaultsONly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* TracerEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<UCameraShake> FireCameraShake;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseDamage; // damage that the weapon deals

	void Fire(); //shoots

	FTimerHandle TimerHandle_TimeBetweenShots; //the world time that has passed between shots being fired

	float LastFireTime; //the world timestamp for when the last shot was fired

	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float RateOfFire; // In Rounds Per Minute

	float TimeBetweenShots; // Derived from RateOfFire
public:	
	void StartFire(); //opens fire

	void StopFire(); //stops shooting
};
