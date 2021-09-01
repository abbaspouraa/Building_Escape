// Copyright Amir Abbaspour 2021


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

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

	// Checking for physics Handle Component
	FindPhysicsHandle();
	SetupInputComponent();
}



// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// if the physics handle is attached
	if (PhysicsHandle -> GrabbedComponent)
	{
		FVector PlayerViewpointLocation;
		FRotator PlayerViewPointRotation;

		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewpointLocation,
			OUT PlayerViewPointRotation
		);

		FVector LineTraceEnd = PlayerViewpointLocation + Reach * PlayerViewPointRotation.Vector();

		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}

	// the physics handle is attached.
		// Move the object we are holding

}

// ----------------------------------------------------------
//	DEFINED FUNCTIONS

// Setup

void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component is correctly set up."));
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No grab input component found."));
	}
}


// Grab and Release
void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grabber Press"));

	FVector PlayerViewpointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewpointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewpointLocation + Reach * PlayerViewPointRotation.Vector();

	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
		;
	// TODO, to only raycast when key is pressed.

	// Try and reach any actors with physics body collision channel set.
	// If we hit something then attach the physics handle.
	if (HitResult.GetActor())
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation
		(
			ComponentToGrab,
			NAME_None,
			LineTraceEnd,
			FRotator(0, 0, 0)
		);
	}

	// TODO attach physics handle
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grabber Release"));

	FHitResult HitResult = GetFirstPhysicsBodyInReach();

	if (HitResult.GetActor())
	{
		PhysicsHandle->ReleaseComponent();
	}
}


// Physics handle
void UGrabber::FindPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		// Physics is found.
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Object \"s%\" has no handle component."), *GetOwner()->GetName());
	}
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	FVector PlayerViewpointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewpointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewpointLocation + Reach * PlayerViewPointRotation.Vector();

	FHitResult Hit;
	// Ray-cast out to a certain distance (Reach)
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewpointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	if (Hit.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Hitted actor: %s"), *Hit.GetActor()->GetName());
	}

	return Hit;
}