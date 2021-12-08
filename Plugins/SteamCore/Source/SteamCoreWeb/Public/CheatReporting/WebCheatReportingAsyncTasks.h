/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* This service allows your game to report cheats and cheaters to the VAC system and provides the toolset behind the Game Bans system. It enables two independent workflows for detecting and managing cheating in your game
* To use this interface you must first opt in to VAC support. This can be done from the Anti-Cheat Configuration page in the App Admin panel.
* https://partner.steamgames.com/doc/webapi/ICheatReportingService
*
* For more info on how to use the Steamworks Web API please see the Web API Overview.
* https://partner.steamgames.com/doc/webapi_overview
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebReportPlayerCheating
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebReportPlayerCheating : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebReportPlayerCheating(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString steamIDReporter, FString appData, bool bHeuristic, bool bDetection, bool bPlayerReport, bool bNoReportID, int32 gameMode, int32 suspicionStartTime, int32 severity)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "ReportPlayerCheating", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("steamidreporter", FCString::Atoi64(*steamIDReporter));
		m_RequestString.AddBoolField("heuristic", bHeuristic);
		m_RequestString.AddBoolField("detection", bDetection);
		m_RequestString.AddBoolField("playerreport", bPlayerReport);
		m_RequestString.AddBoolField("noreportid", bNoReportID);
		m_RequestString.AddNumberField("gamemode", gameMode);
		m_RequestString.AddNumberField("suspicionstarttime", suspicionStartTime);
		m_RequestString.AddNumberField("severity", severity);
	}

private:
	FOnlineAsyncTaskSteamCoreWebReportPlayerCheating() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebReportPlayerCheating")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRequestPlayerGameBan
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRequestPlayerGameBan : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRequestPlayerGameBan(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString reportID, FString cheatDescription, int32 duration, bool bDelayBan)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "RequestPlayerGameBan", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("reportid", FCString::Atoi64(*reportID));
		m_RequestString.AddStringField("cheatdescription", cheatDescription);
		m_RequestString.AddNumberField("duration", duration);
		m_RequestString.AddBoolField("delayban", bDelayBan);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRequestPlayerGameBan() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebRequestPlayerGameBan")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRemovePlayerGameBan
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRemovePlayerGameBan : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRemovePlayerGameBan(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "RequestPlayerGameBan", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebRemovePlayerGameBan() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebRemovePlayerGameBan")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebGetCheatingReports
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebGetCheatingReports : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebGetCheatingReports(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 timeEnd, int32 timeBegin, FString reportIDmin, bool bIncludeReports, bool bIncludeBans, FString steamID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "GetCheatingReports", key, 1, EVerb::GET)
	{
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("timeend", timeEnd);
		m_RequestString.AddNumberField("timebegin", timeBegin);
		m_RequestString.AddNumberField("reportidmin", FCString::Atoi64(*reportIDmin));
		m_RequestString.AddBoolField("includereports", bIncludeReports);
		m_RequestString.AddBoolField("includebans", bIncludeBans);
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebGetCheatingReports() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebGetCheatingReports")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebReportCheatData
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebReportCheatData : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebReportCheatData(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString pathAndFileName, FString webCheatURL, FString timeNow, FString timeStarted, FString timeStopped, FString cheatName, int32 gameProcessID, int32 cheatProcessID, FString cheatParam1, FString cheatParam2)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "ReportCheatData", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddStringField("pathandfilename", pathAndFileName);
		m_RequestString.AddStringField("webcheaturl", pathAndFileName);
		m_RequestString.AddNumberField("time_now", FCString::Atoi64(*timeNow));
		m_RequestString.AddNumberField("time_started", FCString::Atoi64(*timeStarted));
		m_RequestString.AddNumberField("time_stopped", FCString::Atoi64(*timeStopped));
		m_RequestString.AddStringField("cheatname", cheatName);
		m_RequestString.AddNumberField("game_process_id", gameProcessID);
		m_RequestString.AddNumberField("cheat_process_id", cheatProcessID);
		m_RequestString.AddNumberField("cheat_param_1", FCString::Atoi64(*cheatParam1));
		m_RequestString.AddNumberField("cheat_param_2", FCString::Atoi64(*cheatParam2));
	}

private:
	FOnlineAsyncTaskSteamCoreWebReportCheatData() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebReportCheatData")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebRequestVacStatusForUser
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebRequestVacStatusForUser : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebRequestVacStatusForUser(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString sessionID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "RequestVacStatusForUser", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("session_id", FCString::Atoi64(*sessionID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebRequestVacStatusForUser() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebRequestVacStatusForUser")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebStartSecureMultiplayerSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebStartSecureMultiplayerSession : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebStartSecureMultiplayerSession(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "StartSecureMultiplayerSession", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
	}

private:
	FOnlineAsyncTaskSteamCoreWebStartSecureMultiplayerSession() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebStartSecureMultiplayerSession")); }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreWebEndSecureMultiplayerSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
class FOnlineAsyncTaskSteamCoreWebEndSecureMultiplayerSession : public FOnlineAsyncTaskSteamCoreWeb
{
public:
	FOnlineAsyncTaskSteamCoreWebEndSecureMultiplayerSession(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString sessionID)
		: FOnlineAsyncTaskSteamCoreWeb(subsystem, callback, "ICheatReportingService", "EndSecureMultiplayerSession", key, 1, EVerb::POST)
	{
		m_RequestString.AddNumberField("steamid", FCString::Atoi64(*steamID));
		m_RequestString.AddNumberField("appid", appID);
		m_RequestString.AddNumberField("session_id", FCString::Atoi64(*sessionID));
	}

private:
	FOnlineAsyncTaskSteamCoreWebEndSecureMultiplayerSession() = delete;
	virtual FString ToString() const override { return FString::Printf(TEXT("FOnlineAsyncTaskSteamCoreWebEndSecureMultiplayerSession")); }
};
