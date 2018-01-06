// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "CustomCharacterBase.h"
#include "ThingBase.h"
#include "Thing.generated.h"

UCLASS()
class MASTERKNIGHT_API AThing : public AThingBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThing();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Take(ACustomCharacterBase* Owner);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThingData")
		ACustomCharacterBase* OwnerCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThingData")
		bool IsCountable = true;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
