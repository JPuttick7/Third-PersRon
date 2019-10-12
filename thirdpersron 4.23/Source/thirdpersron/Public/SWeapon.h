// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditDefaultsONly, BlueprintReadOnly, Category = "Weapon") //declares TracerEffect
	UParticleSystem* TracerEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<UCameraShake> FireCameraShake;


public:	
	UFUNCTION(BlueprintCallable, Category = "Weapon") //declares the Fire function in public, so it can be called in MyCharacter.cpp
	void Fire();
};
