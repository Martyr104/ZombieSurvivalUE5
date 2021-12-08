/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to Steam Community features.
* https://partner.steamgames.com/doc/webapi/ISteamGameServerStats
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetGameServerPlayerStatsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetGameServerPlayerStatsForGame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetGameServerPlayerStatsForGame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString gameID, int32 appID, FString rangeStart, FString rangeEnd, int32 MaxResults)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamGameServerStats", "GetGameServerPlayerStatsForGame", key, 1, EVerb::GET)
	{
		m_RequestString.Add("gameid", gameID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("rangestart", rangeStart);
		m_RequestString.Add("rangeend", rangeEnd);
		m_RequestString.Add("MaxResults", MaxResults);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetGameServerPlayerStatsForGame() = delete;
};
