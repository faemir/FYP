// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FYPSpline.h"
#include "TimeGate.h"
#include "EngineUtils.h"
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

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void getLastSegSplineTrans();
	void getLastSegSplineTrans_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void MakeSegments();
	void MakeSegments_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	TArray<AFYPSpline* > Segments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	int32 chunkScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	AFYPSpline* testspline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	bool spawnedSegments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	FTransform prevSeg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	ATimeGate* chunksTimeGate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	USceneComponent* SceneComponent;
};
