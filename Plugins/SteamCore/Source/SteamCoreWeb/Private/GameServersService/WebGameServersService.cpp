/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Methods to improve the administration of Steam Game Servers.
* https://partner.steamgames.com/doc/webapi/IGameServersService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#include "GameServersService/WebGameServersService.h"
#include "GameServersService/WebGameServersServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebGameServersService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebGameServersService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

/*
void UWebGameServersService:z:PostGameDataFrame(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString broadcastID, FString frameData)
{
	FOnlineAsyncTaskSteamCoreWebBroadcastPostGameDataFrame* Task = new FOnlineAsyncTaskSteamCoreWebBroadcastPostGameDataFrame(this, callback, key, appID, steamID, broadcastID, frameData);
	QueueAsyncTask(Task);
}*/

void UWebGameServersService::GetAccountList(const FOnSteamCoreWebCallback& callback, FString key)
{
}

void UWebGameServersService::CreateAccount(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString memo)
{
}

void UWebGameServersService::SetMemo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, FString memo)
{
}

void UWebGameServersService::ResetLoginToken(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
}

void UWebGameServersService::DeleteAccount(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
}

void UWebGameServersService::GetAccountPublicInfo(const FOnSteamCoreWebCallback& callback, FString key, FString steamID)
{
}

void UWebGameServersService::QueryLoginToken(const FOnSteamCoreWebCallback& callback, FString key, FString loginToken)
{
}

void UWebGameServersService::SetBanStatus(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, bool bBanned, int32 banSeconds)
{
}

void UWebGameServersService::GetServerSteamIDsByIP(const FOnSteamCoreWebCallback& callback, FString key, FString serverIP)
{
}

void UWebGameServersService::GetServerIPsBySteamID(const FOnSteamCoreWebCallback& callback, FString key, FString serverSteamID)
{
}
