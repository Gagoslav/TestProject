// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TPSBaseCharacter.h"
#include "Components/BaseCharacterMovementComponent.h"
#include "Components/CharacterEquipmentComponent.h"

ATPSBaseCharacter::ATPSBaseCharacter(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UBaseCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	BaseCharacterMovementComponent = StaticCast<UBaseCharacterMovementComponent*>(GetCharacterMovement());

	CharacterEquipmentComponent = CreateDefaultSubobject<UCharacterEquipmentComponent>(TEXT("CharacterEquipment"));
}

void ATPSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TryChangeSprintState();
	
}

void ATPSBaseCharacter::StartSprint()
{
	bIsSprintRequested = 1;
	if (bIsCrouched)
	{
		UnCrouch();
	}
}

void ATPSBaseCharacter::EndSprint()
{
	bIsSprintRequested = 0;
}




void ATPSBaseCharacter::TryChangeSprintState()
{
	if (bIsSprintRequested && !GetBaseCharacterMovement()->GetIsSprinting())
	{
		GetBaseCharacterMovement()->StartSprint();
		OnStartSprint();
	}
	if (!bIsSprintRequested && GetBaseCharacterMovement()->GetIsSprinting())
	{
		GetBaseCharacterMovement()->EndSprint();
		OnEndSprint();
	}
}

void ATPSBaseCharacter::ChangeCrouchState()
{
	if (GetCharacterMovement()->IsCrouching())
	{
		UnCrouch();
	}
	else
	{
		Crouch();
	}
}

void ATPSBaseCharacter::Fire()
{
	CharacterEquipmentComponent->Fire();
}

float ATPSBaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogDamage, Warning, TEXT("ATPSBaseCharacter::TakeDamage %s recieved %.2f amount of damage from %s"), *GetName(), DamageAmount, *DamageCauser->GetName());
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}
