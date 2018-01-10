// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomSaveGame.h"

UCustomSaveGame::UCustomSaveGame() : PlayerName("DefaultName"), PlayerLife(100), WeaponThingIdx(-1), SlotIndex(0), SaveSlotName("Test") {
	PlayerPosition = FVector::ZeroVector;
}

