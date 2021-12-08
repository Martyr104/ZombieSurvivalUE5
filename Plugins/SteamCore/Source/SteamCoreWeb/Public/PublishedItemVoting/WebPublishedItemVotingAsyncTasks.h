/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Allows partners to access the voting information of the content in their Steam Workshop.
* https://partner.steamgames.com/doc/webapi/IPublishedItemVoting
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebItemVoteSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebItemVoteSummary : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebItemVoteSummary(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, TArray<FString> publishedFileIDs)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPublishedItemVoting", "ItemVoteSummary", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("count", publishedFileIDs.Num());
		m_RequestString.Add("publishedfileid", publishedFileIDs);
	}

private:
	FOnlineAsyncTaskSteamCoreWebItemVoteSummary() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebUserVoteSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebUserVoteSummary : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebUserVoteSummary(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, TArray<FString> publishedFileIDs)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPublishedItemVoting", "UserVoteSummary", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("count", publishedFileIDs.Num());
		m_RequestString.Add("publishedfileid", publishedFileIDs);
	}

private:
	FOnlineAsyncTaskSteamCoreWebUserVoteSummary() = delete;
};
