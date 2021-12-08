/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information about users.
* https://partner.steamgames.com/doc/webapi/ISteamUserStats
*/

#include "SteamUserStats/WebUserStats.h"
#include "SteamUserStats/WebUserStatsAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebUserStats::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebUserStats::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebUserStats::GetGlobalAchievementPercentagesForApp(const FOnSteamCoreWebCallback& callback, FString gameID)
{
	FOnlineAsyncTaskSteamCoreWebGetGlobalAchievementPercentagesForApp* Task = new FOnlineAsyncTaskSteamCoreWebGetGlobalAchievementPercentagesForApp(this, callback, gameID);
	QueueAsyncTask(Task);
}

void UWebUserStats::GetGlobalStatsForGame(const FOnSteamCoreWebCallback& callback, int32 appID, TArray<FString> names, int32 startDate, int32 endDate)
{
	FOnlineAsyncTaskSteamCoreWebGetGlobalStatsForGame* Task = new FOnlineAsyncTaskSteamCoreWebGetGlobalStatsForGame(this, callback, appID, names, startDate, endDate);
	QueueAsyncTask(Task);
}

void UWebUserStats::GetNumberOfCurrentPlayers(const FOnSteamCoreWebCallback& callback, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebGetNumberOfCurrentPlayers* Task = new FOnlineAsyncTaskSteamCoreWebGetNumberOfCurrentPlayers(this, callback, appID);
	QueueAsyncTask(Task);
}

void UWebUserStats::GetPlayerAchievements(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString language)
{
	FOnlineAsyncTaskSteamCoreWebGetPlayerAchievements* Task = new FOnlineAsyncTaskSteamCoreWebGetPlayerAchievements(this, callback, key, steamID, appID, language);
	QueueAsyncTask(Task);
}

void UWebUserStats::GetSchemaForGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString language)
{
	FOnlineAsyncTaskSteamCoreWebGetSchemaForGame* Task = new FOnlineAsyncTaskSteamCoreWebGetSchemaForGame(this, callback, key, steamID, appID, language);
	QueueAsyncTask(Task);
}

void UWebUserStats::GetUserStatsForGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebGetUserStatsForGame* Task = new FOnlineAsyncTaskSteamCoreWebGetUserStatsForGame(this, callback, key, steamID, appID);
	QueueAsyncTask(Task);
}

void UWebUserStats::SetUserStatsForGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, TArray<FString> names, TArray<int32> values)
{
	FOnlineAsyncTaskSteamCoreWebSetUserStatsForGame* Task = new FOnlineAsyncTaskSteamCoreWebSetUserStatsForGame(this, callback, key, steamID, appID, names, values);
	QueueAsyncTask(Task);
}
