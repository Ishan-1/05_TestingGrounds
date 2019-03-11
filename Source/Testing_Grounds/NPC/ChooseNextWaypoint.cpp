// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC/ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto IndexV=BlackBoardComp->GetValueAsInt(Index.SelectedKeyName);
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	BlackBoardComp->SetValueAsObject(Waypoint.SelectedKeyName,PatrolPoints[IndexV]);
	IndexV++;
	IndexV = IndexV%PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(Index.SelectedKeyName, IndexV);
	return EBTNodeResult::Succeeded;
}
