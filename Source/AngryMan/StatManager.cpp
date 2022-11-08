// Fill out your copyright notice in the Description page of Project Settings.


#include "StatManager.h"

UStatManager::UStatManager()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/AngryMan/Data/StatTable.StatTable'"));

	MyStats = DATA.Object;
}

void UStatManager::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("StatManager %d"), GetStatData(1)->Attack);
}

FPlayerCharacterData* UStatManager::GetStatData(int32 Level)
{
	return MyStats->FindRow<FPlayerCharacterData>(*FString::FromInt(Level), TEXT(""));
}
