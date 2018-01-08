// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomCharacterBase.h"
#include "Thing.h"
#include "Engine.h"

// Sets default values
ACustomCharacterBase::ACustomCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*WeaponChildActor = CreateDefaultSubobject<UChildActorComponent>("WeaponChildActor");
	FAttachmentTransformRules AttachmentRules(FAttachmentTransformRules::SnapToTargetIncludingScale);
	WeaponChildActor->AttachToComponent(RootComponent, AttachmentRules, FName("hand_rSocket"));*/
	/*WeaponChildActor->SetupAttachment(RootComponent);*/
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
	Opponent->Damage(this);
	FString NameLife = GetName() + TEXT("(") + FString::FromInt(Life) + TEXT(")");
	FString OpponentNameLife = Opponent->GetName() + TEXT("(") + FString::FromInt(Opponent->Life) + TEXT(")");
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, NameLife + TEXT(" > ") + OpponentNameLife);
}
 
void ACustomCharacterBase::Damage(ACustomCharacterBase * Opponent)
{
	Life -= Opponent->GetPower();
	if (Life <= 0) {
		Death();
	}
	else {
		IsDamage = true;
	}
}

void ACustomCharacterBase::Equip(AThingBase* NewWeapon)
{
	if (NewWeapon) {
		UnEquip();
		Weapon = NewWeapon;
		NewWeapon->ContactZone->SetCollisionProfileName(FName("NoCollision"));
		FAttachmentTransformRules AttachmentRules(FAttachmentTransformRules::SnapToTargetIncludingScale);
		NewWeapon->AttachToComponent(GetMesh(), AttachmentRules, FName("hand_rSocket"));
		NewWeapon->bHidden = false;
		Weapon->IsEquip = true;
	}
}

void ACustomCharacterBase::UnEquip()
{
	if (Weapon) {
		Weapon->IsEquip = false;
		Weapon->SetActorHiddenInGame(true);
		Weapon = nullptr;
	}
}

void ACustomCharacterBase::Death() {
	IsDeath = true;
	Target = nullptr;
	InitSomeFields();
	GetCapsuleComponent()->SetCollisionProfileName(FName("CharacterMesh"));
	AttackCapsule->SetCollisionProfileName(FName("NoCollision"));
}
int32 ACustomCharacterBase::GetPower()
{
	return !Weapon ? Power : Weapon->Power;
}
//void ACustomCharacterBase::NotifyActorBeginOverlap(AActor * OtherActor)
//{
//	/*GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("this: ") + GetName() + TEXT(" (Overlap)"));
//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("OtherActor: ") + OtherActor->GetName() + TEXT(" (Overlap)"));*/
//}

bool ACustomCharacterBase::CheckFriend(ACustomCharacterBase* Opponent) {
	return false;
}

void ACustomCharacterBase::AddThing_Implementation(AThingBase * Thing)
{
	if (Things.Find(Thing) == INDEX_NONE) {
		Things.Add(Thing);
	}
	UpdateInventory();
}

void ACustomCharacterBase::DelThing_Implementation(AThingBase * Thing)
{
	int32 idx = Things.Find(Thing);
	if (idx != INDEX_NONE) {
		Things.RemoveAt(idx);
	}
	UpdateInventory();
}

void ACustomCharacterBase::UpdateInventory()
{
	OnUpdateInventory.Broadcast(Things);
}
