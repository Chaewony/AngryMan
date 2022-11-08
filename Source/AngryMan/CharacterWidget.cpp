// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

void UCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UCharacterWidget::UpdateHp);
}

void UCharacterWidget::UpdateHp()
{
	if(CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
