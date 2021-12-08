/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* This is the interface used to support Microtransactions (In-Game Purchases).
* https://partner.steamgames.com/doc/webapi/ISteamMicroTxn
*
* See also: https://partner.steamgames.com/doc/features/microtransactions
*           https://partner.steamgames.com/doc/features/microtransactions/implementation
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebMicroTxn.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebMicroTxn : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebMicroTxn() { SubsystemType = ESubsystemWeb::MicroTxn; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Add time to the payment schedule of an agreement with billing type "steam".
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				Steam ID of the client that is adjusting the agreement.
	* @param	agreementID			Unique 64-bit Steam billing agreement ID.
	* @param	appID				App ID of the game the agreement is for.
	* @param	nextProcessDate		Date that next recurring payment should be initiated. Format is YYYYMMDD. Date can only be adjusted forward indicating you want to add time to the subscription. If the date exceeds the end date of the subscription, the end date will be extended.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void AdjustAgreement(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString agreementID, int32 appID, FString nextProcessDate);

	/**
	* Cancels a recurring billing agreement (subscription).
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				Steam ID of the client that is canceling the agreement.
	* @param	agreementID			Unique 64-bit Steam billing agreement ID.
	* @param	appID				App ID of the game the agreement is for.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void CancelAgreement(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString agreementID, int32 appID);

	/**
	* Completes a purchase that was started by the InitTxn API.
	*
	* This command will capture funds for a transaction and should only be called after the user has authorized the transaction and you have received notification that the authorization was successful.
	* Notification of authorization comes either through the Steam client (your game registers to receive notification) or through the user being redirected back to your web site (return URL specified when you redirect a user's web session to Steam). 
	* The usersession value specified in InitTxn determines the notification mechanism.
	* A successful response to this command means payment has been completed and you can safely grant items to the user. In the event of a timeout or some other communication error, use either the QueryTxn or GetReport APIs to get status on the transaction.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	orderID				Unique 64-bit ID for order
	* @param	appID				App ID for game.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void FinalizeTxn(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, int32 appID);

	/**
	* Steam offers transaction reports that can be downloaded for reconciliation purposes. These reports show detailed information about each transaction that affects the settlement of funds into your accounts.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				App ID for game.
	* @param	time				Start time of the report. (RFC 3339 UTC formatted like: 2010-01-01T00:00:00Z)
	* @param	type				Report type (One of: "GAMESALES", "STEAMSTORESALES", "SETTLEMENT")
	* @param	MaxResults			Maximum number of results to return in report. (Default is 1000 if no value is set)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void GetReport(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString time = "2010-01-01T00:00:00Z", FString type = "GAMESALES", int32 MaxResults = 1000);

	/**
	* Get detailed information of all recurring billing agreements (subscriptions) for a user.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				Steam ID of the client.
	* @param	appID				App ID for game.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void GetUserAgreementInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID);

	/**
	* Retrieves details for a user's purchasing info.
	*
	* These details are based upon the user's Steam wallet.
	* For new accounts or accounts that do not yet have a Steam wallet, the information returned will be based off of the user's IP address. The IP will be taken from the user's Steam client session if they are logged in, otherwise from the ipaddress API parameter. If the user does not have a wallet, is not logged in through the Steam client, and you have not supplied an IP address, this call will return an error indicating the user is not logged in.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				Steam ID of the client.
	* @param	ipaddress			IP address of user in string format (xxx.xxx.xxx.xxx). Only required if usersession in InitTxn was set to web.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void GetUserInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 ipaddress);

	/**
	* Creates a new purchase. Send the order information along with the Steam ID to seed the transaction on Steam.
	*
	* This command allows you to create a shopping cart of one or more items for a user. 
	* The cost and descriptions of these items will be displayed to the user for their approval. 
	* The purchase interface can be configured for either the Steam client or a web browser depending on if you are running a purchase in-game or from a web page.
	*
	* A successful response to this command means the transaction has been created. 
	* If the purchase interface is the Steam client, the user will automatically be presented with a dialog requesting authorization for the purchase. 
	* For a web interface, redirect the user to the steam URL returned in the response. 
	* In the event of a timeout or some other communication error, abandon the transaction and create a new one.
	*
	* When a "client" user session is indicated via [param]usersession[/param] the user will be required to approve the transaction from within the game overlay on the client. 
	* Web sessions will require the user to be logged into Steam via a browser where the transaction will be presented and an approval option displayed.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	orderID				Unique 64-bit ID for order
	* @param	steamID				Steam ID of the client.
	* @param	appID				App ID of game this transaction is for.
	* @param	language			ISO 639-1 language code of the item descriptions.
	* @param	currency			ISO 4217 currency code. See Supported Currencies for proper format of each currency. https://partner.steamgames.com/doc/store/pricing/currencies
	* @param	userSession			Session where user will authorize the transaction. Valid options are "client" or "web". If this parameter is not supplied, the interface will be assumed to be through a currently logged in Steam client session.
	* @param	ipaddress			IP address of user in string format (xxx.xxx.xxx.xxx). Only required if [param]usersession[/param] is set to web.
	* @param	itemID				3rd party ID for item.
	* @param	quantity			Quantity of this item.
	* @param	amount				Total cost (in cents) of item(s) to be charged at this time. See Supported Currencies for proper format of each amount. Note that the amount you pass needs to be in the format that matches the "currency" code you pass.
	* @param	description			Description of item.
	* @param	category			Optional category grouping for item.
	* @param	associatedBundle	Optional bundleid of associated bundle.
	* @param	billingType			Optional recurring billing type.
	* @param	startDate			Optional start date for recurring billing.
	* @param	endDate				Optional end date for recurring billing.
	* @param	period				Optional period for recurring billing.
	* @param	frequency			Optional frequency for recurring billing.
	* @param	recurringAmt		Optional amount to be billed for future recurring billing transactions.
	* @param	bundleCount			Number of bundles in cart.
	* @param	bundleID			3rd party ID of the bundle. This shares the same ID space as 3rd party items.
	* @param	bundleQty			Quantity of this bundle.
	* @param	bundleDesc			Description of bundle.
	* @param	bundleCategory		Optional category grouping for bundle.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn", meta = (AutoCreateRefTerm = "category, associatedBundle, billingType, startDate, endDate, period, frequency, recurringAmt, bundleCount, bundleID, bundleQty, bundleDesc, bundleCategory"))
	void InitTxn(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, FString steamID, int32 appID, FString language, FString currency, FString userSession, FString ipaddress, TArray<int32> itemID, TArray<int32> quantity, TArray<FString> amount, TArray<FString> description, TArray<FString> category, TArray<int32> associatedBundle, TArray<FString> billingType, TArray<FString> startDate, TArray<FString> endDate, TArray<FString> period, TArray<int32> frequency, TArray<FString> recurringAmt, TArray<int32> bundleCount, TArray<int32> bundleID, TArray<int32> bundleQty, TArray<FString> bundleDesc, TArray<FString> bundleCategory);

	/**
	* Initiate a recurring payment (subscription) for the user.
	*
	* A successful response means that Steam will initiate a billing cycle for the user.
	* It does not mean that the actual billing cycle was completed successfully. Use the GetReport or GetUserAgreementInfo APIs to check actual billing status.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	orderID			Unique 64-bit ID for order. If the recurring subscription was initiated from the Steam store, then this field will be 0.
	* @param	steamID			Steam ID of the client.
	* @param	agreementID		Unique 64-bit Steam billing agreement ID.
	* @param	appID			App ID of the game the agreement is for.
	* @param	amount			Total cost (in cents). This value corresponds to an initial one-time amount to be immediately charged to a user.
	* @param	currency		ISO 4217 currency code of prices
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void ProcessAgreement(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, FString steamID, FString agreementID, int32 appID, int32 amount, FString currency);

	/**
	* Query the status of an order that was previously created with InitTxn.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				App ID of game this transaction is for.
	* @param	orderID				Unique 64-bit ID for order.
	* @param	transID				Unique 64-bit Steam transaction ID.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void QueryTxn(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString orderID, FString transID);

	/**
	* Tells Steam to refund a user for a purchase. Refunds can only be made for the full value of the original order.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				App ID of game this transaction is for.
	* @param	orderID				Unique 64-bit ID for order.
	* @param	transID				Unique 64-bit Steam transaction ID.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	void RefundTxn(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, int32 appID);

	/**
	* Utility function to create a unique int64 transaction ID
	* Blueprints don't support int64 which is why it returns a string value
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|MicroTxn")
	static FString MakeTransactionID();
};
