#include "CRifle.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

ACRifle::ACRifle()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateSceneComponent(this, &Mesh, "Mesh");

	USkeletalMesh* meshAsset;
	CHelpers::GetAsset(&meshAsset, "SkeletalMesh'/Game/Weapons/Meshes/AR4/SK_AR4.SK_AR4'");
	Mesh->SetSkeletalMesh(meshAsset);

	CHelpers::GetAsset(&GrabMontage, "/Game/Character/Animations/Rifle/Rifle_Grab_Montage");
	CHelpers::GetAsset(&UngrabMontage, "/Game/Character/Animations/Rifle/Rifle_Ungrab_Montage");
}

ACRifle* ACRifle::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters spawnParam;
	spawnParam.Owner = InOwner;

	return InWorld->SpawnActor<ACRifle>(spawnParam);
}


void ACRifle::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	
	if (!!OwnerCharacter)
		AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACRifle::Equip()
{
	CheckTrue(bEquipping);
	CheckTrue(bEquipped);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(GrabMontage);
}

void ACRifle::Begin_Equip()
{
	bEquipped = true;

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HandSocket);
}

void ACRifle::End_Equip()
{
	bEquipping = false;
}

void ACRifle::Unequip()
{
	CheckFalse(bEquipped);
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(UngrabMontage);
}

void ACRifle::Begin_Unequip()
{
	bEquipped = false;

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::End_Unequip()
{
	bEquipping = false;
}

void ACRifle::Begin_Aim()
{
	bAiming = true;
}

void ACRifle::End_Aim()
{
	bAiming = false;
}


