/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamEconomy
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebCanTrade
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebCanTrade : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebCanTrade(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString targetID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "CanTrade", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("targetid", targetID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebCanTrade() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebFinalizeAssetTransaction
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebFinalizeAssetTransaction : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebFinalizeAssetTransaction(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString txnID, FString language)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "FinalizeAssetTransaction", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("txnid", txnID);
		m_RequestString.Add("language", language);
	}

private:
	FOnlineAsyncTaskSteamCoreWebFinalizeAssetTransaction() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetAssetClassInfo
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetAssetClassInfo : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetAssetClassInfo(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString language, int32 classCount, FString classID, FString instanceID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "GetAssetClassInfo", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("language", language);
		m_RequestString.Add("class_count", language);
		m_RequestString.Add("classid0", classID);
		m_RequestString.Add("instanceid0", instanceID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetAssetClassInfo() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetAssetPrices
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetAssetPrices : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetAssetPrices(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString currency, FString language)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "GetAssetPrices", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("currency", currency);
		m_RequestString.Add("language", language);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetAssetPrices() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetExportedAssetsForUser
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetExportedAssetsForUser : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetExportedAssetsForUser(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString contextID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "GetExportedAssetsForUser", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("contextid", contextID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetExportedAssetsForUser() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetMarketPrices
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetMarketPrices : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetMarketPrices(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "GetMarketPrices", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetMarketPrices() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebStartAssetTransaction
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebStartAssetTransaction : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebStartAssetTransaction(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString assetID, int32 assetQuantity, FString currency, FString language, FString ipaddress, FString referer, bool bClientAuth)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "StartAssetTransaction", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("assetid0", assetID);
		m_RequestString.Add("assetquantity0", assetQuantity);
		m_RequestString.Add("currency", currency);
		m_RequestString.Add("language", language);
		m_RequestString.Add("ipaddress", ipaddress);
		m_RequestString.Add("referrer", referer);
		m_RequestString.Add("clientauth", bClientAuth);
	}

private:
	FOnlineAsyncTaskSteamCoreWebStartAssetTransaction() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebStartTrade
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebStartTrade : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebStartTrade(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID1, FString steamID2)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamEconomy", "StartTrade", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("partya", steamID1);
		m_RequestString.Add("partya", steamID2);
	}

private:
	FOnlineAsyncTaskSteamCoreWebStartTrade() = delete;
};
