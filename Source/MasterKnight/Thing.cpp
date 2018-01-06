// Fill out your copyright notice in the Description page of Project Settings.

#include "Thing.h"
#include "KnightCharacter.h"


// Sets default values
AThing::AThing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	RootComponent = Scene;
	ContactZone = CreateDefaultSubobject<UBoxComponent>("SaveZone");
	ContactZone->AttachTo(Scene);
	ContactZone->OnComponentBeginOverlap.AddDynamic(this, &AThing::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AThing::BeginPlay()
{
	Super::BeginPlay();
	
}

void AThing::Take(ACustomCharacterBase* Owner)
{
	Owner->AddThing(this);
	OwnerCharacter = Owner;
}

// Called every frame
void AThing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AThing::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	auto Owner = Cast<ACustomCharacterBase>(OtherActor);
	if (Owner) {
		if (Owner->IsPlayerControlled()) {
			Take(Owner);
			SetActorHiddenInGame(true);
		}
	}
}


