/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Primary interface for interacting with the Steam Workshop and User Generated Content (UGC).
* https://partner.steamgames.com/doc/webapi/IRemoteStorage
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebRemoteStorage.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebRemoteStorage : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebRemoteStorage() { SubsystemType = ESubsystemWeb::SteamCoreWeb; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Enumerate User Published Files
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appID		appID of product
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void EnumerateUserPublishedFiles(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID);

	/**
	* Enumerate User Subscribed Files
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID		SteamID of user
	* @param	appID		appID of product
	* @param	listType	EUCMListType
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void EnumerateUserSubscribedFiles(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 listType);

	/**
	* Get Collection Details
	*
	* @param	publishedFileIDs		collection ids to get the details for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void GetCollectionDetails(const FOnSteamCoreWebCallback& callback, TArray<FString> publishedFileIDs);

	/**
	* Get Collection Details
	*
	* @param	publishedFileIDs		collection ids to get the details for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void GetPublishedFileDetails(const FOnSteamCoreWebCallback& callback, FString publishedFileID);

	/**
	* Get UGC File Details
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	steamID			If specified, only returns details if the file is owned by the SteamID specified
	* @param	UGCID	 		ID of UGC file to get info for
	* @param	appID			appID of product
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void GetUGCFileDetails(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString UGCID, int32 appID);

	/**
	* Set UGC Used By GC
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			If specified, only returns details if the file is owned by the SteamID specified
	* @param	UGCID	 		ID of UGC file to get info for
	* @param	appID			appID of product
	* @param	bUsed			New state of flag
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void SetUGCUsedByGC(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString UGCID, int32 appID, bool bUsed);

	/**
	* Subscribe Published File
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					If specified, only returns details if the file is owned by the SteamID specified
	* @param	appID					appID of product
	* @param	publishedFileID			published file id to subscribe to
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void SubscribePublishedFile(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString publishedFileID);

	/**
	* Unsubscribe Published File
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					If specified, only returns details if the file is owned by the SteamID specified
	* @param	appID					appID of product
	* @param	publishedFileID			published file id to unsubscribe from
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|RemoteStorage")
	void UnsubscribePublishedFile(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString publishedFileID);
};
