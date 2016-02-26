// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "FYPGameEventInterface.h"
#include "Car.generated.h"

UCLASS()
class FYP_API ACar : public APawn, public IFYPGameEventInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACar(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void RoundStart_Implementation() override;
	virtual void RoundEnd_Implementation() override;
	virtual void GateReached_Implementation() override;
	
};
