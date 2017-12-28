// Fill out your copyright notice in the Description page of Project Settings.

#include "ThingBase.h"


// Sets default values
AThingBase::AThingBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AThingBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThingBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AThingBase::Apply_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Apply thing: ") + Title);
}

