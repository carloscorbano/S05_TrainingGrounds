// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIRouteConfiguration.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TRAININGGROUNDS_API UAIRouteConfiguration : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolRoute() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolRoute;
};
