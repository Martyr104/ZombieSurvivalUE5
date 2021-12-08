/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamGameServerStats
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "SteamGameServerStatsTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USTRUCT(BlueprintType)
struct FGSStatsReceived
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "GameServer")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "GameServer")
	FSteamID SteamIDUser;
public:
	FGSStatsReceived() = default;

	FGSStatsReceived(const GSStatsReceived_t& Data)
		: Result(_SteamResult(Data.m_eResult))
		, SteamIDUser(Data.m_steamIDUser)
	{
	}
};

USTRUCT(BlueprintType)
struct FGSStatsStored
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "GameServer")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "GameServer")
	FSteamID SteamIDUser;
public:
	FGSStatsStored() = default;

	FGSStatsStored(const GSStatsStored_t& Data)
		: Result(_SteamResult(Data.m_eResult))
		, SteamIDUser(Data.m_steamIDUser)
	{
	}
};

USTRUCT(BlueprintType)
struct FGSStatsUnloaded
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "GameServer")
	FSteamID SteamIDUser;

public:
	FGSStatsUnloaded() = default;

	FGSStatsUnloaded(const GSStatsUnloaded_t& Data)
		: SteamIDUser(Data.m_steamIDUser)
	{
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnServerRequestUserStats, const FGSStatsReceived&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnServerStoreUserStats, const FGSStatsStored&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGSStatsUnloaded, const FGSStatsUnloaded&, Data);