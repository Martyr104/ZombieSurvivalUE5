/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebApps.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebApps : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebApps() { SubsystemType = ESubsystemWeb::Apps; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Gets all of the beta branches for the specified application.
	*
	* NOTE: This call requires the publisher API key that owns the specified App ID to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the betas of.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetAppBetas(const FOnSteamCoreWebCallback& callback, FString key, int32 appID);

	/**
	*�Gets an applications build history.
	*
	* NOTE: This call requires the publisher API key that owns the specified App ID to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the build history of.
	* @param	count		The number of builds to retrieve, the default is 10.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetAppBuilds(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 count = 10);

	/**
	* Gets all the versions of all the depots for the specified application.
	*
	* NOTE: This call requires the publisher API key that owns the specified App ID to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the depot versions for.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetAppDepotVersions(const FOnSteamCoreWebCallback& callback, FString key, int32 appID);

	/**
	* Gets the complete list of public apps.
	*
	* @param	key		Steamworks Web API publisher authentication key.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetAppList(const FOnSteamCoreWebCallback& callback, FString key);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetCheatingReports(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 timeBegin, int32 timeEnd, bool bIncludeReports, bool bIncludeBans, int32 reportidMin = 0);

	/**
	* NOTE: This call requires a publisher API key to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key		Steamworks Web API publisher authentication key.
	* @param	appID		AppID of game
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetPlayersBanned(const FOnSteamCoreWebCallback& callback, FString key, int32 appID);

	/**
	* NOTE: This call requires a publisher API key to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	filter		Query filter string
	* @param	limit		Limit number of servers in the response
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetServerList(const FOnSteamCoreWebCallback& callback, FString key, FString filter, int32 limit = 10);

	/**
	* @param	addr	IP or IP:queryport to list
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetServersAtAddress(const FOnSteamCoreWebCallback& callback, FString addr);

	/**
	* NOTE: This call requires a publisher API key to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			AppID of game
	* @param	buildID			BuildID
	* @param	betaKey			beta key, required. Use public for default branch
	* @param	description		optional description for this build
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void SetAppBuildLive(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 buildID, FString betaKey, FString description);

	/**
	* @param	appID		AppID of game
	* @param	version		The installed version of the game
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void UpToDateCheck(const FOnSteamCoreWebCallback& callback, int32 appID, int32 version);
};
