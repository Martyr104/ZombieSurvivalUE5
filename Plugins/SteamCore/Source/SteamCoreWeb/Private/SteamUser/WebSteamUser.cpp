/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information and interact with users.
* https://partner.steamgames.com/doc/webapi/ISteamUser
*/

#include "SteamUser/WebSteamUser.h"
#include "SteamUser/WebSteamUserAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebSteamUser::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebSteamUser::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebSteamUser::CheckAppOwnership(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebCheckAppOwnership* Task = new FOnlineAsyncTaskSteamCoreWebCheckAppOwnership(this, callback, key, steamID, appID);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GetAppPriceInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, TArray<int32> appIDs)
{
	FOnlineAsyncTaskSteamCoreWebGetAppPriceInfo* Task = new FOnlineAsyncTaskSteamCoreWebGetAppPriceInfo(this, callback, key, steamID, appIDs);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GetFriendList(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString relationship)
{
	FOnlineAsyncTaskSteamCoreWebGetFriendList* Task = new FOnlineAsyncTaskSteamCoreWebGetFriendList(this, callback, key, steamID, relationship);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GetPlayerBans(const FOnSteamCoreWebCallback& callback, FString key, TArray<FString> steamIDs)
{
	FOnlineAsyncTaskSteamCoreWebGetPlayerBans* Task = new FOnlineAsyncTaskSteamCoreWebGetPlayerBans(this, callback, key, steamIDs);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GetPlayerSummaries(const FOnSteamCoreWebCallback& callback, FString key, TArray<FString> steamIDs)
{
	FOnlineAsyncTaskSteamCoreWebGetPlayerSummaries* Task = new FOnlineAsyncTaskSteamCoreWebGetPlayerSummaries(this, callback, key, steamIDs);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GetPublisherAppOwnership(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnership* Task = new FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnership(this, callback, key, steamID);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GetPublisherAppOwnershipChanges(const FOnSteamCoreWebCallback& callback, FString key, FString packageRowVersion, FString cdkeyRowVersion)
{
	FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnershipChanges* Task = new FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnershipChanges(this, callback, key, packageRowVersion, cdkeyRowVersion);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GetUserGroupList(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetUserGroupList* Task = new FOnlineAsyncTaskSteamCoreWebGetUserGroupList(this, callback, key, steamID);
	QueueAsyncTask(Task);
}

void UWebSteamUser::GrantPackage(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 packageID, FString ipaddress, FString thirdPartyKey, int32 thirdPartyAppID)
{
	FOnlineAsyncTaskSteamCoreWebGrantPackage* Task = new FOnlineAsyncTaskSteamCoreWebGrantPackage(this, callback, key, steamID, packageID, ipaddress, thirdPartyKey, thirdPartyAppID);
	QueueAsyncTask(Task);
}

void UWebSteamUser::ResolveVanityURL(const FOnSteamCoreWebCallback& callback, FString key, FString vanityURL, EVanityUrlType urlType)
{
	FOnlineAsyncTaskSteamCoreWebResolveVanityURL* Task = new FOnlineAsyncTaskSteamCoreWebResolveVanityURL(this, callback, key, vanityURL, urlType);
	QueueAsyncTask(Task);
}
