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

	timeGateMesh->OnComponentBeginOverlap.AddDynamic(this, &ATimeGate::OnOverlapBegin);
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

	if (GetWorldTimerManager().IsTimerActive(THandle)) {
		timeLeft = GetWorldTimerManager().GetTimerRemaining(THandle);
	}

	

}

//overlap event (when the player drives through it)
void ATimeGate::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	UE_LOG(LogTemp, Warning, TEXT("overlap begin!"));
	ACar* castCar = Cast<ACar>(OtherActor->GetClass());
	if (castCar) {
		UE_LOG(LogTemp, Warning, TEXT("car overlap!"));
		IFYPGameEventInterface* TheInterface = NULL;
		TActorIterator< AActor > ActorItr(GetWorld());
		while (ActorItr)
		{
			//Try casting to the interface
			TheInterface = Cast<IFYPGameEventInterface>(*ActorItr);

			//Run the Event specific to the actor, if the actor has the interface
			if (TheInterface)
			{
				TheInterface->GateReached_Implementation();
			}
			++ActorItr;
		}
	}
	GateReached_Implementation();
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
			TheInterface->RoundEnd();
		}
		++ActorItr;
	}
}

void ATimeGate::RoundStart_Implementation() {

}

void ATimeGate::RoundEnd_Implementation() {

}

//we've passed the gate, so destroy it!
void ATimeGate::GateReached_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("destroying gate"));
	this->Destroy();
}
