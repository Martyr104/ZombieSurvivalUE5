/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamPublishedItemSearch
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebPublishedItemSearchAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRankedByPublicationOrder
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionRankedByPublicationOrder : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Ranked by Publication Order
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamid					SteamID of user
	* @param	appID					appID of product
	* @param	startID					Starting index in the result set(0 based)
	* @param	count					Number Requested
	* @param	bHasAppAdminAccess		Whether the user making the request is an admin for the appand can see private files
	* @param	fileType				EPublishedFileInfoMatchingFileType, defaults to k_PFI_MatchingFileType_Items
	* @param	tag						Tag to filter result set
	* @param	userTag					A user specific tag
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Ranked by Publication Order", AutoCreateRefTerm = "tag,usertag"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionRankedByPublicationOrder* RankedByPublicationOrderAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRankedByTrend
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionRankedByTrend : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Ranked by Trend
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamid					SteamID of user
	* @param	appID					appID of product
	* @param	startID					Starting index in the result set(0 based)
	* @param	count					Number Requested
	* @param	bHasAppAdminAccess		Whether the user making the request is an admin for the appand can see private files
	* @param	fileType				EPublishedFileInfoMatchingFileType, defaults to k_PFI_MatchingFileType_Items
	* @param	days					Number of days for the trend period, including today
	* @param	tag						Tag to filter result set
	* @param	userTag					A user specific tag
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Ranked by Trend", AutoCreateRefTerm = "tag,usertag"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionRankedByTrend* RankedByTrendAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, int32 days, TArray<FString> tag, TArray<FString> userTag);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRankedByVote
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionRankedByVote : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Ranked by Vote
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamid					SteamID of user
	* @param	appID					appID of product
	* @param	startID					Starting index in the result set(0 based)
	* @param	count					Number Requested
	* @param	bHasAppAdminAccess		Whether the user making the request is an admin for the appand can see private files
	* @param	fileType				EPublishedFileInfoMatchingFileType, defaults to k_PFI_MatchingFileType_Items
	* @param	tag						Tag to filter result set
	* @param	userTag					A user specific tag
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Ranked by Vote", AutoCreateRefTerm = "tag,usertag"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionRankedByVote* RankedByVoteAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionResultSetSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionResultSetSummary : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Result Set Summary
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamid					SteamID of user
	* @param	appID					appID of product
	* @param	startID					Starting index in the result set(0 based)
	* @param	bHasAppAdminAccess		Whether the user making the request is an admin for the appand can see private files
	* @param	fileType				EPublishedFileInfoMatchingFileType, defaults to k_PFI_MatchingFileType_Items
	* @param	tag						Tag to filter result set
	* @param	userTag					A user specific tag
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Result Set Summary", AutoCreateRefTerm = "tag,usertag"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionResultSetSummary* ResultSetSummaryAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag);
};
