// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPChunkManager.h"


// Sets default values
AFYPChunkManager::AFYPChunkManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFYPChunkManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFYPChunkManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

