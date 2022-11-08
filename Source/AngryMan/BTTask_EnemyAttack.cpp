// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_EnemyAttack.h"
#include "PlayerCharacter.h"
#include "EnemyAIController.h"

UBTTask_EnemyAttack::UBTTask_EnemyAttack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_EnemyAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	
	auto PlayerCharacter = Cast<APlayerCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (PlayerCharacter == nullptr)
		return EBTNodeResult::Failed;

	PlayerCharacter->Attack();
	bIsAttacking = true;

	//OnAttckEnd가 broadcast되면 이 람다함수를 호출해줘
	PlayerCharacter->OnAttckEnd.AddLambda([this]()
		{
			bIsAttacking = false;
		});
	return Result;
}

void UBTTask_EnemyAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (bIsAttacking == false)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
