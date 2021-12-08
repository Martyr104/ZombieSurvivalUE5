/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Primary interface for interacting with the Steam Workshop and User Generated Content (UGC).
* https://partner.steamgames.com/doc/webapi/IRemoteStorage
*/

#include "SteamRemoteStorage/WebRemoteStorage.h"
#include "SteamRemoteStorage/WebRemoteStorageAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebRemoteStorage::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebRemoteStorage::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebRemoteStorage::EnumerateUserPublishedFiles(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebEnumerateUserPublishedFiles* Task = new FOnlineAsyncTaskSteamCoreWebEnumerateUserPublishedFiles(this, callback, key, steamID, appID);
	QueueAsyncTask(Task);
}

void UWebRemoteStorage::EnumerateUserSubscribedFiles(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 listType)
{
	FOnlineAsyncTaskSteamCoreWebEnumerateUserSubscribedFiles* Task = new FOnlineAsyncTaskSteamCoreWebEnumerateUserSubscribedFiles(this, callback, key, steamID, appID, listType);
	QueueAsyncTask(Task);
}

void UWebRemoteStorage::GetCollectionDetails(const FOnSteamCoreWebCallback& callback, TArray<FString> publishedFileIDs)
{
	FOnlineAsyncTaskSteamCoreWebGetCollectionDetails* Task = new FOnlineAsyncTaskSteamCoreWebGetCollectionDetails(this, callback, publishedFileIDs);
	QueueAsyncTask(Task);
}

void UWebRemoteStorage::GetPublishedFileDetails(const FOnSteamCoreWebCallback& callback, FString publishedFileID)
{
	FOnlineAsyncTaskSteamCoreWebGetPublishedFileDetails* Task = new FOnlineAsyncTaskSteamCoreWebGetPublishedFileDetails(this, callback, publishedFileID);
	QueueAsyncTask(Task);
}

void UWebRemoteStorage::GetUGCFileDetails(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString UGCID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebGetUGCFileDetails* Task = new FOnlineAsyncTaskSteamCoreWebGetUGCFileDetails(this, callback, key, steamID, UGCID, appID);
	QueueAsyncTask(Task);
}

void UWebRemoteStorage::SetUGCUsedByGC(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString UGCID, int32 appID, bool bUsed)
{
	FOnlineAsyncTaskSteamCoreWebSetUGCUsedByGC* Task = new FOnlineAsyncTaskSteamCoreWebSetUGCUsedByGC(this, callback, key, steamID, UGCID, appID, bUsed);
	QueueAsyncTask(Task);
}

void UWebRemoteStorage::SubscribePublishedFile(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString publishedFileID)
{
	FOnlineAsyncTaskSteamCoreWebSubscribePublishedFile* Task = new FOnlineAsyncTaskSteamCoreWebSubscribePublishedFile(this, callback, key, steamID, appID, publishedFileID);
	QueueAsyncTask(Task);
}

void UWebRemoteStorage::UnsubscribePublishedFile(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString publishedFileID)
{
	FOnlineAsyncTaskSteamCoreWebUnsubscribePublishedFile* Task = new FOnlineAsyncTaskSteamCoreWebUnsubscribePublishedFile(this, callback, key, steamID, appID, publishedFileID);
	QueueAsyncTask(Task);
}
