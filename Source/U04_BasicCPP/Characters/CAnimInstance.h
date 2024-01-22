#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class U04_BASICCPP_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character")
		float Speed;

	//Todo. [[Player->GetRifle()]]->IsEquipped();
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Rifle")
		bool bEquipped;

private:
	class ACPlayer* Player;
};
