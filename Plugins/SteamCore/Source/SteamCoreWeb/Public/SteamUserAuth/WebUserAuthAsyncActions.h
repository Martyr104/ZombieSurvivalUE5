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
#include "WebUserAuthAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionAuthenticateUser
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionAuthenticateUser : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Authenticate User
	*
	* @param	steamID					Should be the users steamid, unencrypted.
	* @param	sessionKey				Should be a 32 byte random blob of data, which is then encrypted with RSA using the Steam system's public key. Randomness is important here for security.
	* @param	encryptedLoginKey		Should be the users hashed loginkey, AES encrypted with the sessionkey.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Authenticate User"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionAuthenticateUser* AuthenticateUserAsync(UObject* WorldContextObject, FString steamID, TArray<uint8> sessionKey, TArray<uint8> encryptedLoginKey);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionAuthenticateUserTicket
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionAuthenticateUserTicket : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
	/**
	* Authenticate User Ticket
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the betas of.
	* @param	ticket		Convert the ticket from GetAuthSessionTicket from binary to hex into an appropriately sized byte character array and pass the result in as this ticket parameter.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Authenticate User Ticket"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionAuthenticateUserTicket* AuthenticateUserTicketAsync(UObject* WorldContextObject, FString key, int32 appID, FString ticket);
};
