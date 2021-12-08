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

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebCreateSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebCreateSession : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebCreateSession(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString context, FString title, FString users, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameNotificationsService", "CreateSession", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("context", FCString::Atoi64(*context));
		m_RequestString.AddStringField("title", title);
		m_RequestString.AddStringField("users", users);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebCreateSession() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebCreateSession")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebUpdateSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebUpdateSession : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebUpdateSession(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID, FString title, FString users, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameNotificationsService", "UpdateSession", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("sessionID", FCString::Atoi64(*sessionID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("title", title);
		m_RequestString.AddStringField("users", users);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebUpdateSession() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebUpdateSession")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebEnumerateSessionsForApp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebEnumerateSessionsForApp : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebEnumerateSessionsForApp(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, bool bIncludeAllUserMessages, bool bIncludeAuthUserMessage, FString language)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameNotificationsService", "EnumerateSessionsForApp", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddBoolField("include_all_user_messages", bIncludeAllUserMessages);
		m_RequestString.AddBoolField("include_auth_user_message", bIncludeAuthUserMessage);
		m_RequestString.AddStringField("language", language);
	}

private:
	FOnlineAsyncTaskSteamCoreWebEnumerateSessionsForApp() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebEnumerateSessionsForApp")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetSessionDetailsForApp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetSessionDetailsForApp : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetSessionDetailsForApp(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString sessions, int32 appID, FString language)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameNotificationsService", "GetSessionDetailsForApp", key, 1, EVerb::GET)
	{
		m_RequestString.AddStringField("sessions", sessions);
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("language", language);
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetSessionDetailsForApp() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetSessionDetailsForApp")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRequestNotifications
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRequestNotifications : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRequestNotifications(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameNotificationsService", "RequestNotifications", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRequestNotifications() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebRequestNotifications")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebDeleteSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebDeleteSession : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebDeleteSession(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameNotificationsService", "DeleteSession", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("sessionid", FCString::Atoi64(*sessionID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebDeleteSession() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebDeleteSession")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebDeleteSessionBatch
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebDeleteSessionBatch : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebDeleteSessionBatch(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "IGameNotificationsService", "DeleteSessionBatch", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("sessionid", FCString::Atoi64(*sessionID));
		m_RequestString.AddNumberField("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebDeleteSessionBatch() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebDeleteSessionBatch")); }
};
