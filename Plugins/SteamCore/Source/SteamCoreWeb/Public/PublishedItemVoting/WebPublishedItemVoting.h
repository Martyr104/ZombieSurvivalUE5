/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Allows partners to access the voting information of the content in their Steam Workshop.
* https://partner.steamgames.com/doc/webapi/IPublishedItemVoting
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebPublishedItemVoting.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebPublishedItemVoting : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebPublishedItemVoting() { SubsystemType = ESubsystemWeb::PublishedItemVoting; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Item Vote Summary
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					Steam ID of user
	* @param	appID					appID of product
	* @param	publishedFileIDs		The Published File ID who's vote details are required
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PublishedItemVoting", meta = (AutoCreateRefTerm = "publishedFileIDs"))
	void ItemVoteSummary(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, TArray<FString> publishedFileIDs);

	/**
	* Item Vote Summary
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					Steam ID of user
	* @param	publishedFileIDs		The Published File ID who's vote details are required
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|PublishedItemVoting", meta = (AutoCreateRefTerm = "publishedFileIDs"))
	void UserVoteSummary(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, TArray<FString> publishedFileIDs);
};
