#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpawner.generated.h"

UCLASS()
class U04_BASICCPP_API ACSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSpawner();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
		UClass* ClassRef;


};
