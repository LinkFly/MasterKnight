// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "CustomCharacterBase.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MASTERKNIGHT_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UCustomGameInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
		FString PlayerName = TEXT("<Noname>");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
		FVector PlayerPosition = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRuntimeData")
		ACustomCharacterBase* PlayerCharacter = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRuntimeData")
		bool IsUsingInterface = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRuntimeData")
		int32 EnemyCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameRuntimeData")
		TMap<FString, TSubclassOf<AThingBase>> NameClassTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRuntimeData")
		AThingBase* LastThing;

	UFUNCTION(BlueprintCallable)
		void SaveGame();

	UFUNCTION(BlueprintCallable)
		void LoadGame();

	UFUNCTION(BlueprintCallable)
		void SetPlayerCharacter(ACustomCharacterBase* CurPlayerCharacter);
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void GameOver();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void YouWin();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CreateThing(TSubclassOf<AThingBase> ThingClass);
};

