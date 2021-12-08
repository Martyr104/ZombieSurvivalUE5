/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access Steam leaderboards.
* https://partner.steamgames.com/doc/webapi/ISteamLeaderboards
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebLeaderboardsAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionDeleteLeaderboard
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionDeleteLeaderboard : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Delete Leaderboard
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		appid of game
	* @param	name		name of the leaderboard to delete
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Delete Leaderboard"), Category = "SteamCoreWeb|Leaderboards|Async")
	static USteamCoreWebAsyncActionDeleteLeaderboard* DeleteLeaderboardAsync(UObject* WorldContextObject, FString key, int32 appID, FString name);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionFindOrCreateLeaderboard
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionFindOrCreateLeaderboard : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Find Or Create Leaderboard
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	appID					appid of game
	* @param	name					name of the leaderboard to delete
	* @param	sortMethod				sort method to use for this leaderboard (defaults to Ascending)
	* @param	displayType				display type for this leaderboard (defaults to Numeric)
	* @param	bCreateIfNotFound		if this is true the leaderboard will be created if it doesn't exist. Defaults to true.
	* @param	bOnlyTrustedWrites		if this is true the leaderboard scores cannot be set by clients, and can only be set by publisher via SetLeaderboardScore WebAPI. Defaults to false.
	* @param	bOnlyFriendsReads		if this is true the leaderboard scores can only be read for friends by clients, scores can always be read by publisher. Defaults to false.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Find or Create Leaderboard"), Category = "SteamCoreWeb|Leaderboards|Async")
	static USteamCoreWebAsyncActionFindOrCreateLeaderboard* FindOrCreateLeaderboardAsync(UObject* WorldContextObject, FString key, int32 appID, FString name, FString sortMethod = "Ascending", FString displayType = "Numeric", bool bCreateIfNotFound = false, bool bOnlyTrustedWrites = false, bool bOnlyFriendsReads = false);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetLeaderboardEntries
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetLeaderboardEntries : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Leaderboard Entries
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				appid of game
	* @param	rangeStart			range start or 0
	* @param	rangeEnd			range end or max LB entries
	* @param	leaderboardID		ID of the leaderboard to view
	* @param	dataRequest			type of request: RequestGlobal, RequestAroundUser, RequestFriends
	* @param	steamID				SteamID used for friend & around user requests
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Leaderboard Entries"), Category = "SteamCoreWeb|Leaderboards|Async")
	static USteamCoreWebAsyncActionGetLeaderboardEntries* GetLeaderboardEntriesAsync(UObject* WorldContextObject, FString key, int32 appID, int32 rangeStart, int32 rangeEnd, int32 leaderboardID, int32 dataRequest, FString steamID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetLeaderboardsForGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetLeaderboardsForGame : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Leaderboards for Game
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				appid of game
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Leaderboards for Game"), Category = "SteamCoreWeb|Leaderboards|Async")
	static USteamCoreWebAsyncActionGetLeaderboardsForGame* GetLeaderboardsForGameAsync(UObject* WorldContextObject, FString key, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionResetLeaderboard
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionResetLeaderboard : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Reset Leaderboard
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				appid of game
	* @param	leaderbordID		numeric ID of the target leaderboard. Can be retrieved from GetLeaderboardsForGame
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Reset Leaderboard"), Category = "SteamCoreWeb|Leaderboards|Async")
	static USteamCoreWebAsyncActionResetLeaderboard* ResetLeaderboardAsync(UObject* WorldContextObject, FString key, int32 appID, int32 leaderbordID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionSetLeaderboardScore
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionSetLeaderboardScore : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Set Leaderboard Score
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				appid of game
	* @param	leaderbordID		numeric ID of the target leaderboard. Can be retrieved from GetLeaderboardsForGame
	* @param	steamID				steamID to set the score for
	* @param	score				the score to set for this user
	* @param	details				game-specific details for how the score was earned. Up to 256 bytes.
	* @param	scoreMethod			update method to use. Can be "KeepBest" or "ForceUpdate"
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Set Leaderboard Score", AutoCreateRefTerm = "details"), Category = "SteamCoreWeb|Leaderboards|Async")
	static USteamCoreWebAsyncActionSetLeaderboardScore* SetLeaderboardScoreAsync(UObject* WorldContextObject, FString key, int32 appID, int32 leaderbordID, FString steamID, int32 score, TArray<uint8> details, FString scoreMethod = "KeepBest");
};
