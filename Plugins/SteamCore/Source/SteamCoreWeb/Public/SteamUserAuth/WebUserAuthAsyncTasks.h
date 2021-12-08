/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information about users.
* https://partner.steamgames.com/doc/webapi/IUserAuth
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAuthenticateUser
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAuthenticateUser : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAuthenticateUser(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString steamID, TArray<uint8> sessionKey, TArray<uint8> encryptedLoginKey)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserAuth", "AuthenticateUser", "", 1, EVerb::POST, true)
	{
		m_RequestString.Add("steamid", steamID);
		m_RequestString.Add("sessionkey", sessionKey);
		m_RequestString.Add("encrypted_loginkey", encryptedLoginKey);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAuthenticateUser() = delete;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebAuthenticateUserTicket
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebAuthenticateUserTicket : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebAuthenticateUserTicket(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString ticket)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ISteamUserAuth", "AuthenticateUserTicket", key, 1, EVerb::GET, true)
	{
		m_RequestString.Add("appid", appID);
		m_RequestString.Add("ticket", ticket);
	}

private:
	FOnlineAsyncTaskSteamCoreWebAuthenticateUserTicket() = delete;
};
