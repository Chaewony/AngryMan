// Copyright Epic Games, Inc. All Rights Reserved.


#include "AngryManGameModeBase.h"
#include "PlayerCharacter.h"
AAngryManGameModeBase::AAngryManGameModeBase()
{
//	DefaultPawnClass = APlayerCharacter::StaticClass();
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/AngryMan/BP_PlayerCharacter.BP_PlayerCharacter_C'"));

	if (BP_Char.Succeeded()) {
		DefaultPawnClass = BP_Char.Class;
	}
}