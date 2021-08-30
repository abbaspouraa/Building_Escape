// Copyright Amir Abbaspour 2021


#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get Player's view point
	FVector PlayerViewpointLocation;
	FVector PlayerViewPointRotation;

	GetWorld() -> GetFirstPlayerController() -> GetPlayerViewPoint(
		OUT PlayerViewpointLocation,
		OUT PlayerViewPointRotation
		);

	UE_LOG(LogTemp, Warning, TEXT("PlayerViewpointLocation: %s, PlayerViewPointRotation: %s"), 
	PlayerViewpointLocation.ToString(), PlayerViewPointRotation.ToString());

	// Ray-cast out to a certain distance (Reach)

	// See what it hits
}

