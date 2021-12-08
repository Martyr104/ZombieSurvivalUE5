/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* This is the interface used to support Microtransactions (In-Game Purchases).
* https://partner.steamgames.com/doc/webapi/ISteamMicroTxn
*
* See also: https://partner.steamgames.com/doc/features/microtransactions
*           https://partner.steamgames.com/doc/features/microtransactions/implementation
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAdjustAgreement
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAdjustAgreement : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAdjustAgreement(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString agreementID, int32 appID, FString nextProcessDate)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "AdjustAgreement", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("agreementid", agreementID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("nextprocessdate", nextProcessDate);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAdjustAgreement() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebAdjustAgreement")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebCancelAgreement
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebCancelAgreement : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebCancelAgreement(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString agreementID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "CancelAgreement", key, 1, EVerb::POST)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("agreementid", agreementID);
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebCancelAgreement() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebCancelAgreement")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebFinalizeTxn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebFinalizeTxn : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebFinalizeTxn(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString orderID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "FinalizeTxn", key, 2, EVerb::POST)
	{
		m_RequestString.Add("orderid", orderID);
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebFinalizeTxn() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebFinalizeTxn")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetReport
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetReport : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetReport(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString time, FString type, int32 MaxResults)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "GetReport", key, 4, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("type", type);
		m_RequestString.Add("time", time);
		m_RequestString.Add("MaxResults", MaxResults);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetReport() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetReport")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetUserAgreementInfo
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetUserAgreementInfo : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetUserAgreementInfo(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "GetUserAgreementInfo", key, 1, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetUserAgreementInfo() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetUserAgreementInfo")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetUserInfo
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetUserInfo : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetUserInfo(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 ipaddress)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "GetUserInfo", key, 2, EVerb::GET)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("ipaddress", ipaddress);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetUserInfo() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetUserInfo")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebInitTxn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebInitTxn : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebInitTxn(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString orderID, FString steamID, int32 appID, FString language, FString currency, FString userSession, FString ipaddress, TArray<int32> itemID, TArray<int32> quantity, TArray<FString> amount, TArray<FString> description, TArray<FString> category, TArray<int32> associatedBundle, TArray<FString> billingType, TArray<FString> startDate, TArray<FString> endDate, TArray<FString> period, TArray<int32> frequency, TArray<FString> recurringAmt, TArray<int32> bundleCount, TArray<int32> bundleID, TArray<int32> bundleQty, TArray<FString> bundleDesc, TArray<FString> bundleCategory)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "InitTxn", key, 3, EVerb::POST)
	{
		m_RequestString.Add("orderid", orderID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("itemcount", itemID.Num());
		m_RequestString.Add("language", language);
		m_RequestString.Add("currency", currency);
		m_RequestString.Add("usersession", userSession);
		m_RequestString.Add("ipaddress", ipaddress);
		m_RequestString.Add("itemid", itemID);
		m_RequestString.Add("qty", quantity);
		m_RequestString.Add("amount", amount);
		m_RequestString.Add("description", description);
		m_RequestString.Add("category", category);
		m_RequestString.Add("associated_bundle", associatedBundle);
		m_RequestString.Add("billingtype", billingType);
		m_RequestString.Add("startdate", startDate);
		m_RequestString.Add("enddate", endDate);
		m_RequestString.Add("period", period);
		m_RequestString.Add("frequency", frequency);
		m_RequestString.Add("recurringamt", recurringAmt);
		m_RequestString.Add("bundlecount", bundleCount);
		m_RequestString.Add("bundleid", bundleID);
		m_RequestString.Add("bundle_qty", bundleQty);
		m_RequestString.Add("bundle_desc", bundleDesc);
		m_RequestString.Add("bundle_category", bundleCategory);
	}

private:
	FOnlineAsyncTaskSteamCoreWebInitTxn() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebInitTxn")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebProcessAgreement
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebProcessAgreement : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebProcessAgreement(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString orderID, FString steamID, FString agreementID, int32 appID, int32 amount, FString currency)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "ProcessAgreement", key, 1, EVerb::POST)
	{
		m_RequestString.Add("orderid", orderID);
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("agreementid", agreementID);
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("amount", amount);
		m_RequestString.Add("currency", currency);
	}

private:
	FOnlineAsyncTaskSteamCoreWebProcessAgreement() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebProcessAgreement")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebQueryTxn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebQueryTxn : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebQueryTxn(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString orderID, FString transID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "QueryTxn", key, 2, EVerb::GET)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("orderid", orderID);
		m_RequestString.Add("transid", transID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebQueryTxn() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebQueryTxn")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRefundTxn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRefundTxn : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRefundTxn(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString orderID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, SteamCoreWebMicroTxnSandboxMode() ? "ISteamMicroTxnSandbox" : "ISteamMicroTxn", "RefundTxn", key, 2, EVerb::POST)
	{
		m_RequestString.Add("orderid", orderID);
		m_RequestString.Add("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRefundTxn() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebRefundTxn")); }
};
