// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "bomberman1GameMode.generated.h"
class ABloque; // Forward declaration of ABloque class
class AFabricaDeBloques;
UCLASS(minimalapi)
class Abomberman1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Abomberman1GameMode();
public:
	virtual void BeginPlay() override;

public:
	// Declarar la posición del siguiente bloque
	FVector posicionSiguienteBloque = FVector(1000.0f, 500.0f, 20.0f);

	// Declarar un mapa de bloques como un array bidimensional

	float XInicial = 500.00f;
	float YInicial = 500.00f;
	float AnchoBloque = 100.0f;
	float LargoBloque = 100.0f;
	ABloque* BloqueActual = nullptr;
	// Declarar un array de punteros a objetos de tipo BloqueMadera
	TArray<ABloque*> aBloques;

	FTimerHandle tHDestruirBloques;

	//void SpawnBloques();
	void SpawnBloque(FVector posicion, int32 tipoBloque);
	void DestruirBloque();

	AFabricaDeBloques* FabricadeBloques;
protected:
	// Clases que usarás para instanciar
	UPROPERTY(EditAnywhere, Category = "Bloques")
	TSubclassOf<class ABloqueLadrillo> BloqueLadrilloClass;

	UPROPERTY(EditAnywhere, Category = "Bloques")
	TSubclassOf<class AGrupoBloques> GrupoBloquesClass;
};



