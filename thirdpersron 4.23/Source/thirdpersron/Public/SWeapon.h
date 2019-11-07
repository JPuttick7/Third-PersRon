// Fill out your copyright notice in the Description page of Project Settings.

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon") //declares ImpactEffect
	UParticleSystem* DefaultImpactEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* EnemyDefaultEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* EnemyVulnerableEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UParticleSystem* EnemyMetalEffect;

	UPROPERTY(EditDefaultsONly, BlueprintReadOnly, Category = "Weapon") //declares TracerEffect
	UParticleSystem* TracerEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<UCameraShake> FireCameraShake;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseDamage;

	void Fire();

	FTimerHandle TimerHandle_TimeBetweenShots;

	float LastFireTime;

	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float RateOfFire; // In Rounds Per Minute

	float TimeBetweenShots; // Derived from RateOfFire
public:	
	void StartFire();

	void StopFire();
};
