/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information and interact with users.
* https://partner.steamgames.com/doc/webapi/ISteamUser
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "SteamUser/WebSteamUserTypes.h"
#include "WebSteamUser.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebSteamUser : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebSteamUser() { SubsystemType = ESubsystemWeb::SteamCoreWeb; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Checks if the specified user owns the app.
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appID		AppID to check for ownership
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void CheckAppOwnership(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID);

	/**
	* Get App Price Info
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appIDs		Max: 100
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GetAppPriceInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, TArray<int32> appIDs);

	/**
	* Get Friend List
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			SteamID of user
	* @param	relationship	relationship type (ex: friend)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GetFriendList(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString relationship);

	/**
	* Get Player Bans
	*
	* @param	key				Steamworks Web API publisher authentication key.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GetPlayerBans(const FOnSteamCoreWebCallback& callback, FString key, TArray<FString> steamIDs);

	/**
	* Get Player Summaries
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamIDs		Max: 100
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GetPlayerSummaries(const FOnSteamCoreWebCallback& callback, FString key, TArray<FString> steamIDs);

	/**
	* Get Publisher App Ownership
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			SteamID of user
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GetPublisherAppOwnership(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* This method can be used to determine what SteamIDs have ownership changes starting from a particular package or key row version number. 
	* From the list of SteamIDs returned, a call to GetPublisherAppOwnership can then return the associated ownership data for the applications in the group associated with the key passed in. 
	A partner may wish to track this data in conjunction with linked Steam Accounts to better understand the state of product ownership on Steam.
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	packageRowVersion		64 - bit row version to read package changes from. The row version of data read up to will be returned for use in future calls.
	* @param	cdkeyRowVersion			64 - bit row version to read CD Key changes from. The row version of data read up to will be returned for use in future calls.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GetPublisherAppOwnershipChanges(const FOnSteamCoreWebCallback& callback, FString key, FString packageRowVersion, FString cdkeyRowVersion);

	/**
	* Get User Group List
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			SteamID of user
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GetUserGroupList(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* Get User Group List
	*
	* This call will only work on packages which have "canbegrantedfromexternal" set to 1.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				SteamID of user
	* @param	packageID			PackageID to grant
	* @param	ipaddress			ip address of user in string format(xxx.xxx.xxx.xxx).
	* @param	thirdPartyKey		Optionally associate third party key during grant. 'thirdpartyappid' will have to be set.
	* @param	thirdPartyAppID		Has to be set if 'thirdpartykey' is set.The appid associated with the 'thirdpartykey'.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void GrantPackage(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 packageID, FString ipaddress, FString thirdPartyKey, int32 thirdPartyAppID);

	/**
	* Resolve Vanity URL
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	vanityURL		The vanity URL to get a SteamID for
	* @param	urlType			
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamUser")
	void ResolveVanityURL(const FOnSteamCoreWebCallback& callback, FString key, FString vanityURL, EVanityUrlType urlType);
};
