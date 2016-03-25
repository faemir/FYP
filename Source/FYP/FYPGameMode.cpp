// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPGameMode.h"

AFYPGameMode::AFYPGameMode()
{

}

void AFYPGameMode::BeginPlay()
{

}

void AFYPGameMode::Tick(float DeltaTime)
{

}

//Add performance snapshot when passing each gate
void AFYPGameMode::GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) {
	ACar* theCar = Cast<ACar>(GetWorld()->GetFirstPlayerController()->GetPawn());
	FPlayerStats tempStats = theCar->playerStats;
	playerStats.Add(tempStats);
}

void AFYPGameMode::RoundStart_Implementation() {
	//return("RoundStart_Implementation()");
}

void AFYPGameMode::RoundEnd_Implementation() {
	//return("RoundEnd_Implementation()");
}