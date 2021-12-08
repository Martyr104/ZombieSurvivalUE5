/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides access to the Steam Lobby methods.
* https://partner.steamgames.com/doc/webapi/ILobbyMatchmakingService
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebLobbyMatchmakingServiceTypes.h"
#include "WebLobbyMatchmakingService.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebLobbyMatchmakingService : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebLobbyMatchmakingService() { SubsystemType = ESubsystemWeb::LobbyMatchmaking; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* When using the CreateLobby WebAPI, you'll probably want to set lobby_type to 4 (k_ELobbyTypePrivateUnique). 
	* This lobby type is a private, unique lobby that does not get deleted when emptied, and only one will exist per unique appid/lobby_name.
	* A private unique lobby can only be created by this WebAPI call. But you can also use CreateLobby to generate the more traditional and ephemeral lobbies when no lobby_name is used.
	*
	* Steamid_invited_members will be a json array of all the steamIDs that should be currently allowed into the lobby. 
	* You can update the list of members by calling CreateLobby with the same lobby_name and new complete set of steamIDs.
	* Any steamIDs that were previously in the lobby and not included in the new call will be removed from the lobby.
	* Lobby_metadata is completely optional, but can be used to send general lobby data that needs to be communicated to users in the client.
	*
	* @param	key						Steamworks Web API user authentication key.
	* @param	appID					The ID of the application associated with the lobby.
	* @param	maxMembers				Maximum number of members for this lobby.
	* @param	lobbyType				ESteamCoreWebLobbyType - The type and visibility of this lobby.
	* @param	lobbyName				Unique lobby name if lobby_type = 4. Find lobby with this name if it exists.
	* @param	inputJson				Json data. Required for data that cannot be posted parameters, but can also be used for the other parameters
	* @param	steamIDInvitedMembers	Array of steamIDs to add slots for. Must be specified in the input_json parameter.
	* @param	lobbyMetaData			Optional lobby data. Must be specified in the input_json parameter.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|LobbyMatchmakingService")
	void CreateLobby(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, int32 maxMembers, ESteamCoreWebLobbyType lobbyType, FString lobbyName, FString inputJson, TArray<FString> steamIDInvitedMembers, FString lobbyMetaData);

	/**
	* Remove user from lobby
	*
	* @param	key						Steamworks Web API user authentication key.
	* @param	appID					The ID of the application associated with the lobby.
	* @param	steamIDToRemove			SteamID of the user to remove. If the user is not online when called, this will remove their reserved slot in the lobby.
	* @param	steamIDLobby			Lobby ID
	* @param	inputJson				Json data. Required for data that cannot be posted parameters, but can also be used for the other parameters
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|LobbyMatchmakingService")
	void RemoveUserFromLobby(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString steamIDToRemove, FString steamIDLobby, FString inputJson);
};
