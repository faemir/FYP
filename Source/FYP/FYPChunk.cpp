// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPChunk.h"


// Sets default values
AFYPChunk::AFYPChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	RootComponent = SceneComponent;
	RootComponent->SetMobility(EComponentMobility::Movable);
	spawnedSegments = false;
	chunkScore = 1;

}

// Called when the game starts or when spawned
void AFYPChunk::BeginPlay()
{
	Super::BeginPlay();
	if (!spawnedSegments) {
		MakeSegments();
		spawnedSegments = true;
	}
}

// Called every frame
void AFYPChunk::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//gets the latest/last splinepoint co-ordinates in world space
void AFYPChunk::getLastSegSplineTrans_Implementation()
{
	USplineComponent* tempSpline = Segments[Segments.Num() - 1]->theSpline;
	prevSeg = tempSpline->GetTransformAtSplinePoint(tempSpline->GetNumberOfSplinePoints() - 1, ESplineCoordinateSpace::World);
}

void AFYPChunk::MakeSegments_Implementation()
{
	int32 curChunkScore = 0;
	UWorld* const World = GetWorld();
	if (World) {
		//spawn the first spline of the chunk at 0,0,0
		AFYPSpline* firstSpline = World->SpawnActor<AFYPSpline>(AFYPSpline::StaticClass());
		firstSpline->AttachRootComponentTo(RootComponent,NAME_None,EAttachLocation::KeepRelativeOffset, true);
		Segments.Add(firstSpline);
		//spawn other splines using the last spline's final point as the next one's first
		while (curChunkScore <= chunkScore) {
			FActorSpawnParameters SpawnParams;
			getLastSegSplineTrans_Implementation();
			FVector newLoc = prevSeg.GetLocation();
			FRotator newRot = prevSeg.GetRotation().Rotator();
			AFYPSpline* tempSpline = World->SpawnActor<AFYPSpline>(AFYPSpline::StaticClass(), newLoc, newRot, SpawnParams);
			tempSpline->AttachRootComponentTo(RootComponent, NAME_None, EAttachLocation::KeepWorldPosition, true);
			Segments.Add(tempSpline);
			curChunkScore += 1;
			//this->RegisterAllComponents();
		}
		//add timegates (FIXME: need to make it not do this for the first one)
		FActorSpawnParameters SpawnParams;
		FVector gLoc = { 0.f, 0.f, 0.f };
		FRotator gRot = { 0.f, 0.f, 0.f };
		ATimeGate* TGate = World->SpawnActor<ATimeGate>(ATimeGate::StaticClass(), gLoc, gRot, SpawnParams);
		TGate->AttachRootComponentTo(RootComponent, NAME_None, EAttachLocation::KeepRelativeOffset, true);
		/*TGate->SetActorEnableCollision(false);
		TGate->timeGateMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		TGate->timeGateMesh->SetCollisionObjectType(ECollisionChannel::ECC_Destructible);
		TGate->timeGateMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);*/
		//this->RegisterAllComponents();
		
	}
}

