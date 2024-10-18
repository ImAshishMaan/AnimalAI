#include "StagAnimInstance.h"
#include "AI_Learning/AI/AI_AnimalCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UStagAnimInstance::NativeUpdateAnimation(float DeltaTime) {
	Super::NativeUpdateAnimation(DeltaTime);
	if(Owner == nullptr) {
		Owner = Cast<AAI_AnimalCharacter>(TryGetPawnOwner());
	}

	if(!Owner) {
		return;
	}

	Speed = Owner->GetMovementComponent()->Velocity.Size();
	Direction = UKismetMathLibrary::Dot_VectorVector(Owner->GetMovementComponent()->Velocity, Owner->GetActorForwardVector());

	IsHungry = Owner->GetIsHungry();

	IsEating = Owner->GetIsEating();
	
}
