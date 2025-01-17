#pragma once

#include "CoreMinimal.h"
#include "AIEnums.h"
#include "GameFramework/Character.h"
#include "AI_AnimalCharacter.generated.h"

class USkeletalMeshComponent;
class AActor;

UCLASS()
class AI_LEARNING_API AAI_AnimalCharacter : public ACharacter {
	GENERATED_BODY()

public:
	AAI_AnimalCharacter();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* AnimalMesh;

	UPROPERTY(EditAnywhere, Category = "AI")
	TSubclassOf<AActor> FoodActorBP;

	UPROPERTY()
	int32 HungryAmount;

	UPROPERTY(EditAnywhere)
	int32 MaxHungryAmount = 15;

	UPROPERTY(EditAnywhere)
	int32 HungerDecayRate;

	UPROPERTY()
	bool IsHungry = false;

	UPROPERTY()
	bool IsEating = false;

	UPROPERTY()
	AIState CurrentState = AIState::FreeMovement;

	UFUNCTION()
	void UpdateState(AIState NewState, bool what);
	void SetupHungryState(bool Hungry);
	void SetupEatingState(bool Eating);
	void SetupDeadState();
	void SetupFreeMovementState();

public:
	FTimerHandle HungryTimerHandle;
	void StartHungryTimer();
	void OnHungryTimerFinished();

	FTimerHandle EatingTimerHandle;
	void StartEatingTimer();
	void OnEatingTimerFinished();

	FORCEINLINE TSubclassOf<AActor> GetFoodActor() const { return FoodActorBP; }
	FORCEINLINE bool GetIsHungry() const { return IsHungry; }
	FORCEINLINE bool GetIsEating() const { return IsEating; }
	
};
