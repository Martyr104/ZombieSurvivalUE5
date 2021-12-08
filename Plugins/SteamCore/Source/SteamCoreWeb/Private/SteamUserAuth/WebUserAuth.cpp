/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information about users.
* https://partner.steamgames.com/doc/webapi/IUserAuth
*/

#include "SteamUserAuth/WebUserAuth.h"
#include "SteamUserAuth/WebUserAuthAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebUserAuth::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebUserAuth::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebUserAuth::AuthenticateUser(const FOnSteamCoreWebCallback& callback, FString steamID, TArray<uint8> sessionKey, TArray<uint8> encryptedLoginKey)
{
	FOnlineAsyncTaskSteamCoreWebAuthenticateUser* Task = new FOnlineAsyncTaskSteamCoreWebAuthenticateUser(this, callback, steamID, sessionKey, encryptedLoginKey);
	QueueAsyncTask(Task);
}

void UWebUserAuth::AuthenticateUserTicket(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString ticket)
{
	FOnlineAsyncTaskSteamCoreWebAuthenticateUserTicket* Task = new FOnlineAsyncTaskSteamCoreWebAuthenticateUserTicket(this, callback, key, appID, ticket);
	QueueAsyncTask(Task);
}
