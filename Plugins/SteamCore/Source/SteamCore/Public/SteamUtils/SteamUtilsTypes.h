/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamUtils
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "SteamUtilsTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

UENUM(BlueprintType)
enum class ESteamTextFilteringContext : uint8
{
	k_ETextFilteringContextUnknown = 0,
	// Unknown context
	k_ETextFilteringContextGameContent = 1,
	// Game content, only legally required filtering is performed
	k_ETextFilteringContextChat = 2,
	// Chat from another player
	k_ETextFilteringContextName = 3,
	// Character or item name
};

UENUM(BlueprintType)
enum class ESteamCheckFileSignature : uint8
{
	InvalidSignature = 0,
	ValidSignature = 1,
	FileNotFound = 2,
	NoSignaturesFoundForThisApp = 3,
	NoSignaturesFoundForThisFile = 4,
};

UENUM(BlueprintType)
enum class ESteamGamepadTextInputLineMode : uint8
{
	SingleLine = 0,
	MultipleLines = 1
};

UENUM(BlueprintType)
enum class ESteamGamepadTextInputMode : uint8
{
	Normal = 0,
	Password = 1
};

UENUM(BlueprintType)
enum class ESteamNotificationPosition : uint8
{
	TopLeft = 0,
	TopRight = 1,
	BottomLeft = 2,
	BottomRight = 3,
};

UENUM(BlueprintType)
enum class ESteamUniverse : uint8
{
	Invalid = 0,
	Public = 1,
	Beta = 2,
	Internal = 3,
	Dev = 4,
	Max
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USTRUCT(BlueprintType)
struct FCheckFileSignature
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Utils")
	ESteamCheckFileSignature CheckFileSignature;

public:
	FCheckFileSignature() = default;

	FCheckFileSignature(const CheckFileSignature_t& data)
		: CheckFileSignature(static_cast<ESteamCheckFileSignature>(data.m_eCheckFileSignature))
	{
	}
};

USTRUCT(BlueprintType)
struct FGamepadTextInputDismissed
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Utils")
	bool bSubmitted;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Utils")
	int32 SubmittedText;

public:
	FGamepadTextInputDismissed() = default;

	FGamepadTextInputDismissed(const GamepadTextInputDismissed_t& data)
		: bSubmitted(data.m_bSubmitted)
		, SubmittedText(data.m_unSubmittedText)
	{
	}
};

USTRUCT(BlueprintType)
struct FLowBatteryPower
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Utils")
	int32 MinutesBatteryLeft;

public:
	FLowBatteryPower() = default;

	FLowBatteryPower(const LowBatteryPower_t& data)
		: MinutesBatteryLeft(data.m_nMinutesBatteryLeft)
	{
	}
};

USTRUCT(BlueprintType)
struct FIPCountry
{
	GENERATED_BODY()
public:
public:
	FIPCountry() = default;

	FIPCountry(const IPCountry_t& data)
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamShutdown
{
	GENERATED_BODY()
public:
public:
	FSteamShutdown() = default;

	FSteamShutdown(const SteamShutdown_t& data)
	{
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCheckFileSignature, const FCheckFileSignature&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGamepadTextInputDismissed, const FGamepadTextInputDismissed&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIPCountry, const FIPCountry&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLowBatteryPower, const FLowBatteryPower&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamShutdown, const FSteamShutdown&, data);
