#include "CStaticMesh.h"
#include "Components/StaticMeshComponent.h"

ACStaticMesh::ACStaticMesh()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	//RootComponent = Mesh;
	Mesh->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/StaticMeshes/SM_Cube.SM_Cube'"));
	
	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}

void ACStaticMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

