// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FYPGameEventInterface.h"
#include "Car.h"
#include "FYPPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimeGate.generated.h"

UCLASS()
class FYP_API ATimeGate : public AActor, public IFYPGameEventInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeGate();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	bool reached;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	bool isActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	float gateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	float timeLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	FTimerHandle THandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	UStaticMeshComponent* timeGateMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	UParticleSystemComponent* gateParticle;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void StartCountDown();
	void StartCountDown_Implementation();

	UFUNCTION(Category = "MyVars")
	void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void AlertRoundEnd();

	virtual void RoundStart_Implementation() override;
	virtual void RoundEnd_Implementation() override;
	virtual void GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) override;
};
