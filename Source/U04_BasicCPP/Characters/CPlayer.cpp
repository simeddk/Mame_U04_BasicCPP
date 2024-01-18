#include "CPlayer.h"
#include "Global.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CAnimInstance.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	//MeshComp
	USkeletalMesh* meshAsset;
	CHelpers::GetAsset<USkeletalMesh>(&meshAsset, "SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'");
	GetMesh()->SetSkeletalMesh(meshAsset);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	TSubclassOf<UCAnimInstance> animClass;
	CHelpers::GetClass<UCAnimInstance>(&animClass, "AnimBlueprint'/Game/Player/ABP_CPlayer.ABP_CPlayer_C'");
	GetMesh()->SetAnimInstanceClass(animClass);

	//SpringArmComp
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->TargetArmLength = 200.f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;

	//CameraComp
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	//Movement
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);

	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayer::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayer::OnVerticalLook);

	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Pressed, this, &ACPlayer::OnRun);
	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Released, this, &ACPlayer::OffRun);
}

void ACPlayer::OnMoveForward(float InAxis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnMoveRight(float InAxis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnHorizontalLook(float InAxis)
{
	AddControllerYawInput(InAxis);
}

void ACPlayer::OnVerticalLook(float InAxis)
{
	AddControllerPitchInput(InAxis);
}

void ACPlayer::OnRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

void ACPlayer::OffRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
}

void ACPlayer::SetBodyColor(FLinearColor InColor)
{

}
