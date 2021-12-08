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

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebGameInventoryAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetHistoryCommandDetails
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetHistoryCommandDetails : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets a history of commands
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			appid of game
	* @param	steamID			The steam ID of the account to operate on
	* @param	command			The command to run on that asset
	* @param	contextID		The context to fetch history for
	* @param	arguments		The arguments that were provided with the command in the first place
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get History Command Details"), Category = "SteamCoreWeb|GameInventory|Async")
	static USteamCoreWebAsyncActionGetHistoryCommandDetails* GetHistoryCommandDetailsAsync(UObject* WorldContextObject, FString key, int32 appID, FString steamID, FString command, FString contextID, FString arguments);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetHistoryCommandDetails
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetUserHistory : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets a history of user
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			appid of game
	* @param	steamID			The Steam ID to fetch history for
	* @param	contextID		The context to fetch history for
	* @param	startTime		Start time of the history range to collect
	* @param	endTime			End time of the history range to collect
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get User History"), Category = "SteamCoreWeb|GameInventory|Async")
	static USteamCoreWebAsyncActionGetUserHistory* GetUserHistoryAsync(UObject* WorldContextObject, FString key, int32 appID, FString steamID, FString contextID, int32 startTime, int32 endTime);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionHistoryExecuteCommand
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionHistoryExecuteCommand : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets a history of user
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			appid of game
	* @param	steamID			The Steam ID to fetch history for
	* @param	contextID		The context to fetch history for
	* @param	actorID			A unique 32 bit ID for the support person executing the command
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "History Execute Commands"), Category = "SteamCoreWeb|GameInventory|Async")
	static USteamCoreWebAsyncActionHistoryExecuteCommand* HistoryExecuteCommandAsync(UObject* WorldContextObject, FString key, int32 appID, FString steamID, FString contextID, int32 actorID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionSupportGetAssetHistory
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionSupportGetAssetHistory : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets a history of user
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			appid of game
	* @param	assetID			The asset ID to operate on
	* @param	contextID		The context to fetch history for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Support Get Asset History"), Category = "SteamCoreWeb|GameInventory|Async")
	static USteamCoreWebAsyncActionSupportGetAssetHistory* SupportGetAssetHistoryAsync(UObject* WorldContextObject, FString key, int32 appID, FString assetID, FString contextID);
};
