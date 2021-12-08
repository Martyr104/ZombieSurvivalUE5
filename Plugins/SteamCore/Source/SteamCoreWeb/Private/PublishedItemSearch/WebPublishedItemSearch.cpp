/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamPublishedItemSearch
*/

#include "PublishedItemSearch/WebPublishedItemSearch.h"
#include "PublishedItemSearch/WebPublishedItemSearchAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebSteamPublishedItemSearch::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebSteamPublishedItemSearch::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebSteamPublishedItemSearch::RankedByPublicationOrder(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
{
	FOnlineAsyncTaskSteamCoreWebRankedByPublicationOrder* Task = new FOnlineAsyncTaskSteamCoreWebRankedByPublicationOrder(this, callback, key, steamID, appID, startID, count, bHasAppAdminAccess, fileType, tag, userTag);
	QueueAsyncTask(Task);
}

void UWebSteamPublishedItemSearch::RankedByTrend(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, int32 days, TArray<FString> tag, TArray<FString> userTag)
{
	FOnlineAsyncTaskSteamCoreWebRankedByTrend* Task = new FOnlineAsyncTaskSteamCoreWebRankedByTrend(this, callback, key, steamID, appID, startID, count, bHasAppAdminAccess, fileType, days, tag, userTag);
	QueueAsyncTask(Task);
}

void UWebSteamPublishedItemSearch::RankedByVote(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
{
	FOnlineAsyncTaskSteamCoreWebRankedByVote* Task = new FOnlineAsyncTaskSteamCoreWebRankedByVote(this, callback, key, steamID, appID, startID, count, bHasAppAdminAccess, fileType, tag, userTag);
	QueueAsyncTask(Task);
}

void UWebSteamPublishedItemSearch::ResultSetSummary(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
{
	FOnlineAsyncTaskSteamCoreWebResultSetSummary* Task = new FOnlineAsyncTaskSteamCoreWebResultSetSummary(this, callback, key, steamID, appID, startID, bHasAppAdminAccess, fileType, tag, userTag);
	QueueAsyncTask(Task);
}
