// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class AppsFlyerSDK : ModuleRules
{
	public AppsFlyerSDK(TargetInfo Target)
	{
		Type = ModuleType.External;

		string sdkPath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));
		PublicIncludePaths.Add(Path.Combine(sdkPath, "include"));

		if (Target.Platform == UnrealTargetPlatform.IOS)
        {
			string configuration = "Release";
            string libPath = Path.Combine(sdkPath, "lib", configuration);
            string libFilePath = Path.Combine(libPath, "libAppsFlyerLib.a");

            PublicAdditionalLibraries.Add(libFilePath);
            PublicAdditionalShadowFiles.Add(libFilePath);

            PublicFrameworks.AddRange(
                new string[] {
                    "iAd",
                    "CFNetwork",
                    "Security",
                    "Foundation",
                });
        }
    }
}
