// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/AIRouteConfiguration.h"

TArray<AActor*> UAIRouteConfiguration::GetPatrolRoute() const
{
	return PatrolRoute;
}