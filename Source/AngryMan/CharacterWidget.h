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
	//생명주기가 달라서 메모리관련 문제 생길까봐 위크포인터로 관리
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HpBar; //블루프린트로 만들어진 위젯(hpbar) 바인딩
};
