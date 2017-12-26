// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CustomGameInstance.h"
#include "MasterKnightGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MASTERKNIGHT_API AMasterKnightGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	
protected:
	virtual void BeginPlay() override;

	
};
