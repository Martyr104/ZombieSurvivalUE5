/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/IInventoryService
*/

#include "InventoryService/WebInventoryService.h"
#include "InventoryService/WebInventoryServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebInventoryService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebInventoryService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebInventoryService::AddItem(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, TArray<int32> itemdefID, FString itemPropsJson, FString steamID, bool bNotify, FString requestID, bool bTradeRestriction)
{
	FOnlineAsyncTaskSteamCoreWebAddItem* Task = new FOnlineAsyncTaskSteamCoreWebAddItem(this, callback, key, appID, itemdefID, itemPropsJson, steamID, bNotify, requestID, bTradeRestriction);
	QueueAsyncTask(Task);
}

void UWebInventoryService::AddPromoItem(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 itemdefID, FString itemPropsJson, FString steamID, bool bNotify, FString requestID)
{
	FOnlineAsyncTaskSteamCoreWebAddPromoItem* Task = new FOnlineAsyncTaskSteamCoreWebAddPromoItem(this, callback, key, appID, itemdefID, itemPropsJson, steamID, bNotify, requestID);
	QueueAsyncTask(Task);
}

void UWebInventoryService::ConsumeItem(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString itemID, FString quantity, FString steamID, FString requestID)
{
	FOnlineAsyncTaskSteamCoreWebConsumeItem* Task = new FOnlineAsyncTaskSteamCoreWebConsumeItem(this, callback, key, appID, itemID, quantity, steamID, requestID);
	QueueAsyncTask(Task);
}

void UWebInventoryService::ExchangeItem(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, TArray<int32> materialsItemID, TArray<int32> materialsQuantity, FString outputItemdefID)
{
	FOnlineAsyncTaskSteamCoreWebExchangeItem* Task = new FOnlineAsyncTaskSteamCoreWebExchangeItem(this, callback, key, appID, steamID, materialsItemID, materialsQuantity, outputItemdefID);
	QueueAsyncTask(Task);
}

void UWebInventoryService::GetInventory(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetInventory* Task = new FOnlineAsyncTaskSteamCoreWebGetInventory(this, callback, key, appID, steamID);
	QueueAsyncTask(Task);
}

void UWebInventoryService::GetItemDefs(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString modifiedSince, TArray<int32> itemdefIDs, TArray<int32> workshopIDs, int32 cacheMaxAgeSeconds)
{
	FOnlineAsyncTaskSteamCoreWebGetItemDefs* Task = new FOnlineAsyncTaskSteamCoreWebGetItemDefs(this, callback, key, appID, modifiedSince, itemdefIDs, workshopIDs, cacheMaxAgeSeconds);
	QueueAsyncTask(Task);
}

void UWebInventoryService::GetPriceSheet(const FOnSteamCoreWebCallback& callback, FString key, int32 currency)
{
	FOnlineAsyncTaskSteamCoreWebGetPriceSheet* Task = new FOnlineAsyncTaskSteamCoreWebGetPriceSheet(this, callback, key, currency);
	QueueAsyncTask(Task);
}

void UWebInventoryService::Consolidate(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, TArray<int32> itemdefIDs, bool bForce)
{
	FOnlineAsyncTaskSteamCoreWebConsolidate* Task = new FOnlineAsyncTaskSteamCoreWebConsolidate(this, callback, key, appID, steamID, itemdefIDs, bForce);
	QueueAsyncTask(Task);
}

void UWebInventoryService::GetQuantity(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, TArray<int32> itemdefIDs, bool bForce)
{
	FOnlineAsyncTaskSteamCoreWebGetQuantity* Task = new FOnlineAsyncTaskSteamCoreWebGetQuantity(this, callback, key, appID, steamID, itemdefIDs, bForce);
	QueueAsyncTask(Task);
}

void UWebInventoryService::ModifyItems(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString inputJson, FString steamID, int32 timestamp, FString updates)
{
	FOnlineAsyncTaskSteamCoreWebModifyItems* Task = new FOnlineAsyncTaskSteamCoreWebModifyItems(this, callback, key, appID, inputJson, steamID, timestamp, updates);
	QueueAsyncTask(Task);
}
