/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to Steam Community features.
* https://partner.steamgames.com/doc/webapi/ISteamCommunity
*/

#include "SteamCommunity/WebSteamCommunity.h"
#include "SteamCommunity/WebSteamCommunityAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebSteamCommunity::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebSteamCommunity::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebSteamCommunity::ReportAbuse(const FOnSteamCoreWebCallback& callback, FString key, FString steamIDActor, FString steamIDTarget, int32 appID, int32 abuseType, int32 contentType, FString description, FString gid)
{
	FOnlineAsyncTaskSteamCoreWebReportAbuse* Task = new FOnlineAsyncTaskSteamCoreWebReportAbuse(this, callback, key, steamIDActor, steamIDTarget, appID, abuseType, contentType, description, gid);
	QueueAsyncTask(Task);
}
