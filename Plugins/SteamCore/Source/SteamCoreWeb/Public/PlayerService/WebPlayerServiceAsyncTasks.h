/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides additional methods for interacting with Steam Users.
* https://partner.steamgames.com/doc/webapi/IPlayerService
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetRecentlyPlayedGames
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetRecentlyPlayedGames : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetRecentlyPlayedGames(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 count)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPlayerService", "GetRecentlyPlayedGames", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("count", count);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetRecentlyPlayedGames() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetOwnedGames
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetOwnedGames : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetOwnedGames(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, bool bIncludeAppInfo, bool bIncludePlayedFreeGames, TArray<int32> filter)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPlayerService", "GetOwnedGames", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("include_appinfo", bIncludeAppInfo);
		m_RequestString.Add("include_played_free_games", bIncludePlayedFreeGames);
		m_RequestString.Add("appids_filter", filter);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetOwnedGames() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetSteamLevel
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetSteamLevel : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetSteamLevel(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPlayerService", "GetSteamLevel", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetSteamLevel() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetBadges
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetBadges : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetBadges(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPlayerService", "GetBadges", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetBadges() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetCommunityBadgeProgress
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetCommunityBadgeProgress : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetCommunityBadgeProgress(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 badgeID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPlayerService", "GetCommunityBadgeProgress", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("badgeid", badgeID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetCommunityBadgeProgress() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebIsPlayingSharedGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebIsPlayingSharedGame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebIsPlayingSharedGame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appIDplaying)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPlayerService", "IsPlayingSharedGame", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid_playing", appIDplaying);
	}

private:
	FOnlineAsyncTaskSteamCoreWebIsPlayingSharedGame() = delete;
};
