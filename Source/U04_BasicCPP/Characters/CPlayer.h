#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class U04_BASICCPP_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Axis Event
private:
	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);

	void OnHorizontalLook(float InAxis);
	void OnVerticalLook(float InAxis);

	//Action Event
private:
	void OnRun();
	void OffRun();

public:
	UFUNCTION(BlueprintCallable)
		void SetBodyColor(FLinearColor InColor);

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;
};
