// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "FYPSpline.generated.h"


USTRUCT()
struct FtrackStruct
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		float TrackRoll;
		
		FtrackStruct() {

		}
};

USTRUCT()
struct FSplinePoints
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		FVector SplinePointLoc;
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		FVector SplinePointTan;
		
		FSplinePoints() {

		}
};

USTRUCT()
struct FtrackPieces
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> straight;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> sBendRight;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> sBendLeft;

		FtrackPieces() {
			straight.AddDefaulted(2);
			straight[0].SplinePointLoc = { 0, 0, 0 };
			straight[0].SplinePointTan = { 39168.140625, 0, 0 };
			straight[1].SplinePointLoc = { 39168.140625, 0, 0 };
			straight[1].SplinePointTan = { 39168.140625, 0, 0 };

			rightCurveStrong.AddDefaulted(4);
			rightCurveStrong[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong[0].SplinePointTan = { 10511.702148, -147.367188, 0.000000 };
			rightCurveStrong[1].SplinePointLoc = { 10511.702148, -147.367188, 0.000000 };
			rightCurveStrong[1].SplinePointTan = { 11083.736328, 2661.327393, 0.000000 };
			rightCurveStrong[2].SplinePointLoc = { 22167.472656, 5322.654785, 0.000000 };
			rightCurveStrong[2].SplinePointTan = { 8903.341797, 8228.677734, 0.000000 };
			rightCurveStrong[3].SplinePointLoc = { 28318.386719, 16309.988281, 0.000000 };
			rightCurveStrong[3].SplinePointTan = { 6150.914063, 10987.333984, 0.000000 };

			leftCurveStrong.AddDefaulted(4);
			leftCurveStrong[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong[0].SplinePointTan = { 10511.702148, 0, 0 };
			leftCurveStrong[1].SplinePointLoc = { 10511.702148, 147.367188, 0 };
			leftCurveStrong[1].SplinePointTan = { 11083.736328, -2661.327393, 0 };
			leftCurveStrong[2].SplinePointLoc = { 22167.472656, -5322.654785, 0 };
			leftCurveStrong[2].SplinePointTan = { 8903.341797, -8228.677734, 0 };
			leftCurveStrong[3].SplinePointLoc = { 28318.386719, -16309.988281, 0 };
			leftCurveStrong[3].SplinePointTan = { 6150.914063, -10987.333984, 0 };

			rightCurveLight.AddDefaulted(4);
			rightCurveLight[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveLight[0].SplinePointTan = { 13358.020508, 0.004028, 0 };
			rightCurveLight[1].SplinePointLoc = { 13358.020508, 0.004028, 0 };
			rightCurveLight[1].SplinePointTan = { 14066.132813, 2212.708496, 0 };
			rightCurveLight[2].SplinePointLoc = { 28132.265625, 4425.416992, 0 };
			rightCurveLight[2].SplinePointTan = { 12855.65625, 6396.596191, 0 };
			rightCurveLight[3].SplinePointLoc = { 39069.332031, 12793.196289, 0 };
			rightCurveLight[3].SplinePointTan = { 10937.066406, 8367.779297, 0 };

			leftCurveLight.AddDefaulted(4);
			leftCurveLight[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveLight[0].SplinePointTan = { 13358.020508, -0.004028, 0 };
			leftCurveLight[1].SplinePointLoc = { 13358.020508, -0.004028, 0 };
			leftCurveLight[1].SplinePointTan = { 14066.132813, -2212.708496, 0 };
			leftCurveLight[2].SplinePointLoc = { 28132.265625, -4425.416992, 0 };
			leftCurveLight[2].SplinePointTan = { 12855.65625, -6396.596191, 0 };
			leftCurveLight[3].SplinePointLoc = { 39069.332031, -12793.196289, 0 };
			leftCurveLight[3].SplinePointTan = { 10937.066406, -8367.779297, 0 };

			sBendRight.AddDefaulted(4);
			sBendRight[0].SplinePointLoc = { 0, 0, 0 };
			sBendRight[0].SplinePointTan = { 12456.179688, 0, 0 };
			sBendRight[1].SplinePointLoc = { 12456.179688, 0, 0 };
			sBendRight[1].SplinePointTan = { 10591.566406, 4131.664063, 0 };
			sBendRight[2].SplinePointLoc = { 21183.132813, 8263.328125, 0 };
			sBendRight[2].SplinePointTan = { 13331.820313, 4131.664063, 0 };
			sBendRight[3].SplinePointLoc = { 39119.820313, 8263.328125, 0 };
			sBendRight[3].SplinePointTan = { 17936.6875, 0, 0 };

			sBendLeft.AddDefaulted(4);
			sBendLeft[0].SplinePointLoc = { 0, 0, 0 };
			sBendLeft[0].SplinePointTan = { 12456.179688, 0, 0 };
			sBendLeft[1].SplinePointLoc = { 12456.179688, 0, 0 };
			sBendLeft[1].SplinePointTan = { 10591.566406, -4131.664063, 0 };
			sBendLeft[2].SplinePointLoc = { 21183.132813, -8263.328125, 0 };
			sBendLeft[2].SplinePointTan = { 13331.820313, -4131.664063, 0 };
			sBendLeft[3].SplinePointLoc = { 39119.820313, -8263.328125, 0 };
			sBendLeft[3].SplinePointTan = { 17936.6875, 0, 0 };

		}
};

UCLASS()
class FYP_API AFYPSpline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFYPSpline();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//on property change/spawn (construction script)
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	int32 NumSplinePoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	TArray<FtrackStruct> trackArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	FtrackStruct templateStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	int32 currentIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	UStaticMesh* trackChunk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	TArray<FSplinePoints> splinePointStore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	FtrackPieces trackPiecesList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	USplineComponent* theSpline;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void addNewChunk(int32 ci, UStaticMesh* tm);
	void addNewChunk_Implementation(int32 ci, UStaticMesh* tm);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void storeSplinePoints();
	void storeSplinePoints_Implementation();

	void compSplinePointsToTrackArray(int32 nsp);

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	USplineMeshComponent* chunkSplineMesh;*/
};
