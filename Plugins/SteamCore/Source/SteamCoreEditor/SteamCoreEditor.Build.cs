/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/
*/

using UnrealBuildTool;

public class SteamCoreEditor : ModuleRules
{
	public SteamCoreEditor(ReadOnlyTargetRules rules) : base(rules)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"RenderCore",
				"Projects",
				"HTTP",
				"EditorStyle",
				"WebBrowser"
			}
		);
	}
}