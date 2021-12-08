/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamPublishedItemSearch
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebPublishedItemSearch.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebSteamPublishedItemSearch : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebSteamPublishedItemSearch() { SubsystemType = ESubsystemWeb::PublishedItemSearch; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamPublishedItemSearch", meta = (AutoCreateRefTerm="tag,usertag"))
	void RankedByPublicationOrder(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamPublishedItemSearch", meta = (AutoCreateRefTerm = "tag,usertag"))
	void RankedByTrend(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, int32 days, TArray<FString> tag, TArray<FString> userTag);

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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamPublishedItemSearch", meta = (AutoCreateRefTerm = "tag,usertag"))
	void RankedByVote(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag);

	/**
	* Ranked by Publication Order
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
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamPublishedItemSearch", meta = (AutoCreateRefTerm = "tag,usertag"))
	void ResultSetSummary(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag);
};
