// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "NextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class S05_TRAININGGROUNDS_API UNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Patrol Route")
	FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category = "Patrol Route")
	FBlackboardKeySelector WaypointKey;

};
