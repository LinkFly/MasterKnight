// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightCharacter.h"

AKnightCharacter::AKnightCharacter() {
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
	PlayerInputComponent->BindAxis(TEXT("TurnHoriz"), this, &AKnightCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("TurnVert"), this, &AKnightCharacter::AddControllerPitchInput);
}

void AKnightCharacter::AddControllerYawInput(float Val)
{
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance && !gameInstance->IsUsingInterface) {
		Super::AddControllerYawInput(Val);
	}
}
void AKnightCharacter::AddControllerPitchInput(float Val)
{
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance && !gameInstance->IsUsingInterface) {
		Super::AddControllerPitchInput(Val);
	}
}

void AKnightCharacter::BeginPlay()
{
	Super::BeginPlay();
	auto gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	gameInstance->SetPlayerCharacter(this);
}

void AKnightCharacter::SwordAttack()
{
	BeginAttack();
}

void AKnightCharacter::ForwardMove(float AxisValue)
{
	BackwardForwardAxisValue = AxisValue;
	BaseMove(AxisValue, EAxis::X);
}

void AKnightCharacter::RightMove(float AxisValue)
{
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
	if (GetActorLocation().Z < 0) {
		Death();
	}
}

void AKnightCharacter::Death() {
	Super::Death();
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (gameInstance) {
		gameInstance->GameOver();
	}
}

