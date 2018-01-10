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

	int32 thingsCount = SaveGameObj->ThingsClassNames.Num();
	for (int i = 0; i < thingsCount; i++) {
		FString curClsName = SaveGameObj->ThingsClassNames[i];
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Loaded CLASS: ") + curClsName);
		// TODO Here create Things from classes name
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
	
	/*ACharacter character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);*/
	if (PlayerCharacter) {
		/*auto iter = PlayerCharacter->Things.CreateIterator();*/
		int32 thingsCount = PlayerCharacter->Things.Num();
		for (int i = 0; i < thingsCount; i++) {
			UClass* curCls = PlayerCharacter->Things[i]->GetClass();
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Saved CLASS: ") + curCls->GetName());
			SaveGameObj->ThingsClassNames.Add(curCls->GetName());
		}
	}
}

UCustomGameInstance::UCustomGameInstance() {
	
}
