/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamVideo
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "SteamVideoTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

UENUM(BlueprintType)
enum class ESteamBroadcastUploadResult : uint8
{
	None = 0,
	OK = 1,
	InitFailed = 2,
	FrameFailed = 3,
	Timeout = 4,
	BandwidthExceeded = 5,
	LowFPS = 6,
	MissingKeyFrames = 7,
	NoConnection = 8,
	RelayFailed = 9,
	SettingsChanged = 10,
	MissingAudio = 11,
	TooFarBehind = 12,
	TranscodeBehind = 13,
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USTRUCT(BlueprintType)
struct FGetOPFSettingsResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Video")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Video")
	int32 AppID;

public:
	FGetOPFSettingsResult() = default;

	FGetOPFSettingsResult(const GetOPFSettingsResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, AppID(data.m_unVideoAppID)
	{
	}
};

USTRUCT(BlueprintType)
struct FGetVideoURLResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Video")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Video")
	int32 AppID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Video")
	FString URL;

public:
	FGetVideoURLResult() = default;

	FGetVideoURLResult(const GetVideoURLResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, AppID(data.m_unVideoAppID)
		, URL(UTF8_TO_TCHAR(data.m_rgchURL))
	{
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetOPFSettingsResult, const FGetOPFSettingsResult&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetVideoURLResult, const FGetVideoURLResult&, data);
