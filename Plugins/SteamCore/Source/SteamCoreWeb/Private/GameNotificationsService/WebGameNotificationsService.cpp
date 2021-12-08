/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* This is the interface used to interact with Game Notifications.
* https://partner.steamgames.com/doc/webapi/IGameNotificationsService
*
* See also: https://partner.steamgames.com/doc/features/game_notifications
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#include "GameNotificationsService/WebGameNotificationsService.h"
#include "GameNotificationsService/WebGameNotificationsServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebGameNotificationsService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebGameNotificationsService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebGameNotificationsService::CreateSession(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString context, FString title, FString users, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebCreateSession* Task = new FOnlineAsyncTaskSteamCoreWebCreateSession(this, callback, key, appID, context, title, users, steamID);
	QueueAsyncTask(Task);
}

void UWebGameNotificationsService::UpdateSession(const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID, FString title, FString users, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebUpdateSession* Task = new FOnlineAsyncTaskSteamCoreWebUpdateSession(this, callback, key, sessionID, appID, title, users, steamID);
	QueueAsyncTask(Task);
}

void UWebGameNotificationsService::EnumerateSessionsForApp(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, bool bIncludeAllUserMessages, bool bIncludeAuthUserMessage, FString language)
{
	FOnlineAsyncTaskSteamCoreWebEnumerateSessionsForApp* Task = new FOnlineAsyncTaskSteamCoreWebEnumerateSessionsForApp(this, callback, key, appID, steamID, bIncludeAllUserMessages, bIncludeAuthUserMessage, language);
	QueueAsyncTask(Task);
}

void UWebGameNotificationsService::GetSessionDetailsForApp(const FOnSteamCoreWebCallback& callback, FString key, FString sessions, int32 appID, FString language)
{
	FOnlineAsyncTaskSteamCoreWebGetSessionDetailsForApp* Task = new FOnlineAsyncTaskSteamCoreWebGetSessionDetailsForApp(this, callback, key, sessions, appID, language);
	QueueAsyncTask(Task);
}

void UWebGameNotificationsService::RequestNotifications(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebRequestNotifications* Task = new FOnlineAsyncTaskSteamCoreWebRequestNotifications(this, callback, key, steamID, appID);
	QueueAsyncTask(Task);
}

void UWebGameNotificationsService::DeleteSession(const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebDeleteSession* Task = new FOnlineAsyncTaskSteamCoreWebDeleteSession(this, callback, key, sessionID, appID, steamID);
	QueueAsyncTask(Task);
}

void UWebGameNotificationsService::DeleteSessionBatch(const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebDeleteSessionBatch* Task = new FOnlineAsyncTaskSteamCoreWebDeleteSessionBatch(this, callback, key, sessionID, appID);
	QueueAsyncTask(Task);
}
