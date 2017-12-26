// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameActor.h"


// Sets default values
ASaveGameActor::ASaveGameActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	RootComponent = Scene;
	SaveZone = CreateDefaultSubobject<UBoxComponent>("SaveZone");
	SaveZone->AttachTo(Scene);
	SaveZone->OnComponentBeginOverlap.AddDynamic(this, &ASaveGameActor::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ASaveGameActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASaveGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASaveGameActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance->PlayerCharacter == OtherActor) {
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Player in save zone"));
		gameInstance->SaveGame();
	}
	else {
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Other overlap"));
	}
}

