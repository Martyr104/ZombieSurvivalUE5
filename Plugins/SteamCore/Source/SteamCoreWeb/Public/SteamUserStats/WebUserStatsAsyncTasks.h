/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information about users.
* https://partner.steamgames.com/doc/webapi/ISteamUserStats
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetGlobalAchievementPercentagesForApp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetGlobalAchievementPercentagesForApp : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetGlobalAchievementPercentagesForApp(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString gameID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserStats", "GetGlobalAchievementPercentagesForApp", "", 2, EVerb::GET, true)
	{
		m_RequestString.Add("gameid", gameID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetGlobalAchievementPercentagesForApp() = delete;
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetGlobalStatsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetGlobalStatsForGame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetGlobalStatsForGame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, int32 appID, TArray<FString> names, int32 startDate, int32 endDate)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserStats", "GetGlobalStatsForGame", "", 1, EVerb::GET, true)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("count", names.Num());
		m_RequestString.Add("name", names);
		m_RequestString.Add("startdate", startDate);
		m_RequestString.Add("enddate", endDate);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetGlobalStatsForGame() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetNumberOfCurrentPlayers
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetNumberOfCurrentPlayers : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetNumberOfCurrentPlayers(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserStats", "GetNumberOfCurrentPlayers", "", 1, EVerb::GET, true)
	{
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetNumberOfCurrentPlayers() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetPlayerAchievements
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetPlayerAchievements : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetPlayerAchievements(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString language)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserStats", "GetPlayerAchievements", key, 1, EVerb::GET, true)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("language", language);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetPlayerAchievements() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetSchemaForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetSchemaForGame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetSchemaForGame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString language)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserStats", "GetSchemaForGame", key, 2, EVerb::GET, true)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("language", language);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetSchemaForGame() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetUserStatsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetUserStatsForGame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetUserStatsForGame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserStats", "GetUserStatsForGame", key, 2, EVerb::GET, true)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetUserStatsForGame() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebSetUserStatsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebSetUserStatsForGame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebSetUserStatsForGame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, TArray<FString> names, TArray<int32> values)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserStats", "SetUserStatsForGame", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("count", names.Num());
		m_RequestString.Add("name", names);
		m_RequestString.Add("value", values);
	}

private:
	FOnlineAsyncTaskSteamCoreWebSetUserStatsForGame() = delete;
};
