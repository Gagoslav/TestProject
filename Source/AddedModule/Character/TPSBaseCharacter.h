// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSBaseCharacter.generated.h"

class UBaseCharacterMovementComponent; // Custom character movement component for Sprint implementation
class UCharacterEquipmentComponent;

UCLASS(Abstract, NotBlueprintable)
class TPSSHOOTER_API ATPSBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	 
	ATPSBaseCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaTime) override;

	//declaring pure virtual methods in an abstract base class to implement them in derived classes
	virtual void MoveForward(float Value) {};
	virtual void MoveRight(float Value) {};
	virtual void Turn(float Value) {};
	virtual void LookUp(float Value) {};

	UFUNCTION(BlueprintCallable)
	virtual void StartSprint();

	UFUNCTION(BlueprintCallable)
	virtual void EndSprint();

	virtual void ChangeCrouchState();

	void Fire();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	


	inline UBaseCharacterMovementComponent* GetBaseCharacterMovement() { return BaseCharacterMovementComponent; }
	inline const UCharacterEquipmentComponent* GetCharacterEquipmentComponent()const { return CharacterEquipmentComponent; }

protected:

	// Ensure communicatino between C++ and Blueprints, make the function's implementation in blueprints
	UFUNCTION(BlueprintImplementableEvent, Category = "Character | Movement")
	void OnStartSprint();

	UFUNCTION(BlueprintImplementableEvent, Category = "Character | Movement")
	void OnEndSprint();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Components")
	UCharacterEquipmentComponent* CharacterEquipmentComponent;



	

private:
	 UBaseCharacterMovementComponent* BaseCharacterMovementComponent;
	 void TryChangeSprintState();
	 bool bIsSprintRequested = 0;

};
