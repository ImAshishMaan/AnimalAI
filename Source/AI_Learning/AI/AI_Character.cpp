#include "AI_Character.h"
#include "AIC_DeerStag.h"

AAI_Character::AAI_Character() {
	PrimaryActorTick.bCanEverTick = true;

	AnimalMesh = GetMesh();

	HungryAmount = MaxHungryAmount;
	HungerDecayRate = 1;
	
}

void AAI_Character::BeginPlay() {
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(HungryTimerHandle, this, &AAI_Character::StartHungryTimer, 1.0f, true);
}

void AAI_Character::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AAI_Character::StartHungryTimer() {
	if (HungryAmount > 0) {
		HungryAmount--;
	}

	if(HungryAmount <= 0 && IsHungry == false) {
		HungryAmount = 0;
		IsHungry = true;
		OnHungryTimerFinished();
	}
}

void AAI_Character::OnHungryTimerFinished() {
	AAIC_DeerStag* AIC = Cast<AAIC_DeerStag>(GetController());
	if(AIC) {
		AIC->UpdateHunger(IsHungry);
	}
}

void AAI_Character::StartEatingTimer() {
	IsEating = true;
	GetWorld()->GetTimerManager().SetTimer(EatingTimerHandle, this, &AAI_Character::OnEatingTimerFinished, 4.0f, false);
}

void AAI_Character::OnEatingTimerFinished() {
	IsEating = false;
	HungryAmount = MaxHungryAmount;
	IsHungry = false;
	AAIC_DeerStag* AIC = Cast<AAIC_DeerStag>(GetController());
	if(AIC) {
		AIC->UpdateHunger(IsHungry);
	}
}
