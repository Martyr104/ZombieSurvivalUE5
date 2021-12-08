/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Additional Steam Economy methods that provide access to Steam Trading.
* https://partner.steamgames.com/doc/webapi/IEconService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetTradeHistory
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetTradeHistory : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetTradeHistory(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 maxTrades, int32 startAfterTime, FString startAfterTradeID, bool bNavigatingBack, bool bGetDescriptions, FString language, bool bIncludeFailed, bool bIncludeTotal)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "GetTradeHistory", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("max_trades", maxTrades);
		m_RequestString.AddNumberField("start_after_time", startAfterTime);
		m_RequestString.AddNumberField("start_after_tradeid", FCString::Atoi64(*startAfterTradeID));
		m_RequestString.AddBoolField("navigating_back", bNavigatingBack);
		m_RequestString.AddBoolField("get_descriptions", bGetDescriptions);
		m_RequestString.AddStringField("language", language);
		m_RequestString.AddBoolField("include_failed", bIncludeFailed);
		m_RequestString.AddBoolField("include_total", bIncludeTotal);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetTradeHistory() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetTradeHistory")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebFlushInventoryCache
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebFlushInventoryCache : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebFlushInventoryCache(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString contextID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "FlushInventoryCache", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("contextid", FCString::Atoi64(*contextID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebFlushInventoryCache() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebFlushInventoryCache")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebFlushAssetAppearanceCache
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebFlushAssetAppearanceCache : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebFlushAssetAppearanceCache(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "FlushAssetAppearanceCache", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebFlushAssetAppearanceCache() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebFlushAssetAppearanceCache")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebFlushContextCache
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebFlushContextCache : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebFlushContextCache(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "FlushContextCache", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebFlushContextCache() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebFlushContextCache")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetTradeOffers
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetTradeOffers : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetTradeOffers(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, bool bGetSentOffers, bool bGetReceivedOffers, bool bGetDescriptions, FString language, bool bActiveOnly, bool bHistoricalOnly, int32 timeHistoricalCutoff)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "GetTradeOffers", key, 1, EVerb::GET)
	{
		m_RequestString.AddBoolField("get_sent_offers", bGetSentOffers);
		m_RequestString.AddBoolField("get_received_offers", bGetReceivedOffers);
		m_RequestString.AddBoolField("get_descriptions", bGetDescriptions);
		m_RequestString.AddStringField("language", language);
		m_RequestString.AddBoolField("active_only", bActiveOnly);
		m_RequestString.AddBoolField("historical_only", bHistoricalOnly);
		m_RequestString.AddNumberField("time_historical_cutoff", timeHistoricalCutoff);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetTradeOffers() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetTradeOffers")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetTradeOffer
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetTradeOffer : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetTradeOffer(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString tradeOfferID, FString language)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "GetTradeOffer", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("tradeofferid", FCString::Atoi64(*tradeOfferID));
		m_RequestString.AddStringField("language", language);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetTradeOffer() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetTradeOffer")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetTradeOffersSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetTradeOffersSummary : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetTradeOffersSummary(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 timeLastVisit)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "GetTradeOffersSummary", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("time_last_visit", timeLastVisit);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetTradeOffersSummary() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetTradeOffersSummary")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebDeclineTradeOffer
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebDeclineTradeOffer : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebDeclineTradeOffer(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString tradeOfferID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "DeclineTradeOffer", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("tradeofferid", FCString::Atoi64(*tradeOfferID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebDeclineTradeOffer() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebDeclineTradeOffer")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebCancelTradeOffer
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebCancelTradeOffer : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebCancelTradeOffer(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString tradeOfferID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IEconService", "CancelTradeOffer", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("tradeofferid", FCString::Atoi64(*tradeOfferID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebCancelTradeOffer() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebCancelTradeOffer")); }
};
