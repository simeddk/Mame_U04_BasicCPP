#include "CBlueprintOverride.h"
#include "Global.h"

void ACBlueprintOverride::BeginPlay()
{
	OnActorBeginOverlap.AddDynamic(this, &ACBlueprintOverride::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACBlueprintOverride::ActorEndOverlap);
}

void ACBlueprintOverride::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ChangePlayerColor();
}

void ACBlueprintOverride::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
}
