// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Utils.generated.h"


UCLASS()
class MASTERKNIGHT_API AUtils : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AUtils();

	UFUNCTION(BlueprintCallable)
		static UClass* FindClass(FString NameOfClass);
	
};
