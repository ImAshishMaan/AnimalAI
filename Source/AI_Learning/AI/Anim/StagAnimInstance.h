#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "StagAnimInstance.generated.h"

class AAI_AnimalCharacter;

UCLASS()
class AI_LEARNING_API UStagAnimInstance : public UAnimInstance {
	GENERATED_BODY()

public:

	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	AAI_AnimalCharacter* Owner;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	float Direction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	bool IsHungry;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	bool IsEating;
};
