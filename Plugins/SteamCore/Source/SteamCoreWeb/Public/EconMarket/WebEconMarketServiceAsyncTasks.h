/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to the Steam Market for partners.
* https://partner.steamgames.com/doc/webapi/IEconMarketService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetMarketEligibility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetMarketEligibility : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetMarketEligibility(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconMarketService", "GetMarketEligibility", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetMarketEligibility() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetMarketEligibility")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebCancelAppListingsForUser
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebCancelAppListingsForUser : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebCancelAppListingsForUser(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, bool bSynchronous)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconMarketService", "CancelAppListingsForUser", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddBoolField("synchronous", bSynchronous);
	}

private:
	FOnlineAsyncTaskSteamCoreWebCancelAppListingsForUser() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebCancelAppListingsForUser")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetAssetID
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetAssetID : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetAssetID(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString listingID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconMarketService", "GetAssetID", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("listingid", FCString::Atoi64(*listingID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetAssetID() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetAssetID")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetPopular
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetPopular : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetPopular(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString language, int32 rows, int32 start, int32 filterAppID, int32 eCurrency)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconMarketService", "GetPopular", key, 1, EVerb::GET)
	{
		m_RequestString.AddStringField("language", language);
		m_RequestString.AddNumberField("rows", rows);
		m_RequestString.AddNumberField("start", start);
		m_RequestString.AddNumberField("filter_appid", filterAppID);
		m_RequestString.AddNumberField("ecurrency", eCurrency);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetPopular() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetPopular")); }
};
