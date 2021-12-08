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

#include "CheatReporting/WebCheatReporting.h"
#include "CheatReporting/WebCheatReportingAsyncTasks.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

void UWebCheatReporting::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWebCheatReporting::Deinitialize()
{
	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UWebCheatReporting::ReportPlayerCheating(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, FString steamIDReporter, FString appData, bool bHeuristic, bool bDetection, bool bPlayerReport, bool bNoReportID, int32 gameMode, int32 suspicionStartTime, int32 severity)
{
	FOnlineAsyncTaskSteamCoreWebReportPlayerCheating* Task = new FOnlineAsyncTaskSteamCoreWebReportPlayerCheating(this, callback, key, appID, steamID, steamIDReporter, appData, bHeuristic, bDetection, bPlayerReport, bNoReportID, gameMode, suspicionStartTime, severity);
	QueueAsyncTask(Task);
}

void UWebCheatReporting::RequestPlayerGameBan(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString reportID, FString cheatDescription, int32 duration, bool bDelayBan)
{
	FOnlineAsyncTaskSteamCoreWebRequestPlayerGameBan* Task = new FOnlineAsyncTaskSteamCoreWebRequestPlayerGameBan(this, callback, key, steamID, appID, reportID, cheatDescription, duration, bDelayBan);
	QueueAsyncTask(Task);
}

void UWebCheatReporting::RemovePlayerGameBan(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebRemovePlayerGameBan* Task = new FOnlineAsyncTaskSteamCoreWebRemovePlayerGameBan(this, callback, key, steamID, appID);
	QueueAsyncTask(Task);
}

void UWebCheatReporting::GetCheatingReports(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 timeEnd, int32 timeBegin, FString reportIDmin, bool bIncludeReports, bool bIncludeBans, FString steamID)
{
	FOnlineAsyncTaskSteamCoreWebGetCheatingReports* Task = new FOnlineAsyncTaskSteamCoreWebGetCheatingReports(this, callback, key, appID, timeEnd, timeBegin, reportIDmin, bIncludeReports, bIncludeBans, steamID);
	QueueAsyncTask(Task);
}

void UWebCheatReporting::ReportCheatData(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString pathAndFileName, FString webCheatURL, FString timeNow, FString timeStarted, FString timeStopped, FString cheatName, int32 gameProcessID, int32 cheatProcessID, FString cheatParam1, FString cheatParam2)
{
	FOnlineAsyncTaskSteamCoreWebReportCheatData* Task = new FOnlineAsyncTaskSteamCoreWebReportCheatData(this, callback, key, steamID, appID, pathAndFileName, webCheatURL, timeNow, timeStarted, timeStopped, cheatName, gameProcessID, cheatProcessID, cheatParam1, cheatParam2);
	QueueAsyncTask(Task);
}

void UWebCheatReporting::RequestVacStatusForUser(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString sessionID)
{
	FOnlineAsyncTaskSteamCoreWebRequestVacStatusForUser* Task = new FOnlineAsyncTaskSteamCoreWebRequestVacStatusForUser(this, callback, key, steamID, appID, sessionID);
	QueueAsyncTask(Task);
}

void UWebCheatReporting::StartSecureMultiplayerSession(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID)
{
	FOnlineAsyncTaskSteamCoreWebStartSecureMultiplayerSession* Task = new FOnlineAsyncTaskSteamCoreWebStartSecureMultiplayerSession(this, callback, key, steamID, appID);
	QueueAsyncTask(Task);
}

void UWebCheatReporting::EndSecureMultiplayerSession(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID, FString sessionID)
{
	FOnlineAsyncTaskSteamCoreWebEndSecureMultiplayerSession* Task = new FOnlineAsyncTaskSteamCoreWebEndSecureMultiplayerSession(this, callback, key, steamID, appID, sessionID);
	QueueAsyncTask(Task);
}
