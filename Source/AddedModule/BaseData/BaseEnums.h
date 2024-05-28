// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEnums.generated.h"

#define ECC_Bullet ECC_GameTraceChannel3

UENUM(BlueprintType)
enum class EEquipedItemType : uint8
{
	None,
	Pistol
};


UCLASS()
class TPSSHOOTER_API ABaseEnums : public AActor
{
	GENERATED_BODY()
	


};
