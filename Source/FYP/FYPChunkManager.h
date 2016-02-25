// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FYPChunk.h"
#include "FYPGameEventInterface.h"
#include "FYPChunkManager.generated.h"

UCLASS()
class FYP_API AFYPChunkManager : public AActor, public IFYPGameEventInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFYPChunkManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	TArray<AFYPChunk *> levelChunks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	USceneComponent* SceneComponent;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void AddChunk();
	void AddChunk_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void RemoveChunk(int32 chunkToRemove);
	void RemoveChunk_Implementation(int32 chunkToRemove);

	void SecondChunk();
	
	virtual void RoundStart_Implementation() override;
	virtual void RoundEnd_Implementation() override;
	virtual void GateReached_Implementation() override;

};
