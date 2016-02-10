// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPChunk.h"


// Sets default values
AFYPChunk::AFYPChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFYPChunk::BeginPlay()
{
	Super::BeginPlay();
	if (!spawnedSegments) {
		//makeSegments();
		spawnedSegments = true;
	}
}

// Called every frame
void AFYPChunk::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//void AFYPChunk::getLastSegSplineTrans()
//{
//
//}
//
//void AFYPChunk::makeSegments()
//{
//}

