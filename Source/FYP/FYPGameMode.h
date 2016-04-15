// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "FYPGameEventInterface.h"
#include "Car.h"
#include "Kismet/KismetMathLibrary.h"
#include "FYPGameMode.generated.h"

UCLASS()
class FYP_API AFYPGameMode : public AGameMode, public IFYPGameEventInterface
{
	GENERATED_BODY()
	
public:
	
	AFYPGameMode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	TArray<FPlayerStats> playerStats;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	ACar* theCar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	TArray<float> playerAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	float WeightAS;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	float WeightATL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	float WeightBU;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	float WeightC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	float WeightTS;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	bool firstChunk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	int chunkScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	int chunkIncTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	int gatesPassed;

	void AFYPGameMode::IncrementChunk();

	virtual void RoundStart_Implementation() override;
	virtual void RoundEnd_Implementation() override;
	virtual void GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void AssessPlayer();
	void AssessPlayer_Implementation();
	
};
