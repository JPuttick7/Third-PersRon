//includes vital header files, that allow the code in this file to work
#include "../Public/MyCharacter.h" //includes declarations and code in the header file
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "thirdpersron.h"
#include "SHealthComponent.h"
#include "SWeapon.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creates a spring arm for the third person camera, controls object collision against the camera and allows the camera to follow the character
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	//allow the character to crouch, uses built-in function from Unreal Engine
	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore); //sets up collision for the weapon mesh

	//initialise the health component for the character.
	HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComp"));

	//Attaches the spring arm camera to the character
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	ZoomedFOV = 65.0f; //sets the zoomed FOV
	ZoomInterpSpeed = 20; //sets the speed of the zoom transition

	WeaponAttachSocketName = "hand_rSocket"; // name of the socket to attach the weapon to
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	DefaultFOV = CameraComp->FieldOfView; //sets the default FOV

	//Spawn the players weapon
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; //sets the collison spawn parameters

	CurrentWeapon = GetWorld()->SpawnActor<ASWeapon>(StarterWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	if (CurrentWeapon)
	{
		CurrentWeapon->SetOwner(this); // Attaches the weapon the the players hand
		CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponAttachSocketName);
	}

	HealthComp->OnHealthChanged.AddDynamic(this, &AMyCharacter::OnHealthChanged);
}

void AMyCharacter::MoveForward(float Value) // function for moving forward
{
	AddMovementInput(GetActorForwardVector() * Value);//moves the character forward
}

void AMyCharacter::MoveRight(float Value)// function for moving right
{
	AddMovementInput(GetActorRightVector() * Value);//moves the character right
}

void AMyCharacter::BeginCrouch() // function to start crouching
{
	Crouch();//crouches the character
}

void AMyCharacter::EndCrouch() // function to end crouching
{
	UnCrouch();//uncrouches the character
}


void AMyCharacter::BeginZoom()// function to start zooming
{
	bWantsToZoom = true; //Turns on the Zoom
}

void AMyCharacter::EndZoom()// function to end zooming
{
	bWantsToZoom = false; // Turns off the zoom
}

void AMyCharacter::StartFire()//allows non-blueprint input and checks if there is a weapon spawned
{
	if(CurrentWeapon)
	{
		CurrentWeapon->StartFire(); //calls the weapon file to fire
	}
}

void AMyCharacter::StopFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StopFire(); //stops firing the weapon
	}
}

void AMyCharacter::OnHealthChanged(USHealthComponent* HealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	
	if (Health <= 0.0f && !bDied)  //checks if you are dead
	{
		//You are dead		
		bDied = true; 

		GetMovementComponent()->StopMovementImmediately(); //stops all movement

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);	//disables collision
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV; // checks of the user wants to zoom

	float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed); //magical math makes a smooth zoom transition

	CameraComp->SetFieldOfView(NewFOV); // sets the FOV the user wants (zoomed or not zoomed)

	
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//binds the different movement controls to input controls, that can be set in the Unreal Engine settings.
	// for example, MoveForward, is an input component that is binded to the W key, in the Unreal Engine, outside of the code.
	
	//moving
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	//Looking around
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);

	//crouching
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyCharacter::BeginCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMyCharacter::EndCrouch);

	//jumping
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);

	//zooming
	PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &AMyCharacter::BeginZoom);
	PlayerInputComponent->BindAction("Zoom", IE_Released, this, &AMyCharacter::EndZoom);

	//shooting
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AMyCharacter::StopFire);
}

FVector AMyCharacter::GetPawnViewLocation() const //get the pawns view location
{
	if (CameraComp) //checks if null
	{
		return CameraComp->GetComponentLocation(); // gets the location of the camera component
	}
	return Super::GetPawnViewLocation(); //return the pawn view location
}