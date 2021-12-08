/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Allows partners to access the voting information of the content in their Steam Workshop.
* https://partner.steamgames.com/doc/webapi/IPublishedItemVoting
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebPublishedItemVotingAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionItemVoteSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionItemVoteSummary : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Item Vote Summary
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					Steam ID of user
	* @param	appID					appID of product
	* @param	publishedFileIDs		The Published File ID who's vote details are required
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Item Vote Summary", AutoCreateRefTerm = "publishedFileIDs"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionItemVoteSummary* ItemVoteSummaryAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, TArray<FString> publishedFileIDs);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionUserVoteSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionUserVoteSummary : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Item Vote Summary
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					Steam ID of user
	* @param	publishedFileIDs		The Published File ID who's vote details are required
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "User Vote Summary", AutoCreateRefTerm = "publishedFileIDs"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionUserVoteSummary* UserVoteSummaryAsync(UObject* WorldContextObject, FString key, FString steamID, TArray<FString> publishedFileIDs);
};
