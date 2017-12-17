// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterBase.h"
//#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Engine.h"
#include "KnightCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MASTERKNIGHT_API AKnightCharacter : public ACustomCharacterBase
{
	GENERATED_BODY()

public:
	AKnightCharacter();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Sword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* SwordMesh;
};
