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

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebGameNotificationsService.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebGameNotificationsService : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebGameNotificationsService() { SubsystemType = ESubsystemWeb::GameNotifications; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Creates a brand new async session with the players specified in the request.
	*
	* The unique session id returned in this API call should be stored with the game session state of the game, as it will be used to reference other calls in the Game Notifications API
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	appID				The App ID of the session to update.
	* @param	context	(int64)		Game-specified context value the game can use to associate the session with some object on their backend.
	* @param	title				The title of the session to be displayed within each user's list of sessions.
	* @param	users				The initial state of all users in the session.
	* @param	steamID				(Optional) Steam ID to make the request on behalf of -- if specified, the user must be in the session and all users being added to the session must be friends with the user.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameNotificationsService")
	void CreateSession(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString context, FString title, FString users, FString steamID);

	/**
	* Update a game session whenever the state of the game changes.
	*
	* Be sure to update the state of each user accordingly, as what is sent here will be reflected in user notifications for all users in the game. 
	* Any users that were in the session that are not specified will be removed from the session, and any newly specified users will be added to the session. 
	* You must send the complete state of the session -- all previous state will be replaced by the newly specified state.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	sessionID (int64)	The sessionid to update.
	* @param	appID				The App ID of the session to update.
	* @param	title				(Optional) The new title of the session. If not specified, the title will not be changed.
	* @param	users				(Optional) A list of users whose state will be updated to reflect the given state. If the users are not already in the session, they will be added to it.
	* @param	steamID				(Optional) Steam ID to make the request on behalf of -- if specified, the user must be in the session.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameNotificationsService")
	void UpdateSession(const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID, FString title, FString users, FString steamID);

	/**
	* This returns a list of sessions that a Steam ID is part of.
	*
	* The optional bools will return further details about each session if set.
	*
	* @param	key							Steamworks Web API publisher authentication key.
	* @param	appID						The sessionid to request details for. Optional. If not specified, all the user's sessions will be returned.
	* @param	steamID						The user whose sessions are to be enumerated.
	* @param	bIncludeAllUserMessages		(Optional) Set whether the message for all users should be included. Defaults to false.
	* @param	bIncludeAuthUserMessage		(Optional) Set whether the message for the authenticated user should be included. Defaults to false.
	* @param	language					(Optional) Language to localize the text in.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameNotificationsService")
	void EnumerateSessionsForApp(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamID, bool bIncludeAllUserMessages, bool bIncludeAuthUserMessage, FString language);

	/**
	* Returns details about specific session(s).
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	sessions			The session(s) to receive the details for
	* @param	appID				The appid for the sessions.
	* @param	language			Language to localize the text in.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameNotificationsService")
	void GetSessionDetailsForApp(const FOnSteamCoreWebCallback& callback, FString key, FString sessions, int32 appID, FString language);

	/**
	* Requests that a user receive game notifications for an app.
	*
	* Whenever a user starts a game that requires game notifications, the server must make a RequestNotifications call for the signed in user. 
	* This will register your game to use offline notifications with the user by asking the user to opt into game notifications for your specific game. 
	* Make this call, at most, once per game launch. Subsequent calls will not ask the user to opt in if the user has decided to opt out.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamID			The Steam ID to request notifications for.
	* @param	appID			The App ID to request notifications for.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameNotificationsService")
	void RequestNotifications(const FOnSteamCoreWebCallback& callback, FString key, FString steamID, int32 appID);

	/**
	* Delete an active async game session. This will remove all notifications to any user that is part of the game session.
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	sessionID (int64)	The sessionid to delete.
	* @param	appID				The App ID of the session to delete.
	* @param	steamID				(Optional) Steam ID to make the request on behalf of -- if specified, the user must be in the session.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameNotificationsService")
	void DeleteSession(const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID, FString steamID);

	/**
	* Deletes a batch of async game sessions
	*
	* @param	key					Steamworks Web API publisher authentication key.
	* @param	sessionID (int64)	The sessionid to delete.
	* @param	appID				The App ID of the session to delete.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|GameNotificationsService")
	void DeleteSessionBatch(const FOnSteamCoreWebCallback& callback, FString key, FString sessionID, int32 appID);
};
