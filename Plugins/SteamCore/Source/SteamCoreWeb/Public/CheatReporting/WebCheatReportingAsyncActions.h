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
#include "WebCheatReportingAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionReportPlayerCheating
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionReportPlayerCheating : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* ReportPlayerCheating is designed to gather community reports of cheating, where one player reports another player within the game.
	*
	* It is intended for unreliable data from peers in the game ( semi-trusted sources ). The back-end that reports the data should ensure that both parties are authenticated, but the data in itself is treated as hearsay. Optional parameters may be used to encode the type of cheating that is suspected or additional evidence ( an identifier pointing to the match/demo for further review )
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				The App ID for the game.
	* @param	steamID				The Steam ID of the user who is being reported for cheating.
	* @param	steamIDReporter		(Optional) The Steam ID of the user or game server who is reporting the cheating.
	* @param	appData				(Optional) App specific data about the type of cheating set by developer. (ex 1 = Aimbot, 2 = Wallhack, 3 = Griefing)
	* @param	bHeuristic			(Optional) Extra information about the source of the cheating - was it a heuristic.
	* @param	bDetection			(Optional) Extra information about the source of the cheating - was it a detection.
	* @param	bPlayerReport		(Optional) Extra information about the source of the cheating - was it a player report.
	* @param	bNoReportID			(Optional) Don't return reportid. This should only be passed if you don't intend to issue a ban based on this report.
	* @param	gameMode			(Optional) Extra information about state of game - was it a specific type of game play or game mode. (0 = generic)
	* @param	suspicionStartTime	(Optional) Extra information indicating how far back the game thinks is interesting for this user. Unix epoch time (time since Jan 1st, 1970).
	* @param	severity			(Optional) Level of severity of bad action being reported. Scale set by developer.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Report Player Cheating"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionReportPlayerCheating* ReportPlayerCheatingAsync(UObject* WorldContextObject, FString key, int32 appID, FString steamID, FString steamIDReporter, FString appData, bool bHeuristic, bool bDetection, bool bPlayerReport, bool bNoReportID, int32 gameMode, int32 suspicionStartTime, int32 severity);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRequestPlayerGameBan
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionRequestPlayerGameBan : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Requests a game ban on a specific player.
	*
	* This is designed to be used after the incidents from ReportPlayerCheating have been reviewed and cheating has been confirmed.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				The Steam ID of the user who is being reported for cheating.
	* @param	appID				The App ID for the game.
	* @param	reportID			The reportid originally used to report cheating.
	* @param	cheatDescription	Text describing cheating infraction.
	* @param	duration			Ban duration requested in seconds. (duration 0 will issue infinite - less than a year is a suspension and not visible on profile)
	* @param	bDelayBan			Delay the ban according to default ban delay rules.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Request Player Game Ban"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionRequestPlayerGameBan* RequestPlayerGameBanAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString reportID, FString cheatDescription, int32 duration, bool bDelayBan);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRemovePlayerGameBan
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionRemovePlayerGameBan : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Remove a game ban on a player.
	*
	* This is used if a Game ban is determined to be a false positive.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The Steam ID of the user to remove the game ban on.
	* @param	appID			The App ID for the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Remove Player Game Ban"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionRemovePlayerGameBan* RemovePlayerGameBanAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionGetCheatingReports
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionGetCheatingReports : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Get a list of cheating reports submitted for this app.
	*
	* Used to gather the cheating reports so that they may be reviewed and a determination made.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				The App ID for the game.
	* @param	timeEnd				The end of the time range. Formatted as Unix epoch time (time since Jan 1st, 1970).
	* @param	timeBegin			The beginning of the time range. Formatted as Unix epoch time (time since Jan 1st, 1970).
	* @param	reportIDmin			Minimum reportID to include. (can pass 0 - end of previous report range)
	* @param	bIncludeReports		(Optional) Include reports. If false includebans must be true.
	* @param	bIncludeBans		(Optional) Include ban requests? If false includereports must be true.
	* @param	steamID				(Optional) Query just for this Steam ID.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Get Cheating Reports"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionGetCheatingReports* GetCheatingReportsAsync(UObject* WorldContextObject, FString key, int32 appID, int32 timeEnd, int32 timeBegin, FString reportIDmin, bool bIncludeReports, bool bIncludeBans, FString steamID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionReportCheatData
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionReportCheatData : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Reports cheat data. Only use on test account that is running the game but not in a multiplayer session.
	*
	* This is for reporting specific cheats to the VAC system. This is done by running the cheat and the game and then calling this webapi.
	*
	* @param	key						Steamworks Web API publisher authentication key.
	* @param	steamID					The Steam ID of the user to remove the game ban on.
	* @param	appID					The App ID for the game.
	* @param	pathAndFileName			Path and file name of the cheat executable.
	* @param	webCheatURL				Web url where the cheat was found and downloaded.
	* @param	timeNow					Local system time now. 64 bit windows system time.
	* @param	timeStarted				Local system time when cheat process started. ( 0 if not yet run ) 64 bit windows system time.
	* @param	timeStopped				Local system time when cheat process stopped. ( 0 if still running ) 64 bit windows system time.
	* @param	cheatName				Descriptive name for the cheat.
	* @param	gameProcessID			Process ID of the running game.
	* @param	cheatProcessID			Process ID of the cheat process that ran.
	* @param	cheatParam1	(int64)		Extra cheat data.
	* @param	cheatParam2	(int64)		Extra cheat data.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Report Cheat Data"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionReportCheatData* ReportCheatDataAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString pathAndFileName, FString webCheatURL, FString timeNow, FString timeStarted, FString timeStopped, FString cheatName, int32 gameProcessID, int32 cheatProcessID, FString cheatParam1, FString cheatParam2);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionRequestVacStatusForUser
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionRequestVacStatusForUser : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Checks a user's VAC ban status and verifies a user's VAC session status. If verification fails, then do not let the user matchmake into a secure game.
	*
	* This is used before a user enters matchmaking or joins a game.
	* If the player is blocking VAC in some way and VAC can not scan the computer for cheats, it will report success = true and session_verified = false.
	* Checking this webapi will allow you to prevent the user from matchmaking or joining a server and then just getting kicked by VAC a short time later ( with a k_EAuthSessionResponseVACCheckTimedOut result from an authentication callback ).
	* The VAC system may not always have had time to fully determine if the clients system is cooperating, and if so it will report success = false.
	* It is also possible for the players system to pass the initial check but then fail to respond later, in that case verification will succeed, but a k_EAuthSessionResponseVACCheckTimedOut may follow later.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				The Steam ID of the user.
	* @param	appID				The App ID for the game.
	* @param	sessionID (int64)	The Session ID that was obtained from the call to StartSecureMultiplayerSession.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Request VAC Status for User"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionRequestVacStatusForUser* RequestVacStatusForUserAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString sessionID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionStartSecureMultiplayerSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionStartSecureMultiplayerSession : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Tell the VAC servers that a secure multiplayer session has started.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The Steam ID of the user.
	* @param	appID			The App ID for the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Start Secure Multiplayer Session"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionStartSecureMultiplayerSession* StartSecureMultiplayerSessionAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionEndSecureMultiplayerSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionEndSecureMultiplayerSession : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Tell the VAC servers that a secure multiplayer session has ended.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	steamID				The Steam ID of the user.
	* @param	appID				The App ID for the game.
	* @param	sessionID (int64)	The Session ID that was obtained from the call to StartSecureMultiplayerSession.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "End Secure Multiplayer Session"), Category = "SteamCoreWeb|CheatReporting|Async")
	static USteamCoreWebAsyncActionEndSecureMultiplayerSession* EndSecureMultiplayerSessionAsync(UObject* WorldContextObject, FString key, FString steamID, int32 appID, FString sessionID);
};
