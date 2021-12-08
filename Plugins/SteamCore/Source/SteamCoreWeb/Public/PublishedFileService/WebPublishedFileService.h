/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides additional methods for interacting with Steam Workshop items.
* https://partner.steamgames.com/doc/webapi/IPublishedFileService
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebPublishedFileService.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebPublishedFileService : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebPublishedFileService() { SubsystemType = ESubsystemWeb::PublishedFile; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Performs a search query for published files
	*
	* @param	key							Steamworks Web API publisher authentication key.
	* @param	queryType					enumeration EPublishedFileQueryType in clientenums.h
	* @param	page						Current page. Currently there is an upper limit of 1000.
	* @param	cursor						Cursor to paginate through the results (set to '*' for the first request). Prefer this over using the page parameter, as it will allow you to do deep pagination. When used, the page parameter will be ignored. Use the "next_cursor" value returned in the response to set up the next query to get the next set of results.
	* @param	numPerPage					(Optional) The number of results, per page to return.
	* @param	creatorAppID				App that created the files
	* @param	appID						App that consumes the files
	* @param	requiredTags				Tags to match on. See match_all_tags parameter below
	* @param	excludedTags				(Optional) Tags that must NOT be present on a published file to satisfy the query.
	* @param	bMatchAllTags				If true, then items must have all the tags specified, otherwise they must have at least one of the tags.
	* @param	requiredFlags				Required flags that must be set on any returned items
	* @param	omittedFlags				Flags that must not be set on any returned items
	* @param	searchText					Text to match in the item's title or description
	* @param	fileType					EPublishedFileInfoMatchingFileType
	* @param	childPublishedFileID		Find all items that reference the given item.
	* @param	days						If query_type is k_PublishedFileQueryType_RankedByTrend, then this is the number of days to get votes for [1,7].
	* @param	bIncludeRecentVotesOnly		If query_type is k_PublishedFileQueryType_RankedByTrend, then limit result set just to items that have votes within the day range given
	* @param	cacheMaxAgeSeconds			Allow stale data to be returned for the specified number of seconds.
	* @param	language					Language to search in and also what gets returned. Defaults to English.
	* @param	requiredKvTags				Required key-value tags to match on.
	* @param	bTotalOnly					(Optional) If true, only return the total number of files that satisfy this query.
	* @param	bIDsOnly					(Optional) If true, only return the published file ids of files that satisfy this query.
	* @param	bReturnVoteData				Return vote data
	* @param	bReturnTags					Return tags in the file details
	* @param	bReturnKvTags				Return key-value tags in the file details
	* @param	bReturnPreviews				Return preview image and video details in the file details
	* @param	bReturnChildren				Return child item ids in the file details
	* @param	bReturnShortDescription		Populate the short_description field instead of file_description
	* @param	bReturnForSaleData			Return pricing information, if applicable
	* @param	bReturnMetaData				Populate the metadata
	* @param	returnPlaytimeStats			Return playtime stats for the specified number of days before today.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PublishedFileService")
	void QueryFiles(const FOnSteamCoreWebCallback& callback, FString key, int32 queryType, int32 page, FString cursor, int32 numPerPage, int32 creatorAppID, int32 appID, FString requiredTags, FString excludedTags, bool bMatchAllTags, FString requiredFlags, FString omittedFlags, FString searchText, int32 fileType, FString childPublishedFileID, int32 days, bool bIncludeRecentVotesOnly, int32 cacheMaxAgeSeconds, int32 language, FString requiredKvTags, bool bTotalOnly, bool bIDsOnly, bool bReturnVoteData, bool bReturnTags, bool bReturnKvTags, bool bReturnPreviews, bool bReturnChildren, bool bReturnShortDescription, bool bReturnForSaleData, bool bReturnMetaData, int32 returnPlaytimeStats);

	/**
	* Sets the metadata for a developer on the published file
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	publishedFileID		
	* @param	appID		
	* @param	metaData	

	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PublishedFileService")
	void SetDeveloperMetadata(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, FString metaData);

	/**
	* Updates the ban status on the published file
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	publishedFileID
	* @param	appID
	* @param	bBanned
	* @param	reason				Reason why the item was banned. Only visible to admins.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PublishedFileService")
	void UpdateBanStatus(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, bool bBanned, FString reason);

	/**
	* Updates the incompatible status on the published file. "Incompatible" items are hidden from community hubs and user profiles, but can still be accessed by a direct link.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	publishedFileID
	* @param	appID
	* @param	bIncompatible
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PublishedFileService")
	void UpdateIncompatibleStatus(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, bool bIncompatible);

	/**
	* Updates tags on the published file. Existing tags will not be removed unless they are specified in the remove_tags parameter.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	publishedFileID
	* @param	appID
	* @param	addTags
	* @param	removeTags
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PublishedFileService")
	void UpdateTags(const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, FString addTags, FString removeTags);
};
