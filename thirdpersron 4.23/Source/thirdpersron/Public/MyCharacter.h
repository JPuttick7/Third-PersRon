#pragma once
//includes all of the required components
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "MyCharacter.generated.h"




//initializes classes
class UCameraComponent; 
class USpringArmComponent;
class ASWeapon; 
class USHealthComponent;

UCLASS()
class THIRDPERSRON_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public: //declaring functions in public means making the function visible anywhere

	// Sets default values for this character's properties
	AMyCharacter();

protected: //declaring functions in protected means making the function visible to all classes

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//declares the movement functions
	void MoveForward(float Value);

	void MoveRight(float Value);

	//declares the crouching functions
	void BeginCrouch();

	void EndCrouch();

	//UPROPERTY exposes whatever specified to blueprint

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") //initialises the camera component
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") //intitialises the spring arm component for the camera
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") //intitialises the health component for the character
	USHealthComponent* HealthComp;

	bool bWantsToZoom; //declares the zoom boolean
	

	UPROPERTY(EditDefaultsOnly, Category = "Player") //decalres the ZoomedFOV and exposes it to edits in the editor
	float ZoomedFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100)) //exposes the Zoom speed in the editor
	float ZoomInterpSpeed; // declares ZoomInterpSpeed

	float DefaultFOV;// declares DefaultFOV

	//declares the Zoom functions
	void BeginZoom();

	void EndZoom();

	ASWeapon* CurrentWeapon; //uses a pointer to fetch the current weapon from the ASWeapon class
	UPROPERTY(EditDefaultsOnly, Category = "Player") 
	TSubclassOf<ASWeapon> StarterWeaponClass; //creates a subclass of the ASWeapon class

	UPROPERTY(VisibleDefaultsOnly, Category = "Player") //declares WeaponAttachSocketName and exposes to blueprint
	FName WeaponAttachSocketName;

	void StartFire();

	void StopFire();

	UFUNCTION()
	void OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	//Has the pawn died previously
	UPROPERTY(BlueprintReadOnly, Category = "Player")
	bool bDied;

	public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent * PlayerInputComponent) override;

	virtual FVector GetPawnViewLocation() const override; //declares the GetPawnViewLocation functuon and overrides the previous call
};
