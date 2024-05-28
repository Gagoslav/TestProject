// Fill out your copyright notice in the Description page of Project Settings.


#include "../Controllers/TPSPlayerController.h"
#include "../Character/TPSBaseCharacter.h"

void ATPSPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	// Not to crash if we have invalid type
	InBaseCharacter = Cast<ATPSBaseCharacter>(InPawn);

}

void ATPSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ATPSPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATPSPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ATPSPlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &ATPSPlayerController::LookUp);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATPSPlayerController::Jump);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &ATPSPlayerController::ChangeCrouchState);
	InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &ATPSPlayerController::StartSprint);
	InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &ATPSPlayerController::EndSprint);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATPSPlayerController::Fire);

}

void ATPSPlayerController::MoveForward(float Value)
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->MoveForward(Value);
	}

}

void ATPSPlayerController::MoveRight(float Value)
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->MoveRight(Value);
	}
}

void ATPSPlayerController::Turn(float Value)
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->Turn(Value);
	}
}

void ATPSPlayerController::LookUp(float Value)
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->LookUp(Value);
	}
}

void ATPSPlayerController::Jump()
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->Jump();
	}
}

void ATPSPlayerController::ChangeCrouchState()
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->ChangeCrouchState();
	}
}

void ATPSPlayerController::StartSprint()
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->StartSprint();
	}
}

void ATPSPlayerController::EndSprint()
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->EndSprint();
	}
}

void ATPSPlayerController::Fire()
{
	if (InBaseCharacter.IsValid())
	{
		InBaseCharacter->Fire();
	}
}
