// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_EnemyCanAttack.h"
#include "EnemyAIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_EnemyCanAttack::UBTDecorator_EnemyCanAttack()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_EnemyCanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return false;

	auto Target = Cast<APlayerCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	return bResult && Target->GetDistanceTo(CurrentPawn) <= 200.f;
}
