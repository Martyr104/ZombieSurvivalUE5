/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access data about applications on Steam.
* https://partner.steamgames.com/doc/webapi/ISteamApps
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetAppBetas
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetAppBetas : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppBetas(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetAppBetas", key)
	{
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppBetas() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetAppBetas")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetAppBuilds
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetAppBuilds : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppBuilds(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString key, int32 appID, int32 count)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetAppBuilds", key)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("count", count);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppBuilds() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetAppBuilds")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetAppDepotVersions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetAppDepotVersions : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppDepotVersions(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString key, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetAppDepotVersion", key)
	{
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppDepotVersions() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetAppDepotVersions")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetAppList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetAppList : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppList(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString key)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetAppList", key, 2)
	{
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetAppList() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetAppList")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetCheatingReports
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetCheatingReports : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetCheatingReports(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString key, int32 appID, int32 timeBegin, int32 timeEnd, bool bIncludeReports, bool bIncludeBans, int32 reportidMin)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetCheatingReports", key)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("timebegin", timeBegin);
		m_RequestString.Add("timeend", timeEnd);
		m_RequestString.Add("includereports", bIncludeReports);
		m_RequestString.Add("includebans", bIncludeBans);
		m_RequestString.Add("reportidmin", reportidMin);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetCheatingReports() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetCheatingReports")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetPlayersBanned
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetPlayersBanned : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetPlayersBanned(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString key, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetPlayersBanned", key)
	{
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetPlayersBanned() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetPlayersBanned")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetServerList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetServerList : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetServerList(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString key, FString filter, int32 limit)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetServerList", key)
	{
		m_RequestString.Add("filter", filter);
		m_RequestString.Add("limit", limit);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetServerList() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetServerList")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsGetServersAtAddress
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsGetServersAtAddress : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsGetServersAtAddress(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString addr)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "GetServersAtAddress")
	{
		m_RequestString.Add("addr", addr);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsGetServersAtAddress() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsGetServersAtAddress")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsSetAppBuildLive
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsSetAppBuildLive : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsSetAppBuildLive(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, FString key, int32 appID, int32 buildID, FString betaKey, FString description)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "SetAppBuildLive", key)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("buildid", buildID);
		m_RequestString.Add("betakey", betaKey);
		m_RequestString.Add("description", description);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsSetAppBuildLive() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsSetAppBuildLive")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAppsUpToDateCheck
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAppsUpToDateCheck : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAppsUpToDateCheck(USteamCoreWebSubsystem* subsystem, FOnSteamCoreWebCallback callback, int32 appID, int32 version)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamApps", "UpToDateCheck")
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("version", version);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAppsUpToDateCheck() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAppsUpToDateCheck")); }
};
