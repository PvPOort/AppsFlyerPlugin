// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AppsFlyer : ModuleRules
{
	public AppsFlyer(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"AppsFlyer/Public"
			});
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                "AppsFlyer/Private",
			});
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Analytics",
                "AnalyticsBlueprintLibrary",
            }
			);

        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Analytics",
                "AnalyticsBlueprintLibrary",
            }
			);
			
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			});

        PublicIncludePathModuleNames.Add("Analytics");

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PublicFrameworks.AddRange(new string[]
            {
                "Foundation",
                "UIKit",
                "CoreFoundation",
            });

            AddThirdPartyPrivateStaticDependencies(Target, "AppsFlyerSDK");
        }
    }
}
