// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"

void UCustomGameInstance::LoadGame()
{
	UCustomSaveGame* SaveGameObj = Cast<UCustomSaveGame>(UGameplayStatics::CreateSaveGameObject(UCustomSaveGame::StaticClass()));
	SaveGameObj = Cast<UCustomSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveGameObj->SaveSlotName, SaveGameObj->SlotIndex));
	if (SaveGameObj) {
		PlayerName = SaveGameObj->PlayerName;
		PlayerPosition = SaveGameObj->PlayerPosition;
		if (PlayerCharacter) {
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Game LOADED! PlayerName = ") + PlayerName + TEXT(", PlayerPosition = ") + PlayerPosition.ToString());
			PlayerCharacter->SetActorLocation(PlayerPosition);
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Failed - Not setted PlayerCharacter!"));
		}
		
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Failed - Not saved!"));
	}
	
}

void UCustomGameInstance::SetPlayerCharacter(ACustomCharacterBase * CurPlayerCharacter)
{
	PlayerCharacter = CurPlayerCharacter;
	//PlayerCharacter->SetActorLocation(PlayerPosition);
}

void UCustomGameInstance::SaveGame()
{
	UCustomSaveGame* SaveGameObj = Cast<UCustomSaveGame>(UGameplayStatics::CreateSaveGameObject(UCustomSaveGame::StaticClass()));
	if (SaveGameObj) {
		SaveGameObj->PlayerName = PlayerName;
		SaveGameObj->PlayerPosition = PlayerCharacter->GetActorLocation();
		UGameplayStatics::SaveGameToSlot(SaveGameObj, SaveGameObj->SaveSlotName, SaveGameObj->SlotIndex);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Game saved!"));
	}
}

UCustomGameInstance::UCustomGameInstance() {
	
}
