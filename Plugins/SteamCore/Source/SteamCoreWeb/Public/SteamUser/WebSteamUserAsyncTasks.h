/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information and interact with users.
* https://partner.steamgames.com/doc/webapi/ISteamUser
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "SteamUser/WebSteamUserTypes.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebCheckAppOwnership
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebCheckAppOwnership : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebCheckAppOwnership(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "CheckAppOwnership", key, 2, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebCheckAppOwnership() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetAppPriceInfo
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetAppPriceInfo : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetAppPriceInfo(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, TArray<int32> appIDs)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GetAppPriceInfo", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);

		FString AppIDs;
		for (int32 i = 0; i < appIDs.Num(); i++)
		{
			AppIDs.Append(FString::Printf(TEXT(",%d"), appIDs[i]));
		}

		m_RequestString.Add("appids", AppIDs);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetAppPriceInfo() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetFriendList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetFriendList : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetFriendList(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString relationship)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GetFriendList", key, 1, EVerb::GET, true)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("relationship", relationship);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetFriendList() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetPlayerBans
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetPlayerBans : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetPlayerBans(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, TArray<FString> steamIDs)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GetPlayerBans", key, 1, EVerb::GET)
	{
		FString m_SteamIDs;
		for (int32 i = 0; i < steamIDs.Num(); i++)
		{
			m_SteamIDs.Append(FString::Printf(TEXT(",%s"), *LexToString(steamIDs[i])));
		}
		m_RequestString.Add("steamids", m_SteamIDs);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetPlayerBans() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetPlayerSummaries
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetPlayerSummaries : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetPlayerSummaries(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, TArray<FString> steamIDs)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GetPlayerSummaries", key, 2, EVerb::GET)
	{
		FString m_SteamIDs;
		for (int32 i = 0; i < steamIDs.Num(); i++)
		{
			m_SteamIDs.Append(FString::Printf(TEXT(",%s"), *LexToString(steamIDs[i])));
		}
		m_RequestString.Add("steamids", m_SteamIDs);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetPlayerSummaries() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnership
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnership : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnership(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GetPublisherAppOwnership", key, 3, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnership() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnershipChanges
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnershipChanges : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnershipChanges(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString packageRowVersion, FString cdkeyRowVersion)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GetPublisherAppOwnershipChanges", key, 1, EVerb::GET)
	{
		m_RequestString.Add("packagerowversion", packageRowVersion);
		m_RequestString.Add("cdkeyrowversion", cdkeyRowVersion);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetPublisherAppOwnershipChanges() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetUserGroupList
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetUserGroupList : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetUserGroupList(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GetUserGroupList", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetUserGroupList() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGrantPackage
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGrantPackage : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGrantPackage(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 packageID, FString ipaddress, FString thirdPartyKey, int32 thirdPartyAppID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "GrantPackage", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("packageid", packageID);
		m_RequestString.Add("ipaddress", ipaddress);
		m_RequestString.Add("thirdpartykey", thirdPartyKey);
		m_RequestString.Add("thirdpartyappid", thirdPartyAppID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGrantPackage() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebResolveVanityURL
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebResolveVanityURL : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebResolveVanityURL(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString vanityURL, EVanityUrlType urlType)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUser", "ResolveVanityURL", key, 1, EVerb::GET)
	{
		m_RequestString.Add("vanityurl", vanityURL);
		m_RequestString.Add("url_type", static_cast<int32>(urlType));
	}

private:
	FOnlineAsyncTaskSteamCoreWebResolveVanityURL() = delete;
};
