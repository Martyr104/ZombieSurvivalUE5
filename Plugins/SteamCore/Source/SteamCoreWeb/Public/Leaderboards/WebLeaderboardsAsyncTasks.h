/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access Steam leaderboards.
* https://partner.steamgames.com/doc/webapi/ISteamLeaderboards
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebDeleteLeaderboard
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebDeleteLeaderboard : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebDeleteLeaderboard(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString name)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamLeaderboards", "DeleteLeaderboard", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("name", name);
	}

private:
	FOnlineAsyncTaskSteamCoreWebDeleteLeaderboard() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebDeleteLeaderboard")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebFindOrCreateLeaderboard
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebFindOrCreateLeaderboard : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebFindOrCreateLeaderboard(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString name, FString sortMethod, FString displayType, bool bCreateIfNotFound, bool bOnlyTrustedWrites, bool bOnlyFriendsReads)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamLeaderboards", "FindOrCreateLeaderboard", key, 2, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("name", name);
		m_RequestString.Add("sortmethod", sortMethod);
		m_RequestString.Add("displaytype", displayType);
		m_RequestString.Add("createifnotfound", bCreateIfNotFound);
		m_RequestString.Add("onlytrustedwrites", bOnlyTrustedWrites);
		m_RequestString.Add("onlyfriendsreads", bOnlyFriendsReads);
		m_RequestString.Add("name", name);
	}

private:
	FOnlineAsyncTaskSteamCoreWebFindOrCreateLeaderboard() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebFindOrCreateLeaderboard")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetLeaderboardEntries
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetLeaderboardEntries : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetLeaderboardEntries(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 rangeStart, int32 rangeEnd, int32 leaderboardID, int32 dataRequest, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamLeaderboards", "GetLeaderboardEntries", key)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("rangestart", rangeStart);
		m_RequestString.Add("rangeend", rangeEnd);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("leaderboardid", leaderboardID);
		m_RequestString.Add("datarequest", dataRequest);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetLeaderboardEntries() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetLeaderboardEntries")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetLeaderboardsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetLeaderboardsForGame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetLeaderboardsForGame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamLeaderboards", "GetLeaderboardsForGame", key, 2, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetLeaderboardsForGame() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetLeaderboardsForGame")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebResetLeaderboard
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebResetLeaderboard : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebResetLeaderboard(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 leaderbordID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamLeaderboards", "ResetLeaderboard", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("leaderboardid", leaderbordID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebResetLeaderboard() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebResetLeaderboard")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebSetLeaderboardScore
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebSetLeaderboardScore : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebSetLeaderboardScore(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 leaderbordID, FString steamID, int32 score, FString scoreMethod, TArray<uint8> details)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamLeaderboards", "SetLeaderboardScore", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("leaderboardid", leaderbordID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("score", score);
		m_RequestString.Add("scoremethod", scoreMethod);
		m_RequestString.Add("details", details);
	}

private:
	FOnlineAsyncTaskSteamCoreWebSetLeaderboardScore() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebSetLeaderboardScore")); }
};
