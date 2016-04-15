// Fill out your copyright notice in the Description page of Project Settings.

#include "FYP.h"
#include "TimeGate.h"


// Sets default values
ATimeGate::ATimeGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	timeGateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("timegate static mesh"));
	timeGateMesh->SetMobility(EComponentMobility::Movable);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> timeg(TEXT("/Game/Meshes/timegate.timegate"));
	timeGateMesh->SetStaticMesh(timeg.Object);
	timeGateMesh->OnComponentEndOverlap.AddDynamic(this, &ATimeGate::OnOverlapEnd);

	gateParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("timegate particle effect"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> pbar(TEXT("/Game/Particles/P_ParticleBarrier.P_ParticleBarrier"));
	gateParticle->Template = pbar.Object;
	gateParticle->AttachTo(timeGateMesh);
	gateTime = 20.0f;
}

// Called when the game starts or when spawned
void ATimeGate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeGate::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (isActive) {
		if (!(GetWorldTimerManager().IsTimerActive(THandle))) {
			StartCountDown_Implementation();
		}
	}

	if (GetWorldTimerManager().IsTimerActive(THandle)) {
		timeLeft = GetWorldTimerManager().GetTimerRemaining(THandle);
	}
}

//overlap event (when the player drives through it)
void ATimeGate::OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	float playRate = 1.f;
	float colourDist = 100000.f;
	FLinearColor newColour = UKismetMathLibrary::MakeColor(UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), 1.0f);
	UE_LOG(LogTemp, Log, TEXT("overlap begin!"));
	if (OtherActor->GetClass()->IsChildOf(ACar::StaticClass())) {
		UE_LOG(LogTemp, Log, TEXT("car overlap!"));
		IFYPGameEventInterface* TheInterface = NULL;
		TActorIterator< AActor > ActorItr(GetWorld());
		while (ActorItr)
		{
			//Try casting to the interface
			TheInterface = Cast<IFYPGameEventInterface>(*ActorItr);

			//Run the Event specific to the actor, if the actor has the interface
			if (TheInterface)
			{
				TheInterface->GateReached_Implementation(newColour, playRate, colourDist);
			}
			++ActorItr;
		}
		UE_LOG(LogTemp, Warning, TEXT("destroying gate"));
		this->Destroy();
	}
}

//countdown for when this is the active gate
void ATimeGate::StartCountDown_Implementation() {
	
	GetWorldTimerManager().SetTimer(THandle, this, &ATimeGate::AlertRoundEnd, gateTime);
}

void ATimeGate::AlertRoundEnd() {
	//Actor iterator from https://wiki.unrealengine.com/Interfaces_in_C%2B%2B#Creating_Global_Events
	IFYPGameEventInterface* TheInterface = NULL;
	TActorIterator< AActor > ActorItr(GetWorld());
	while (ActorItr)
	{
		//Try casting to the interface
		TheInterface = Cast<IFYPGameEventInterface>(*ActorItr);

		//Run the Event specific to the actor, if the actor has the interface
		if (TheInterface)
		{
			TheInterface->RoundEnd_Implementation();
		}
		++ActorItr;
	}
}


void ATimeGate::RoundStart_Implementation() {

}

void ATimeGate::RoundEnd_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("Game Over! (from timegate timer)"));
	if (isActive) {
		GetWorldTimerManager().ClearTimer(THandle);
	}
	AFYPPlayerController* playerCon = Cast<AFYPPlayerController>(GetWorld()->GetFirstPlayerController());
	playerCon->gameOver = true;
}

//we've passed the gate, so destroy it!
void ATimeGate::GateReached_Implementation(FLinearColor newColour, float playRate, float colourDist) {
}
