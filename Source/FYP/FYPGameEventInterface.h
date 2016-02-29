// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FYPGameEventInterface.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)
class FYP_API UFYPGameEventInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
	
};

class IFYPGameEventInterface {
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void RoundStart();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void RoundEnd();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void GateReached(FLinearColor newColour, float playRate, float colourDist);
};