// Fill out your copyright notice in the Description page of Project Settings.

#include "MasterKnightGameModeBase.h"

void AMasterKnightGameModeBase::BeginPlay() {
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	gameInstance->LoadGame();
}



