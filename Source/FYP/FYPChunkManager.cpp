// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPChunkManager.h"


// Sets default values
AFYPChunkManager::AFYPChunkManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("root scene comp"));
	RootComponent = SceneComponent;
	RootComponent->SetMobility(EComponentMobility::Static);


}

// Called when the game starts or when spawned
void AFYPChunkManager::BeginPlay()
{
	Super::BeginPlay();
	
	AddChunk_Implementation();
	FTimerHandle THandle;
	GetWorldTimerManager().SetTimer(THandle, this, &AFYPChunkManager::AddChunk_Implementation, 0.5f);
}

// Called every frame
void AFYPChunkManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AFYPChunkManager::AddChunk_Implementation() {
	UWorld* const World = GetWorld();
	if (World) {
		if (levelChunks.Num() == 0) {
			//first bit needs to not have a timegate, and be straight so use child class 'FYPStartSpline'
			AFYPStartSpline* startingSpline = World->SpawnActor<AFYPStartSpline>(AFYPStartSpline::StaticClass());
			startingSpline->AttachRootComponentTo(RootComponent, NAME_None, EAttachLocation::KeepWorldPosition, true);

			AFYPSpline* castStart = Cast<AFYPSpline>(startingSpline);
			USplineComponent* lastStrSpline = castStart->theSpline;
			FTransform strTrans = lastStrSpline->GetTransformAtSplinePoint((lastStrSpline->GetNumberOfSplinePoints() - 1), ESplineCoordinateSpace::World, false);
			FVector strLoc = strTrans.GetLocation();
			FRotator strRot = strTrans.GetRotation().Rotator();

			FActorSpawnParameters SpawnParams;
			AFYPChunk* firstChunk = World->SpawnActor<AFYPChunk>(AFYPChunk::StaticClass(), strLoc, strRot, SpawnParams);
			firstChunk->AttachRootComponentTo(RootComponent, NAME_None, EAttachLocation::KeepWorldPosition, true);
			levelChunks.Add(firstChunk);
		}
		else {
			//every chunk after first, grab previous, get its final segment, then that segment's last spline point
			//and spawn the next chunk from there to line up perfectly.
			AFYPChunk* lastChunk = levelChunks[(levelChunks.Num() - 1)];
			USplineComponent* lastChunkLastSpline = lastChunk->Segments[(lastChunk->Segments.Num() - 1)]->theSpline;
			FTransform newChunkStartTrans = lastChunkLastSpline->GetTransformAtSplinePoint((lastChunkLastSpline->GetNumberOfSplinePoints() - 1), ESplineCoordinateSpace::World, false);
			
			FVector newLoc = newChunkStartTrans.GetLocation();
			FRotator newRot = newChunkStartTrans.GetRotation().Rotator();
			FActorSpawnParameters SpawnParams;

			AFYPChunk* tailChunk = World->SpawnActor<AFYPChunk>(AFYPChunk::StaticClass(), newLoc, newRot, SpawnParams);
			tailChunk->AttachRootComponentTo(RootComponent, NAME_None, EAttachLocation::KeepWorldPosition, true);
			levelChunks.Add(tailChunk);

		}
	}
}

void AFYPChunkManager::RemoveChunk_Implementation(int32 chunkToRemove) {

}

void AFYPChunkManager::RoundStart_Implementation() {
	//return("RoundStart_Implementation()");
}

void AFYPChunkManager::RoundEnd_Implementation() {
	//return("RoundEnd_Implementation()");
}

void AFYPChunkManager::GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) {
	AddChunk_Implementation();
}