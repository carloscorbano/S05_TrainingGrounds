// Fill out your copyright notice in the Description page of Project Settings.

#include "NextWaypoint.h"
#include "AIController.h"
#include "PatrolGuard.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//Get Patrol Points
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetControlledPawn();
	auto PatrolGuard = Cast<APatrolGuard>(ControlledPawn);
	auto PatrolPoints = PatrolGuard->PatrolRouteCPP;

	//Set the next waypoint
	auto Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	auto NextWaypoint = PatrolPoints[Index];
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, NextWaypoint);

	//Cycle
	auto NextIndex = (Index + 1)%PatrolPoints.Num();
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("EXECUTING TASK"));
	return EBTNodeResult::Succeeded;
}

