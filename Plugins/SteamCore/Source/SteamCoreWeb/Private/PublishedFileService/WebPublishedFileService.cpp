/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides additional methods for interacting with Steam Workshop items.
* https://partner.steamgames.com/doc/webapi/IPublishedFileService
*/

#include "PublishedFileService/WebPublishedFileService.h"
#include "PublishedFileService/WebPublishedFileServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebPublishedFileService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebPublishedFileService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebPublishedFileService::QueryFiles(const FOnSteamCoreWebCallback& callback, FString key, int32 queryType, int32 page, FString cursor, int32 numPerPage, int32 creatorAppID, int32 appID, FString requiredTags, FString excludedTags, bool bMatchAllTags, FString requiredFlags, FString omittedFlags, FString searchText, int32 fileType, FString childPublishedFileID, int32 days, bool bIncludeRecentVotesOnly, int32 cacheMaxAgeSeconds, int32 language, FString requiredKvTags, bool bTotalOnly, bool bIDsOnly, bool bReturnVoteData, bool bReturnTags, bool bReturnKvTags, bool bReturnPreviews, bool bReturnChildren, bool bReturnShortDescription, bool bReturnForSaleData, bool bReturnMetaData, int32 returnPlaytimeStats)
{
	FOnlineAsyncTaskSteamCoreWebQueryFiles* Task = new FOnlineAsyncTaskSteamCoreWebQueryFiles(this, callback, key, queryType, page, cursor, numPerPage, creatorAppID, appID, requiredTags, excludedTags, bMatchAllTags, requiredFlags, omittedFlags, searchText, fileType, childPublishedFileID, days, bIncludeRecentVotesOnly, cacheMaxAgeSeconds, language, requiredKvTags, bTotalOnly, bIDsOnly, bReturnVoteData, bReturnTags, bReturnKvTags, bReturnPreviews, bReturnChildren, bReturnShortDescription, bReturnForSaleData, bReturnMetaData, returnPlaytimeStats);
	QueueAsyncTask(Task);
}

void UWebPublishedFileService::SetDeveloperMetadata(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, FString metaData)
{
	FOnlineAsyncTaskSteamCoreWebSetDeveloperMetadata* Task = new FOnlineAsyncTaskSteamCoreWebSetDeveloperMetadata(this, callback, key, publishedFileID, appID, metaData);
	QueueAsyncTask(Task);
}

void UWebPublishedFileService::UpdateBanStatus(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, bool bBanned, FString reason)
{
	FOnlineAsyncTaskSteamCoreWebUpdateBanStatus* Task = new FOnlineAsyncTaskSteamCoreWebUpdateBanStatus(this, callback, key, publishedFileID, appID, bBanned, reason);
	QueueAsyncTask(Task);
}

void UWebPublishedFileService::UpdateIncompatibleStatus(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, bool bIncompatible)
{
	FOnlineAsyncTaskSteamCoreWebUpdateIncompatibleStatus* Task = new FOnlineAsyncTaskSteamCoreWebUpdateIncompatibleStatus(this, callback, key, publishedFileID, appID, bIncompatible);
	QueueAsyncTask(Task);
}

void UWebPublishedFileService::UpdateTags(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, FString addTags, FString removeTags)
{
	FOnlineAsyncTaskSteamCoreWebUpdateTags* Task = new FOnlineAsyncTaskSteamCoreWebUpdateTags(this, callback, key, publishedFileID, appID, addTags, removeTags);
	QueueAsyncTask(Task);
}
