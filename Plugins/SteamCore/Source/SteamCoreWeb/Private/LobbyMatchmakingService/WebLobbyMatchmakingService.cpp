/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides access to the Steam Lobby methods.
* https://partner.steamgames.com/doc/webapi/ILobbyMatchmakingService
*/

#include "LobbyMatchmakingService/WebLobbyMatchmakingService.h"
#include "LobbyMatchmakingService/WebLobbyMatchmakingServiceAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebLobbyMatchmakingService::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebLobbyMatchmakingService::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebLobbyMatchmakingService::CreateLobby(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 maxMembers, ESteamCoreWebLobbyType lobbyType, FString lobbyName, FString inputJson, TArray<FString> steamIDInvitedMembers, FString lobbyMetaData)
{
	FOnlineAsyncTaskSteamCoreWebCreateLobby* Task = new FOnlineAsyncTaskSteamCoreWebCreateLobby(this, callback, key, appID, maxMembers, lobbyType, lobbyName, inputJson, steamIDInvitedMembers, lobbyMetaData);
	QueueAsyncTask(Task);
}

void UWebLobbyMatchmakingService::RemoveUserFromLobby(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamIDToRemove, FString steamIDLobby, FString inputJson)
{
	FOnlineAsyncTaskSteamCoreWebRemoveUserFromLobby* Task = new FOnlineAsyncTaskSteamCoreWebRemoveUserFromLobby(this, callback, key, appID, steamIDToRemove, steamIDLobby, inputJson);
	QueueAsyncTask(Task);
}
