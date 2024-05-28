// Fill out your copyright notice in the Description page of Project Settings.


#include "../Components/CharacterEquipmentComponent.h"
#include "../Character/TPSBaseCharacter.h"
#include "../Actors/Equipment/RangeWeapon.h"
#include "../BaseData/BaseEnums.h"





EEquipedItemType UCharacterEquipmentComponent::GetCurrentEquipedItemType() const
{
	EEquipedItemType Result = EEquipedItemType::None;
	if (IsValid(CurrentEquippedWeapon))
	{
		Result = CurrentEquippedWeapon->GetEquipedItemType();
	}
	return Result;
	
}

// Called when the game starts
void UCharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	checkf(GetOwner()->IsA<ATPSBaseCharacter>(), TEXT("Owner of Equipment component can be only ABaseCharacter actor"));
	InBaseCharacter = StaticCast<ATPSBaseCharacter*>(GetOwner());
	CreateLoadOut();
	
	
}

void UCharacterEquipmentComponent::Fire()
{
	if (IsValid(CurrentEquippedWeapon))
	{
		CurrentEquippedWeapon->Fire();
	}
}

void UCharacterEquipmentComponent::CreateLoadOut()
{
	if (!IsValid(SideArmClass))
	{
		return;
	}
	CurrentEquippedWeapon = GetWorld()->SpawnActor<ARangeWeapon>(SideArmClass);
	CurrentEquippedWeapon->AttachToComponent(InBaseCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName("SocketWeapon"));
	CurrentEquippedWeapon->SetOwner(InBaseCharacter.Get());
}


// Called every frame
