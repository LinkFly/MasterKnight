// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ThingBase.generated.h"

UCLASS()
class MASTERKNIGHT_API AThingBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThingBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThingData")
		FString Title = TEXT("<None>");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThingData")
		UBoxComponent* ContactZone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThingData")
		bool IsEquip = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThingData")
		int32 Power = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThingData")
		float AttackSpeed = 1.0f;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Apply();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void WasTake();
};
