/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information about users.
* https://partner.steamgames.com/doc/webapi/ISteamUserStats
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebUserStatsAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetGlobalAchievementPercentagesForApp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetGlobalAchievementPercentagesForApp : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Retrieves the global achievement percentages for the specified app.
	*
	* @param	gameID		GameID to retrieve the achievement percentages for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Global Achievement Percentages for App"), Category = "SteamCoreWeb|UserStats|Async")
	static USteamCoreWebAsyncActionGetGlobalAchievementPercentagesForApp* GetGlobalAchievementPercentagesForAppAsync(UObject* WorldContextObject, FString gameID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetGlobalStatsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetGlobalStatsForGame : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Retrieves the global stats percentages for the specified app.
	*
	* @param	appID			AppID that we're getting global stats for
	* @param	names			Names of stat to get data for
	* @param	startDate		Start date for daily totals (unix epoch timestamp)
	* @param	endDate			End date for daily totals (unix epoch timestamp)
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Global Stats for Game"), Category = "SteamCoreWeb|UserStats|Async")
	static USteamCoreWebAsyncActionGetGlobalStatsForGame* GetGlobalStatsForGameAsync(UObject* WorldContextObject, int32 appID, TArray<FString> names, int32 startDate, int32 endDate);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetNumberOfCurrentPlayers
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetNumberOfCurrentPlayers : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets the total number of players currently active in the specified app on Steam.
	*
	* Note that this will not return players that are playing while not connected to Steam.
	*
	* @param	appID			AppID that we're getting user count for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Number of Current Players"), Category = "SteamCoreWeb|UserStats|Async")
	static USteamCoreWebAsyncActionGetNumberOfCurrentPlayers* GetNumberOfCurrentPlayersAsync(UObject* WorldContextObject, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetPlayerAchievements
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetPlayerAchievements : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets the list of achievements the specified user has unlocked in an app.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	steamID			SteamID of user
	* @param	appID			AppID to get achievements for
	* @param	language		Language to return strings for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Player Achievements"), Category = "SteamCoreWeb|UserStats|Async")
	static USteamCoreWebAsyncActionGetPlayerAchievements* GetPlayerAchievementsAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString language = "english");
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetSchemaForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetSchemaForGame : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets the complete list of stats and achievements for the specified game.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	appID			AppID to get achievements for
	* @param	language		Language to return strings for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Schema for Game"), Category = "SteamCoreWeb|UserStats|Async")
	static USteamCoreWebAsyncActionGetSchemaForGame* GetSchemaForGameAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString language = "english");
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetUserStatsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetUserStatsForGame : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets the list of stats that the specified user has set in an app.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	steamID			SteamID of user
	* @param	appID			AppID to get achievements for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get User Stats for Game"), Category = "SteamCoreWeb|UserStats|Async")
	static USteamCoreWebAsyncActionGetUserStatsForGame* GetUserStatsForGameAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionSetUserStatsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionSetUserStatsForGame : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Sets a stat for the specified user for the game.
	*
	* @param	key				Steamworks Web API user authentication key.
	* @param	steamID			SteamID of user
	* @param	appID			AppID to get achievements for
	* @param	names			Names of stat or achievement to set
	* @param	values			Values to set
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Set User Stats for Game"), Category = "SteamCoreWeb|UserStats|Async")
	static USteamCoreWebAsyncActionSetUserStatsForGame* SetUserStatsForGameAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, TArray<FString> names, TArray<int32> values);
};
