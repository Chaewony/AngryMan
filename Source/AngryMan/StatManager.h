// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "StatManager.generated.h"

USTRUCT()
struct FPlayerCharacterData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp;
};

/**
 * 
 */
UCLASS()
class ANGRYMAN_API UStatManager : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UStatManager();

	virtual void Init() override;

	FPlayerCharacterData* GetStatData(int32 Level);

private:
	UPROPERTY()
	class UDataTable* MyStats;
};
