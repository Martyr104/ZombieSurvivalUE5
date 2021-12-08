/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides access to Steam broadcasts.
* https://partner.steamgames.com/doc/webapi/IBroadcastService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebBroadcastService.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebBroadcastService : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebBroadcastService() { SubsystemType = ESubsystemWeb::Broadcast; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Gets all of the beta branches for the specified application.
	*
	* NOTE: This call requires the publisher API key that owns the specified App ID to use this method. As such this API MUST be called from a secure server, and can never be used directly by clients!
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the betas of.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Apps")
	void PostGameDataFrame(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString broadcastID, FString frameData);
};
