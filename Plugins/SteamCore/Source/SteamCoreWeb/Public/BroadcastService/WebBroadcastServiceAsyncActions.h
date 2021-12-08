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

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebBroadcastServiceAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreAppsAsyncActionPostGameDataFrame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionPostGameDataFrame : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Provides access to Steam broadcasts.
	*		
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	appID			
	* @param	steamID			
	* @param	broadcastID		
	* @param	frameData		
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Post Game Data Frame"), Category = "SteamCoreWeb|Broadcast|Async")
	static USteamCoreWebAsyncActionPostGameDataFrame* PostGameDataFrameAsync(UObject* WorldContextObject, FString key, int32 appID, FString steamID, FString broadcastID, FString frameData);
};
