/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamNews
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebSteamNews.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebSteamNews : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebSteamNews() { SubsystemType = ESubsystemWeb::News; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Get the news for the specified app.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			AppID to retrieve news for
	* @param	maxLength		Maximum length for the content to return, if this is 0 the full content is returned, if it's less then a blurb is generated to fit.
	* @param	endDate			Retrieve posts earlier than this date (unix epoch timestamp)
	* @param	feeds			# of posts to retrieve (default 20)
	* @param	count			List of feed names to return news for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamNews", meta = (AutoCreateRefTerm = "feeds"))
	void GetNewsForApp(const FOnSteamCoreWebCallback& callback, int32 appID, int32 maxLength, TArray<FString> feeds, int32 endDate = 1549795233, int32 count = 20);

	/**
	* Get the news for the specified app. Publisher only version that can return info for unreleased games.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			AppID to retrieve news for
	* @param	maxLength		Maximum length for the content to return, if this is 0 the full content is returned, if it's less then a blurb is generated to fit.
	* @param	endDate			Retrieve posts earlier than this date (unix epoch timestamp)
	* @param	feeds			# of posts to retrieve (default 20)
	* @param	count			List of feed names to return news for
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamNews", meta = (AutoCreateRefTerm = "feeds"))
	void GetNewsForAppAuthed(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 maxLength, TArray<FString> feeds, int32 endDate = 1549795233, int32 count = 20);
};
