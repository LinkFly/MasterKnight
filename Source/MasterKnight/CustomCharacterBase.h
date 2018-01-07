// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "ThingBase.h"
#include "CustomCharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateInventoryDelegate, const TArray<AThingBase*>&, InventoryItems);

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
	/*void NotifyActorBeginOverlap(AActor* OtherActor) override;*/

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	bool IsPlayerCharacter = false;
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
		bool IsDamage = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsDeath = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCapsuleComponent* AttackCapsule;

	// Trash, req delete
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MinAttackSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MinAttackingDiff = 20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackingDiff = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsEnoughAttackPower = false;
	/////////////////////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsPowerAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AThingBase*> Things;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UChildActorComponent* WeaponChildActor;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AThingBase* Weapon;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	TSubclassOf<AThingBase> WeaponClass;

	UFUNCTION(BlueprintCallable)
		void BeginAttack(ACustomCharacterBase * Opponent);
	UFUNCTION(BlueprintCallable)
		void Attack(ACustomCharacterBase* Opponent);
	UFUNCTION(BlueprintCallable)
		void Damage(ACustomCharacterBase* Opponent);
	UFUNCTION(BlueprintCallable)
		void InitSomeFields();
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		//void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddThing(AThingBase* Thing);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void DelThing(AThingBase* Thing);
	UFUNCTION(BlueprintCallable)
		void Equip(AThingBase* NewWeapon);
	UFUNCTION(BlueprintCallable)
		void UnEquip();
	UFUNCTION(BlueprintCallable)
		void UpdateInventory();
	UPROPERTY(BlueprintAssignable, Category = "Pickup")
		FUpdateInventoryDelegate OnUpdateInventory;

private:
	FVector PredAttackCapsuleLocation;
	void Death();
	int32 GetPower();

protected:
	virtual bool CheckFriend(ACustomCharacterBase* Opponent);
	
};


