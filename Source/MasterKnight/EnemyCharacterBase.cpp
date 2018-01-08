// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacterBase.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "CustomGameInstance.h"

AEnemyCharacterBase::AEnemyCharacterBase() {
	//UClass* blueprintClass = FindClass<UBlueprintGeneratedClass>(ANY_PACKAGE, TEXT("Blueprint'/Game/AI/EnemyBase_AICon.EnemyBase_AICon'"));

	/*ConstructorHelpers::FObjectFinder<UBlueprintGeneratedClass> Result(TEXT("Blueprint'/Game/AI/EnemyBase_AICon.EnemyBase_AICon'"));*/
	//if(blueprintClass){
	////if (AIControllerAsset.Succeeded()) {
	//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Finded Blueprint class!!!!!!!!!"));
	//}
	//else {
	//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Failed !!!! Finded Blueprint class!!!!!!!!!"));
	//}

	//UClass* Result = FindClass<UClass>(TEXT("Blueprint'/Game/AI/EnemyBase_AICon.EnemyBase_AICon'"));
	/*if (Result.Object) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Finded Blueprint class!!!!!!!!!"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Failed !!!! Finded Blueprint class!!!!!!!!!"));
	}*/
	// TODO Maybe save increment/decrement gameInstance->EnemyCount
}

void AEnemyCharacterBase::BeginPlay() {
	Super::BeginPlay();
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance) {
		gameInstance->EnemyCount++;
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, FString::FromInt(gameInstance->EnemyCount));
	}
}

bool AEnemyCharacterBase::CheckFriend(ACustomCharacterBase* Opponent) {
	AEnemyCharacterBase* maybeEnemyRef = Cast<AEnemyCharacterBase>(Opponent);
	return maybeEnemyRef != nullptr;
}

void AEnemyCharacterBase::Death() {
	Super::Death();
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance) {
		gameInstance->EnemyCount--;
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, FString::FromInt(gameInstance->EnemyCount));
		if (gameInstance->EnemyCount == 0) {
			OnAllEnemyDeath.Broadcast();
		}
	}
}

