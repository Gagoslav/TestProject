// Fill out your copyright notice in the Description page of Project Settings.


#include "../Components/CharacterAttributes.h"


UCharacterAttributes::UCharacterAttributes()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	
}



void UCharacterAttributes::BeginPlay()
{
	Super::BeginPlay();

	
	
}



void UCharacterAttributes::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

