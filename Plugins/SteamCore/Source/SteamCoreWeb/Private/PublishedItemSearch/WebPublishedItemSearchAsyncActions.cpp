/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamPublishedItemSearch
*/

#include "PublishedItemSearch/WebPublishedItemSearchAsyncActions.h"
#include "PublishedItemSearch/WebPublishedItemSearchAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"
#include "SteamCoreWeb/SteamCoreWeb.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRankedByPublicationOrder
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreWebAsyncActionRankedByPublicationOrder* USteamCoreWebAsyncActionRankedByPublicationOrder::RankedByPublicationOrderAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
{
	auto* GameInstance = WorldContextObject->GetWorld()->GetGameInstance();
	auto* Subsystem = GameInstance->GetSubsystem<USteamCoreWebSubsystem>();

	auto* AsyncObject = NewObject<USteamCoreWebAsyncActionRankedByPublicationOrder>();
	auto* Task = new FOnlineAsyncTaskSteamCoreWebRankedByPublicationOrder(Subsystem, AsyncObject->OnCallbackInternal, key, steamID, appID, startID, count, bHasAppAdminAccess, fileType, tag, userTag);
	AsyncObject->RegisterWithGameInstance(GameInstance);
	AsyncObject->m_WorldContextObject = WorldContextObject;
	Subsystem->QueueAsyncTask(Task);
	AsyncObject->Activate();

	return AsyncObject;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRankedByTrend
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreWebAsyncActionRankedByTrend* USteamCoreWebAsyncActionRankedByTrend::RankedByTrendAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, int32 days, TArray<FString> tag, TArray<FString> userTag)
{
	auto* GameInstance = WorldContextObject->GetWorld()->GetGameInstance();
	auto* Subsystem = GameInstance->GetSubsystem<USteamCoreWebSubsystem>();

	auto* AsyncObject = NewObject<USteamCoreWebAsyncActionRankedByTrend>();
	auto* Task = new FOnlineAsyncTaskSteamCoreWebRankedByTrend(Subsystem, AsyncObject->OnCallbackInternal, key, steamID, appID, startID, count, bHasAppAdminAccess, fileType, days, tag, userTag);
	AsyncObject->RegisterWithGameInstance(GameInstance);
	AsyncObject->m_WorldContextObject = WorldContextObject;
	Subsystem->QueueAsyncTask(Task);
	AsyncObject->Activate();

	return AsyncObject;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRankedByVote
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreWebAsyncActionRankedByVote* USteamCoreWebAsyncActionRankedByVote::RankedByVoteAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, int32 count, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
{
	auto* GameInstance = WorldContextObject->GetWorld()->GetGameInstance();
	auto* Subsystem = GameInstance->GetSubsystem<USteamCoreWebSubsystem>();

	auto* AsyncObject = NewObject<USteamCoreWebAsyncActionRankedByVote>();
	auto* Task = new FOnlineAsyncTaskSteamCoreWebRankedByVote(Subsystem, AsyncObject->OnCallbackInternal, key, steamID, appID, startID, count, bHasAppAdminAccess, fileType, tag, userTag);
	AsyncObject->RegisterWithGameInstance(GameInstance);
	AsyncObject->m_WorldContextObject = WorldContextObject;
	Subsystem->QueueAsyncTask(Task);
	AsyncObject->Activate();

	return AsyncObject;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionResultSetSummary
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreWebAsyncActionResultSetSummary* USteamCoreWebAsyncActionResultSetSummary::ResultSetSummaryAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, int32 startID, bool bHasAppAdminAccess, int32 fileType, TArray<FString> tag, TArray<FString> userTag)
{
	auto* GameInstance = WorldContextObject->GetWorld()->GetGameInstance();
	auto* Subsystem = GameInstance->GetSubsystem<USteamCoreWebSubsystem>();

	auto* AsyncObject = NewObject<USteamCoreWebAsyncActionResultSetSummary>();
	auto* Task = new FOnlineAsyncTaskSteamCoreWebResultSetSummary(Subsystem, AsyncObject->OnCallbackInternal, key, steamID, appID, startID, bHasAppAdminAccess, fileType, tag, userTag);
	AsyncObject->RegisterWithGameInstance(GameInstance);
	AsyncObject->m_WorldContextObject = WorldContextObject;
	Subsystem->QueueAsyncTask(Task);
	AsyncObject->Activate();

	return AsyncObject;
}
