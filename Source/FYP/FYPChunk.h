// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FYPChunk.generated.h"

UCLASS()
class FYP_API AFYPChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFYPChunk();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//UFUNCTION(BlueprintNativeEvent)
	//void getLastSegSplineTrans();

	//UFUNCTION(BlueprintNativeEvent)
	//void makeSegments();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	bool spawnedSegments;
	
};
