// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BaseCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TPSSHOOTER_API UBaseCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "CharacterMovement | Sprint")
	inline bool GetIsSprinting() { return bIsSprinting; }

	
	
	void StartSprint();
	void EndSprint();

	virtual float GetMaxSpeed() const override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterMovement | Sprint", meta =(ClampMin= 0.0f, UIMin = 0.0f))
	float SprintSpeed = 1200.0f;



private:
	bool bIsSprinting = 0;


};
