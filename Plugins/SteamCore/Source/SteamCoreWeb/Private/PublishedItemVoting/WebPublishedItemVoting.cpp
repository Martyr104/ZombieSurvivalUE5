/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Allows partners to access the voting information of the content in their Steam Workshop.
* https://partner.steamgames.com/doc/webapi/IPublishedItemVoting
*/

#include "PublishedItemVoting/WebPublishedItemVoting.h"
#include "PublishedItemVoting/WebPublishedItemVotingAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebPublishedItemVoting::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebPublishedItemVoting::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebPublishedItemVoting::ItemVoteSummary(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, TArray<FString> publishedFileIDs)
{
	FOnlineAsyncTaskSteamCoreWebItemVoteSummary* Task = new FOnlineAsyncTaskSteamCoreWebItemVoteSummary(this, callback, key, steamID, appID, publishedFileIDs);
	QueueAsyncTask(Task);
}

void UWebPublishedItemVoting::UserVoteSummary(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, TArray<FString> publishedFileIDs)
{
	FOnlineAsyncTaskSteamCoreWebUserVoteSummary* Task = new FOnlineAsyncTaskSteamCoreWebUserVoteSummary(this, callback, key, steamID, publishedFileIDs);
	QueueAsyncTask(Task);
}
