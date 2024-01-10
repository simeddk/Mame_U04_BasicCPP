#include "CPrintLog.h"
#include "Global.h"

ACPrintLog::ACPrintLog()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACPrintLog::BeginPlay()
{
	Super::BeginPlay();
	
	CLog::Print(1);
	CLog::Print(2, 1);
	CLog::Print(3, 2, 20.f);
	CLog::Print(4, 2, 20.f, FColor::Emerald);
	CLog::Print("Test");
	CLog::Print(FVector(999, 999, 999));
	CLog::Print(GetActorRotation());
}

void ACPrintLog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

