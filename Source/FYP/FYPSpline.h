// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FYPGameEventInterface.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "FYPGameMode.h"
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
		TArray<FSplinePoints> leftCurveLight1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight2;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight3;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight4;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight5;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight6;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight7;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight8;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveLight9;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong2;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong3;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong4;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong5;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong6;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong7;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong8;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftCurveStrong9;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend2;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend3;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend4;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend5;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend6;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend7;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend8;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> leftSBend9;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight2;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight3;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight4;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight5;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight6;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight7;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight8;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveLight9;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong2;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong3;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong4;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong5;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong6;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong7;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong8;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightCurveStrong9;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend2;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend3;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend4;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend5;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend6;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend7;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend8;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
		TArray<FSplinePoints> rightSBend9;

		FtrackPieces() {
			straight.AddDefaulted(2);
			straight[0].SplinePointLoc = { 0, 0, 0 };
			straight[0].SplinePointTan = { 39168.140625, 0, 0 };
			straight[1].SplinePointLoc = { 39168.140625, 0, 0 };
			straight[1].SplinePointTan = { 39168.140625, 0, 0 };
			leftCurveLight1.AddDefaulted(4);
			leftCurveLight1[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			leftCurveLight1[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight1[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight1[1].SplinePointTan = { 14067.177734, -1190.000000, 0.000000 };
			leftCurveLight1[2].SplinePointLoc = { 28134.355469, -2380.000000, 0.000000 };
			leftCurveLight1[2].SplinePointTan = { 14310.740234, -3365.000000, 0.000000 };
			leftCurveLight1[3].SplinePointLoc = { 41970.000000, -6730.000000, 0.000000 };
			leftCurveLight1[3].SplinePointTan = { 13835.644531, -4350.000000, 0.000000 };
			leftCurveLight2.AddDefaulted(4);
			leftCurveLight2[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			leftCurveLight2[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight2[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight2[1].SplinePointTan = { 14067.177734, -1190.000000, 0.000000 };
			leftCurveLight2[2].SplinePointLoc = { 28134.355469, -2380.000000, 0.000000 };
			leftCurveLight2[2].SplinePointTan = { 14050.740234, -3915.000000, 0.000000 };
			leftCurveLight2[3].SplinePointLoc = { 41450.000000, -7830.000000, 0.000000 };
			leftCurveLight2[3].SplinePointTan = { 13315.644531, -5450.000000, 0.000000 };
			leftCurveLight3.AddDefaulted(4);
			leftCurveLight3[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			leftCurveLight3[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight3[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight3[1].SplinePointTan = { 14072.177734, -1330.000000, 0.000000 };
			leftCurveLight3[2].SplinePointLoc = { 28144.355469, -2660.000000, 0.000000 };
			leftCurveLight3[2].SplinePointTan = { 13800.740234, -4910.000000, 0.000000 };
			leftCurveLight3[3].SplinePointLoc = { 40950.000000, -9820.000000, 0.000000 };
			leftCurveLight3[3].SplinePointTan = { 12805.644531, -7160.000000, 0.000000 };
			leftCurveLight4.AddDefaulted(4);
			leftCurveLight4[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			leftCurveLight4[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight4[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			leftCurveLight4[1].SplinePointTan = { 14077.177734, -1565.000000, 0.000000 };
			leftCurveLight4[2].SplinePointLoc = { 28154.355469, -3130.000000, 0.000000 };
			leftCurveLight4[2].SplinePointTan = { 13440.740234, -5900.000000, 0.000000 };
			leftCurveLight4[3].SplinePointLoc = { 40230.000000, -11800.000000, 0.000000 };
			leftCurveLight4[3].SplinePointTan = { 12075.644531, -8670.000000, 0.000000 };
			leftCurveLight5.AddDefaulted(4);
			leftCurveLight5[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveLight5[0].SplinePointTan = { 13358.020508, -0.004028, 0 };
			leftCurveLight5[1].SplinePointLoc = { 13358.020508, -0.004028, 0 };
			leftCurveLight5[1].SplinePointTan = { 14066.132813, -2212.708496, 0 };
			leftCurveLight5[2].SplinePointLoc = { 28132.265625, -4425.416992, 0 };
			leftCurveLight5[2].SplinePointTan = { 12855.65625, -6396.596191, 0 };
			leftCurveLight5[3].SplinePointLoc = { 39069.332031, -12793.196289, 0 };
			leftCurveLight5[3].SplinePointTan = { 10937.066406, -8367.779297, 0 };
			leftCurveLight6.AddDefaulted(4);
			leftCurveLight6[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveLight6[0].SplinePointTan = { 13348.519531, 0, 0 };
			leftCurveLight6[1].SplinePointLoc = { 13348.519531, 0, 0 };
			leftCurveLight6[1].SplinePointTan = { 13882.177734, -2705, 0 };
			leftCurveLight6[2].SplinePointLoc = { 27764.355469, -5410, 0 };
			leftCurveLight6[2].SplinePointTan = { 12080.740234, -7630, 0 };
			leftCurveLight6[3].SplinePointLoc = { 39069.332031, -15260, 0 };
			leftCurveLight6[3].SplinePointTan = { 9745.644531, -9850.000000, 0 };
			leftCurveLight7.AddDefaulted(4);
			leftCurveLight7[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveLight7[0].SplinePointTan = { 13348.519531, 0, 0 };
			leftCurveLight7[1].SplinePointLoc = { 13348.519531, 0, 0 };
			leftCurveLight7[1].SplinePointTan = { 13062.177734, -3425, 0 };
			leftCurveLight7[2].SplinePointLoc = { 26124.355469, -6850, 0 };
			leftCurveLight7[2].SplinePointTan = { 11060.740234, -8965, 0 };
			leftCurveLight7[3].SplinePointLoc = { 35470.000000, -17930, 0 };
			leftCurveLight7[3].SplinePointTan = { 9345.644531, -11080, 0 };
			leftCurveLight8.AddDefaulted(4);
			leftCurveLight8[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveLight8[0].SplinePointTan = { 13348.519531, 0, 0 };
			leftCurveLight8[1].SplinePointLoc = { 13348.519531, 0, 0 };
			leftCurveLight8[1].SplinePointTan = { 12807.177734, -3735, 0 };
			leftCurveLight8[2].SplinePointLoc = { 25614.355469, -7470, 0 };
			leftCurveLight8[2].SplinePointTan = { 9780.740234, -9415, 0 };
			leftCurveLight8[3].SplinePointLoc = { 32910.000000, -18830, 0 };
			leftCurveLight8[3].SplinePointTan = { 7295.644531, -11360, 0 };
			leftCurveLight6.AddDefaulted(4);
			leftCurveLight6[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveLight6[0].SplinePointTan = { 13348.519531, 0, 0 };
			leftCurveLight6[1].SplinePointLoc = { 13348.519531, 0, 0 };
			leftCurveLight6[1].SplinePointTan = { 12372.177734, -3960, 0 };
			leftCurveLight6[2].SplinePointLoc = { 24744.355469, -7920, 0 };
			leftCurveLight6[2].SplinePointTan = { 8990.740234, -9770, 0 };
			leftCurveLight6[3].SplinePointLoc = { 31330.000000, -19540, 0 };
			leftCurveLight6[3].SplinePointTan = { 6585.644531, -11620, 0 };
			leftCurveLight6.AddDefaulted(4);
			leftCurveLight6[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveLight6[0].SplinePointTan = { 13348.519531, 0, 0 };
			leftCurveLight6[1].SplinePointLoc = { 13348.519531, 0, 0 };
			leftCurveLight6[1].SplinePointTan = { 12372.177734, -3960, 0 };
			leftCurveLight6[2].SplinePointLoc = { 24744.355469, -7920, 0 };
			leftCurveLight6[2].SplinePointTan = { 8990.740234, -9770, 0 };
			leftCurveLight6[3].SplinePointLoc = { 31330.000000, -19540, 0 };
			leftCurveLight6[3].SplinePointTan = { 6585.644531, -11620, 0 };
			leftCurveStrong1.AddDefaulted(4);
			leftCurveStrong1[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong1[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong1[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong1[1].SplinePointTan = { 11247.177734, -2355, 0 };
			leftCurveStrong1[2].SplinePointLoc = { 22494.355469, -4710, 0 };
			leftCurveStrong1[2].SplinePointTan = { 8345.740234, -8295, 0 };
			leftCurveStrong1[3].SplinePointLoc = { 27210.000000, -16430, 0 };
			leftCurveStrong1[3].SplinePointTan = { 4715.644531, -11720, 0 };
			leftCurveStrong2.AddDefaulted(4);
			leftCurveStrong2[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong2[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong2[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong2[1].SplinePointTan = { 11062.177734, -1795, 0 };
			leftCurveStrong2[2].SplinePointLoc = { 22124.355469, -3590, 0 };
			leftCurveStrong2[2].SplinePointTan = { 7995.740234, -8385, 0 };
			leftCurveStrong2[3].SplinePointLoc = { 26510, -16610, 0 };
			leftCurveStrong2[3].SplinePointTan = { 4385.644531, -13020, 0 };
			leftCurveStrong3.AddDefaulted(4);
			leftCurveStrong3[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong3[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong3[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong3[1].SplinePointTan = { 11272.177734, -1315, 0 };
			leftCurveStrong3[2].SplinePointLoc = { 22544.355469, -2630, 0 };
			leftCurveStrong3[2].SplinePointTan = { 7600.740234, -8345, 0 };
			leftCurveStrong3[3].SplinePointLoc = { 25720, -16530, 0 };
			leftCurveStrong3[3].SplinePointTan = { 3175.644531, -13900, 0 };
			leftCurveStrong4.AddDefaulted(4);
			leftCurveStrong4[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong4[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong4[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong4[1].SplinePointTan = { 11442.177734, -1095, 0 };
			leftCurveStrong4[2].SplinePointLoc = { 22884.355469, -2190, 0 };
			leftCurveStrong4[2].SplinePointTan = { 7250.740234, -8350, 0 };
			leftCurveStrong4[3].SplinePointLoc = { 25020, -16540, 0 };
			leftCurveStrong4[3].SplinePointTan = { 2135.644531, -14350, 0 };
			leftCurveStrong5.AddDefaulted(4);
			leftCurveStrong5[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong5[0].SplinePointTan = { 10511.702148, 0, 0 };
			leftCurveStrong5[1].SplinePointLoc = { 10511.702148, 147.367188, 0 };
			leftCurveStrong5[1].SplinePointTan = { 11083.736328, -2661.327393, 0 };
			leftCurveStrong5[2].SplinePointLoc = { 22167.472656, -5322.654785, 0 };
			leftCurveStrong5[2].SplinePointTan = { 8903.341797, -8228.677734, 0 };
			leftCurveStrong5[3].SplinePointLoc = { 28318.386719, -16309.988281, 0 };
			leftCurveStrong5[3].SplinePointTan = { 6150.914063, -10987.333984, 0 };
			leftCurveStrong6.AddDefaulted(4);
			leftCurveStrong6[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong6[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong6[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong6[1].SplinePointTan = { 11262.177734, -2375, 0 };
			leftCurveStrong6[2].SplinePointLoc = { 22524.355469, -4750, 0 };
			leftCurveStrong6[2].SplinePointTan = { 8925.740234, -7750, 0 };
			leftCurveStrong6[3].SplinePointLoc = { 28370, -15340, 0 };
			leftCurveStrong6[3].SplinePointTan = { 5845.644531, -10590, 0 };
			leftCurveStrong7.AddDefaulted(4);
			leftCurveStrong7[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong7[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong7[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong7[1].SplinePointTan = { 11432.177734, -2110, 0 };
			leftCurveStrong7[2].SplinePointLoc = { 22864.355469, -4220, 0 };
			leftCurveStrong7[2].SplinePointTan = { 9085.740234, -7250, 0 };
			leftCurveStrong7[3].SplinePointLoc = { 28690, -14340, 0 };
			leftCurveStrong7[3].SplinePointTan = { 5825.644531, -10120, 0 };
			leftCurveStrong8.AddDefaulted(4);
			leftCurveStrong8[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong8[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong8[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong8[1].SplinePointTan = { 11467.177734, -1590, 0 };
			leftCurveStrong8[2].SplinePointLoc = { 22934.355469, -3180, 0 };
			leftCurveStrong8[2].SplinePointTan = { 9410.740234, -6790, 0 };
			leftCurveStrong8[3].SplinePointLoc = { 29340, -13420, 0 };
			leftCurveStrong8[3].SplinePointTan = { 6405.644531, -10240, 0 };
			leftCurveStrong9.AddDefaulted(4);
			leftCurveStrong9[0].SplinePointLoc = { 0, 0, 0 };
			leftCurveStrong9[0].SplinePointTan = { 10518.519531, 160, 0 };
			leftCurveStrong9[1].SplinePointLoc = { 10518.519531, 160, 0 };
			leftCurveStrong9[1].SplinePointTan = { 11507.177734, -1460, 0 };
			leftCurveStrong9[2].SplinePointLoc = { 23014.355469, -2920, 0 };
			leftCurveStrong9[2].SplinePointTan = { 9525.740234, -6330, 0 };
			leftCurveStrong9[3].SplinePointLoc = { 29570, -12500, 0 };
			leftCurveStrong9[3].SplinePointTan = { 6555.644531, -9580, 0 };
			leftSBend1.AddDefaulted(4);
			leftSBend1[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend1[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend1[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend1[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend1[2].SplinePointLoc = { 23264.355469, -8330, 0 };
			leftSBend1[2].SplinePointTan = { 9440.740234, -1225, 0 };
			leftSBend1[3].SplinePointLoc = { 33130, -8270, 0 };
			leftSBend1[3].SplinePointTan = { 9865.644531, 60, 0 };
			leftSBend2.AddDefaulted(4);
			leftSBend2[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend2[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend2[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend2[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend2[2].SplinePointLoc = { 25794.355469, -8330, 0 };
			leftSBend2[2].SplinePointTan = { 9440.740234, -1225, 0 };
			leftSBend2[3].SplinePointLoc = { 35660, -8270, 0 };
			leftSBend2[3].SplinePointTan = { 9865.644531, 60, 0 };
			leftSBend3.AddDefaulted(4);
			leftSBend3[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend3[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend3[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend3[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend3[2].SplinePointLoc = { 28904.355469, -8330, 0 };
			leftSBend3[2].SplinePointTan = { 9440.740234, -1225, 0 };
			leftSBend3[3].SplinePointLoc = { 38770, -8270, 0 };
			leftSBend3[3].SplinePointTan = { 9865.644531, 60, 0 };
			leftSBend4.AddDefaulted(4);
			leftSBend4[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend4[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend4[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend4[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend4[2].SplinePointLoc = { 33604.355469, -8330, 0 };
			leftSBend4[2].SplinePointTan = { 9440.740234, -1225, 0 };
			leftSBend4[3].SplinePointLoc = { 43470, -8270, 0 };
			leftSBend4[3].SplinePointTan = { 9865.644531, 60, 0 };
			leftSBend5.AddDefaulted(4);
			leftSBend5[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend5[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend5[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend5[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend5[2].SplinePointLoc = { 21514.355469, -8330, 0 };
			leftSBend5[2].SplinePointTan = { 9440.740234, -1225, 0 };
			leftSBend5[3].SplinePointLoc = { 31380, -8270, 0 };
			leftSBend5[3].SplinePointTan = { 9865.644531, 60, 0 };
			leftSBend6.AddDefaulted(4);
			leftSBend6[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend6[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend6[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend6[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend6[2].SplinePointLoc = { 20304.355469, -8160, 0 };
			leftSBend6[2].SplinePointTan = { 8970.740234, -2045, 0 };
			leftSBend6[3].SplinePointLoc = { 30620, -8100, 0 };
			leftSBend6[3].SplinePointTan = { 10315.644531, 60, 0 };
			leftSBend7.AddDefaulted(4);
			leftSBend7[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend7[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend7[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend7[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend7[2].SplinePointLoc = { 19144.355469, -7320, 0 };
			leftSBend7[2].SplinePointTan = { 8970.740234, -2045, 0 };
			leftSBend7[3].SplinePointLoc = { 29460, -7260, 0 };
			leftSBend7[3].SplinePointTan = { 10315.644531, 60, 0 };
			leftSBend8.AddDefaulted(4);
			leftSBend8[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend8[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend8[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend8[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend8[2].SplinePointLoc = { 18304.355469, -6550, 0 };
			leftSBend8[2].SplinePointTan = { 8970.740234, -2045, 0 };
			leftSBend8[3].SplinePointLoc = { 27550, -7400, 0 };
			leftSBend8[3].SplinePointTan = { 10315.644531, 60, 0 };
			leftSBend9.AddDefaulted(4);
			leftSBend9[0].SplinePointLoc = { 0, 0, 0 };
			leftSBend9[0].SplinePointTan = { 12498.519531, 0, 0 };
			leftSBend9[1].SplinePointLoc = { 12498.519531, 0, 0 };
			leftSBend9[1].SplinePointTan = { 10757.177734, -1855, 0 };
			leftSBend9[2].SplinePointLoc = { 16234.355469, -7650, 0 };
			leftSBend9[2].SplinePointTan = { 7810.740234, -3405, 0 };
			leftSBend9[3].SplinePointLoc = { 26550, -7590, 0 };
			leftSBend9[3].SplinePointTan = { 10315.644531, 60, 0 };
			rightCurveLight1.AddDefaulted(4);
			rightCurveLight1[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			rightCurveLight1[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight1[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight1[1].SplinePointTan = { 14067.177734, 1190.000000, 0.000000 };
			rightCurveLight1[2].SplinePointLoc = { 28134.355469, 2380.000000, 0.000000 };
			rightCurveLight1[2].SplinePointTan = { 14310.740234, 3365.000000, 0.000000 };
			rightCurveLight1[3].SplinePointLoc = { 41970.000000, 6730.000000, 0.000000 };
			rightCurveLight1[3].SplinePointTan = { 13835.644531, 4350.000000, 0.000000 };
			rightCurveLight2.AddDefaulted(4);
			rightCurveLight2[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			rightCurveLight2[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight2[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight2[1].SplinePointTan = { 14067.177734, 1190.000000, 0.000000 };
			rightCurveLight2[2].SplinePointLoc = { 28134.355469, 2380.000000, 0.000000 };
			rightCurveLight2[2].SplinePointTan = { 14050.740234, 3915.000000, 0.000000 };
			rightCurveLight2[3].SplinePointLoc = { 41450.000000, 7830.000000, 0.000000 };
			rightCurveLight2[3].SplinePointTan = { 13315.644531, 5450.000000, 0.000000 };
			rightCurveLight3.AddDefaulted(4);
			rightCurveLight3[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			rightCurveLight3[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight3[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight3[1].SplinePointTan = { 14072.177734, 1330.000000, 0.000000 };
			rightCurveLight3[2].SplinePointLoc = { 28144.355469, 2660.000000, 0.000000 };
			rightCurveLight3[2].SplinePointTan = { 13800.740234, 4910.000000, 0.000000 };
			rightCurveLight3[3].SplinePointLoc = { 40950.000000, 9820.000000, 0.000000 };
			rightCurveLight3[3].SplinePointTan = { 12805.644531, 7160.000000, 0.000000 };
			rightCurveLight4.AddDefaulted(4);
			rightCurveLight4[0].SplinePointLoc = { 0.000000, 0.000000, 0.000000 };
			rightCurveLight4[0].SplinePointTan = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight4[1].SplinePointLoc = { 13348.519531, 0.000000, 0.000000 };
			rightCurveLight4[1].SplinePointTan = { 14077.177734, 1565.000000, 0.000000 };
			rightCurveLight4[2].SplinePointLoc = { 28154.355469, 3130.000000, 0.000000 };
			rightCurveLight4[2].SplinePointTan = { 13440.740234, 5900.000000, 0.000000 };
			rightCurveLight4[3].SplinePointLoc = { 40230.000000, 11800.000000, 0.000000 };
			rightCurveLight4[3].SplinePointTan = { 12075.644531, 8670.000000, 0.000000 };
			rightCurveLight5.AddDefaulted(4);
			rightCurveLight5[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveLight5[0].SplinePointTan = { 13358.020508, 0.004028, 0 };
			rightCurveLight5[1].SplinePointLoc = { 13358.020508, 0.004028, 0 };
			rightCurveLight5[1].SplinePointTan = { 14066.132813, 2212.708496, 0 };
			rightCurveLight5[2].SplinePointLoc = { 28132.265625, 4425.416992, 0 };
			rightCurveLight5[2].SplinePointTan = { 12855.65625, 6396.596191, 0 };
			rightCurveLight5[3].SplinePointLoc = { 39069.332031, 12793.196289, 0 };
			rightCurveLight5[3].SplinePointTan = { 10937.066406, 8367.779297, 0 };
			rightCurveLight6.AddDefaulted(4);
			rightCurveLight6[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveLight6[0].SplinePointTan = { 13348.519531, 0, 0 };
			rightCurveLight6[1].SplinePointLoc = { 13348.519531, 0, 0 };
			rightCurveLight6[1].SplinePointTan = { 13882.177734, 2705, 0 };
			rightCurveLight6[2].SplinePointLoc = { 27764.355469, 5410, 0 };
			rightCurveLight6[2].SplinePointTan = { 12080.740234, 7630, 0 };
			rightCurveLight6[3].SplinePointLoc = { 39069.332031, 15260, 0 };
			rightCurveLight6[3].SplinePointTan = { 9745.644531, 9850.000000, 0 };
			rightCurveLight7.AddDefaulted(4);
			rightCurveLight7[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveLight7[0].SplinePointTan = { 13348.519531, 0, 0 };
			rightCurveLight7[1].SplinePointLoc = { 13348.519531, 0, 0 };
			rightCurveLight7[1].SplinePointTan = { 13062.177734, 3425, 0 };
			rightCurveLight7[2].SplinePointLoc = { 26124.355469, 6850, 0 };
			rightCurveLight7[2].SplinePointTan = { 11060.740234, 8965, 0 };
			rightCurveLight7[3].SplinePointLoc = { 35470.000000, 17930, 0 };
			rightCurveLight7[3].SplinePointTan = { 9345.644531, 11080, 0 };
			rightCurveLight8.AddDefaulted(4);
			rightCurveLight8[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveLight8[0].SplinePointTan = { 13348.519531, 0, 0 };
			rightCurveLight8[1].SplinePointLoc = { 13348.519531, 0, 0 };
			rightCurveLight8[1].SplinePointTan = { 12807.177734, 3735, 0 };
			rightCurveLight8[2].SplinePointLoc = { 25614.355469, 7470, 0 };
			rightCurveLight8[2].SplinePointTan = { 9780.740234, 9415, 0 };
			rightCurveLight8[3].SplinePointLoc = { 32910.000000, 18830, 0 };
			rightCurveLight8[3].SplinePointTan = { 7295.644531, 11360, 0 };
			rightCurveLight6.AddDefaulted(4);
			rightCurveLight6[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveLight6[0].SplinePointTan = { 13348.519531, 0, 0 };
			rightCurveLight6[1].SplinePointLoc = { 13348.519531, 0, 0 };
			rightCurveLight6[1].SplinePointTan = { 12372.177734, 3960, 0 };
			rightCurveLight6[2].SplinePointLoc = { 24744.355469, 7920, 0 };
			rightCurveLight6[2].SplinePointTan = { 8990.740234, 9770, 0 };
			rightCurveLight6[3].SplinePointLoc = { 31330.000000, 19540, 0 };
			rightCurveLight6[3].SplinePointTan = { 6585.644531, 11620, 0 };
			rightCurveLight6.AddDefaulted(4);
			rightCurveLight6[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveLight6[0].SplinePointTan = { 13348.519531, 0, 0 };
			rightCurveLight6[1].SplinePointLoc = { 13348.519531, 0, 0 };
			rightCurveLight6[1].SplinePointTan = { 12372.177734, 3960, 0 };
			rightCurveLight6[2].SplinePointLoc = { 24744.355469, 7920, 0 };
			rightCurveLight6[2].SplinePointTan = { 8990.740234, 9770, 0 };
			rightCurveLight6[3].SplinePointLoc = { 31330.000000, 19540, 0 };
			rightCurveLight6[3].SplinePointTan = { 6585.644531, 11620, 0 };
			rightCurveStrong1.AddDefaulted(4);
			rightCurveStrong1[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong1[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong1[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong1[1].SplinePointTan = { 11247.177734, 2355, 0 };
			rightCurveStrong1[2].SplinePointLoc = { 22494.355469, 4710, 0 };
			rightCurveStrong1[2].SplinePointTan = { 8345.740234, 8295, 0 };
			rightCurveStrong1[3].SplinePointLoc = { 27210.000000, 16430, 0 };
			rightCurveStrong1[3].SplinePointTan = { 4715.644531, 11720, 0 };
			rightCurveStrong2.AddDefaulted(4);
			rightCurveStrong2[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong2[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong2[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong2[1].SplinePointTan = { 11062.177734, 1795, 0 };
			rightCurveStrong2[2].SplinePointLoc = { 22124.355469, 3590, 0 };
			rightCurveStrong2[2].SplinePointTan = { 7995.740234, 8385, 0 };
			rightCurveStrong2[3].SplinePointLoc = { 26510, 16610, 0 };
			rightCurveStrong2[3].SplinePointTan = { 4385.644531, 13020, 0 };
			rightCurveStrong3.AddDefaulted(4);
			rightCurveStrong3[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong3[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong3[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong3[1].SplinePointTan = { 11272.177734, 1315, 0 };
			rightCurveStrong3[2].SplinePointLoc = { 22544.355469, 2630, 0 };
			rightCurveStrong3[2].SplinePointTan = { 7600.740234, 8345, 0 };
			rightCurveStrong3[3].SplinePointLoc = { 25720, 16530, 0 };
			rightCurveStrong3[3].SplinePointTan = { 3175.644531, 13900, 0 };
			rightCurveStrong4.AddDefaulted(4);
			rightCurveStrong4[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong4[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong4[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong4[1].SplinePointTan = { 11442.177734, 1095, 0 };
			rightCurveStrong4[2].SplinePointLoc = { 22884.355469, 2190, 0 };
			rightCurveStrong4[2].SplinePointTan = { 7250.740234, 8350, 0 };
			rightCurveStrong4[3].SplinePointLoc = { 25020, 16540, 0 };
			rightCurveStrong4[3].SplinePointTan = { 2135.644531, 14350, 0 };
			rightCurveStrong5.AddDefaulted(4);
			rightCurveStrong5[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong5[0].SplinePointTan = { 10511.702148, 0, 0 };
			rightCurveStrong5[1].SplinePointLoc = { 10511.702148, -147.367188, 0 };
			rightCurveStrong5[1].SplinePointTan = { 11083.736328, 2661.327393, 0 };
			rightCurveStrong5[2].SplinePointLoc = { 22167.472656, 5322.654785, 0 };
			rightCurveStrong5[2].SplinePointTan = { 8903.341797, 8228.677734, 0 };
			rightCurveStrong5[3].SplinePointLoc = { 28318.386719, 16309.988281, 0 };
			rightCurveStrong5[3].SplinePointTan = { 6150.914063, 10987.333984, 0 };
			rightCurveStrong6.AddDefaulted(4);
			rightCurveStrong6[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong6[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong6[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong6[1].SplinePointTan = { 11262.177734, 2375, 0 };
			rightCurveStrong6[2].SplinePointLoc = { 22524.355469, 4750, 0 };
			rightCurveStrong6[2].SplinePointTan = { 8925.740234, 7750, 0 };
			rightCurveStrong6[3].SplinePointLoc = { 28370, 15340, 0 };
			rightCurveStrong6[3].SplinePointTan = { 5845.644531, 10590, 0 };
			rightCurveStrong7.AddDefaulted(4);
			rightCurveStrong7[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong7[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong7[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong7[1].SplinePointTan = { 11432.177734, 2110, 0 };
			rightCurveStrong7[2].SplinePointLoc = { 22864.355469, 4220, 0 };
			rightCurveStrong7[2].SplinePointTan = { 9085.740234, 7250, 0 };
			rightCurveStrong7[3].SplinePointLoc = { 28690, 14340, 0 };
			rightCurveStrong7[3].SplinePointTan = { 5825.644531, 10120, 0 };
			rightCurveStrong8.AddDefaulted(4);
			rightCurveStrong8[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong8[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong8[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong8[1].SplinePointTan = { 11467.177734, 1590, 0 };
			rightCurveStrong8[2].SplinePointLoc = { 22934.355469, 3180, 0 };
			rightCurveStrong8[2].SplinePointTan = { 9410.740234, 6790, 0 };
			rightCurveStrong8[3].SplinePointLoc = { 29340, 13420, 0 };
			rightCurveStrong8[3].SplinePointTan = { 6405.644531, 10240, 0 };
			rightCurveStrong9.AddDefaulted(4);
			rightCurveStrong9[0].SplinePointLoc = { 0, 0, 0 };
			rightCurveStrong9[0].SplinePointTan = { 10518.519531, -160, 0 };
			rightCurveStrong9[1].SplinePointLoc = { 10518.519531, -160, 0 };
			rightCurveStrong9[1].SplinePointTan = { 11507.177734, 1460, 0 };
			rightCurveStrong9[2].SplinePointLoc = { 23014.355469, 2920, 0 };
			rightCurveStrong9[2].SplinePointTan = { 9525.740234, 6330, 0 };
			rightCurveStrong9[3].SplinePointLoc = { 29570, 12500, 0 };
			rightCurveStrong9[3].SplinePointTan = { 6555.644531, 9580, 0 };
			rightSBend1.AddDefaulted(4);
			rightSBend1[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend1[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend1[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend1[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend1[2].SplinePointLoc = { 23264.355469, 8330, 0 };
			rightSBend1[2].SplinePointTan = { 9440.740234, 1225, 0 };
			rightSBend1[3].SplinePointLoc = { 33130, 8270, 0 };
			rightSBend1[3].SplinePointTan = { 9865.644531, -60, 0 };
			rightSBend2.AddDefaulted(4);
			rightSBend2[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend2[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend2[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend2[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend2[2].SplinePointLoc = { 25794.355469, 8330, 0 };
			rightSBend2[2].SplinePointTan = { 9440.740234, 1225, 0 };
			rightSBend2[3].SplinePointLoc = { 35660, 8270, 0 };
			rightSBend2[3].SplinePointTan = { 9865.644531, -60, 0 };
			rightSBend3.AddDefaulted(4);
			rightSBend3[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend3[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend3[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend3[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend3[2].SplinePointLoc = { 28904.355469, 8330, 0 };
			rightSBend3[2].SplinePointTan = { 9440.740234, 1225, 0 };
			rightSBend3[3].SplinePointLoc = { 38770, 8270, 0 };
			rightSBend3[3].SplinePointTan = { 9865.644531, -60, 0 };
			rightSBend4.AddDefaulted(4);
			rightSBend4[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend4[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend4[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend4[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend4[2].SplinePointLoc = { 33604.355469, 8330, 0 };
			rightSBend4[2].SplinePointTan = { 9440.740234, 1225, 0 };
			rightSBend4[3].SplinePointLoc = { 43470, 8270, 0 };
			rightSBend4[3].SplinePointTan = { 9865.644531, -60, 0 };
			rightSBend5.AddDefaulted(4);
			rightSBend5[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend5[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend5[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend5[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend5[2].SplinePointLoc = { 21514.355469, 8330, 0 };
			rightSBend5[2].SplinePointTan = { 9440.740234, 1225, 0 };
			rightSBend5[3].SplinePointLoc = { 31380, 8270, 0 };
			rightSBend5[3].SplinePointTan = { 9865.644531, -60, 0 };
			rightSBend6.AddDefaulted(4);
			rightSBend6[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend6[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend6[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend6[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend6[2].SplinePointLoc = { 20304.355469, 8160, 0 };
			rightSBend6[2].SplinePointTan = { 8970.740234, 2045, 0 };
			rightSBend6[3].SplinePointLoc = { 30620, 8100, 0 };
			rightSBend6[3].SplinePointTan = { 10315.644531, -60, 0 };
			rightSBend7.AddDefaulted(4);
			rightSBend7[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend7[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend7[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend7[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend7[2].SplinePointLoc = { 19144.355469, 7320, 0 };
			rightSBend7[2].SplinePointTan = { 8970.740234, 2045, 0 };
			rightSBend7[3].SplinePointLoc = { 29460, 7260, 0 };
			rightSBend7[3].SplinePointTan = { 10315.644531, -60, 0 };
			rightSBend8.AddDefaulted(4);
			rightSBend8[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend8[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend8[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend8[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend8[2].SplinePointLoc = { 18304.355469, 6550, 0 };
			rightSBend8[2].SplinePointTan = { 8970.740234, 2045, 0 };
			rightSBend8[3].SplinePointLoc = { 27550, 7400, 0 };
			rightSBend8[3].SplinePointTan = { 10315.644531, -60, 0 };
			rightSBend9.AddDefaulted(4);
			rightSBend9[0].SplinePointLoc = { 0, 0, 0 };
			rightSBend9[0].SplinePointTan = { 12498.519531, 0, 0 };
			rightSBend9[1].SplinePointLoc = { 12498.519531, 0, 0 };
			rightSBend9[1].SplinePointTan = { 10757.177734, 1855, 0 };
			rightSBend9[2].SplinePointLoc = { 16234.355469, 7650, 0 };
			rightSBend9[2].SplinePointTan = { 7810.740234, 3405, 0 };
			rightSBend9[3].SplinePointLoc = { 26550, 7590, 0 };
			rightSBend9[3].SplinePointTan = { 10315.644531, -60, 0 };
		}
};

UCLASS()
class FYP_API AFYPSpline : public AActor, public IFYPGameEventInterface
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVars")
	TArray<USplineMeshComponent*> listofsplinemeshes;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void addNewChunk(int32 ci, UStaticMesh* tm);
	virtual void addNewChunk_Implementation(int32 ci, UStaticMesh* tm);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	void storeSplinePoints();
	virtual void storeSplinePoints_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyVars")
	TArray<FSplinePoints> chooseSpline();
	virtual TArray<FSplinePoints> chooseSpline_Implementation();

	virtual	void compSplinePointsToTrackArray(int32 nsp);

	virtual void RoundStart_Implementation() override;
	virtual void RoundEnd_Implementation() override;
	virtual void GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) override;
};
