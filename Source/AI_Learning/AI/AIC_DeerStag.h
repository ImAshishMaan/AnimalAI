#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_DeerStag.generated.h"

/**
 * 
 */
UCLASS()
class AI_LEARNING_API AAIC_DeerStag : public AAIController {
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviourTree;
	
	virtual void BeginPlay() override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

public:
	
	void UpdateHunger(bool IsHungry);
	
};
