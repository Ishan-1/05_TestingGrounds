// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto IndexV=BlackBoardComp->GetValueAsInt(Index.SelectedKeyName);
	UE_LOG(LogTemp,Warning,TEXT("Waypoint Index: %i"),IndexV)
	return EBTNodeResult::Succeeded;
}
