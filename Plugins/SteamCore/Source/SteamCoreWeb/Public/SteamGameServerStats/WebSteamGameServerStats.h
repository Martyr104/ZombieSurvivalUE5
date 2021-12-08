/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to Steam Community features.
* https://partner.steamgames.com/doc/webapi/ISteamGameServerStats
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebSteamGameServerStats.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebSteamGameServerStats : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebSteamGameServerStats() { SubsystemType = ESubsystemWeb::GameServerStats; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Get Game Server Player Stats For Game
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	gameID			game id to get stats for, if not a mod, it's safe to use appid here
	* @param	appID			appID of the game
	* @param	rangeStart		range start date/time (Format: YYYY-MM-DD HH:MM:SS, Seattle local time)
	* @param	rangeEnd		range end date/time (Format: YYYY-MM-DD HH:MM:SS, Seattle local time)
	* @param	MaxResults		Max number of results to return (up to 1000)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamGameServerStats")
	void GetGameServerPlayerStatsForGame(const FOnSteamCoreWebCallback& callback, FString key, FString gameID, int32 appID, FString rangeStart, FString rangeEnd, int32 MaxResults = 1000);
};
