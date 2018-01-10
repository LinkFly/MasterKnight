// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Thing.h"
#include "CustomSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class MASTERKNIGHT_API UCustomSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public: 

	UCustomSaveGame();

	UPROPERTY(VisibleAnywhere, Category = Basic)
		FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		int32 PlayerLife;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		int32 WeaponThingIdx;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		int32 SlotIndex;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		FVector PlayerPosition;
	UPROPERTY(VisibleAnywhere, Category = Basic)
		TArray<FString> ThingsClassNames;
	UPROPERTY(VisibleAnywhere, Category = Basic)
		FString LastWeapon;

};