/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* The primary interface to interact with the Steam Economy.
* https://partner.steamgames.com/doc/webapi/IEconService
*
* See also: https://partner.steamgames.com/doc/webapi/ISteamEconomy
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#include "GameInventory/WebGameInventory.h"
#include "GameInventory/WebGameInventoryAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebGameInventory::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebGameInventory::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebGameInventory::GetHistoryCommandDetails(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString command, FString contextID, FString arguments)
{
	FOnlineAsyncTaskSteamCoreWebGetHistoryCommandDetails* Task = new FOnlineAsyncTaskSteamCoreWebGetHistoryCommandDetails(this, callback, key, appID, steamID, command, contextID, arguments);
	QueueAsyncTask(Task);
}

void UWebGameInventory::GetUserHistory(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString contextID, int32 startTime, int32 endTime)
{
	FOnlineAsyncTaskSteamCoreWebGetUserHistory* Task = new FOnlineAsyncTaskSteamCoreWebGetUserHistory(this, callback, key, appID, steamID, contextID, startTime, endTime);
	QueueAsyncTask(Task);
}

void UWebGameInventory::HistoryExecuteCommands(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString contextID, int32 actorID)
{
	FOnlineAsyncTaskSteamCoreWebHistoryExecuteCommands* Task = new FOnlineAsyncTaskSteamCoreWebHistoryExecuteCommands(this, callback, key, appID, steamID, contextID, actorID);
	QueueAsyncTask(Task);
}

void UWebGameInventory::SupportGetAssetHistory(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString assetID, FString contextID)
{
	FOnlineAsyncTaskSteamCoreWebSupportGetAssetHistory* Task = new FOnlineAsyncTaskSteamCoreWebSupportGetAssetHistory(this, callback, key, appID, assetID, contextID);
	QueueAsyncTask(Task);
}

void UWebGameInventory::UpdateItemDefs()
{
}
