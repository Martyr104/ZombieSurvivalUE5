/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamFriends
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamFriendsTypes.generated.h"

class UTexture2D;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

UENUM(BlueprintType)
enum class ESteamActivateGameOverlayToWebPageMode : uint8
{
	Default = 0,
	Modal = 1
};

UENUM(BlueprintType)
enum class ESteamFriendRelationship : uint8
{
	None = 0,
	Blocked = 1,
	RequestRecipient = 2,
	Friend = 3,
	RequestInitiator = 4,
	Ignored = 5,
	IgnoredFriend = 6,
	Suggested_DEPRECATED = 7,
	Max = 8,
};

UENUM(BlueprintType)
enum class ESteamPersonaState : uint8
{
	Offline = 0,
	Online = 1,
	Busy = 2,
	Away = 3,
	Snooze = 4,
	LookingToTrade = 5,
	LookingToPlay = 6,
	Max
};

UENUM(BlueprintType, meta = (Bitflags))
enum class ESteamFriendFlags : uint8
{
	None,
	Blocked,
	FriendshipRequested,
	Immediate,
	// "regular" friend
	ClanMember,
	OnGameServer,
	// HasPlayedWith	= 0x20,	// not currently used
	// FriendOfFriend	= 0x40, // not currently used
	RequestingFriendship,
	RequestingInfo,
	Ignored,
	IgnoredFriend,
	// Suggested		= 0x800,	// not used
	ChatMember,
	All,
};

FORCEINLINE int32 operator*(ESteamFriendFlags flags)
{
	int32 FlagValue = 0;

	switch (flags)
	{
	case ESteamFriendFlags::None:
		FlagValue = k_EFriendFlagNone;
		break;
	case ESteamFriendFlags::Blocked:
		FlagValue = k_EFriendFlagBlocked;
		break;
	case ESteamFriendFlags::FriendshipRequested:
		FlagValue = k_EFriendFlagFriendshipRequested;
		break;
	case ESteamFriendFlags::Immediate:
		FlagValue = k_EFriendFlagImmediate;
		break;
	case ESteamFriendFlags::ClanMember:
		FlagValue = k_EFriendFlagClanMember;
		break;
	case ESteamFriendFlags::OnGameServer:
		FlagValue = k_EFriendFlagOnGameServer;
		break;
	case ESteamFriendFlags::RequestingFriendship:
		FlagValue = k_EFriendFlagRequestingFriendship;
		break;
	case ESteamFriendFlags::RequestingInfo:
		FlagValue = k_EFriendFlagRequestingInfo;
		break;
	case ESteamFriendFlags::Ignored:
		FlagValue = k_EFriendFlagIgnored;
		break;
	case ESteamFriendFlags::IgnoredFriend:
		FlagValue = k_EFriendFlagIgnoredFriend;
		break;
	case ESteamFriendFlags::ChatMember:
		FlagValue = k_EFriendFlagChatMember;
		break;
	case ESteamFriendFlags::All:
		FlagValue = k_EFriendFlagAll;
		break;
	}

	return FlagValue;
}

UENUM(BlueprintType, meta = (Bitflags))
enum class ESteamUserRestriction : uint8
{
	None = 0,
	Unknown = k_nUserRestrictionUnknown,
	AnyChat = k_nUserRestrictionAnyChat,
	VoiceChat = k_nUserRestrictionVoiceChat,
	GroupChat = k_nUserRestrictionGroupChat,
	Rating = k_nUserRestrictionRating,
	GameInvites = k_nUserRestrictionGameInvites,
	Trading = k_nUserRestrictionTrading,
};

UENUM(BlueprintType, meta = (Bitflags))
enum class ESteamPersonaChange : uint8
{
	Name = 0,
	Status,
	ComeOnline,
	GoneOffline,
	GamePlayed,
	GameServer,
	Avatar,
	JoinedSource,
	LeftSource,
	RelationshipChanged,
	NameFirstSet,
	FacebookInfo,
	Nickname,
	SteamLevel
};

UENUM(BlueprintType)
enum class ESteamOverlayToStoreFlag : uint8
{
	None = 0,
	AddToCart = 1,
	AddToCartAndShow = 2
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct STEAMCORE_API FSteamFriendsGroupID
{
	GENERATED_BODY()
public:
	FSteamFriendsGroupID()
		: Value(0)
	{
	}

	FSteamFriendsGroupID(int16 value)
		: Value(value)
	{
	}

public:
	operator int16() const { return Value; }
private:
	int16 Value;
};

USTRUCT(BlueprintType)
struct FAvatarImageLoaded
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	UTexture2D* Image;

	int m_iImage, m_iWide, m_iTall;
public:
	FAvatarImageLoaded() = default;

	FAvatarImageLoaded(const AvatarImageLoaded_t& Data)
		: SteamID(Data.m_steamID)
		, m_iImage(Data.m_iImage)
		, m_iWide(Data.m_iWide)
		, m_iTall(Data.m_iTall)
	{
	}
};

USTRUCT(BlueprintType)
struct FFriendRichPresenceUpdate
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDFriend;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	int32 AppID;
public:
	FFriendRichPresenceUpdate() = default;

	FFriendRichPresenceUpdate(const FriendRichPresenceUpdate_t& Data)
		: SteamIDFriend(Data.m_steamIDFriend)
		, AppID(Data.m_nAppID)
	{
	}
};

USTRUCT(BlueprintType)
struct FGameConnectedChatJoin
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDClanChat;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDUser;
public:
	FGameConnectedChatJoin() = default;

	FGameConnectedChatJoin(const GameConnectedChatJoin_t& Data)
		: SteamIDClanChat(Data.m_steamIDClanChat)
		, SteamIDUser(Data.m_steamIDUser)
	{
	}
};

USTRUCT(BlueprintType)
struct FGameConnectedChatLeave
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDClanChat;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDUser;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bKicked;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bDropped;
public:
	FGameConnectedChatLeave() = default;

	FGameConnectedChatLeave(const GameConnectedChatLeave_t& Data)
		: SteamIDClanChat(Data.m_steamIDClanChat)
		, SteamIDUser(Data.m_steamIDUser)
		, bKicked(Data.m_bKicked)
		, bDropped(Data.m_bDropped)
	{
	}
};

USTRUCT(BlueprintType)
struct FGameConnectedClanChatMsg
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDUser;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDClanChat;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	int32 MessageID;
public:
	FGameConnectedClanChatMsg() = default;

	FGameConnectedClanChatMsg(const GameConnectedClanChatMsg_t& Data)
		: SteamIDUser(Data.m_steamIDUser)
		, SteamIDClanChat(Data.m_steamIDClanChat)
		, MessageID(Data.m_iMessageID)
	{
	}
};

USTRUCT(BlueprintType)
struct FGameConnectedFriendChatMsg
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDUser;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	int MessageID;
public:
	FGameConnectedFriendChatMsg() = default;

	FGameConnectedFriendChatMsg(const GameConnectedFriendChatMsg_t& Data)
		: SteamIDUser(Data.m_steamIDUser)
		, MessageID(Data.m_iMessageID)
	{
	}
};

USTRUCT(BlueprintType)
struct FGameLobbyJoinRequested
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDLobby;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDFriend;
public:
	FGameLobbyJoinRequested() = default;

	FGameLobbyJoinRequested(const GameLobbyJoinRequested_t& Data)
		: SteamIDLobby(Data.m_steamIDLobby)
		, SteamIDFriend(Data.m_steamIDFriend)
	{
	}
};

USTRUCT(BlueprintType)
struct FGameOverlayActivated
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bActive;
public:
	FGameOverlayActivated() = default;

	FGameOverlayActivated(const GameOverlayActivated_t& Data)
		: bActive(Data.m_bActive > 0)
	{
	}
};

USTRUCT(BlueprintType)
struct FGameRichPresenceJoinRequested
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDFriend;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FString Connect;
public:
	FGameRichPresenceJoinRequested() = default;

	FGameRichPresenceJoinRequested(const GameRichPresenceJoinRequested_t& Data)
		: SteamIDFriend(Data.m_steamIDFriend)
		, Connect(UTF8_TO_TCHAR(Data.m_rgchConnect))
	{
	}
};

USTRUCT(BlueprintType)
struct FGameServerChangeRequested
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FString Server;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FString Password;
public:
	FGameServerChangeRequested() = default;

	FGameServerChangeRequested(const GameServerChangeRequested_t& Data)
		: Server(UTF8_TO_TCHAR(Data.m_rgchServer))
		, Password(UTF8_TO_TCHAR(Data.m_rgchPassword))
	{
	}
};

USTRUCT(BlueprintType)
struct FPersonaStateChange
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	TArray<ESteamPersonaChange> Flags;
public:
	FPersonaStateChange() = default;

	FPersonaStateChange(const PersonaStateChange_t& Data)
		: SteamID(Data.m_ulSteamID)
	{
		for (int32 i = 0; i <= 31; i++)
		{
			if (Data.m_nChangeFlags & 1 << i)
			{
				Flags.Add(static_cast<ESteamPersonaChange>(i));
			}
		}
	}
};

USTRUCT(BlueprintType)
struct FSetPersonaNameResponse
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bSuccess;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bLocalSuccess;
public:
	FSetPersonaNameResponse() = default;

	FSetPersonaNameResponse(const SetPersonaNameResponse_t& Data)
		: Result(_SteamResult(Data.m_result))
		, bSuccess(Data.m_bSuccess)
		, bLocalSuccess(Data.m_bLocalSuccess)
	{
	}
};

USTRUCT(BlueprintType)
struct FDownloadClanActivityCountsResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bSuccess;
public:
	FDownloadClanActivityCountsResult() = default;

	FDownloadClanActivityCountsResult(const DownloadClanActivityCountsResult_t& Data)
		: bSuccess(Data.m_bSuccess)
	{
	}
};

USTRUCT(BlueprintType)
struct FClanOfficerListResponse
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDClan;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	int32 Officers;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bSuccess;
public:
	FClanOfficerListResponse() = default;

	FClanOfficerListResponse(const ClanOfficerListResponse_t& Data)
		: SteamIDClan(Data.m_steamIDClan)
		, Officers(Data.m_cOfficers)
		, bSuccess(Data.m_bSuccess > 0)
	{
	}
};

USTRUCT(BlueprintType)
struct FJoinClanChatRoomCompletionResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamIDClanChat;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	ESteamChatRoomEnterResponse ChatRoomEnterResponse;
public:
	FJoinClanChatRoomCompletionResult() = default;

	FJoinClanChatRoomCompletionResult(const JoinClanChatRoomCompletionResult_t& Data)
		: SteamIDClanChat(Data.m_steamIDClanChat)
		, ChatRoomEnterResponse(static_cast<ESteamChatRoomEnterResponse>(Data.m_eChatRoomEnterResponse))
	{
	}
};

USTRUCT(BlueprintType)
struct FFriendsGetFollowerCount
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	int32 Count;
public:
	FFriendsGetFollowerCount() = default;

	FFriendsGetFollowerCount(const FriendsGetFollowerCount_t& Data)
		: Result(_SteamResult(Data.m_eResult))
		, SteamID(Data.m_steamID)
		, Count(Data.m_nCount)
	{
	}
};

USTRUCT(BlueprintType)
struct FFriendsIsFollowing
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	FSteamID SteamID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	bool bIsFollowing;
public:
	FFriendsIsFollowing() = default;

	FFriendsIsFollowing(const FriendsIsFollowing_t& Data)
		: Result(_SteamResult(Data.m_eResult))
		, SteamID(Data.m_steamID)
		, bIsFollowing(Data.m_bIsFollowing)
	{
	}
};

USTRUCT(BlueprintType)
struct FFriendsEnumerateFollowingList
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	TArray<FSteamID> SteamIDs;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	int32 Results;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Friends")
	int32 TotalResult;
public:
	FFriendsEnumerateFollowingList() = default;

	FFriendsEnumerateFollowingList(const FriendsEnumerateFollowingList_t& Data)
		: Result(_SteamResult(Data.m_eResult))
		, Results(Data.m_nResultsReturned)
		, TotalResult(Data.m_nTotalResultCount)
	{
		for (int i = 0; i < Data.m_nResultsReturned; i++)
		{
			SteamIDs.Add(Data.m_rgSteamID[i]);
		}
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameOverlayActivated, const FGameOverlayActivated&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAvatarImageLoaded, const FAvatarImageLoaded&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameServerChangeRequested, const FGameServerChangeRequested&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameConnectedFriendChatMsg, const FGameConnectedFriendChatMsg&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameLobbyJoinRequested, const FGameLobbyJoinRequested&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameRichPresenceJoinRequested, const FGameRichPresenceJoinRequested&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPersonaStateChange, const FPersonaStateChange&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClanOfficerListResponse, const FClanOfficerListResponse&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFriendRichPresenceUpdate, const FFriendRichPresenceUpdate&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameConnectedClanChatMsg, const FGameConnectedClanChatMsg&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameConnectedChatJoin, const FGameConnectedChatJoin&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameConnectedChatLeave, const FGameConnectedChatLeave&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDownloadClanActivityCountsResult, const FDownloadClanActivityCountsResult&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJoinClanChatRoomCompletionResult, const FJoinClanChatRoomCompletionResult&, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetPersonaNameResponse, const FSetPersonaNameResponse&, Data);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDownloadClanActivityCounts, const FDownloadClanActivityCountsResult&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestClanOfficerList, const FClanOfficerListResponse&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnJoinClanChatRoom, const FJoinClanChatRoomCompletionResult&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetFollowerCount, const FFriendsGetFollowerCount&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestFriendRichPresence, const FFriendRichPresenceUpdate&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnIsFollowing, const FFriendsIsFollowing&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEnumerateFollowingList, const FFriendsEnumerateFollowingList&, Data, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSetPersonaName, const FSetPersonaNameResponse&, Data, bool, bWasSuccessful);