/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* The primary interface to interact with the Steam Economy.
* https://partner.steamgames.com/doc/webapi/IEconService
*
* See also: https://partner.steamgames.com/doc/webapi/ISteamEconomy
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetHistoryCommandDetails
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetHistoryCommandDetails : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetHistoryCommandDetails(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString command, FString contextID, FString arguments)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameInventory", "GetHistoryCommandDetails", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("command", command);
		m_RequestString.Add("contextid", contextID);
		m_RequestString.Add("arguments", arguments);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetHistoryCommandDetails() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetHistoryCommandDetails")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetUserHistory
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetUserHistory : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetUserHistory(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString contextID, int32 startTime, int32 endTime)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameInventory", "GetUserHistory", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("contextid", contextID);
		m_RequestString.Add("starttime", startTime);
		m_RequestString.Add("endtime", endTime);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetUserHistory() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetUserHistory")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebHistoryExecuteCommands
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebHistoryExecuteCommands : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebHistoryExecuteCommands(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString contextID, int32 actorID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameInventory", "HistoryExecuteCommands", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("contextid", contextID);
		m_RequestString.Add("actorid", actorID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebHistoryExecuteCommands() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebHistoryExecuteCommands")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebSupportGetAssetHistory
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebSupportGetAssetHistory : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebSupportGetAssetHistory(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString assetID, FString contextID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameInventory", "SupportGetAssetHistory", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("assetid", assetID);
		m_RequestString.Add("contextid", contextID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebSupportGetAssetHistory() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebSupportGetAssetHistory")); }
};
