/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Used to access information about users.
* https://partner.steamgames.com/doc/webapi/IUserAuth
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebUserAuth.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebUserAuth : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebUserAuth() { SubsystemType = ESubsystemWeb::UserAuth; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Authenticate User
	*
	* @param	steamID					Should be the users steamid, unencrypted.
	* @param	sessionKey				Should be a 32 byte random blob of data, which is then encrypted with RSA using the Steam system's public key. Randomness is important here for security.
	* @param	encryptedLoginKey		Should be the users hashed loginkey, AES encrypted with the sessionkey.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|UserAuth")
	void AuthenticateUser(const FOnSteamCoreWebCallback& callback, FString steamID, TArray<uint8> sessionKey, TArray<uint8> encryptedLoginKey);

	/**
	* Authenticate User Ticket
	*
	* @param	key			Steamworks Web API publisher authentication key.
	* @param	appID		The App ID to get the betas of.
	* @param	ticket		Convert the ticket from GetAuthSessionTicket from binary to hex into an appropriately sized byte character array and pass the result in as this ticket parameter.
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|UserAuth")
	void AuthenticateUserTicket(const FOnSteamCoreWebCallback& callback, FString key, int32 appID, FString ticket);
};
