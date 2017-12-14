// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "CustomCharacterBase.generated.h"

UCLASS()
class MASTERKNIGHT_API ACustomCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayProps")
		AActor* Target;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Life = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Power = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsDeath = false;

	UFUNCTION(BlueprintCallable)
		void Attack(ACustomCharacterBase* Opponent);

	UFUNCTION(BlueprintCallable)
		void Damage(ACustomCharacterBase* Opponent);

	void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
