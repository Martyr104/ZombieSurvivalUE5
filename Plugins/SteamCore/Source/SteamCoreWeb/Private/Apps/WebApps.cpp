/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access data about applications on Steam.
* https://partner.steamgames.com/doc/webapi/ISteamApps
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#include "Apps/WebApps.h"
#include "Apps/WebAppsAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebApps::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebApps::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebApps::GetAppBetas(const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetAppBetas* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetAppBetas(this, callback, key, appID);
	QueueAsyncTask(Task);
}

void UWebApps::GetAppBuilds(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 count /*= 10*/)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetAppBuilds* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetAppBuilds(this, callback, key, appID, count);
	QueueAsyncTask(Task);
}

void UWebApps::GetAppDepotVersions(const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetAppDepotVersions* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetAppDepotVersions(this, callback, key, appID);
	QueueAsyncTask(Task);
}

void UWebApps::GetAppList(const FOnSteamCoreWebCallback& callback, FString key)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetAppList* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetAppList(this, callback, key);
	QueueAsyncTask(Task);
}

void UWebApps::GetCheatingReports(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 timeBegin, int32 timeEnd, bool bIncludeReports, bool bIncludeBans, int32 reportidMin /*= 0*/)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetCheatingReports* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetCheatingReports(this, callback, key, appID, timeBegin, timeEnd, bIncludeReports, bIncludeBans, reportidMin);
	QueueAsyncTask(Task);
}

void UWebApps::GetPlayersBanned(const FOnSteamCoreWebCallback& callback, FString key, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetPlayersBanned* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetPlayersBanned(this, callback, key, appID);
	QueueAsyncTask(Task);
}

void UWebApps::GetServerList(const FOnSteamCoreWebCallback& callback, FString key, FString filter, int32 limit /*= 10*/)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetServerList* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetServerList(this, callback, key, filter, limit);
	QueueAsyncTask(Task);
}

void UWebApps::GetServersAtAddress(const FOnSteamCoreWebCallback& callback, FString addr)
{
	FOnlineAsyncTaskSteamCoreWebAppsGetServersAtAddress* Task = new FOnlineAsyncTaskSteamCoreWebAppsGetServersAtAddress(this, callback, addr);
	QueueAsyncTask(Task);
}

void UWebApps::SetAppBuildLive(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 buildID, FString betaKey, FString description)
{
	FOnlineAsyncTaskSteamCoreWebAppsSetAppBuildLive* Task = new FOnlineAsyncTaskSteamCoreWebAppsSetAppBuildLive(this, callback, key, appID, buildID, betaKey, description);
	QueueAsyncTask(Task);
}

void UWebApps::UpToDateCheck(const FOnSteamCoreWebCallback& callback, int32 appID, int32 version)
{
	FOnlineAsyncTaskSteamCoreWebAppsUpToDateCheck* Task = new FOnlineAsyncTaskSteamCoreWebAppsUpToDateCheck(this, callback, appID, version);
	QueueAsyncTask(Task);
}
