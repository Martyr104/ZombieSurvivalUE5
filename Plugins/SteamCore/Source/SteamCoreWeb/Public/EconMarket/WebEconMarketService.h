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

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebEconMarketService.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebEconMarketService : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebEconMarketService() { SubsystemType = ESubsystemWeb::EconMarket; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Checks whether or not an account is allowed to use the market
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The SteamID of the user to check
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|EconMarketService")
	void GetMarketEligibility(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* Cancels all of a user's listings for a specific app ID.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			The app making the request
	* @param	steamID			The SteamID of the user whose listings should be canceled
	* @param	bSynchronous	Whether or not to wait until all listings have been canceled before returning the response
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|EconMarketService")
	void CancelAppListingsForUser(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, bool bSynchronous);

	/**
	* Returns the asset ID of the item sold in a listing
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				The app that's asking. Must match the app of the listing and must belong to the publisher group that owns the API key making the request
	* @param	listingid (int64)	The identifier of the listing to get information for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|EconMarketService")
	void GetAssetID(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString listingID);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|EconMarketService")
	void GetPopular(const FOnSteamCoreWebCallback& callback, FString key, FString language, int32 rows, int32 start, int32 filterAppID, int32 eCurrency);
};
