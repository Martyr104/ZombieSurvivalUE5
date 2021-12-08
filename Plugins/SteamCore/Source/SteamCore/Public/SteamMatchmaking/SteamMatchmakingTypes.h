/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamMatchmaking
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "OnlineSubsystemUtils/Classes/FindSessionsCallbackProxy.h"
#include "SteamMatchmakingTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

UENUM(BlueprintType)
enum class ESteamSessionFindType : uint8
{
	Listen,
	Dedicated
};


enum class ESteamCoreFindLobbiesState : uint8
{
	Init = 0,
	RequestLobbyList,
	RequestLobbyData,
	WaitForRequestLobbyData,
	Finished
};

UENUM(BlueprintType)
enum class ESteamLobbyType : uint8
{
	Private = 0,
	FriendsOnly = 1,
	Public = 2,
	Invisible = 3,
};

// lobby search filter tools
UENUM(BlueprintType)
enum class ESteamLobbyComparison : uint8
{
	EqualToOrLessThan = 0,
	LessThan = 1,
	Equal = 2,
	GreaterThan = 3,
	EqualToOrGreaterThan = 4,
	NotEqual = 5
};

// lobby search distance. Lobby results are sorted from closest to farthest.
UENUM(BlueprintType)
enum class ESteamLobbyDistanceFilter : uint8
{
	Close = 0,
	Default = 1,
	Far = 2,
	Worldwide = 3
};

UENUM(BlueprintType, meta = (Bitflags))
enum class ESteamChatMemberStateChange : uint8
{
	None = 0,
	Entered = k_EChatMemberStateChangeEntered,
	Left = k_EChatMemberStateChangeLeft,
	Disconnected = k_EChatMemberStateChangeDisconnected,
	Kicked = k_EChatMemberStateChangeKicked,
	Banned = k_EChatMemberStateChangeBanned,
};

ENUM_CLASS_FLAGS(ESteamChatMemberStateChange)

UENUM(BlueprintType, meta = (Bitflags))
enum class ESteamFavoriteFlags : uint8
{
	None = 0,
	Favorite = 1,
	History = 2,
};

ENUM_CLASS_FLAGS(ESteamFavoriteFlags)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FFavoritesListAccountsUpdated
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	ESteamResult Result;
public:
	FFavoritesListAccountsUpdated() = default;

	FFavoritesListAccountsUpdated(const FavoritesListAccountsUpdated_t& data)
		: Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FFavoritesListChanged
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FString IP;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	int32 QueryPort;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	int32 ConnectionPort;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	int32 AppID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	TArray<ESteamFavoriteFlags> Flags;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	bool bAdd;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamID;
public:
	FFavoritesListChanged() = default;

	FFavoritesListChanged(const FavoritesListChanged_t& data)
		: IP(FIPv4Address(data.m_nIP).ToString())
		, QueryPort(data.m_nQueryPort)
		, ConnectionPort(data.m_nConnPort)
		, AppID(data.m_nAppID)
		, bAdd(data.m_bAdd)
		, SteamID(data.m_unAccountId)
	{
		if ((data.m_nFlags & static_cast<uint32>(ESteamFavoriteFlags::None)) > 0)
		{
			Flags.Add(ESteamFavoriteFlags::None);
		}
		if ((data.m_nFlags & static_cast<uint32>(ESteamFavoriteFlags::Favorite)) > 0)
		{
			Flags.Add(ESteamFavoriteFlags::Favorite);
		}
		if ((data.m_nFlags & static_cast<uint32>(ESteamFavoriteFlags::History)) > 0)
		{
			Flags.Add(ESteamFavoriteFlags::History);
		}
	}
};

USTRUCT(BlueprintType)
struct FLobbyChatMsg
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDUser;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	ESteamChatEntryType ChatEntryType;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	int32 ChatID;
public:
	FLobbyChatMsg() = default;

	FLobbyChatMsg(const LobbyChatMsg_t& data)
		: SteamIDLobby(data.m_ulSteamIDLobby)
		, SteamIDUser(data.m_ulSteamIDUser)
		, ChatEntryType(static_cast<ESteamChatEntryType>(data.m_eChatEntryType))
		, ChatID(data.m_iChatID)
	{
	}
};

USTRUCT(BlueprintType)
struct FLobbyChatUpdate
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDUserChanged;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDMakingChange;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	TArray<ESteamChatMemberStateChange> ChatMemberStateChange;
public:
	FLobbyChatUpdate() = default;

	FLobbyChatUpdate(const LobbyChatUpdate_t& data)
		: SteamIDLobby(data.m_ulSteamIDLobby)
		, SteamIDUserChanged(data.m_ulSteamIDUserChanged)
		, SteamIDMakingChange(data.m_ulSteamIDMakingChange)
	{
		for (int32 i = 0; i <= 32; i++)
		{
			if ((data.m_rgfChatMemberStateChange & static_cast<int32>(static_cast<ESteamChatMemberStateChange>(i))) > 0)
			{
				ChatMemberStateChange.Add(static_cast<ESteamChatMemberStateChange>(i));
			}
		}
	}
};

USTRUCT(BlueprintType)
struct FLobbyDataUpdate
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDMember;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	bool bSuccess;

	FLobbyDataUpdate() = default;

	FLobbyDataUpdate(const LobbyDataUpdate_t& data)
		: SteamIDLobby(data.m_ulSteamIDLobby)
		, SteamIDMember(data.m_ulSteamIDMember)
		, bSuccess(data.m_bSuccess > 0)
	{
	}
};

USTRUCT(BlueprintType)
struct FLobbyEnterData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	bool bLocked;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	ESteamChatRoomEnterResponse ChatRoomEnterResponse;
public:
	FLobbyEnterData() = default;

	FLobbyEnterData(const LobbyEnter_t& data)
		: SteamIDLobby(data.m_ulSteamIDLobby)
		, bLocked(data.m_bLocked)
		, ChatRoomEnterResponse(static_cast<ESteamChatRoomEnterResponse>(data.m_EChatRoomEnterResponse))
	{
	}
};

USTRUCT(BlueprintType)
struct FLobbyGameCreated
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDGameServer;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FString IP;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	int32 Port;
public:
	FLobbyGameCreated() = default;

	FLobbyGameCreated(const LobbyGameCreated_t& data)
		: SteamIDLobby(data.m_ulSteamIDLobby)
		, SteamIDGameServer(data.m_ulSteamIDGameServer)
		, IP(FIPv4Address(data.m_unIP).ToString())
		, Port(data.m_usPort)
	{
	}
};

USTRUCT(BlueprintType)
struct FLobbyInviteData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDUser;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamGameID GameID;
public:
	FLobbyInviteData() = default;

	FLobbyInviteData(const LobbyInvite_t& data)
		: SteamIDUser(data.m_ulSteamIDUser)
		, SteamIDLobby(data.m_ulSteamIDLobby)
		, GameID(data.m_ulGameID)
	{
	}
};

USTRUCT(BlueprintType)
struct FLobbyKickedData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDAdmin;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	bool bKickedDueToDisconnect;
public:
	FLobbyKickedData() = default;

	FLobbyKickedData(const LobbyKicked_t& data)
		: SteamIDLobby(data.m_ulSteamIDLobby)
		, SteamIDAdmin(data.m_ulSteamIDAdmin)
		, bKickedDueToDisconnect(data.m_bKickedDueToDisconnect > 0)
	{
	}
};

USTRUCT(BlueprintType)
struct FLobbyMatchList
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	int32 LobbiesMatching;
public:
	FLobbyMatchList() = default;

	FLobbyMatchList(const LobbyMatchList_t& data)
		: LobbiesMatching(data.m_nLobbiesMatching)
	{
	}
};

USTRUCT(BlueprintType)
struct FCreateLobbyData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
public:
	FCreateLobbyData() = default;

	FCreateLobbyData(const LobbyCreated_t& data)
		: Result(_SteamResult(data.m_eResult))
		, SteamIDLobby(data.m_ulSteamIDLobby)
	{
	}
};

USTRUCT(BlueprintType)
struct FJoinLobbyData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	bool bLocked;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Matchmaking")
	ESteamChatRoomEnterResponse ChatRoomEnterResponse;

	uint32 m_rgfChatPermissions; // Permissions of the current user - unused always 0

public:
	FJoinLobbyData() = default;

	FJoinLobbyData(const LobbyEnter_t& data)
		: SteamIDLobby(data.m_ulSteamIDLobby)
		, bLocked(data.m_bLocked)
		, ChatRoomEnterResponse(static_cast<ESteamChatRoomEnterResponse>(data.m_EChatRoomEnterResponse))
		, m_rgfChatPermissions(data.m_rgfChatPermissions)
	{
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFavoritesListAccountsUpdated, const FFavoritesListAccountsUpdated&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFavoritesListChanged, const FFavoritesListChanged&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyChatMsg, const FLobbyChatMsg&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyChatUpdate, const FLobbyChatUpdate&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyDataUpdate, FLobbyDataUpdate, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyEnter, const FLobbyEnterData&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyGameCreated, const FLobbyGameCreated&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyInvite, const FLobbyInviteData&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyKicked, const FLobbyKickedData&, data);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestLobbyList, const FLobbyMatchList&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnCreateLobby, const FCreateLobbyData&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnJoinLobby, const FJoinLobbyData&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnFindSessions, const TArray<FBlueprintSessionResult>&, data, bool, bWasSuccessful);
