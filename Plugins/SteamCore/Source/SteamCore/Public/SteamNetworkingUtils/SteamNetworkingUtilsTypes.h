/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamNetworkingUtils
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "SteamNetworkingUtilsTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FSteamNetworkPingLocation
{
	GENERATED_BODY()
public:
	FSteamNetworkPingLocation() = default;

	FSteamNetworkPingLocation(const SteamNetworkPingLocation_t& Val)
	{
		char* m_Data = new char[k_cchMaxSteamNetworkingPingLocationString];
		SteamNetworkingUtils()->ConvertPingLocationToString(Val, m_Data, k_cchMaxSteamNetworkingPingLocationString);
		Location = UTF8_TO_TCHAR(m_Data);
		delete[] m_Data;
	}

public:
	operator SteamNetworkPingLocation_t()
	{
		SteamNetworkPingLocation_t m_Data;
		SteamNetworkingUtils()->ParsePingLocationString(TCHAR_TO_UTF8(*Location), m_Data);
		return m_Data;
	}

	operator SteamNetworkPingLocation_t() const
	{
		SteamNetworkPingLocation_t m_Data;
		SteamNetworkingUtils()->ParsePingLocationString(TCHAR_TO_UTF8(*Location), m_Data);
		return m_Data;
	}

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "NetworkingUtils")
	FString Location;
};
