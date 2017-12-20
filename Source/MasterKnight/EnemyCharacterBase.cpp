// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacterBase.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

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
}

void AEnemyCharacterBase::BeginPlay() {
	Super::BeginPlay();
}

bool AEnemyCharacterBase::CheckFriend(ACustomCharacterBase* Opponent) {
	AEnemyCharacterBase* maybeEnemyRef = Cast<AEnemyCharacterBase>(Opponent);
	return maybeEnemyRef != nullptr;
}

