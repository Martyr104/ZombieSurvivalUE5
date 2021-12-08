/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides access to the Steam Lobby methods.
* https://partner.steamgames.com/doc/webapi/ILobbyMatchmakingService
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebLobbyMatchmakingServiceTypes.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebCreateLobby
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebCreateLobby : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebCreateLobby(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 maxMembers, ESteamCoreWebLobbyType lobbyType, FString lobbyName, FString inputJson, TArray<FString> steamIDInvitedMembers, FString lobbyMetaData)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ILobbyMatchmakingService", "CreateLobby", key, 1, EVerb::POST)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("max_members", maxMembers);
		m_RequestString.Add("lobby_type", static_cast<int32>(lobbyType));
		m_RequestString.Add("lobby_name", lobbyName);
		m_RequestString.AddStringField("input_json", inputJson);
		TArray<TSharedPtr<FJsonValue>> m_Arr;

		for (int32 i = 0; i < steamIDInvitedMembers.Num(); i++)
		{
			m_Arr.Add(MakeShared<FJsonValueString>(LexToString(steamIDInvitedMembers[i])));
		}

		m_RequestString.AddArrayField("steamid_invited_members", m_Arr);
		m_RequestString.AddStringField("lobby_metadata", lobbyMetaData);
	}

private:
	FOnlineAsyncTaskSteamCoreWebCreateLobby() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRemoveUserFromLobby
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRemoveUserFromLobby : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRemoveUserFromLobby(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamIDToRemove, FString steamIDLobby, FString inputJson)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ILobbyMatchmakingService", "RemoveUserFromLobby", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("steamid_to_remove", FCString::Atoi64(*steamIDToRemove));
		m_RequestString.AddNumberField("steamid_lobby", FCString::Atoi64(*steamIDLobby));
		m_RequestString.AddStringField("input_json", inputJson);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRemoveUserFromLobby() = delete;
};
