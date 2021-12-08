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

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebEconMarketServiceAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetMarketEligibility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetMarketEligibility : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Checks whether or not an account is allowed to use the market
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The SteamID of the user to check
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Market Eligibility"), Category = "SteamCoreWeb|EconMarketService|Async")
	static USteamCoreWebAsyncActionGetMarketEligibility* GetMarketEligibilityAsync(UObject* WorldContextObject, FString key, FString steamID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionCancelAppListingsForUser
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionCancelAppListingsForUser : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Cancels all of a user's listings for a specific app ID.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			The app making the request
	* @param	steamID			The SteamID of the user whose listings should be canceled
	* @param	bSynchronous	Whether or not to wait until all listings have been canceled before returning the response
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Cancel App Listings for User"), Category = "SteamCoreWeb|EconMarketService|Async")
	static USteamCoreWebAsyncActionCancelAppListingsForUser* CancelAppListingsForUserAsync(UObject* WorldContextObject, FString key, int32 appID, FString steamID, bool bSynchronous);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetAssetID
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetAssetID : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Returns the asset ID of the item sold in a listing
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				The app that's asking. Must match the app of the listing and must belong to the publisher group that owns the API key making the request
	* @param	listingid (int64)	The identifier of the listing to get information for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Asset ID"), Category = "SteamCoreWeb|EconMarketService|Async")
	static USteamCoreWebAsyncActionGetAssetID* GetAssetIDAsync(UObject* WorldContextObject, FString key, int32 appID, FString listingID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetPopular
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetPopular : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets the most popular items
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	language			The app that's asking. Must match the app of the listing and must belong to the publisher group that owns the API key making the request
	* @param	rows				Number of rows per page
	* @param	start				The result number to start at
	* @param	filterAppID			If present, the app ID to limit results to
	* @param	eCurrency			If present, prices returned will be represented in this currency
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Popular"), Category = "SteamCoreWeb|EconMarketService|Async")
	static USteamCoreWebAsyncActionGetPopular* GetPopularAsync(UObject* WorldContextObject, FString key, FString language, int32 rows, int32 start, int32 filterAppID, int32 eCurrency);
};
