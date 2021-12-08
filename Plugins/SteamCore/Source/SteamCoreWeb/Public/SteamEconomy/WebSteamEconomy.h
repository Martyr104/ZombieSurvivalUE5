/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamEconomy
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebSteamEconomy.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebSteamEconomy : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebSteamEconomy() { SubsystemType = ESubsystemWeb::Economy; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Can trade
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				That the key is associated with. Must be a steam economy app.
	* @param	steamID				SteamID of user attempting to initiate a trade
	* @param	targetID (int64)	SteamID of user that is the target of the trade invitation
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void CanTrade(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString targetID);

	/**
	* Finalize Asset Transaction
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The app ID the user is buying assets for
	* @param	steamID		SteamID of the user making a purchase
	* @param	txnID		The transaction ID
	* @param	language	The local language for the user
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void FinalizeAssetTransaction(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString txnID, FString language);

	/**
	* Get Asset Class Info
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			The app ID the user is buying assets for
	* @param	language		The user's local language
	* @param	classCount		Number of classes requested. Must be at least one.
	* @param	classID			Class ID of the nth class.
	* @param	instanceID		Instance ID of the nth class.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void GetAssetClassInfo(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString language, int32 classCount, FString classID, FString instanceID);

	/**
	* Returns prices and categories for items that users are able to purchase.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			The app ID the user is buying assets for
	* @param	currency		The currency to filter for
	* @param	language		The user's local language
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void GetAssetPrices(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString currency, FString language);

	/**
	* Get Exported Assets for User
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				SteamID of user
	* @param	appID				The app to get exported items from.
	* @param	contextID (int64)	The context in the app to get exported items from.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void GetExportedAssetsForUser(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString contextID);

	/**
	* Get Market Prices
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			The app ID the user is buying assets for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void GetMarketPrices(const FOnSteamCoreWebCallback& callback, FString key, int32 appID);

	/**
	* Start Asset Transaction
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				The app ID the user is buying assets for
	* @param	steamID				SteamID of user making a purchase
	* @param	assetID				The ID of the first asset the user is buying - there must be at least one
	* @param	assetQuantity		The quantity of assetid0's the the user is buying
	* @param	currency			The local currency for the user
	* @param	language			The local language for the user
	* @param	ipaddress			The user's IP address
	* @param	referer				The referring URL
	* @param	bClientAuth			If true (default is false), the authorization will appear in the user's steam client overlay, rather than as a web page - useful for stores that are embedded in products.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void StartAssetTransaction(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString assetID, int32 assetQuantity, FString currency, FString language, FString ipaddress, FString referer, bool bClientAuth);

	/**
	* Start Trade
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			The app ID the user is buying assets for
	* @param	steamID1		SteamID of first user in the trade
	* @param	steamID2		SteamID of second user in the trade
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamEconomy")
	void StartTrade(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID1, FString steamID2);
};
