/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides additional methods for interacting with Steam Users.
* https://partner.steamgames.com/doc/webapi/IPlayerService
*/

#include "PlayerService/WebPlayerService.h"
#include "PlayerService/WebPlayerServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebPlayerService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebPlayerService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebPlayerService::GetRecentlyPlayedGames(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 count)
{
	FOnlineAsyncTaskSteamCoreWebGetRecentlyPlayedGames* Task = new FOnlineAsyncTaskSteamCoreWebGetRecentlyPlayedGames(this, callback, key, steamID, count);
	QueueAsyncTask(Task);
}

void UWebPlayerService::GetOwnedGames(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, bool bIncludeAppInfo, bool bIncludePlayedFreeGames, TArray<int32> filter)
{
	FOnlineAsyncTaskSteamCoreWebGetOwnedGames* Task = new FOnlineAsyncTaskSteamCoreWebGetOwnedGames(this, callback, key, steamID, bIncludeAppInfo, bIncludePlayedFreeGames, filter);
	QueueAsyncTask(Task);
}

void UWebPlayerService::GetSteamLevel(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetSteamLevel* Task = new FOnlineAsyncTaskSteamCoreWebGetSteamLevel(this, callback, key, steamID);
	QueueAsyncTask(Task);
}

void UWebPlayerService::GetBadges(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetBadges* Task = new FOnlineAsyncTaskSteamCoreWebGetBadges(this, callback, key, steamID);
	QueueAsyncTask(Task);
}

void UWebPlayerService::GetCommunityBadgeProgress(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 badgeID)
{
	FOnlineAsyncTaskSteamCoreWebGetCommunityBadgeProgress* Task = new FOnlineAsyncTaskSteamCoreWebGetCommunityBadgeProgress(this, callback, key, steamID, badgeID);
	QueueAsyncTask(Task);
}

void UWebPlayerService::IsPlayingSharedGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appIDplaying)
{
	FOnlineAsyncTaskSteamCoreWebIsPlayingSharedGame* Task = new FOnlineAsyncTaskSteamCoreWebIsPlayingSharedGame(this, callback, key, steamID, appIDplaying);
	QueueAsyncTask(Task);
}
