// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterBase.h"
#include "EnemyCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class MASTERKNIGHT_API AEnemyCharacterBase : public ACustomCharacterBase
{
	GENERATED_BODY()

public:
	AEnemyCharacterBase();
	virtual void BeginPlay() override;

protected:
	virtual bool CheckFriend(ACustomCharacterBase* Opponent) override;
};
