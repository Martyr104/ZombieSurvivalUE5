/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamMatchmaking
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "SteamPartiesTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

UENUM(BlueprintType)
enum class ESteamPartiesBeaconLocationType : uint8
{
	Invalid = 0,
	ChatGroup = 1,
	Max,
};

UENUM(BlueprintType)
enum class ESteamPartiesBeaconLocationData : uint8
{
	Invalid = 0,
	Name = 1,
	IconURLSmall = 2,
	IconURLMedium = 3,
	IconURLLarge = 4,
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FSteamPartyBeaconLocation
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	ESteamPartiesBeaconLocationType Type;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	FString LocationId;
public:
	FSteamPartyBeaconLocation() = default;

	FSteamPartyBeaconLocation(const SteamPartyBeaconLocation_t& data)
		: Type(static_cast<ESteamPartiesBeaconLocationType>(data.m_eType))
		, LocationId(LexToString(data.m_ulLocationID))
	{
	}
};

USTRUCT(BlueprintType)
struct FJoinPartyData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	FPartyBeaconID BeaconID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	FSteamID SteamIDBeaconOwner;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	FString ConnectString;
public:
	FJoinPartyData() = default;

	FJoinPartyData(const JoinPartyCallback_t& data)
		: Result(_SteamResult(data.m_eResult))
		, BeaconID(data.m_ulBeaconID)
		, SteamIDBeaconOwner(data.m_SteamIDBeaconOwner)
		, ConnectString(UTF8_TO_TCHAR(data.m_rgchConnectString))
	{
	}
};

USTRUCT(BlueprintType)
struct FCreateBeaconData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	FPartyBeaconID BeaconID;
public:
	FCreateBeaconData() = default;

	FCreateBeaconData(const CreateBeaconCallback_t& data)
		: Result(_SteamResult(data.m_eResult))
		, BeaconID(data.m_ulBeaconID)
	{
	}
};

USTRUCT(BlueprintType)
struct FReservationNotificationData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	FPartyBeaconID BeaconId;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	FSteamID SteamIDJoiner;
public:
	FReservationNotificationData() = default;

	FReservationNotificationData(const ReservationNotificationCallback_t& data)
		: BeaconId(data.m_ulBeaconID)
		, SteamIDJoiner(data.m_steamIDJoiner)
	{
	}
};

USTRUCT(BlueprintType)
struct FChangeNumOpenSlotsData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SteamParties")
	ESteamResult Result;
public:
	FChangeNumOpenSlotsData() = default;

	FChangeNumOpenSlotsData(const ChangeNumOpenSlotsCallback_t& data)
		: Result(_SteamResult(data.m_eResult))
	{
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJoinPartyDelegate, const FJoinPartyData&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateBeaconDelegate, const FCreateBeaconData&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReservationNotificationDelegate, const FReservationNotificationData&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeNumOpenSlotsDelegate, const FChangeNumOpenSlotsData&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAvailableBeaconLocationsDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActiveBeaconsDelegate);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnJoinParty, const FJoinPartyData&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnCreateBeacon, const FCreateBeaconData&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnChangeNumOpenSlots, const FChangeNumOpenSlotsData&, data, bool, bWasSuccessful);
