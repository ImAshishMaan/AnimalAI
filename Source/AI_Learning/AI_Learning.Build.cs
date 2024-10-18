// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI_Learning : ModuleRules
{
	public AI_Learning(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "NavigationSystem" });
	}
}
