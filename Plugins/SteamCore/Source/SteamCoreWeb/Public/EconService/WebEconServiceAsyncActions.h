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

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebEconServiceAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetTradeHistory
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetTradeHistory : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets a history of trades
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	maxTrades				The number of trades to return information for
	* @param	startAfterTime			The time of the last trade shown on the previous page of results, or the time of the first trade if navigating back
	* @param	startAfterTradeID		The tradeid shown on the previous page of results, or the ID of the first trade if navigating back
	* @param	bNavigatingBack			The user wants the previous page of results, so return the previous max_trades trades before the start time and ID
	* @param	bGetDescriptions		If set, the item display data for the items included in the returned trades will also be returned
	* @param	language				The language to use when loading item display data
	* @param	bIncludeFailed			Include Failed
	* @param	bIncludeTotal			If set, the total number of trades the account has participated in will be included in the response
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Trade History"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionGetTradeHistory* GetTradeHistoryAsync(UObject* WorldContextObject, FString key, int32 maxTrades, int32 startAfterTime, FString startAfterTradeID, bool bNavigatingBack, bool bGetDescriptions, FString language, bool bIncludeFailed, bool bIncludeTotal);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionFlushInventoryCache
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionFlushInventoryCache : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Flushes the cache for a user's inventory in a specific app context
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			User to clear cache for.
	* @param	appID			App to clear cache for.
	* @param	contextID		Context to clear cache for.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Flush Inventory Cache"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionFlushInventoryCache* FlushInventoryCacheAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString contextID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionFlushAssetAppearanceCache
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionFlushAssetAppearanceCache : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Flushes the display cache for assets. This will result in calls to GetAssetClassInfo for each asset class the next time it is displayed.
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Flush Asset Appearance Cache"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionFlushAssetAppearanceCache* FlushAssetAppearanceCacheAsync(UObject* WorldContextObject, FString key, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionFlushContextCache
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionFlushContextCache : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Flushes the cache of inventory contents. This will result in calls to GetContexts and GetContextContents to get fresh data for each user next time Steam needs their inventory.
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Flush Context Cache"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionFlushContextCache* FlushContextCacheAsync(UObject* WorldContextObject, FString key, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetTradeOffers
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetTradeOffers : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get a list of sent or received trade offers
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	bGetSentOffers			Request the list of sent offers.
	* @param	bGetReceivedOffers		Request the list of received offers.
	* @param	bGetDescriptions		If set, the item display data for the items included in the returned trade offers will also be returned.
	* @param	language				The language to use when loading item display data.
	* @param	bActiveOnly				Indicates we should only return offers which are still active, or offers that have changed in state since the time_historical_cutoff
	* @param	bHistoricalOnly			Indicates we should only return offers which are not active.
	* @param	timeHistoricalCutoff	When active_only is set, offers updated since this time will also be returned
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Trade Offers"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionGetTradeOffers* GetTradeOffersAsync(UObject* WorldContextObject, FString key, bool bGetSentOffers, bool bGetReceivedOffers, bool bGetDescriptions, FString language, bool bActiveOnly, bool bHistoricalOnly, int32 timeHistoricalCutoff);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetTradeOffer
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetTradeOffer : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets a specific trade offer
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Trade Offer"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionGetTradeOffer* GetTradeOfferAsync(UObject* WorldContextObject, FString key, FString tradeOfferID, FString language);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetTradeOffersSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetTradeOffersSummary : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get counts of pending and new trade offers
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	timeLastVisit			The time the user last visited. If not passed, will use the time the user last visited the trade offer page.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Trade Offers Summary"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionGetTradeOffersSummary* GetTradeOffersSummaryAsync(UObject* WorldContextObject, FString key, int32 timeLastVisit);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetTradeOffersSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionDeclineTradeOffer : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Decline a trade offer someone sent to us
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	tradeOfferID
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Decline Trade Offer"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionDeclineTradeOffer* DeclineTradeOfferAsync(UObject* WorldContextObject, FString key, FString tradeOfferID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionCancelTradeOffer
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionCancelTradeOffer : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Cancel a trade offer we sent
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	tradeOfferID
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Cancel Trade Offer"), Category = "SteamCoreWeb|EconService|Async")
	static USteamCoreWebAsyncActionCancelTradeOffer* CancelTradeOfferAsync(UObject* WorldContextObject, FString key, FString tradeOfferID);
};
