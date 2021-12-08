/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamRemotePlay
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamRemotePlayTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UENUM(BlueprintType)
enum class ESteamCoreDeviceFormFactor : uint8
{
	Unknown = 0,
	Phone,
	Tablet,
	Computer,
	TV,
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FSteamRemotePlaySessionConnected
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RemotePlay")
	int32 SessionID;
public:
	FSteamRemotePlaySessionConnected() = default;

	FSteamRemotePlaySessionConnected(const SteamRemotePlaySessionConnected_t& data)
		: SessionID(data.m_unSessionID)
	{
	}

public:
	operator uint32() const { return SessionID; }
	operator int32() const { return SessionID; }
	operator uint32() { return SessionID; }
	operator int32() { return SessionID; }
};

USTRUCT(BlueprintType)
struct FSteamRemotePlaySessionDisconnected
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RemotePlay")
	int32 SessionID;
public:
	FSteamRemotePlaySessionDisconnected() = default;

	FSteamRemotePlaySessionDisconnected(const SteamRemotePlaySessionDisconnected_t& data)
		: SessionID(data.m_unSessionID)
	{
	}

public:
	operator uint32() const { return SessionID; }
	operator int32() const { return SessionID; }
	operator uint32() { return SessionID; }
	operator int32() { return SessionID; }
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamRemotePlaySessionConnected, const FSteamRemotePlaySessionConnected&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamRemotePlaySessionDisconnected, const FSteamRemotePlaySessionDisconnected&, data);
