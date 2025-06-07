// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "iBloque.h"
#include "BloqueLadrillo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN1_API ABloqueLadrillo : public ABloque, public IiBloque
{
	GENERATED_BODY()
public:
	ABloqueLadrillo();
	// Implementación de la interfaz IiBloque
	virtual void MostrarPropiedades() override;
	virtual void DestruirBloque() override;

protected:
	virtual void BeginPlay() override;
	
};
