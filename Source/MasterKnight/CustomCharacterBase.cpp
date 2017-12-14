// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomCharacterBase.h"
#include "Engine.h"

// Sets default values
ACustomCharacterBase::ACustomCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACustomCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Speed = GetVelocity().Size();
}

// Called to bind functionality to input
void ACustomCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACustomCharacterBase::Attack(ACustomCharacterBase * Opponent)
{
	IsAttack = true; 
	Opponent->Damage(this);
}
 
void ACustomCharacterBase::Damage(ACustomCharacterBase * Opponent)
{
	Life -= Opponent->Power;
	if (Life <= 0) {
		IsDeath = true;
	}
}

void ACustomCharacterBase::NotifyActorBeginOverlap(AActor * OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Overlap"));
}

