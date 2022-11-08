// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_EnemyCanAttack.generated.h"

/**
 * 
 */
UCLASS()
class ANGRYMAN_API UBTDecorator_EnemyCanAttack : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTDecorator_EnemyCanAttack();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)const override;

};
