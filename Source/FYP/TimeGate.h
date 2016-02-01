// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimeGate.generated.h"

UCLASS()
class FYP_API ATimeGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeGate();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power")
	bool reached;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power")
	bool isActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power")
	float gateTime = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power")
	float timeLeft;
	
};
