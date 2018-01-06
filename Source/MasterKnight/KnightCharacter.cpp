// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightCharacter.h"

AKnightCharacter::AKnightCharacter() {
	//Sword = CreateDefaultSubobject<UStaticMeshComponent>("Sword");
	//auto MeshCmp = GetMesh();
	//FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
	//USceneComponent* SceneCmp = Cast<USceneComponent>(MeshCmp);
	//if (SceneCmp) {
	//	ConstructorHelpers::FObjectFinder<UStaticMesh> SwordMeshObj(TEXT("StaticMesh'/Game/SwordAnimsetPro/Models/Sword/Sword.Sword'"));
	//	if (SwordMeshObj.Object) {
	//		SwordMesh = SwordMeshObj.Object;
	//		Sword->SetStaticMesh(SwordMesh);
	//	}
	//	AttachToComponent(SceneCmp, AttachmentRules, FName("hand_rSocket"));
	//}
	//else {
	//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("ERROR: Failing attach sword component!"));
	//}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	SpringArm->TargetArmLength = 300;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetupAttachment(RootComponent);
	CameraFollow = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraFollow->bUsePawnControlRotation = false;
	CameraFollow->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	//IsPlayerCharacter = true;
}

void AKnightCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Attack"), IE_Pressed, this, &AKnightCharacter::SwordAttack);
	PlayerInputComponent->BindAxis(TEXT("ForwardMove"), this, &AKnightCharacter::ForwardMove);
	PlayerInputComponent->BindAxis(TEXT("RightMove"), this, &AKnightCharacter::RightMove);
	PlayerInputComponent->BindAxis(TEXT("TurnHoriz"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("TurnVert"), this, &APawn::AddControllerPitchInput);
}

void AKnightCharacter::BeginPlay()
{
	Super::BeginPlay();
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	gameInstance->SetPlayerCharacter(this);
}

void AKnightCharacter::SwordAttack()
{
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("Attack"));
	BeginAttack(nullptr);
}

void AKnightCharacter::ForwardMove(float AxisValue)
{
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("ForwardMove: ") + FString::SanitizeFloat(AxisValue));
	BackwardForwardAxisValue = AxisValue;
	BaseMove(AxisValue, EAxis::X);
}

void AKnightCharacter::RightMove(float AxisValue)
{
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("RightMove: ") + FString::SanitizeFloat(AxisValue));
	BaseMove(AxisValue, EAxis::Y);
	LeftRightAxisValue = AxisValue;
}

void AKnightCharacter::BaseMove(float AxisValue, EAxis::Type Side)
{
	if (Controller && !IsDeath) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(Side);
		AddMovementInput(Direction, AxisValue); 
	}
}

void AKnightCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}