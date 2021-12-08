/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamUser
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "SteamUserTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

UENUM(BlueprintType)
enum class ESteamVoiceResult : uint8
{
	OK = 0,
	NotInitialized = 1,
	NotRecording = 2,
	NoData = 3,
	BufferTooSmall = 4,
	DataCorrupted = 5,
	Restricted = 6,
	UnsupportedCodec = 7,
	ReceiverOutOfDate = 8,
	ReceiverDidNotAnswer = 9
};

UENUM(BlueprintType)
enum class ESteamFailureType : uint8
{
	FlushedCallbackQueue = 0,
	PipeFail = 1
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

class UUser;

USTRUCT(BlueprintType)
struct FClientGameServerDeny
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	int32 AppID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	FString GameServerIP;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	int32 GameServerPort;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	bool bSecure;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	ESteamDenyReason Reason;
public:
	FClientGameServerDeny() = default;

	FClientGameServerDeny(const ClientGameServerDeny_t& data)
		: AppID(data.m_uAppID)
		, GameServerIP(FIPv4Address(data.m_unGameServerIP).ToString())
		, GameServerPort(data.m_usGameServerPort)
		, bSecure(data.m_bSecure > 0)
		, Reason(static_cast<ESteamDenyReason>(data.m_uReason))
	{
	}
};

USTRUCT(BlueprintType)
struct FGameWebCallback
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	FString URL;
public:
	FGameWebCallback() = default;

	FGameWebCallback(const GameWebCallback_t& data)
		: URL(UTF8_TO_TCHAR(data.m_szURL))
	{
	}
};

USTRUCT(BlueprintType)
struct FGetAuthSessionTicketResponse
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	FSteamTicketHandle AuthTicket;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	ESteamResult Result;
public:
	FGetAuthSessionTicketResponse() = default;

	FGetAuthSessionTicketResponse(const GetAuthSessionTicketResponse_t& data)
		: AuthTicket(data.m_hAuthTicket)
		, Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FIPCFailure
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	ESteamFailureType FailureType;
public:
	FIPCFailure() = default;

	FIPCFailure(const IPCFailure_t& data)
		: FailureType(static_cast<ESteamFailureType>(data.m_eFailureType))
	{
	}
};

USTRUCT(BlueprintType)
struct FLicensesUpdated
{
	GENERATED_BODY()
public:
public:
	FLicensesUpdated() = default;

	FLicensesUpdated(const LicensesUpdated_t& data)
	{
	}
};

USTRUCT(BlueprintType)
struct FMicroTxnAuthorizationResponse
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	int32 AppID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	FString OrderID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	bool bAuthorized;
public:
	FMicroTxnAuthorizationResponse() = default;

	FMicroTxnAuthorizationResponse(const MicroTxnAuthorizationResponse_t& data)
		: AppID(data.m_unAppID)
		, OrderID(LexToString(data.m_ulOrderID))
		, bAuthorized(data.m_bAuthorized > 0)
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamServersConnected
{
	GENERATED_BODY()
public:
public:
	FSteamServersConnected() = default;

	FSteamServersConnected(const SteamServersConnected_t& data)
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamServerConnectFailure
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	bool bStillRetrying;
public:
	FSteamServerConnectFailure() = default;

	FSteamServerConnectFailure(const SteamServerConnectFailure_t& data)
		: Result(_SteamResult(data.m_eResult))
		, bStillRetrying(data.m_bStillRetrying)
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamServersDisconnected
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	ESteamResult Result;
public:
	FSteamServersDisconnected() = default;

	FSteamServersDisconnected(const SteamServersDisconnected_t& data)
		: Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FEncryptedAppTicketResponse
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	ESteamResult Result;
public:
	FEncryptedAppTicketResponse() = default;

	FEncryptedAppTicketResponse(const EncryptedAppTicketResponse_t& data)
		: Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FStoreAuthURLResponse
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "User")
	FString URL;
public:
	FStoreAuthURLResponse() = default;

	FStoreAuthURLResponse(const StoreAuthURLResponse_t& data)
		: URL(UTF8_TO_TCHAR(data.m_szURL))
	{
	}
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClientGameServerDeny, const FClientGameServerDeny&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameWebCallback, const FGameWebCallback&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetAuthSessionTicketResponse, const FGetAuthSessionTicketResponse&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIPCFailure, const FIPCFailure&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLicensesUpdated, const FLicensesUpdated&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMicroTxnAuthorizationResponse, const FMicroTxnAuthorizationResponse&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamServersConnected, const FSteamServersConnected&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamServerConnectFailure, const FSteamServerConnectFailure&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamServersDisconnected, const FSteamServersDisconnected&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValidateAuthTicketResponse, const FValidateAuthTicketResponse&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestEncryptedAppTicketResponse, const FEncryptedAppTicketResponse&, data);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestEncryptedAppTicket, const FEncryptedAppTicketResponse&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnStoreAuthURLResponse, const FStoreAuthURLResponse&, data, bool, bWasSuccessful);
