// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UEnemyCharacterAnimInstance::UEnemyCharacterAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/AngryMan/SK_ElfCharacter_Montage.SK_ElfCharacter_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UEnemyCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			isFalling = Character->GetMovementComponent()->IsFalling();
		}
	}
}

void UEnemyCharacterAnimInstance::PlayAttackMontage()
{
	if(this!=NULL)
		Montage_Play(AttackMontage, 1.f);
}

void UEnemyCharacterAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UEnemyCharacterAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	return FName(*FString::Printf(TEXT("EnemyAttack%d"), SectionIndex));
}

void UEnemyCharacterAnimInstance::AnimNotify_EnemyAttackHit()
{
	OnEnemyAttackHit.Broadcast();
}
