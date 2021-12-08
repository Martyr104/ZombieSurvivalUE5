/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Additional Steam Economy methods that provide access to Steam Trading.
* https://partner.steamgames.com/doc/webapi/IEconService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#include "EconService/WebEconService.h"
#include "EconService/WebEconServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebEconService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebEconService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebEconService::GetTradeHistory(const FOnSteamCoreWebCallback& callback, FString key, int32 maxTrades, int32 startAfterTime, FString startAfterTradeID, bool bNavigatingBack, bool bGetDescriptions, FString language, bool bIncludeFailed, bool bIncludeTotal)
{
	FOnlineAsyncTaskSteamCoreWebGetTradeHistory* Task = new FOnlineAsyncTaskSteamCoreWebGetTradeHistory(this, callback, key, maxTrades, startAfterTime, startAfterTradeID, bNavigatingBack, bGetDescriptions, language, bIncludeFailed, bIncludeTotal);
	QueueAsyncTask(Task);
}

void UWebEconService::FlushInventoryCache(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString contextID)
{
	FOnlineAsyncTaskSteamCoreWebFlushInventoryCache* Task = new FOnlineAsyncTaskSteamCoreWebFlushInventoryCache(this, callback, key, steamID, appID, contextID);
	QueueAsyncTask(Task);
}

void UWebEconService::FlushAssetAppearanceCache(const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebFlushAssetAppearanceCache* Task = new FOnlineAsyncTaskSteamCoreWebFlushAssetAppearanceCache(this, callback, key, appID);
	QueueAsyncTask(Task);
}

void UWebEconService::FlushContextCache(const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebFlushContextCache* Task = new FOnlineAsyncTaskSteamCoreWebFlushContextCache(this, callback, key, appID);
	QueueAsyncTask(Task);
}

void UWebEconService::GetTradeOffers(const FOnSteamCoreWebCallback& callback, FString key, bool bGetSentOffers, bool bGetReceivedOffers, bool bGetDescriptions, FString language, bool bActiveOnly, bool bHistoricalOnly, int32 timeHistoricalCutoff)
{
	FOnlineAsyncTaskSteamCoreWebGetTradeOffers* Task = new FOnlineAsyncTaskSteamCoreWebGetTradeOffers(this, callback, key, bGetSentOffers, bGetReceivedOffers, bGetDescriptions, language, bActiveOnly, bHistoricalOnly, timeHistoricalCutoff);
	QueueAsyncTask(Task);
}

void UWebEconService::GetTradeOffer(const FOnSteamCoreWebCallback& callback, FString key, FString tradeOfferID, FString language)
{
	FOnlineAsyncTaskSteamCoreWebGetTradeOffer* Task = new FOnlineAsyncTaskSteamCoreWebGetTradeOffer(this, callback, key, tradeOfferID, language);
	QueueAsyncTask(Task);
}

void UWebEconService::GetTradeOffersSummary(const FOnSteamCoreWebCallback& callback, FString key, int32 timeLastVisit)
{
	FOnlineAsyncTaskSteamCoreWebGetTradeOffersSummary* Task = new FOnlineAsyncTaskSteamCoreWebGetTradeOffersSummary(this, callback, key, timeLastVisit);
	QueueAsyncTask(Task);
}

void UWebEconService::DeclineTradeOffer(const FOnSteamCoreWebCallback& callback, FString key, FString tradeOfferID)
{
	FOnlineAsyncTaskSteamCoreWebDeclineTradeOffer* Task = new FOnlineAsyncTaskSteamCoreWebDeclineTradeOffer(this, callback, key, tradeOfferID);
	QueueAsyncTask(Task);
}

void UWebEconService::CancelTradeOffer(const FOnSteamCoreWebCallback& callback, FString key, FString tradeOfferID)
{
	FOnlineAsyncTaskSteamCoreWebCancelTradeOffer* Task = new FOnlineAsyncTaskSteamCoreWebCancelTradeOffer(this, callback, key, tradeOfferID);
	QueueAsyncTask(Task);
}
