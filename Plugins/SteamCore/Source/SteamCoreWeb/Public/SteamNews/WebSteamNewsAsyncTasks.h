/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamNews
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetNewsForApp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetNewsForApp : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetNewsForApp(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, int32 appID, int32 maxLength, int32 endDate, TArray<FString> feeds, int32 count)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamNews", "GetNewsForApp", "", 2, EVerb::GET, true)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("maxlength", maxLength);
		m_RequestString.Add("enddate", endDate);
		m_RequestString.Add("count", count);

		FString m_Feeds = "";

		for (int32 i = 0; i < feeds.Num(); i++)
		{
			m_Feeds.Append(FString::Printf(TEXT(",%s"), *feeds[i]));
		}

		m_RequestString.Add("feeds", m_Feeds);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetNewsForApp() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetNewsForAppAuthed
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetNewsForAppAuthed : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetNewsForAppAuthed(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 maxLength, int32 endDate, TArray<FString> feeds, int32 count)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamNews", "GetNewsForAppAuthed", key, 2, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("maxlength", maxLength);
		m_RequestString.Add("enddate", endDate);
		m_RequestString.Add("count", count);

		FString m_Feeds = "";

		for (int32 i = 0; i < feeds.Num(); i++)
		{
			m_Feeds.Append(FString::Printf(TEXT(",%s"), *feeds[i]));
		}

		m_RequestString.Add("feeds", m_Feeds);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetNewsForAppAuthed() = delete;
};
