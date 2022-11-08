// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class ANGRYMAN_API UCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindHp(class UMyStatComponent* StatComp);
	void UpdateHp();

private:
	//�����ֱⰡ �޶� �޸𸮰��� ���� ������ ��ũ�����ͷ� ����
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HpBar; //�������Ʈ�� ������� ����(hpbar) ���ε�
};
