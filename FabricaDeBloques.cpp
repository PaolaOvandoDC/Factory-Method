// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaDeBloques.h"
#include "BloqueAcero.h"
#include "BloqueMadera.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "Engine/World.h"


// Sets default values
AFabricaDeBloques::AFabricaDeBloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaDeBloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaDeBloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
ABloque* AFabricaDeBloques::CrearBloque(FString tipoBloque, FVector posicion)
{
	if (tipoBloque.Equals("Acero")) {
		return GetWorld()->SpawnActor<ABloqueAcero>
			(ABloqueAcero::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Concreto")) {
		return GetWorld()->SpawnActor<ABloqueConcreto>
			(ABloqueConcreto::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Ladrillo")) {
		return GetWorld()->SpawnActor<ABloqueLadrillo>
			(ABloqueLadrillo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Madera")) {
		return GetWorld()->SpawnActor<ABloqueLadrillo>
			(ABloqueLadrillo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else return nullptr;
}

