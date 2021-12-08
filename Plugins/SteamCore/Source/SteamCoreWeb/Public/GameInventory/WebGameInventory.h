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

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebGameInventory.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebGameInventory : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebGameInventory() { SubsystemType = ESubsystemWeb::GameInventory; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameInventory")
	void GetHistoryCommandDetails(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString command, FString contextID, FString arguments);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameInventory")
	void GetUserHistory(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString contextID, int32 startTime, int32 endTime);

	/**
	* Gets a history of user
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			appid of game
	* @param	steamID			The Steam ID to fetch history for
	* @param	contextID		The context to fetch history for
	* @param	actorID			A unique 32 bit ID for the support person executing the command
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameInventory")
	void HistoryExecuteCommands(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString contextID, int32 actorID);

	/**
	* Gets a history of user
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			appid of game
	* @param	assetID			The asset ID to operate on
	* @param	contextID		The context to fetch history for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameInventory")
	void SupportGetAssetHistory(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString assetID, FString contextID);

	/**
	* FUNCTION NOT SUPPORTED
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameInventory")
	void UpdateItemDefs();
};
