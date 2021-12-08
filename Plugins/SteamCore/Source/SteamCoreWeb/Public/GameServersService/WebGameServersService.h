/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/IGameServersService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebGameServersService.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebGameServersService : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebGameServersService() { SubsystemType = ESubsystemWeb::GameServers; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Gets a list of game server accounts with their logon tokens
	*
	* @param	key			Steamworks Web API publisher authentication key.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void GetAccountList(const FOnSteamCoreWebCallback& callback, FString key);

	/**
	* Creates a persistent game server account
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The app to use the account for
	* @param	memo		The memo to set on the new account
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void CreateAccount(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString memo);

	/**
	* This method changes the memo associated with the game server account. Memos do not affect the account in any way.
	* The memo shows up in the GetAccountList response and serves only as a reminder of what the account is used for.
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The SteamID of the game server to set the memo on
	* @param	memo		The memo to set on the new account
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void SetMemo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString memo);

	/**
	* Generates a new login token for the specified game server
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The SteamID of the game server to reset the login token of
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void ResetLoginToken(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* Deletes a persistent game server account
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The SteamID of the game server account to delete
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void DeleteAccount(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* Gets public information about a given game server account
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The SteamID of the game server to get info on
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void GetAccountPublicInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* Queries the status of the specified token, which must be owned by you
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	loginToken		Login token to query
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void QueryLoginToken(const FOnSteamCoreWebCallback& callback, FString key, FString loginToken);

	/**
	* performs a GSLT ban/unban of GSLT associated with a GS. If banning, also bans associated users' GSLTs.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			
	* @param	bBanned			
	* @param	banSeconds		
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void SetBanStatus(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, bool bBanned, int32 banSeconds);

	/**
	* Gets a list of server SteamIDs given a list of IPs
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	serverIP
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void GetServerSteamIDsByIP(const FOnSteamCoreWebCallback& callback, FString key, FString serverIP);

	/**
	* Gets a list of server IP addresses given a list of SteamIDs
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	serverSteamID
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameServersService")
	void GetServerIPsBySteamID(const FOnSteamCoreWebCallback& callback, FString key, FString serverSteamID);
};
