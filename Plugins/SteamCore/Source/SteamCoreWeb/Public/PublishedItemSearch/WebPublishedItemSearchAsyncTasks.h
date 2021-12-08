/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamPublishedItemSearch
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRankedByPublicationOrder
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRankedByPublicationOrder : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRankedByPublicationOrder(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamPublishedItemSearch", "RankedByPublicationOrder", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("startidx", startID);
		m_RequestString.Add("count", count);
		m_RequestString.Add("tagcount", tag.Num());
		m_RequestString.Add("usertagcount", userTag.Num());
		m_RequestString.Add("hasappadminaccess", bHasAppAdminAccess);
		m_RequestString.Add("fileType", fileType);
		m_RequestString.Add("tag", tag);
		m_RequestString.Add("usertag", userTag);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRankedByPublicationOrder() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRankedByTrend
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRankedByTrend : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRankedByTrend(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, int32 days, TArray<FString> tag, TArray<FString> userTag)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamPublishedItemSearch", "RankedByTrend", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("startidx", startID);
		m_RequestString.Add("count", count);
		m_RequestString.Add("tagcount", tag.Num());
		m_RequestString.Add("usertagcount", userTag.Num());
		m_RequestString.Add("hasappadminaccess", bHasAppAdminAccess);
		m_RequestString.Add("fileType", fileType);
		m_RequestString.Add("days", days);
		m_RequestString.Add("tag", tag);
		m_RequestString.Add("usertag", userTag);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRankedByTrend() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRankedByVote
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRankedByVote : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRankedByVote(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamPublishedItemSearch", "RankedByVote", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("startidx", startID);
		m_RequestString.Add("count", count);
		m_RequestString.Add("tagcount", tag.Num());
		m_RequestString.Add("usertagcount", userTag.Num());
		m_RequestString.Add("hasappadminaccess", bHasAppAdminAccess);
		m_RequestString.Add("fileType", fileType);
		m_RequestString.Add("tag", tag);
		m_RequestString.Add("usertag", userTag);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRankedByVote() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebResultSetSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebResultSetSummary : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebResultSetSummary(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, int32 startID, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamPublishedItemSearch", "ResultSetSummary", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("startidx", startID);
		m_RequestString.Add("tagcount", tag.Num());
		m_RequestString.Add("usertagcount", userTag.Num());
		m_RequestString.Add("hasappadminaccess", bHasAppAdminAccess);
		m_RequestString.Add("fileType", fileType);
		m_RequestString.Add("tag", tag);
		m_RequestString.Add("usertag", userTag);
	}

private:
	FOnlineAsyncTaskSteamCoreWebResultSetSummary() = delete;
};
