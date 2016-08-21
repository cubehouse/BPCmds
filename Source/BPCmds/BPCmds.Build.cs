// Copyright 2016 @cube. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class BPCmds : ModuleRules
	{
		public BPCmds(TargetInfo Target)
		{
			PrivateIncludePaths.AddRange(new string[] {
                "BPCmds/Private"
            });

			PublicDependencyModuleNames.AddRange(new string[]{
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore"
            });
		}
	}
}
