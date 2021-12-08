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

#include "Leaderboards/WebLeaderboards.h"
#include "Leaderboards/WebLeaderboardsAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebLeaderboards::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebLeaderboards::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebLeaderboards::DeleteLeaderboard(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString name)
{
	FOnlineAsyncTaskSteamCoreWebDeleteLeaderboard* Task = new FOnlineAsyncTaskSteamCoreWebDeleteLeaderboard(this, callback, key, appID, name);
	QueueAsyncTask(Task);
}

void UWebLeaderboards::FindOrCreateLeaderboard(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString name, FString sortMethod, FString displayType, bool bCreateIfNotFound, bool bOnlyTrustedWrites, bool bOnlyFriendsReads)
{
	FOnlineAsyncTaskSteamCoreWebFindOrCreateLeaderboard* Task = new FOnlineAsyncTaskSteamCoreWebFindOrCreateLeaderboard(this, callback, key, appID, name, sortMethod, displayType, bCreateIfNotFound, bOnlyTrustedWrites, bOnlyFriendsReads);
	QueueAsyncTask(Task);
}

void UWebLeaderboards::GetLeaderboardEntries(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 rangeStart, int32 rangeEnd, int32 leaderboardID, int32 dataRequest, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetLeaderboardEntries* Task = new FOnlineAsyncTaskSteamCoreWebGetLeaderboardEntries(this, callback, key, appID, rangeStart, rangeEnd, leaderboardID, dataRequest, steamID);
	QueueAsyncTask(Task);
}

void UWebLeaderboards::GetLeaderboardsForGame(const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebGetLeaderboardsForGame* Task = new FOnlineAsyncTaskSteamCoreWebGetLeaderboardsForGame(this, callback, key, appID);
	QueueAsyncTask(Task);
}

void UWebLeaderboards::ResetLeaderboard(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 leaderbordID)
{
	FOnlineAsyncTaskSteamCoreWebResetLeaderboard* Task = new FOnlineAsyncTaskSteamCoreWebResetLeaderboard(this, callback, key, appID, leaderbordID);
	QueueAsyncTask(Task);
}

void UWebLeaderboards::SetLeaderboardScore(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 leaderbordID, FString steamID, int32 score, TArray<uint8> details, FString scoreMethod)
{
	FOnlineAsyncTaskSteamCoreWebSetLeaderboardScore* Task = new FOnlineAsyncTaskSteamCoreWebSetLeaderboardScore(this, callback, key, appID, leaderbordID, steamID, score, scoreMethod, details);
	QueueAsyncTask(Task);
}
