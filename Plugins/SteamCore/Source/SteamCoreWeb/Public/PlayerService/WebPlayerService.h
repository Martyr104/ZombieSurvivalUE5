/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides additional methods for interacting with Steam Users.
* https://partner.steamgames.com/doc/webapi/IPlayerService
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebPlayerService.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebPlayerService : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebPlayerService() { SubsystemType = ESubsystemWeb::PlayerService; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Gets information about a player's recently played games
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		The player we're asking about
	* @param	count		The number of games to return (0/unset: all)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PlayerService")
	void GetRecentlyPlayedGames(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 count);

	/**
	* Return a list of games owned by the player
	*
	* @param	key							Steamworks Web API publisher authentication key.
	* @param	steamID						The player we're asking about
	* @param	bIncludeAppInfo				true if we want additional details (name, icon) about each game
	* @param	bIncludePlayedFreeGames		Free games are excluded by default. If this is set, free games the user has played will be returned.
	* @param	filter						if set, restricts result set to the passed in apps
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PlayerService")
	void GetOwnedGames(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, bool bIncludeAppInfo, bool bIncludePlayedFreeGames, TArray<int32> filter);

	/**
	* Returns the Steam Level of a user
	*
	* @param	key							Steamworks Web API publisher authentication key.
	* @param	steamID						The player we're asking about
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PlayerService")
	void GetSteamLevel(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* Gets badges that are owned by a specific user
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The player we're asking about
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PlayerService")
	void GetBadges(const FOnSteamCoreWebCallback& callback, FString key, FString steamID);

	/**
	* Gets all the quests needed to get the specified badge, and which are completed
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The player we're asking about
	* @param	badgeID			The badge we're asking about
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PlayerService")
	void GetCommunityBadgeProgress(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 badgeID);

	/**
	* Returns valid lender SteamID if game currently played is borrowed
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The player we're asking about
	* @param	appIDplaying	The game player is currently playing
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PlayerService")
	void IsPlayingSharedGame(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appIDplaying);
};
