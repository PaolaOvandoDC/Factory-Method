// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo.h"

ABloqueLadrillo::ABloqueLadrillo()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
}

void ABloqueLadrillo::MostrarPropiedades()
{
    UE_LOG(LogTemp, Warning, TEXT("Este es un bloque individual."));
	UE_LOG(LogTemp, Warning, TEXT("Tipo de bloque: Ladrillo"));

}

void ABloqueLadrillo::DestruirBloque()
{
	Destroy(); // Destruir el bloque
	UE_LOG(LogTemp, Warning, TEXT("Bloque de ladrillo destruido."));
}

void ABloqueLadrillo::BeginPlay()
{
    Super::BeginPlay();

}

