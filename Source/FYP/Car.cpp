// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "Car.h"


// Sets default values
ACar::ACar(const FObjectInitializer& ObjectInitializer)	: Super(ObjectInitializer)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ACar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ACar::RoundStart_Implementation() {
	//return("RoundStart_Implementation()");
}

void ACar::RoundEnd_Implementation() {
	//return("RoundEnd_Implementation()");
}

void ACar::GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) {
	//return("GateReached_Implementation()");
}
