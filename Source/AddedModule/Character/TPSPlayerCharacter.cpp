// Fill out your copyright notice in the Description page of Project Settings.


#include "../Character/TPSPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../Source/AddedModule//Components/BaseCharacterMovementComponent.h"

ATPSPlayerCharacter::ATPSPlayerCharacter(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
	bUseControllerRotationPitch = 0;
	bUseControllerRotationRoll = 0;
	bUseControllerRotationYaw = 0;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = 1;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArm);
	CameraComponent->bUsePawnControlRotation = 0;

	GetBaseCharacterMovement()->bOrientRotationToMovement = 0;
	
}

void ATPSPlayerCharacter::MoveForward(float Value)
{
	// consider some small inaccuracies
	if (!FMath::IsNearlyZero(Value, 1e-6) && !GetBaseCharacterMovement()->GetIsSprinting())
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		// to move a character along the mouse direction
		FVector Forward = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(Forward, Value);
		
	}
	
}

void ATPSPlayerCharacter::MoveRight(float Value)
{
	// consider some small inaccuracies
	if (!FMath::IsNearlyZero(Value, 1e-6) && !GetBaseCharacterMovement()->GetIsSprinting())
	{
		
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		// to move a character along the mouse direction
		FVector Right = YawRotator.RotateVector(FVector::RightVector);
		AddMovementInput(Right, Value);
	}
	
}

void ATPSPlayerCharacter::Turn(float Value)
{
	
	AddControllerYawInput(Value);
}

void ATPSPlayerCharacter::LookUp(float Value)
{
	
	AddControllerPitchInput(Value);
}

void ATPSPlayerCharacter::Jump()
{
	Super::Jump();
	
}

void ATPSPlayerCharacter::OnStartCrouch(float HeightAdjust, float ScaledHeightAdjust)
{
	Super::OnStartCrouch(HeightAdjust, ScaledHeightAdjust);
	SpringArm->TargetOffset += FVector(0.0f, 0.0f, HeightAdjust);
}


void ATPSPlayerCharacter::OnEndCrouch(float HeightAdjust, float ScaledHeightAdjust)
{
	Super::OnEndCrouch(HeightAdjust, ScaledHeightAdjust);
	SpringArm->TargetOffset -= FVector(0.0f, 0.0f, HeightAdjust);
	
}

bool ATPSPlayerCharacter::CanJumpInternal_Implementation() const
{
	return bIsCrouched || Super::CanJumpInternal_Implementation();
}







