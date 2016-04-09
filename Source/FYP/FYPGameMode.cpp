// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPGameMode.h"

AFYPGameMode::AFYPGameMode()
{
	//set weights for each measure of player performance
	WeightAS = 0.25f;
	WeightATL = 2.f;
	WeightBU = 0.5f;
	WeightC = 2.f;
	WeightTS = 0.25f;
	firstChunk = true;
}

void AFYPGameMode::BeginPlay()
{

}

void AFYPGameMode::Tick(float DeltaTime) {
	//every x seconds of game time, increment  number of pieces per chunk
	//If the player is doing particularly well, then ramp up quicker
	int wTime = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	wTime = wTime % chunkIncTime;
	if (wTime == 0) {
		if (playerAbility[playerAbility.Num()-1] > 3) {
			chunkScore += 2;
			UE_LOG(LogTemp, Warning, TEXT("chunkScore is now %d"), chunkScore);
		} else {
			chunkScore += 1;
			UE_LOG(LogTemp, Warning, TEXT("chunkScore is now %d"), chunkScore);
		}
	}

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

void AFYPGameMode::AssessPlayer_Implementation() {
	//only start assessing after 4 gates are passed
	if (playerStats.Num() > 4) {
		FPlayerStats avgStats;
		int32 startStat = (playerStats.Num() - 4);
		//average the latest four stat entries
		avgStats.averageSpeed = (playerStats[startStat].averageSpeed + playerStats[startStat + 1].averageSpeed + playerStats[startStat + 2].averageSpeed + playerStats[startStat + 3].averageSpeed) / 4;
		avgStats.averageTimeLeft = (playerStats[startStat].averageTimeLeft + playerStats[startStat + 1].averageTimeLeft + playerStats[startStat + 2].averageTimeLeft + playerStats[startStat + 3].averageTimeLeft) / 4;
		avgStats.brakesUsed = (playerStats[startStat].brakesUsed + playerStats[startStat + 1].brakesUsed + playerStats[startStat + 2].brakesUsed + playerStats[startStat + 3].brakesUsed) / 4;
		avgStats.collisions = (playerStats[startStat].collisions + playerStats[startStat + 1].collisions + playerStats[startStat + 2].collisions + playerStats[startStat + 3].collisions) / 4;
		avgStats.topSpeed = (playerStats[startStat].topSpeed + playerStats[startStat + 1].topSpeed + playerStats[startStat + 2].topSpeed + playerStats[startStat + 3].topSpeed) / 4;
		//map to discrete range for assessment purposes
		float scaledAveSpeed = FMath::GetMappedRangeValueClamped(FVector2D(0.f, 15.f), FVector2D(0.f, 1.f), avgStats.averageSpeed);
		float scaledAveTime = FMath::GetMappedRangeValueClamped(FVector2D(0.f, 15.f), FVector2D(0.f, 1.f), avgStats.averageTimeLeft);
		float scaledBrakes = FMath::GetMappedRangeValueClamped(FVector2D(0.f, 30.f), FVector2D(1.f, 0.f), avgStats.brakesUsed);
		float scaledCol = FMath::GetMappedRangeValueClamped(FVector2D(0.f, 15.f), FVector2D(0.f, 1.f), avgStats.collisions);
		float scaledTopSpeed = FMath::GetMappedRangeValueClamped(FVector2D(0.f, 15.f), FVector2D(0.f, 1.f), avgStats.topSpeed);
		//multiple by the weighting for each value
		scaledAveSpeed *= WeightAS;
		scaledAveTime *= WeightATL;
		scaledBrakes *= WeightBU;
		scaledCol *= WeightC;
		scaledTopSpeed *= WeightTS;
		//add final value to playerAbility array
		playerAbility.Add(scaledAveSpeed + scaledAveTime + scaledBrakes + scaledCol + scaledTopSpeed);

	}
}