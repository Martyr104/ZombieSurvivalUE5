/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/IInventoryService
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAddItem
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAddItem : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAddItem(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, TArray<int32> itemdefID, FString itemPropsJson, FString steamID, bool bNotify, FString requestID, bool bTradeRestriction)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "AddItem", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("itemdefid", itemdefID);
		m_RequestString.Add("itempropsjson", itemPropsJson);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("notify", bNotify);
		m_RequestString.Add("requestid", requestID);
		m_RequestString.Add("trade_restriction", bTradeRestriction);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAddItem() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAddPromoItem
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAddPromoItem : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAddPromoItem(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 itemdefID, FString itemPropsJson, FString steamID, bool bNotify, FString requestID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "AddPromoItem", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("itemdefid", itemdefID);
		m_RequestString.Add("itempropsjson", itemPropsJson);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("notify", bNotify);
		m_RequestString.Add("requestid", requestID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAddPromoItem() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebConsumeItem
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebConsumeItem : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebConsumeItem(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString itemID, FString quantity, FString steamID, FString requestID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "ConsumeItem", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("itemid", itemID);
		m_RequestString.Add("quantity", quantity);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("requestid", requestID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebConsumeItem() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebExchangeItem
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebExchangeItem : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebExchangeItem(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, TArray<int32> materialsItemID, TArray<int32> materialsQuantity, FString outputItemdefID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "ExchangeItem", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("materialsitemid", materialsItemID);
		m_RequestString.Add("materialsquantity", materialsQuantity);
		m_RequestString.Add("outputitemdefid", outputItemdefID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebExchangeItem() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetInventory
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetInventory : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetInventory(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "GetInventory", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetInventory() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetItemDefs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetItemDefs : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetItemDefs(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString modifiedSince, TArray<int32> itemdefIDs, TArray<int32> workshopIDs, int32 cacheMaxAgeSeconds)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "GetItemDefs", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("modifiedsince", modifiedSince);
		m_RequestString.Add("itemdefids", itemdefIDs);
		m_RequestString.Add("workshopids", workshopIDs);
		m_RequestString.Add("cache_max_age_seconds", cacheMaxAgeSeconds);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetItemDefs() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetPriceSheet
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetPriceSheet : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetPriceSheet(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 currency)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "GetPriceSheet", key, 1, EVerb::GET)
	{
		m_RequestString.Add("ecurrency", currency);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetPriceSheet() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebConsolidate
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebConsolidate : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebConsolidate(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, TArray<int32> itemdefIDs, bool bForce)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "Consolidate", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("itemdefid", itemdefIDs);
		m_RequestString.Add("force", bForce);
	}

private:
	FOnlineAsyncTaskSteamCoreWebConsolidate() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetQuantity
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetQuantity : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetQuantity(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, TArray<int32> itemdefIDs, bool bForce)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "GetQuantity", key, 1, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("itemdefid", itemdefIDs);
		m_RequestString.Add("force", bForce);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetQuantity() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebModifyItems
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebModifyItems : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebModifyItems(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString inputJson, FString steamID, int32 timestamp, FString updates)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IInventoryService", "ModifyItems", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("input_json", inputJson);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("timestamp", timestamp);
		m_RequestString.AddStringField("updates", updates);
	}

private:
	FOnlineAsyncTaskSteamCoreWebModifyItems() = delete;
};
