/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*/

#include "CoreMinimal.h"
#include "Misc/Paths.h"

#pragma once

static FString IniConfig = FPaths::EngineConfigDir() / "BaseEditor.ini";
static constexpr auto PLUGIN_NAME = TEXT("SteamCore");
static constexpr auto MODULE_NAME = TEXT("SteamCoreEditor");
static constexpr auto PLUGIN_INI_CONFIG_NAME = TEXT("SteamCoreVersion");
static constexpr auto AUTHOR_URL = TEXT("https://eeldev.com");
static constexpr auto PLUGIN_URL = TEXT("https://eeldev.com/index.php/category/unreal-engine/steamcore/feed/");
static constexpr auto PLUGIN_DOCUMENTATION = TEXT("https://eeldev.com/index.php/docs/steamcore/");
static constexpr auto PLUGIN_LAUNCHER_URL = TEXT("com.epicgames.launcher://ue/marketplace/product/steamcore");

FORCEINLINE FString PrepareXmlString(FString String)
{
	String = String.TrimStartAndEnd();
	String.RemoveFromStart("<title>");
	String.RemoveFromEnd("</title>");
	String.RemoveFromStart("<link>");
	String.RemoveFromEnd("</link>");
	String.RemoveFromStart("<lastBuildDate>");
	String.RemoveFromEnd("</lastBuildDate>");

	return String;
}

struct FXmlItemData
{
	FString Title;
	FString Link;

	FXmlItemData() = default;

	FXmlItemData(const TArray<FString>& inArr)
	{
		for (int32 i = 0; i < inArr.Num(); i++)
		{
			FString Value = inArr[i].TrimStartAndEnd();

			if (Value.Contains("<title>"))
			{
				Title = PrepareXmlString(Value);
			}
			else if (Value.Contains("<link>"))
			{
				Link = PrepareXmlString(Value);
			}
		}
	}

	void ToString()
	{
		UE_LOG(LogTemp, Warning, TEXT("Title: %s, Link: %s"), *Title, *Link);
	}
};
