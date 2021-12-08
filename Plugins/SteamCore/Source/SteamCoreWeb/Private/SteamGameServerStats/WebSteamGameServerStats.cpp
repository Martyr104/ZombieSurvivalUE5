/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to Steam Community features.
* https://partner.steamgames.com/doc/webapi/ISteamGameServerStats
*/

#include "SteamGameServerStats/WebSteamGameServerStats.h"
#include "SteamGameServerStats/WebSteamGameServerStatsAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebSteamGameServerStats::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebSteamGameServerStats::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebSteamGameServerStats::GetGameServerPlayerStatsForGame(const FOnSteamCoreWebCallback& callback, FString key, FString gameID, int32 appID, FString rangeStart, FString rangeEnd, int32 MaxResults /*= 1000*/)
{
	FOnlineAsyncTaskSteamCoreWebGetGameServerPlayerStatsForGame* Task = new FOnlineAsyncTaskSteamCoreWebGetGameServerPlayerStatsForGame(this, callback, key, gameID, appID, rangeStart, rangeEnd, MaxResults);
	QueueAsyncTask(Task);
}
