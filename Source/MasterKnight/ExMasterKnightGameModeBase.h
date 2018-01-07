// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterKnightGameModeBase.h"
#include "ExMasterKnightGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MASTERKNIGHT_API AExMasterKnightGameModeBase : public AMasterKnightGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	
	
};
