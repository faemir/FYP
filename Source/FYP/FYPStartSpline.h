// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FYPSpline.h"
#include "FYPStartSpline.generated.h"

UCLASS()
class FYP_API AFYPStartSpline : public AFYPSpline
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFYPStartSpline();

	virtual void storeSplinePoints_Implementation() override;
	virtual	void addNewChunk_Implementation(int32 ci, UStaticMesh* tm) override;
	virtual	void compSplinePointsToTrackArray(int32 nsp) override;
};
