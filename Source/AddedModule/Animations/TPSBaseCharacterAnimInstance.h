// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseData/BaseEnums.h"
#include "TPSBaseCharacterAnimInstance.generated.h"


/**
 * 
 */
UCLASS()
class TPSSHOOTER_API UTPSBaseCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation")
	float Speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation", meta = (UIMin =-180.0f, UIMax = 180.0f))
	float Direction = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation")
	bool bIsFalling = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation")
	bool bIsCrouching = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation")
	bool bIsSprinting = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation")
	bool bIsCharacterRotOriented = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation")
	EEquipedItemType CurrentEquipedItem = EEquipedItemType::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Animation")
	FRotator AimRotation = FRotator::ZeroRotator;


private:
	// Animation is always loaded when we already have a character
	TWeakObjectPtr<class ATPSBaseCharacter> InPlayerCharacter;
	
};
