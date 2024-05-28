// Fill out your copyright notice in the Description page of Project Settings.


#include "../Components/BaseCharacterMovementComponent.h"

void UBaseCharacterMovementComponent::StartSprint()
{
	bIsSprinting = 1;
	bForceMaxAccel = 1;
	
}

void UBaseCharacterMovementComponent::EndSprint()
{
	bIsSprinting = 0;
	bForceMaxAccel = 0;
}

float UBaseCharacterMovementComponent::GetMaxSpeed() const
{
	float Result = Super::GetMaxSpeed();
	if (bIsSprinting)
	{
		Result = SprintSpeed;
	}
	return Result;
}
