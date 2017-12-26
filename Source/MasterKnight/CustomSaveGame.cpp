// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomSaveGame.h"

UCustomSaveGame::UCustomSaveGame() : PlayerName("DefaultName"), SlotIndex(0), SaveSlotName("Test") {
	PlayerPosition = FVector::ZeroVector;
}

