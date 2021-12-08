/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to the Steam Market for partners.
* https://partner.steamgames.com/doc/webapi/IEconMarketService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#include "EconMarket/WebEconMarketService.h"
#include "EconMarket/WebEconMarketServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebEconMarketService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebEconMarketService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebEconMarketService::GetMarketEligibility(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetMarketEligibility* Task = new FOnlineAsyncTaskSteamCoreWebGetMarketEligibility(this, callback, key, steamID);
	QueueAsyncTask(Task);
}

void UWebEconMarketService::CancelAppListingsForUser(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, bool bSynchronous)
{
	FOnlineAsyncTaskSteamCoreWebCancelAppListingsForUser* Task = new FOnlineAsyncTaskSteamCoreWebCancelAppListingsForUser(this, callback, key, appID, steamID, bSynchronous);
	QueueAsyncTask(Task);
}

void UWebEconMarketService::GetAssetID(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString listingID)
{
	FOnlineAsyncTaskSteamCoreWebGetAssetID* Task = new FOnlineAsyncTaskSteamCoreWebGetAssetID(this, callback, key, appID, listingID);
	QueueAsyncTask(Task);
}

void UWebEconMarketService::GetPopular(const FOnSteamCoreWebCallback& callback, FString key, FString language, int32 rows, int32 start, int32 filterAppID, int32 eCurrency)
{
	FOnlineAsyncTaskSteamCoreWebGetPopular* Task = new FOnlineAsyncTaskSteamCoreWebGetPopular(this, callback, key, language, rows, start, filterAppID, eCurrency);
	QueueAsyncTask(Task);
}
