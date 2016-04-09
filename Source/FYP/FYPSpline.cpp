// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPSpline.h"
#include <random>

// Sets default values
AFYPSpline::AFYPSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//this can only be used in here, NOT onconstruction
	theSpline = CreateDefaultSubobject<USplineComponent>(TEXT("the spline"));
	theSpline->SetMobility(EComponentMobility::Movable);
	RootComponent = theSpline;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> trackp(TEXT("/Game/Meshes/trackpiece.trackpiece"));
	trackChunk = trackp.Object;
}

// Called when the game starts or when spawned
void AFYPSpline::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFYPSpline::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AFYPSpline::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);
	
	theSpline->ClearSplinePoints(); //need to remove default 2 points
	storeSplinePoints_Implementation();
	NumSplinePoints = theSpline->GetNumberOfSplinePoints();
	
	compSplinePointsToTrackArray(NumSplinePoints);
	//can't do this in the constructor, so it's done on construction of object in-game
	for (int32 i = 0; i <= (NumSplinePoints - 2); i++) {
		addNewChunk_Implementation(i, trackChunk);
	}
	FString tempstr = FString::FromInt(theSpline->GetNumberOfSplinePoints());
	theSpline->bSplineHasBeenEdited = true;
}

//Takes the spline loc/tan and creates a spline mesh according to it
void AFYPSpline::addNewChunk_Implementation(int32 ci, UStaticMesh* tm)
{
	int32 curSplinePoint = ci;
	int32 nextSplinePoint = (curSplinePoint + 1) % NumSplinePoints; //why did I do this again??
	FVector curLoc = theSpline->GetLocationAtSplinePoint(curSplinePoint, ESplineCoordinateSpace::Local);
	FVector curTang = theSpline->GetTangentAtSplinePoint(curSplinePoint, ESplineCoordinateSpace::Local);
	FVector nextLoc = theSpline->GetLocationAtSplinePoint(nextSplinePoint, ESplineCoordinateSpace::Local);
	FVector nextTang = theSpline->GetTangentAtSplinePoint(nextSplinePoint, ESplineCoordinateSpace::Local);
	UStaticMesh* trackChunkStaticMesh = tm; //could use tm directly
	USplineMeshComponent* chunkSplineMesh = NewObject<USplineMeshComponent>(this, NAME_None);
	chunkSplineMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;
	chunkSplineMesh->SetMobility(EComponentMobility::Movable); //needed because root comp is movable
	chunkSplineMesh->AttachTo(RootComponent, NAME_None);
	chunkSplineMesh->SetStaticMesh(trackChunkStaticMesh);
	chunkSplineMesh->SetStartAndEnd(curLoc, curTang, nextLoc, nextTang);
	chunkSplineMesh->SetStartScale(FVector2D(1.0, 1.0));
	chunkSplineMesh->SetEndScale(FVector2D(1.0, 1.0));
	chunkSplineMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	chunkSplineMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	chunkSplineMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	chunkSplineMesh->bGenerateOverlapEvents = true;
	chunkSplineMesh->CastShadow = false;
	FinishAndRegisterComponent(chunkSplineMesh);
	listofsplinemeshes.Add(chunkSplineMesh);
}

//Picks the spline shape, uses the playerAbility to choose
//the difficulty variant of said shape
TArray<FSplinePoints> AFYPSpline::chooseSpline_Implementation() {
	TArray<FSplinePoints> tempChosenPieceArray;
	int32 ranTrackPiece = UKismetMathLibrary::RandomIntegerInRange(0, 6);
	switch (ranTrackPiece) {
	case 0:
		tempChosenPieceArray = trackPiecesList.straight;
		break;
	case 1:
		tempChosenPieceArray = trackPiecesList.rightCurveStrong;
		break;
	case 2:
		tempChosenPieceArray = trackPiecesList.leftCurveStrong;
		break;
	case 3:
		tempChosenPieceArray = trackPiecesList.rightCurveLight;
		break;
	case 4:
		tempChosenPieceArray = trackPiecesList.leftCurveLight;
		break;
	case 5:
		tempChosenPieceArray = trackPiecesList.sBendRight;
		break;
	case 6:
		tempChosenPieceArray = trackPiecesList.sBendLeft;
		break;
	default:
		tempChosenPieceArray = trackPiecesList.straight;
		break;
	}
	return(tempChosenPieceArray);
}

//Calls ChooseSpline then stores the location and tangents for this particular spline.
void AFYPSpline::storeSplinePoints_Implementation()
{
	TArray<FSplinePoints> tempChosenPieceArray = chooseSpline_Implementation();

	for (int32 j = 0; j < tempChosenPieceArray.Num(); j++) {
		FSplinePoints tempSplinePoint = tempChosenPieceArray[j];
		theSpline->AddSplinePoint(tempSplinePoint.SplinePointLoc, ESplineCoordinateSpace::Local);
		theSpline->SetTangentAtSplinePoint(j, tempChosenPieceArray[j].SplinePointTan, ESplineCoordinateSpace::Local);
	}
}

//Each splinepoint needs adding to the trackpiece array
//If count is different, add it
// if it's equal, continue
// if there are too many then remove it
void AFYPSpline::compSplinePointsToTrackArray(int32 nsp)
{
	if (nsp == trackArray.Num()) {
		//nothing to do
	} else if (nsp > trackArray.Num()) {
		trackArray.Add(templateStruct);
		compSplinePointsToTrackArray(nsp);
	} else if (nsp < trackArray.Num()) {
		trackArray.RemoveAt(trackArray.Num() - 1);
	}
}

void AFYPSpline::RoundStart_Implementation() {

}

void AFYPSpline::RoundEnd_Implementation() {

}

void AFYPSpline::GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) {

}

