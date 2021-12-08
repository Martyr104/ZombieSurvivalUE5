/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides additional methods for interacting with Steam Users.
* https://partner.steamgames.com/doc/webapi/IPlayerService
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebPlayerServiceAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetRecentlyPlayedGames
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetRecentlyPlayedGames : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets information about a player's recently played games
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The player we're asking about
	* @param	count		The number of games to return (0/unset: all)
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Recently PlayedGames"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetRecentlyPlayedGames* GetRecentlyPlayedGamesAsync(UObject* WorldContextObject, FString key, FString steamID, int32 count);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetOwnedGames
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetOwnedGames : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Return a list of games owned by the player
	*
	* @param	key							Steamworks Web API publisher authentication key.
	* @param	steamID						The player we're asking about
	* @param	bIncludeAppInfo				true if we want additional details (name, icon) about each game
	* @param	bIncludePlayedFreeGames		Free games are excluded by default. If this is set, free games the user has played will be returned.
	* @param	filter						if set, restricts result set to the passed in apps
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Owned Games"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetOwnedGames* GetOwnedGamesAsync(UObject* WorldContextObject, FString key, FString steamID, bool bIncludeAppInfo, bool bIncludePlayedFreeGames, TArray<int32> filter);
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetSteamLevel
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetSteamLevel : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Returns the Steam Level of a user
	*
	* @param	key							Steamworks Web API publisher authentication key.
	* @param	steamID						The player we're asking about
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Steam Level"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetSteamLevel* GetSteamLevelAsync(UObject* WorldContextObject, FString key, FString steamID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetBadges
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetBadges : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets badges that are owned by a specific user
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The player we're asking about
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Badges"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetBadges* GetBadgesAsync(UObject* WorldContextObject, FString key, FString steamID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetCommunityBadgeProgress
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetCommunityBadgeProgress : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Gets all the quests needed to get the specified badge, and which are completed
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The player we're asking about
	* @param	badgeID			The badge we're asking about
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Community Badge Progress"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetCommunityBadgeProgress* GetCommunityBadgeProgressAsync(UObject* WorldContextObject, FString key, FString steamID, int32 badgeID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionIsPlayingSharedGame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionIsPlayingSharedGame : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Returns valid lender SteamID if game currently played is borrowed
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The player we're asking about
	* @param	appIDplaying	The game player is currently playing
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Is Playing Shared Game"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionIsPlayingSharedGame* IsPlayingSharedGameAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appIDplaying);
};
