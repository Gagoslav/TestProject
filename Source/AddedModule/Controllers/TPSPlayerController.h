// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TPSSHOOTER_API ATPSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//Override base method of AController to set it responsible for the new pawn (InBaseCharacter)
	virtual void SetPawn(APawn* InPawn) override;

protected:

	//Implement player input 
	virtual void SetupInputComponent() override;

private:
	//Declaring our InBaseCharacter as Soft object pointer as we may need to refer it before it's created
	TSoftObjectPtr <class ATPSBaseCharacter> InBaseCharacter;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void Jump();
	void ChangeCrouchState();
	void StartSprint();
	void EndSprint();

	void Fire();
};
