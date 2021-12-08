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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebBroadcastPostGameDataFrame
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebBroadcastPostGameDataFrame : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebBroadcastPostGameDataFrame(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString broadcastID, FString frameData)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IBroadcastService", "PostGameDataFrame", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("broadcast_id", FCString::Atoi64(*broadcastID));
		m_RequestString.AddStringField("frame_data", frameData);
	}

private:
	FOnlineAsyncTaskSteamCoreWebBroadcastPostGameDataFrame() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebBroadcastPostGameDataFrame")); }
};
