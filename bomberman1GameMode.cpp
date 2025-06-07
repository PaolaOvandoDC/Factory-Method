// Copyright Epic Games, Inc. All Rights Reserved.

#include "bomberman1GameMode.h"
#include "bomberman1Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueMadera.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "FabricaDeBloques.h"
#include "GrupoBloques.h"
#include "iBloque.h"
#include "Engine/World.h"


Abomberman1GameMode::Abomberman1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void Abomberman1GameMode::BeginPlay()
{
	Super::BeginPlay();

	if (!BloqueLadrilloClass || !GrupoBloquesClass)
	{
		UE_LOG(LogTemp, Error, TEXT("Las clases BloqueMadera o GrupoBloques no están asignadas en el editor."));
		return;
	}

	//crea un bloque individual
	FActorSpawnParameters SpawnParams;
	FVector PosicionBloque(0.f, 0.f, 100.f); // Altura suficiente para que no esté bajo el suelo
	FRotator Rotacion = FRotator::ZeroRotator;

	ABloqueLadrillo* Bloque1 = GetWorld()->SpawnActor<ABloqueLadrillo>(BloqueLadrilloClass, PosicionBloque, Rotacion, SpawnParams);


	//crea un grupo de bloques
	FVector PosicionGrupo(200.f, 0.f, 100.f); // Separado del bloque individual
	AGrupoBloques* Grupo = GetWorld()->SpawnActor<AGrupoBloques>(GrupoBloquesClass, PosicionBloque, Rotacion, SpawnParams);

	if (Grupo && Bloque1)
	{
		Grupo->AgregarBloque(Bloque1);

		// Mostrar propiedades (Composite llama a sus hijos)
		Grupo->MostrarPropiedades();

		// Destruir el grupo (también destruye los bloques dentro)
		Grupo->DestruirBloque();
	}


	AFabricaDeBloques* FabricaDeBloques = GetWorld()->SpawnActor<AFabricaDeBloques>(AFabricaDeBloques::StaticClass());

	
}
void Abomberman1GameMode::SpawnBloque(FVector posicionBloque, int32 tipoBloque)
{
	//ABloque* BloqueGenerado = nullptr;
	

	ABloque* BloqueGenerado = nullptr;
	// Elegir tipo de bloque basado en el valor
	if (tipoBloque == 4)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = FabricadeBloques->CrearBloque("Acero", posicionBloque);
	}
	else if (tipoBloque == 3)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = FabricadeBloques->CrearBloque("Concreto", posicionBloque);
	}
	else if (tipoBloque == 2)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = FabricadeBloques->CrearBloque("Ladrillo", posicionBloque);
	}
	else if (tipoBloque == 1)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = FabricadeBloques->CrearBloque("Madera", posicionBloque);
	}
	else {
		return;
	}
	// Agregar el bloque al TArray si fue generado
	if (BloqueGenerado)
	{
		aBloques.Add(BloqueGenerado);
	}
}
void Abomberman1GameMode::DestruirBloque()
{
	//Seleccionar aleatoriamente un bloque del array ABloques para su eliminacion
	int numeroBloques = aBloques.Num();
	int NumeroAleatorio = FMath::RandRange(1, numeroBloques);

	if (aBloques.Num() > 0)
	{
		BloqueActual = aBloques[NumeroAleatorio]; // Obtén el primer bloque
		if (BloqueActual)
		{
			BloqueActual->Destroy();
			// Realiza operaciones con el bloque
			//primerBloque->SetActorLocation(FVector(100.0f, 100.0f, 100.0f));
		}
	}
}
