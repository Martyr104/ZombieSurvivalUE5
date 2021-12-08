/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information and interact with users.
* https://partner.steamgames.com/doc/webapi/ISteamUser
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebSteamUserAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionCheckAppOwnership
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionCheckAppOwnership : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Checks if the specified user owns the app.
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appID		AppID to check for ownership
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Check App Ownership"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionCheckAppOwnership* CheckAppOwnershipAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetAppPriceInfo
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetAppPriceInfo : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get App Price Info
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appIDs		Max: 100
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get App Price Info"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGetAppPriceInfo* GetAppPriceInfoAsync(UObject* WorldContextObject, FString key, FString steamID, TArray<int32> appIDs);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetFriendList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetFriendList : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Friend List
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			SteamID of user
	* @param	relationship	relationship type (ex: friend)
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Friend List"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGetFriendList* GetFriendListAsync(UObject* WorldContextObject, FString key, FString steamID, FString relationship);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetPlayerBans
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetPlayerBans : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Player Bans
	*
	* @param	key				Steamworks Web API publisher authentication key.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Player Bans"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGetPlayerBans* GetPlayerBansAsync(UObject* WorldContextObject, FString key, TArray<FString> steamIDs);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetPlayerSummaries
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetPlayerSummaries : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Player Summaries
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamIDs		Max: 100
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Player Summaries"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGetPlayerSummaries* GetPlayerSummariesAsync(UObject* WorldContextObject, FString key, TArray<FString> steamIDs);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetPublisherAppOwnership
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetPublisherAppOwnership : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Publisher App Ownership
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			SteamID of user
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Publisher App Ownership"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGetPublisherAppOwnership* GetPublisherAppOwnershipAsync(UObject* WorldContextObject, FString key, FString steamID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetPublisherAppOwnershipChanges
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetPublisherAppOwnershipChanges : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* This method can be used to determine what SteamIDs have ownership changes starting from a particular package or key row version number.
	* From the list of SteamIDs returned, a call to GetPublisherAppOwnership can then return the associated ownership data for the applications in the group associated with the key passed in.
	A partner may wish to track this data in conjunction with linked Steam Accounts to better understand the state of product ownership on Steam.
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	packageRowVersion		64 - bit row version to read package changes from. The row version of data read up to will be returned for use in future calls.
	* @param	cdkeyRowVersion			64 - bit row version to read CD Key changes from. The row version of data read up to will be returned for use in future calls.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Publisher App Ownership Changes"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGetPublisherAppOwnershipChanges* GetPublisherAppOwnershipChangesAsync(UObject* WorldContextObject, FString key, FString packageRowVersion, FString cdkeyRowVersion);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetUserGroupList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetUserGroupList : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get User Group List
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			SteamID of user
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get User Group List"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGetUserGroupList* GetUserGroupListAsync(UObject* WorldContextObject, FString key, FString steamID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGrantPackage
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGrantPackage : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
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
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Grant Package"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionGrantPackage* GrantPackageAsync(UObject* WorldContextObject, FString key, FString steamID, int32 packageID, FString ipaddress, FString thirdPartyKey, int32 thirdPartyAppID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionResolveVanityURL
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionResolveVanityURL : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Resolve Vanity URL
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	vanityURL		The vanity URL to get a SteamID for
	* @param	urlType
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Resolve Vanity URL"), Category = "SteamCoreWeb|SteamUser|Async")
	static USteamCoreWebAsyncActionResolveVanityURL* ResolveVanityURLAsync(UObject* WorldContextObject, FString key, FString vanityURL, EVanityUrlType urlType);
};
