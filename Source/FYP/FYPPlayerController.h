// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "FYPGameEventInterface.h"
#include "FYPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FYP_API AFYPPlayerController : public APlayerController, public IFYPGameEventInterface
{
	GENERATED_BODY()
	
public:

	AFYPPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	bool gameOver;

	virtual void RoundStart_Implementation() override;
	virtual void RoundEnd_Implementation() override;
	virtual void GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) override;
};
