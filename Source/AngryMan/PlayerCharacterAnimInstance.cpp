// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UPlayerCharacterAnimInstance::UPlayerCharacterAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/AngryMan/SK_Lich_Full_Skeleton_Montage.SK_Lich_Full_Skeleton_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<ACharacter>(Pawn);
		if(Character)
		{
			isFalling = Character->GetMovementComponent()->IsFalling();
		}
	}
}

void UPlayerCharacterAnimInstance::PlayAttackMontage()
{
//	UE_LOG(LogTemp, Log, TEXT("몽타주"));
	Montage_Play(AttackMontage, 1.f);
}

void UPlayerCharacterAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UPlayerCharacterAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	return FName(*FString::Printf(TEXT("Attack%d"),SectionIndex));
}

void UPlayerCharacterAnimInstance::AnimNotify_AttackHit()
{
	//UE_LOG(LogTemp, Log, TEXT("AnimNotify_AttackHit"));

	//구독자패턴
	OnAttackHit.Broadcast();
}
