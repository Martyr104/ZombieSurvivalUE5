/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebAppsAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetAppBetas
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetAppBetas : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets all of the beta branches for the specified application.
	*
	* NOTE: This call requires the publisher API key that owns the specified App ID to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*		
	* @param	Key			Steamworks Web API publisher authentication key.
	* @param	AppID		The App ID to get the betas of.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get App Betas"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetAppBetas* GetAppBetasAsync(UObject* WorldContextObject, FString Key, int32 AppID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetAppBuilds
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetAppBuilds : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	*�Gets an applications build history.
	*
	* NOTE: This call requires the publisher API key that owns the specified App ID to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the build history of.
	* @param	count		The number of builds to retrieve, the default is 10.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get App Builds"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetAppBuilds* GetAppBuildsAsync(UObject* WorldContextObject, FString key, int32 appID, int32 count = 10);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetAppDepotVersions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetAppDepotVersions : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets all the versions of all the depots for the specified application.
	*
	* NOTE: This call requires the publisher API key that owns the specified App ID to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the depot versions for.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get App Depot Versions"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetAppDepotVersions* GetAppDepotVersionsAsync(UObject* WorldContextObject, FString key, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetAppList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetAppList : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets the complete list of public apps.
	*
	* @param	key		Steamworks Web API publisher authentication key.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get App List"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetAppList* GetAppListAsync(UObject* WorldContextObject, FString key);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetCheatingReports
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetCheatingReports : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get a list of cheating reports submitted for this app.
	*
	* Used to gather the cheating reports so that they may be reviewed and a determination made.
	* NOTE: This call requires a publisher API key to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				AppID of game
	* @param	timeBegin			Time range begin
	* @param	timeEnd				Time range end
	* @param	bIncludeReports		include reports that were not bans
	* @param	bIncludeBans		include reports that were bans
	* @param	reportidMin			minimum report id
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Cheating Reports"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetCheatingReports* GetCheatingReportsAsync(UObject* WorldContextObject, FString key, int32 appID, int32 timeBegin, int32 timeEnd, bool bIncludeReports, bool bIncludeBans, int32 reportidMin);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetPlayersBanned
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetPlayersBanned : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* NOTE: This call requires a publisher API key to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key		Steamworks Web API publisher authentication key.
	* @param	appID		AppID of game
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Players Banned"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetPlayersBanned* GetPlayersBannedAsync(UObject* WorldContextObject, FString key, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetServerList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetServerList : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* NOTE: This call requires a publisher API key to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	filter		Query filter string
	* @param	limit		Limit number of servers in the response
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Server List"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetServerList* GetServerListAsync(UObject* WorldContextObject, FString key, FString filter, int32 limit);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionGetServersAtAddress
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionGetServersAtAddress : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* @param	addr	IP or IP:queryport to list
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Servers at Address"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionGetServersAtAddress* GetServersAtAddressAsync(UObject* WorldContextObject, FString addr);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionSetAppBuildLive
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionSetAppBuildLive : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* NOTE: This call requires a publisher API key to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			AppID of game
	* @param	buildID			BuildID
	* @param	betaKey			beta key, required. Use public for default branch
	* @param	description		optional description for this build
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Set App Build Live"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionSetAppBuildLive* SetAppBuildLiveAsync(UObject* WorldContextObject, FString key, int32 appID, int32 buildID, FString betaKey, FString description);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionUpToDateCheck
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreAppsAsyncActionUpToDateCheck : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* @param	appID		AppID of game
	* @param	version		The installed version of the game
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Up To Date Check"), Category = "SteamCoreWeb|Apps|Async")
	static USteamCoreAppsAsyncActionUpToDateCheck* UpToDateCheckAsync(UObject* WorldContextObject, int32 appID, int32 version);
};
