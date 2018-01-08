// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "CustomCharacterBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CustomGameInstance.h"
#include "KnightCharacter.generated.h"

namespace ESide {
	enum {
		Forward = 1, Right = 2, Backward = 3, Left = 4, None = 0
	};
}

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* CameraFollow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BackwardForwardAxisValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LeftRightAxisValue;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	virtual void AddControllerYawInput(float Val) override;
	virtual void AddControllerPitchInput(float Val) override;
	virtual void Death();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SwordAttack();
	void ForwardMove(float AxisValue);
	void RightMove(float AxisValue);

private:
	void BaseMove(float AxisValue, EAxis::Type Side);
	
};

