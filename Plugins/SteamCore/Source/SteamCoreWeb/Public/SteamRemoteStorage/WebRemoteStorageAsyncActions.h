/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Primary interface for interacting with the Steam Workshop and User Generated Content (UGC).
* https://partner.steamgames.com/doc/webapi/IRemoteStorage
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebRemoteStorageAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionEnumerateUserPublishedFiles
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionEnumerateUserPublishedFiles : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Enumerate User Published Files
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appID		appID of product
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Enumerate User Published Files"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionEnumerateUserPublishedFiles* EnumerateUserPublishedFilesAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionEnumerateUserSubscribedFiles
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionEnumerateUserSubscribedFiles : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Enumerate User Subscribed Files
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appID		appID of product
	* @param	listType	EUCMListType
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = ""), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionEnumerateUserSubscribedFiles* EnumerateUserSubscribedFilesAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 listType);
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetCollectionDetails
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetCollectionDetails : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Collection Details
	*
	* @param	publishedFileIDs		collection ids to get the details for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Collection Details"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetCollectionDetails* GetCollectionDetailsAsync(UObject* WorldContextObject, TArray<FString> publishedFileIDs);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetPublishedFileDetails
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetPublishedFileDetails : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get Collection Details
	*
	* @param	publishedFileIDs		collection ids to get the details for
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Published File Details"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetPublishedFileDetails* GetPublishedFileDetailsAsync(UObject* WorldContextObject, FString publishedFileID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetUGCFileDetails
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetUGCFileDetails : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get UGC File Details
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			If specified, only returns details if the file is owned by the SteamID specified
	* @param	UGCID	 		ID of UGC file to get info for
	* @param	appID			appID of product
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get UGC File Details"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionGetUGCFileDetails* GetUGCFileDetailsAsync(UObject* WorldContextObject, FString key, FString steamID, FString UGCID, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionSetUGCUsedByGC
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionSetUGCUsedByGC : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Set UGC Used By GC
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			If specified, only returns details if the file is owned by the SteamID specified
	* @param	UGCID	 		ID of UGC file to get info for
	* @param	appID			appID of product
	* @param	bUsed			New state of flag
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Set UGC Used By GC"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionSetUGCUsedByGC* SetUGCUsedByGCAsync(UObject* WorldContextObject, FString key, FString steamID, FString UGCID, int32 appID, bool bUsed);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionSubscribePublishedFile
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionSubscribePublishedFile : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Subscribe Published File
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					If specified, only returns details if the file is owned by the SteamID specified
	* @param	appID					appID of product
	* @param	publishedFileID			published file id to subscribe to
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Subscribe Published File"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionSubscribePublishedFile* SubscribePublishedFileAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString publishedFileID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionUnsubscribePublishedFile
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionUnsubscribePublishedFile : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Unsubscribe Published File
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					If specified, only returns details if the file is owned by the SteamID specified
	* @param	appID					appID of product
	* @param	publishedFileID			published file id to unsubscribe from
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Unsubscribe Published File"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionUnsubscribePublishedFile* UnsubscribePublishedFileAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString publishedFileID);
};
