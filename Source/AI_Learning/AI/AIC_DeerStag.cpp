#include "AIC_DeerStag.h"

#include "AI_Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"

void AAIC_DeerStag::BeginPlay() {
	Super::BeginPlay();

	if(BehaviourTree) {
		RunBehaviorTree(BehaviourTree);
	}
}

void AAIC_DeerStag::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) {
	Super::OnMoveCompleted(RequestID, Result);

	if(Result.IsSuccess()) {
		AAI_Character* AIChar = Cast<AAI_Character>(GetPawn());
		if(AIChar && AIChar->GetIsHungry() && AIChar->GetIsEating() == false) {
			AIChar->StartEatingTimer();
		}
	} else if(Result.IsFailure()) {
		// Handle failure (could not reach the destination)
	} else if(Result.IsInterrupted()) {
		// Handle aborted (movement stopped before reaching the destination)
	}
}

void AAIC_DeerStag::UpdateHunger(bool IsHungry) {
	GetBlackboardComponent()->SetValueAsBool("IsHungry", IsHungry);
}
