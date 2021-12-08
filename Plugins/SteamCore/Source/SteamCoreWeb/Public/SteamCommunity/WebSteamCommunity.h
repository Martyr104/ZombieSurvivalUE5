/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to Steam Community features.
* https://partner.steamgames.com/doc/webapi/ISteamCommunity
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "WebSteamCommunity.generated.h"

UCLASS()
class STEAMCOREWEB_API UWebSteamCommunity : public USteamCoreWebSubsystem
{
	GENERATED_BODY()
public:
	UWebSteamCommunity() { SubsystemType = ESubsystemWeb::Community; }
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		Steam API Functions
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	* Allows publishers to report users who are behaving badly on their community hub.
	*
	* @param	key				Steamworks Web API publisher authentication key.
	* @param	steamidActor	SteamID of user doing the reporting
	* @param	steamidTarget	SteamID of the entity being accused of abuse
	* @param	appID			AppID to check for ownership
	* @param	abuseType		Abuse type code (see EAbuseReportType enum)
	* @param	contentType		Content type code (see ECommunityContentType enum)
	* @param	description		Narrative from user
	* @param	gid				GID of related record (depends on content type)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|SteamCommunity")
	void ReportAbuse(const FOnSteamCoreWebCallback& callback, FString key, FString steamIDActor, FString steamIDTarget, int32 appID, int32 abuseType, int32 contentType, FString description, FString gid);
};
