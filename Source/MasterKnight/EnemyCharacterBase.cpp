// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacterBase.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "CustomGameInstance.h"

AEnemyCharacterBase::AEnemyCharacterBase() {
}

void AEnemyCharacterBase::BeginPlay() {
	Super::BeginPlay();
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance) {
		gameInstance->EnemyCount++;
		int32 uid = GetUniqueID();
		UEnemyData* enemyData = NewObject<UEnemyData>(this, UEnemyData::StaticClass());
		enemyData->Enemy = this;
		enemyData->Life = Life;
		enemyData->IsDeath = IsDeath;
		enemyData->Position = GetActorLocation();
		gameInstance->EnemiesData.Add(uid, enemyData);
		/*GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, FString::FromInt(gameInstance->EnemyCount));*/
	}
}

bool AEnemyCharacterBase::CheckFriend(ACustomCharacterBase* Opponent) {
	AEnemyCharacterBase* maybeEnemyRef = Cast<AEnemyCharacterBase>(Opponent);
	return maybeEnemyRef != nullptr;
}

void AEnemyCharacterBase::Death() {
	if (IsDeath) return;
	Super::Death();
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance) {
		gameInstance->EnemyCount--;
		/*GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, FString::FromInt(gameInstance->EnemyCount));*/
		if (gameInstance->EnemyCount == 0) {
			OnAllEnemyDeath.Broadcast();
		}
	}
}

