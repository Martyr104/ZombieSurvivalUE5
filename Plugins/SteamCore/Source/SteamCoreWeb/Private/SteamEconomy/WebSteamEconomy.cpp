/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamEconomy
*/

#include "SteamEconomy/WebSteamEconomy.h"
#include "SteamEconomy/WebSteamEconomyAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebSteamEconomy::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebSteamEconomy::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebSteamEconomy::CanTrade(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString targetID)
{
	FOnlineAsyncTaskSteamCoreWebCanTrade* Task = new FOnlineAsyncTaskSteamCoreWebCanTrade(this, callback, key, appID, steamID, targetID);
	QueueAsyncTask(Task);
}

void UWebSteamEconomy::FinalizeAssetTransaction(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString txnID, FString language)
{
	FOnlineAsyncTaskSteamCoreWebFinalizeAssetTransaction* Task = new FOnlineAsyncTaskSteamCoreWebFinalizeAssetTransaction(this, callback, key, appID, steamID, txnID, language);
	QueueAsyncTask(Task);
}

void UWebSteamEconomy::GetAssetClassInfo(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString language, int32 classCount, FString classID, FString instanceID)
{
	FOnlineAsyncTaskSteamCoreWebGetAssetClassInfo* Task = new FOnlineAsyncTaskSteamCoreWebGetAssetClassInfo(this, callback, key, appID, language, classCount, classID, instanceID);
	QueueAsyncTask(Task);
}

void UWebSteamEconomy::GetAssetPrices(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString currency, FString language)
{
	FOnlineAsyncTaskSteamCoreWebGetAssetPrices* Task = new FOnlineAsyncTaskSteamCoreWebGetAssetPrices(this, callback, key, appID, currency, language);
	QueueAsyncTask(Task);
}

void UWebSteamEconomy::GetExportedAssetsForUser(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString contextID)
{
	FOnlineAsyncTaskSteamCoreWebGetExportedAssetsForUser* Task = new FOnlineAsyncTaskSteamCoreWebGetExportedAssetsForUser(this, callback, key, steamID, appID, contextID);
	QueueAsyncTask(Task);
}

void UWebSteamEconomy::GetMarketPrices(const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebGetMarketPrices* Task = new FOnlineAsyncTaskSteamCoreWebGetMarketPrices(this, callback, key, appID);
	QueueAsyncTask(Task);
}

void UWebSteamEconomy::StartAssetTransaction(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString assetID, int32 assetQuantity, FString currency, FString language, FString ipaddress, FString referer, bool bClientAuth)
{
	FOnlineAsyncTaskSteamCoreWebStartAssetTransaction* Task = new FOnlineAsyncTaskSteamCoreWebStartAssetTransaction(this, callback, key, appID, steamID, assetID, assetQuantity, currency, language, ipaddress, referer, bClientAuth);
	QueueAsyncTask(Task);
}

void UWebSteamEconomy::StartTrade(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID1, FString steamID2)
{
	FOnlineAsyncTaskSteamCoreWebStartTrade* Task = new FOnlineAsyncTaskSteamCoreWebStartTrade(this, callback, key, appID, steamID1, steamID2);
	QueueAsyncTask(Task);
}
