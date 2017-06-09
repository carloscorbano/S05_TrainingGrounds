// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/AIWaypointFinder.h"
#include "AIController.h"
#include "AIRouteConfiguration.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UAIWaypointFinder::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//Get Patrol Points
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!ensure(BlackboardComponent)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = OwnerComp.GetAIOwner()->GetControlledPawn()->FindComponentByClass<UAIRouteConfiguration>()->GetPatrolRoute();
	
	//Protect Against Empty Array
	if (PatrolPoints.Num() == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("NPC Patrol without Patrol Points! NPC NAME = %s"), *OwnerComp.GetAIOwner()->GetControlledPawn()->GetName());
		return EBTNodeResult::Failed; 
	}

	//Set the next waypoint
	auto Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	auto AIWaypointFinder = PatrolPoints[Index];
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, AIWaypointFinder);

	//Cycle
	auto NextIndex = (Index + 1)%PatrolPoints.Num();
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("EXECUTING TASK"));
	return EBTNodeResult::Succeeded;
}

