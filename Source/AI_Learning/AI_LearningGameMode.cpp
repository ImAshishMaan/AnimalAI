// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_LearningGameMode.h"
#include "AI_LearningCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_LearningGameMode::AAI_LearningGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
