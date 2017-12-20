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
	if (AttackCapsule) {
		AttackCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACustomCharacterBase::OnOverlapBegin);
	}
	InitSomeFields();
}

void ACustomCharacterBase::InitSomeFields() {
	if (AttackCapsule) {
		PredAttackCapsuleLocation = AttackCapsule->GetComponentLocation();
		IsEnoughAttackPower = false;
	}
	IsAttack = false;
	Target = nullptr;
}

void ACustomCharacterBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsPowerAttack) {
		ACustomCharacterBase* opponent = Cast<ACustomCharacterBase>(OtherActor);
		if (opponent) {
			if (opponent != this && !CheckFriend(opponent)) {
				GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("Attack!!!"));
				Attack(opponent);
			}
		}
	}

}

// Called every frame
void ACustomCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Speed = GetVelocity().Size();
	//if (AttackCapsule) {
	//	//AttackSpeed = AttackCapsule->GetComponentVelocity().Size();
	//	
	//	FVector curAttackCapsuleLocation = AttackCapsule->GetComponentLocation();
	//	FVector DiffLocation = curAttackCapsuleLocation - PredAttackCapsuleLocation;
	//	AttackingDiff = DiffLocation.Size();
	//	AttackSpeed = AttackingDiff * DeltaTime;
	//	/*GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::SanitizeFloat(AttackSpeed));*/
	//	if (IsAttack && (AttackSpeed >= MinAttackSpeed) && !IsDeath) {
	//		IsEnoughAttackPower = true;
	//		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::SanitizeFloat(AttackSpeed));
	//	}
	//	PredAttackCapsuleLocation = curAttackCapsuleLocation;
	//} 
}

// Called to bind functionality to input
void ACustomCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACustomCharacterBase::BeginAttack(ACustomCharacterBase * Opponent)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, GetName() + TEXT(" > ") + Opponent->GetName() + TEXT(" (Begin Attack)"));
	IsAttack = true;
}

void ACustomCharacterBase::Attack(ACustomCharacterBase * Opponent)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, GetName() + TEXT(" > ") + Opponent->GetName() + TEXT(" (Attack)"));
	InitSomeFields();
	Opponent->Damage(this);
}
 
void ACustomCharacterBase::Damage(ACustomCharacterBase * Opponent)
{
	Life -= Opponent->Power;
	if (Life <= 0) {
		Death();
	}
}

void ACustomCharacterBase::Death() {
	IsDeath = true;
	InitSomeFields();
	GetCapsuleComponent()->SetCollisionProfileName(FName("CharacterMesh"));
}
//void ACustomCharacterBase::NotifyActorBeginOverlap(AActor * OtherActor)
//{
//	/*GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("this: ") + GetName() + TEXT(" (Overlap)"));
//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("OtherActor: ") + OtherActor->GetName() + TEXT(" (Overlap)"));*/
//}

bool ACustomCharacterBase::CheckFriend(ACustomCharacterBase* Opponent) {
	return false;
}
