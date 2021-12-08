/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/ISteamNews
*/

#include "SteamNews/WebSteamNews.h"
#include "SteamNews/WebSteamNewsAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebSteamNews::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebSteamNews::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebSteamNews::GetNewsForApp(const FOnSteamCoreWebCallback& callback, int32 appID, int32 maxLength, TArray<FString> feeds, int32 endDate, int32 count)
{
	FOnlineAsyncTaskSteamCoreWebGetNewsForApp* Task = new FOnlineAsyncTaskSteamCoreWebGetNewsForApp(this, callback, appID, maxLength, endDate, feeds, count);
	QueueAsyncTask(Task);
}

void UWebSteamNews::GetNewsForAppAuthed(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 maxLength, TArray<FString> feeds, int32 endDate, int32 count)
{
	FOnlineAsyncTaskSteamCoreWebGetNewsForAppAuthed* Task = new FOnlineAsyncTaskSteamCoreWebGetNewsForAppAuthed(this, callback, key, appID, maxLength, endDate, feeds, count);
	QueueAsyncTask(Task);
}
