/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides additional methods for interacting with Steam Workshop items.
* https://partner.steamgames.com/doc/webapi/IPublishedFileService
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebQueryFiles
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebQueryFiles : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebQueryFiles(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 queryType, int32 page, FString cursor, int32 numPerPage, int32 creatorAppID, int32 appID, FString requiredTags, FString excludedTags, bool bMatchAllTags, FString requiredFlags, FString omittedFlags, FString searchText, int32 fileType, FString childPublishedFileID, int32 days, bool bIncludeRecentVotesOnly, int32 cacheMaxAgeSeconds, int32 language, FString requiredKvTags, bool bTotalOnly, bool bIDsOnly, bool bReturnVoteData, bool bReturnTags, bool bReturnKvTags, bool bReturnPreviews, bool bReturnChildren, bool bReturnShortDescription, bool bReturnForSaleData, bool bReturnMetaData, int32 returnPlaytimeStats)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPublishedFileService", "QueryFiles", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("query_type", queryType);
		m_RequestString.AddNumberField("page", page);
		m_RequestString.AddStringField("cursor", cursor);
		m_RequestString.AddNumberField("numperpage", numPerPage);
		m_RequestString.AddNumberField("creator_appid", creatorAppID);
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("requiredtags", requiredTags);
		m_RequestString.AddStringField("excludedtags", excludedTags);
		m_RequestString.AddBoolField("match_all_tags", bMatchAllTags);
		m_RequestString.AddStringField("required_flags", requiredFlags);
		m_RequestString.AddStringField("omitted_flags", omittedFlags);
		m_RequestString.AddStringField("search_text", searchText);
		m_RequestString.AddNumberField("filetype", fileType);
		m_RequestString.AddStringField("child_publishedfileid", childPublishedFileID);
		m_RequestString.AddNumberField("days", days);
		m_RequestString.AddBoolField("include_recent_votes_only", bIncludeRecentVotesOnly);
		m_RequestString.AddNumberField("cache_max_age_seconds", cacheMaxAgeSeconds);
		m_RequestString.AddNumberField("language", language);
		m_RequestString.AddStringField("required_kv_tags", requiredKvTags);
		m_RequestString.AddBoolField("totalonly", bTotalOnly);
		m_RequestString.AddBoolField("ids_only", bIDsOnly);
		m_RequestString.AddBoolField("return_vote_data", bReturnVoteData);
		m_RequestString.AddBoolField("return_tags", bReturnTags);
		m_RequestString.AddBoolField("return_kv_tags", bReturnKvTags);
		m_RequestString.AddBoolField("return_previews", bReturnPreviews);
		m_RequestString.AddBoolField("return_children", bReturnChildren);
		m_RequestString.AddBoolField("return_short_description", bReturnShortDescription);
		m_RequestString.AddBoolField("return_for_sale_data", bReturnForSaleData);
		m_RequestString.AddBoolField("return_metadata", bReturnMetaData);
		m_RequestString.AddNumberField("return_playtime_stats", returnPlaytimeStats);
	}

private:
	FOnlineAsyncTaskSteamCoreWebQueryFiles() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebSetDeveloperMetadata
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebSetDeveloperMetadata : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebSetDeveloperMetadata(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, FString metaData)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPublishedFileService", "SetDeveloperMetadata", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("publishedfileid", FCString::Atoi64(*publishedFileID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("metadata", metaData);
	}

private:
	FOnlineAsyncTaskSteamCoreWebSetDeveloperMetadata() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebUpdateBanStatus
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebUpdateBanStatus : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebUpdateBanStatus(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, bool bBanned, FString reason)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPublishedFileService", "UpdateBanStatus", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("publishedfileid", FCString::Atoi64(*publishedFileID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddBoolField("banned", bBanned);
		m_RequestString.AddStringField("reason", reason);
	}

private:
	FOnlineAsyncTaskSteamCoreWebUpdateBanStatus() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebUpdateIncompatibleStatus
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebUpdateIncompatibleStatus : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebUpdateIncompatibleStatus(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, bool bIncompatible)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPublishedFileService", "UpdateIncompatibleStatus", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("publishedfileid", FCString::Atoi64(*publishedFileID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddBoolField("incompatible", bIncompatible);
	}

private:
	FOnlineAsyncTaskSteamCoreWebUpdateIncompatibleStatus() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebUpdateTags
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebUpdateTags : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebUpdateTags(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString publishedFileID, int32 appID, FString addTags, FString removeTags)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IPublishedFileService", "UpdateTags", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("publishedfileid", FCString::Atoi64(*publishedFileID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("add_tags", addTags);
		m_RequestString.AddStringField("remove_tags", removeTags);
	}

private:
	FOnlineAsyncTaskSteamCoreWebUpdateTags() = delete;
};
