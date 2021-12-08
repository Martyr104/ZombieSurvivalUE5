// Copyright (C) 2017-2021 | eelDev (Dry Eel Development)

using UnrealBuildTool;

public class SteamCoreWeb : ModuleRules
{
	public SteamCoreWeb(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivatePCHHeaderFile = "Private/SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h";

		PrivateDependencyModuleNames.AddRange
		(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Projects",
				"OnlineSubsystem",
				"HTTP",
				"JSON",
				"JSONUTILITIES"
			}
		);

		if (Target.Version.MinorVersion >= 26 || Target.Version.MajorVersion == 5)
			PrivateDependencyModuleNames.Add("DeveloperSettings");
	}
}