// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaDeBloques.generated.h"
class ABloque; // Forward declaration of ABloque class
UCLASS()
class BOMBERMAN1_API AFabricaDeBloques : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaDeBloques();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ABloque* CrearBloque(FString tipoBloque, FVector posicion);

};
