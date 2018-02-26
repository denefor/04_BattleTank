// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AICOntroller can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AICOntroller found player: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}



