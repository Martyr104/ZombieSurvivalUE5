/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore::Web Documentation: https://eeldev.com/index.php/steamcoreweb-plugin/
*
* Provides restricted access to Steam Community features.
* https://partner.steamgames.com/doc/webapi/ISteamCommunity
*/

#pragma once

#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "WebSteamCommunityAsyncActions.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreWebAsyncActionReportAbuse
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncActionReportAbuse : public USteamCoreWebAsyncAction
{
	GENERATED_BODY()
public:
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
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Report Abuse"), Category = "SteamCoreWeb|PlayerService|Async")
	static USteamCoreWebAsyncActionReportAbuse* ReportAbuseAsync(UObject* WorldContextObject, FString key, FString steamIDActor, FString steamIDTarget, int32 appID, int32 abuseType, int32 contentType, FString description, FString gid);
};
