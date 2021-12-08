/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to Steam Community features.
* https://partner.steamgames.com/doc/webapi/ISteamCommunity
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebReportAbuse
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebReportAbuse : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebReportAbuse(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamIDActor, FString steamIDTarget, int32 appID, int32 abuseType, int32 contentType, FString description, FString gid)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamCommunity", "ReportAbuse", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamidActor", steamIDActor);
		m_RequestString.Add("steamidTarget", steamIDTarget);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("abuseType", abuseType);
		m_RequestString.Add("contentType", contentType);
		m_RequestString.Add("description", description);
		m_RequestString.Add("gid", gid);
	}

private:
	FOnlineAsyncTaskSteamCoreWebReportAbuse() = delete;
};
