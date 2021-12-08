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

#include "MicroTxn/WebMicroTxn.h"
#include "MicroTxn/WebMicroTxnAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebMicroTxn::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebMicroTxn::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebMicroTxn::AdjustAgreement(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString agreementID, int32 appID, FString nextProcessDate)
{
	FOnlineAsyncTaskSteamCoreWebAdjustAgreement* Task = new FOnlineAsyncTaskSteamCoreWebAdjustAgreement(this, callback, key, steamID, agreementID, appID, nextProcessDate);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::CancelAgreement(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString agreementID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebCancelAgreement* Task = new FOnlineAsyncTaskSteamCoreWebCancelAgreement(this, callback, key, steamID, agreementID, appID);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::FinalizeTxn(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebFinalizeTxn* Task = new FOnlineAsyncTaskSteamCoreWebFinalizeTxn(this, callback, key, orderID, appID);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::GetReport(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString time, FString type, int32 MaxResults)
{
	FOnlineAsyncTaskSteamCoreWebGetReport* Task = new FOnlineAsyncTaskSteamCoreWebGetReport(this, callback, key, appID, time, type, MaxResults);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::GetUserAgreementInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebGetUserAgreementInfo* Task = new FOnlineAsyncTaskSteamCoreWebGetUserAgreementInfo(this, callback, key, steamID, appID);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::GetUserInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 ipaddress)
{
	FOnlineAsyncTaskSteamCoreWebGetUserInfo* Task = new FOnlineAsyncTaskSteamCoreWebGetUserInfo(this, callback, key, steamID, ipaddress);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::InitTxn(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, FString steamID, int32 appID, FString language, FString currency, FString userSession, FString ipaddress, TArray<int32> itemID, TArray<int32> quantity, TArray<FString> amount, TArray<FString> description, TArray<FString> category, TArray<int32> associatedBundle, TArray<FString> billingType, TArray<FString> startDate, TArray<FString> endDate, TArray<FString> period, TArray<int32> frequency, TArray<FString> recurringAmt, TArray<int32> bundleCount, TArray<int32> bundleID, TArray<int32> bundleQty, TArray<FString> bundleDesc, TArray<FString> bundleCategory)
{
	FOnlineAsyncTaskSteamCoreWebInitTxn* Task = new FOnlineAsyncTaskSteamCoreWebInitTxn(this, callback, key, orderID, steamID, appID, language, currency, userSession, ipaddress, itemID, quantity, amount, description, category, associatedBundle, billingType, startDate, endDate, period, frequency, recurringAmt, bundleCount, bundleID, bundleQty, bundleDesc, bundleCategory);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::ProcessAgreement(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, FString steamID, FString agreementID, int32 appID, int32 amount, FString currency)
{
	FOnlineAsyncTaskSteamCoreWebProcessAgreement* Task = new FOnlineAsyncTaskSteamCoreWebProcessAgreement(this, callback, key, orderID, steamID, agreementID, appID, amount, currency);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::QueryTxn(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString orderID, FString transID)
{
	FOnlineAsyncTaskSteamCoreWebQueryTxn* Task = new FOnlineAsyncTaskSteamCoreWebQueryTxn(this, callback, key, appID, orderID, transID);
	QueueAsyncTask(Task);
}

void UWebMicroTxn::RefundTxn(const FOnSteamCoreWebCallback& callback, FString key, FString orderID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebRefundTxn* Task = new FOnlineAsyncTaskSteamCoreWebRefundTxn(this, callback, key, orderID, appID);
	QueueAsyncTask(Task);
}

FString UWebMicroTxn::MakeTransactionID()
{
	return FString::Printf(TEXT("%d"), (FMath::Rand() * 9223372036854775807));
}
