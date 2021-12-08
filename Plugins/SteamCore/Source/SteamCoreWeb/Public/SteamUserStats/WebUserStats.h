/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information about users.
* https://partner.steamgames.com/doc/webapi/ISteamUserStats
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebUserStats.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebUserStats : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebUserStats() { SubsystemType = ESubsystemWeb::UserStats; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Retrieves the global achievement percentages for the specified app.
	*
	* @param	gameID		GameID to retrieve the achievement percentages for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|CloudService")
	void GetGlobalAchievementPercentagesForApp(const FOnSteamCoreWebCallback& callback, FString gameID);

	/**
	* Retrieves the global stats percentages for the specified app.
	*
	* @param	appID			AppID that we're getting global stats for
	* @param	names			Names of stat to get data for
	* @param	startDate		Start date for daily totals (unix epoch timestamp)
	* @param	endDate			End date for daily totals (unix epoch timestamp)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|CloudService")
	void GetGlobalStatsForGame(const FOnSteamCoreWebCallback& callback, int32 appID, TArray<FString> names, int32 startDate, int32 endDate);

	/**
	* Gets the total number of players currently active in the specified app on Steam.
	*
	* Note that this will not return players that are playing while not connected to Steam.
	*
	* @param	appID			AppID that we're getting user count for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|CloudService")
	void GetNumberOfCurrentPlayers(const FOnSteamCoreWebCallback& callback, int32 appID);

	/**
	* Gets the list of achievements the specified user has unlocked in an app.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	steamID			SteamID of user
	* @param	appID			AppID to get achievements for
	* @param	language		Language to return strings for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|CloudService")
	void GetPlayerAchievements(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString language = "english");

	/**
	* Gets the complete list of stats and achievements for the specified game.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	appID			AppID to get achievements for
	* @param	language		Language to return strings for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|CloudService")
	void GetSchemaForGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString language = "english");

	/**
	* Gets the list of stats that the specified user has set in an app.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	steamID			SteamID of user
	* @param	appID			AppID to get achievements for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|CloudService")
	void GetUserStatsForGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID);

	/**
	* Sets a stat for the specified user for the game.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	steamID			SteamID of user
	* @param	appID			AppID to get achievements for
	* @param	names			Names of stat or achievement to set
	* @param	values			Values to set
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|CloudService")
	void SetUserStatsForGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, TArray<FString> names, TArray<int32> values);
};
