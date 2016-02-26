// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "FYPStartSpline.h"

AFYPStartSpline::AFYPStartSpline() : Super()
{

}

void AFYPStartSpline::storeSplinePoints_Implementation() {
	TArray<FSplinePoints> tempChosenPieceArray;
	tempChosenPieceArray = trackPiecesList.straight;

	for (int32 j = 0; j < tempChosenPieceArray.Num(); j++) {
		FSplinePoints tempSplinePoint = tempChosenPieceArray[j];
		theSpline->AddSplinePoint(tempSplinePoint.SplinePointLoc, ESplineCoordinateSpace::Local);
		theSpline->SetTangentAtSplinePoint(j, tempChosenPieceArray[j].SplinePointTan, ESplineCoordinateSpace::Local);
	}
}

void AFYPStartSpline::addNewChunk_Implementation(int32 ci, UStaticMesh* tm) {
	Super::addNewChunk_Implementation(ci, tm);
}

void AFYPStartSpline::compSplinePointsToTrackArray(int32 nsp)
{
	Super::compSplinePointsToTrackArray(nsp);
}