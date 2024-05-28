// Fill out your copyright notice in the Description page of Project Settings.


#include "../Animations/TPSBaseCharacterAnimInstance.h"
#include "../Components/BaseCharacterMovementComponent.h"
#include "../Character/TPSBaseCharacter.h"
#include "Components/CharacterEquipmentComponent.h"

void UTPSBaseCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<ATPSBaseCharacter>(), TEXT("Pawn owner should be ATPSPlayerCharacter, otherwise we will have a crash"));
	InPlayerCharacter = StaticCast<ATPSBaseCharacter*>(TryGetPawnOwner());
}

void UTPSBaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!InPlayerCharacter.IsValid())
	{
		return;
	}
	UBaseCharacterMovementComponent* MovementComponent = InPlayerCharacter->GetBaseCharacterMovement();
	Speed = MovementComponent->Velocity.Size();
	Direction = CalculateDirection(MovementComponent->Velocity, InPlayerCharacter->GetActorRotation());
	bIsFalling = MovementComponent->IsFalling();
	bIsCrouching = MovementComponent->IsCrouching();
	bIsSprinting = MovementComponent->GetIsSprinting();
	bIsCharacterRotOriented = MovementComponent->bOrientRotationToMovement;

	const UCharacterEquipmentComponent* CharacterEquipment = InPlayerCharacter->GetCharacterEquipmentComponent();
	CurrentEquipedItem = CharacterEquipment->GetCurrentEquipedItemType();

	AimRotation = InPlayerCharacter->GetBaseAimRotation();
}
