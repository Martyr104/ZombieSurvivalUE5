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

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebLeaderboards.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebLeaderboards : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebLeaderboards() { SubsystemType = ESubsystemWeb::Leaderboards; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Delete Leaderboard
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		appid of game
	* @param	name		name of the leaderboard to delete
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void DeleteLeaderboard(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString name);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void FindOrCreateLeaderboard(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString name, FString sortMethod = "Ascending", FString displayType = "Numeric", bool bCreateIfNotFound = false, bool bOnlyTrustedWrites = false, bool bOnlyFriendsReads = false);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetLeaderboardEntries(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 rangeStart, int32 rangeEnd, int32 leaderboardID, int32 dataRequest, FString steamID);

	/**
	* Get Leaderboards for Game
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				appid of game
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void GetLeaderboardsForGame(const FOnSteamCoreWebCallback& callback, FString key, int32 appID);

	/**
	* Reset Leaderboard
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				appid of game
	* @param	leaderbordID		numeric ID of the target leaderboard. Can be retrieved from GetLeaderboardsForGame
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void ResetLeaderboard(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 leaderbordID);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps", meta = (AutoCreateRefTerm = "details"))
	void SetLeaderboardScore(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 leaderbordID, FString steamID, int32 score, TArray<uint8> details, FString scoreMethod = "KeepBest");
};
