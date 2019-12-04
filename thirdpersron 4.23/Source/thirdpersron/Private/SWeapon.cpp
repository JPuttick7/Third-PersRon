//includes vital header files, that allow the code in this file to work
#include "SWeapon.h"
#include "DrawDebugHelpers.h" 
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h" 
#include "Components/SkeletalMeshComponent.h" 
#include "Particles/ParticleSystemComponent.h" 
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "TimerManager.h"	
#include "thirdpersron.h"

//creates a console command to draw debug lines from the camera to where the player is aiming
static int32 DebugWeaponDrawing = 0;
FAutoConsoleVariableRef CVARDebugWeaponDrawing(TEXT("DebugWeapons"),
	DebugWeaponDrawing,
	TEXT("Draw Debug Lines for Weapons"),
	ECVF_Cheat);
FVector TracerEndPoint; //declares TracerEndPoint

// Sets default values
ASWeapon::ASWeapon()
{
 	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));//creates the mesh component of the weapon
	RootComponent = MeshComp; //assigns the RootComponent the value of MeshComp

	MuzzleSocketName = "MuzzleSocket"; //assigns the name of the muzzle socket
	TracerTargetName = "Target"; // assigns the name of the target for the tracer

	BaseDamage = 200; // The damage the weapon deals per hit

	RateOfFire = 600; // Rate of fire of the weapon in Rounds per Minute
	
}

void ASWeapon::BeginPlay()
{	
	//called when the game begins
	Super::BeginPlay();

	TimeBetweenShots = 60 / RateOfFire; //calculates the time between individual shots at the specified rate of fire
}

void ASWeapon::Fire() //function that fires the weapon
{
	AActor*  MyOwner = GetOwner(); //pointer to fetch the owner of the weapon
	if (MyOwner) //checks if the owner has spawned
	{
		FVector EyeLocation; //declares EyeLocation
		FRotator EyeRotation; //declares EyeRotation
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation); //get the location of the characters eyes

		FVector ShotDirection = EyeRotation.Vector(); //assign the direction of the shot to the rotation of the player eye

		FVector TraceEnd = EyeLocation + (ShotDirection * 10000); //traces the direction of the shot that is fires

		FCollisionQueryParams QueryParams; //creates query parameters with the collision model
		QueryParams.AddIgnoredActor(MyOwner); //cant shoot yourself ;)
		QueryParams.AddIgnoredActor(this); // cant hit the gun itself
		QueryParams.bTraceComplex = true; // checks whether it should trace against complex collision models
		QueryParams.bReturnPhysicalMaterial = true;

		TracerEndPoint = TraceEnd; //assign TracerEndPoint the value of TraceEnd

		FHitResult Hit; //the hit checker variable

		//traces the players eyes, and checks if there is a correct collion model is the direction, if there is, it is a hit
		if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams))
		{
			AActor* HitActor = Hit.GetActor(); //fetches the actor that was hit
			
			EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get()); //gets the material that was hit

			//determines the damage multiplier dependant on the part of enemy hit
			float ActualDamage = BaseDamage;
			if (SurfaceType == SURFACE_ENEMYVULNERABLE)
			{
				ActualDamage *= 4.0f; //x4 on headshots
			}
			else if (SurfaceType == SURFACE_ENEMYMETAL)
			{
				ActualDamage = 0; //no damage
			}
			
			//applies the damage of the weapon
			UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, MyOwner->GetInstigatorController(), this, DamageType);
			   
			//determines the effect based upon what material was impacted
			UParticleSystem* SelectedEffect = nullptr;
			switch (SurfaceType)
			{
			case SURFACE_ENEMYDEFAULT:
				SelectedEffect = EnemyDefaultEffect;
				break;
			case SURFACE_ENEMYVULNERABLE:
				SelectedEffect = EnemyVulnerableEffect;
				break;
			case SURFACE_ENEMYMETAL:
				SelectedEffect = EnemyMetalEffect;
				break;
			default:
				SelectedEffect = DefaultImpactEffect;
				break;
			}

			if (SelectedEffect)
			{   // displays the hit effect
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SelectedEffect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
			}

			TracerEndPoint = Hit.ImpactPoint; //assign TracerEndPoint the value of the impactpoinf if the shot was a ht
		}

		if (DebugWeaponDrawing) //if the debug console command is active
		{
			DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f); //draws a line from the camera to the hit point
		}
		PlayFireEffects(TracerEndPoint); //plays the muzzle flash and bullet tracer effects

		LastFireTime = GetWorld()->TimeSeconds; //gets the world time of the last weapon discharge
	}
}


void ASWeapon::StartFire()
{
	//starts firing fully automatic
	float FirstDelay = FMath::Max(LastFireTime + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);
	GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &ASWeapon::Fire, TimeBetweenShots, true, FirstDelay);
}

void ASWeapon::StopFire()
{
	//stops the automatic fire
	GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
}

void ASWeapon::PlayFireEffects(FVector TraceEnd) //function for the weapon effects 
{
	if (MuzzleEffect)
	{
		UGameplayStatics::SpawnEmitterAttached(MuzzleEffect, MeshComp, MuzzleSocketName); //plays the muzzle flash
	
	}

	if (TracerEffect)
	{	
		//plays the tracer location from the muzzle tocket to the target location
		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);

		UParticleSystemComponent* TracerComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TracerEffect, MuzzleLocation);

		if (TracerComp) 
		{
			TracerComp->SetVectorParameter(TracerTargetName, TraceEnd);
		}
	}
	//shakes the camera slightly when firing
	APawn* MyOwner = Cast<APawn>(GetOwner()); 
	if (MyOwner) 
	{
		APlayerController* PC = Cast<APlayerController>(MyOwner->GetController());
		if (PC)
		{
			PC->ClientPlayCameraShake(FireCameraShake); //plays the camera shake component
		}
	}
}