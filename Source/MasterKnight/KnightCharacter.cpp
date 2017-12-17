// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightCharacter.h"

AKnightCharacter::AKnightCharacter() {
	Sword = CreateDefaultSubobject<UStaticMeshComponent>("Sword");
	auto MeshCmp = GetMesh();
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
	USceneComponent* SceneCmp = Cast<USceneComponent>(MeshCmp);
	if (SceneCmp) {
		ConstructorHelpers::FObjectFinder<UStaticMesh> SwordMeshObj(TEXT("StaticMesh'/Game/SwordAnimsetPro/Models/Sword/Sword.Sword'"));
		if (SwordMeshObj.Object) {
			SwordMesh = SwordMeshObj.Object;
			Sword->SetStaticMesh(SwordMesh);
		}
		AttachToComponent(SceneCmp, AttachmentRules, FName("hand_rSocket"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("ERROR: Failing attach sword component!"));
	}
	
}