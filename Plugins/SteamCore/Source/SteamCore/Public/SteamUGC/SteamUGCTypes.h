/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamUGC
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamUGCTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Matching UGC types for queries
UENUM(BlueprintType)
enum class ESteamUGCMatchingUGCType : uint8
{
	Items = 0,
	Items_Mtx = 1,
	Items_ReadyToUse = 2,
	Collections = 3,
	Artwork = 4,
	Videos = 5,
	Screenshots = 6,
	AllGuides = 7,
	WebGuides = 8,
	IntegratedGuides = 9,
	UsableInGame = 10,
	ControllerBindings = 11,
	GameManagedItems = 12,
	All = 13,
};

// Different lists of published UGC for a user.
// If the current logged in user is different than the specified user, then some options may not be allowed.
UENUM(BlueprintType)
enum class ESteamUserUGCList : uint8
{
	Published = 0,
	VotedOn,
	VotedUp,
	VotedDown,
	WillVoteLater,
	Favorited,
	Subscribed,
	UsedOrPlayed,
	Followed,
};

// Sort order for user published UGC lists (defaults to creation order descending)
UENUM(BlueprintType)
enum class ESteamUserUGCListSortOrder : uint8
{
	CreationOrderDesc = 0,
	CreationOrderAsc,
	TitleAsc,
	LastUpdatedDesc,
	SubscriptionDateDesc,
	VoteScoreDesc,
	ForModeration,
};

// Combination of sorting and filtering for queries across all UGC
UENUM(BlueprintType)
enum class ESteamUGCQuery : uint8
{
	RankedByVote = 0,
	RankedByPublicationDate = 1,
	AcceptedForGameRankedByAcceptanceDate = 2,
	RankedByTrend = 3,
	FavoritedByFriendsRankedByPublicationDate = 4,
	CreatedByFriendsRankedByPublicationDate = 5,
	RankedByNumTimesReported = 6,
	CreatedByFollowedUsersRankedByPublicationDate = 7,
	NotYetRated = 8,
	RankedByTotalVotesAsc = 9,
	RankedByVotesUp = 10,
	RankedByTextSearch = 11,
	RankedByTotalUniqueSubscriptions = 12,
	RankedByPlaytimeTrend = 13,
	RankedByTotalPlaytime = 14,
	RankedByAveragePlaytimeTrend = 15,
	RankedByLifetimeAveragePlaytime = 16,
	RankedByPlaytimeSessionsTrend = 17,
	RankedByLifetimePlaytimeSessions = 18,
};

UENUM(BlueprintType)
enum class ESteamItemUpdateStatus : uint8
{
	// The item update handle was invalid, job might be finished, listen too SubmitItemUpdateResult_t
	Invalid = 0,
	// The item update is processing configuration data
	PreparingConfig = 1,
	// The item update is reading and processing content files
	PreparingContent = 2,
	// The item update is uploading content changes to Steam
	UploadingContent = 3,
	// The item update is uploading new preview file image
	UploadingPreviewFile = 4,
	// The item update is committing all changes
	CommittingChanges = 5
};

UENUM(BlueprintType, meta = (Bitflags))
enum class ESteamItemState : uint8
{
	// item not tracked on client
	None = 0,
	// current user is subscribed to this item. Not just cached.
	Subscribed = 1,
	// item was created with ISteamRemoteStorage
	LegacyItem = 2,
	// item is installed and usable (but maybe out of date)
	Installed = 4,
	// items needs an update. Either because it's not installed yet or creator updated content
	NeedsUpdate = 8,
	// item update is currently downloading
	Downloading = 16,
	// DownloadItem() was called for this item, content isn't available until DownloadItemResult_t is fired
	DownloadPending = 32,
};

ENUM_CLASS_FLAGS(ESteamItemState);

UENUM(BlueprintType)
enum class ESteamItemStatistic : uint8
{
	NumSubscriptions = 0,
	NumFavorites = 1,
	NumFollowers = 2,
	NumUniqueSubscriptions = 3,
	NumUniqueFavorites = 4,
	NumUniqueFollowers = 5,
	NumUniqueWebsiteViews = 6,
	ReportScore = 7,
	NumSecondsPlayed = 8,
	NumPlaytimeSessions = 9,
	NumComments = 10,
	NumSecondsPlayedDuringTimePeriod = 11,
	NumPlaytimeSessionsDuringTimePeriod = 12,
};

UENUM(BlueprintType)
enum class ESteamItemPreviewType : uint8
{
	// standard image file expected (e.g. jpg, png, gif, etc.)
	Image = 0,
	// video id is stored
	YouTubeVideo = 1,
	// model id is stored
	Sketchfab = 2,
	// standard image file expected - cube map in the layout
	EnvironmentMap_HorizontalCross = 3,
	// standard image file expected
	EnvironmentMap_LatLong = 4,
	// you can specify your own types above this value
	ReservedMax = 254,
};

UENUM(BlueprintType)
enum class ESteamWorkshopFileType : uint8
{
	First = 0,
	Community = 0,
	Microtransaction = 1,
	Collection = 2,
	Art = 3,
	Video = 4,
	Screenshot = 5,
	Game = 6,
	Software = 7,
	Concept = 8,
	WebGuide = 9,
	IntegratedGuide = 10,
	Merch = 11,
	ControllerBinding = 12,
	SteamworksAccessInvite = 13,
	SteamVideo = 14,
	GameManagedItem = 15,
	Max = 16
};

UENUM(BlueprintType)
enum class ESteamRemoteStoragePublishedFileVisibility : uint8
{
	Public = 0,
	FriendsOnly = 1,
	Private = 2,
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USTRUCT(BlueprintType)
struct FSteamUGCDetails
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamWorkshopFileType FileType;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 CreatorAppID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 ConsumerAppID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FString Title;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FString Description;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FSteamID SteamIDOwner;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 TimeCreated;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 TimeUpdated;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 TimeAddedToUserList;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamRemoteStoragePublishedFileVisibility Visibility;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bBanned;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bAcceptedForUse;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bTagsTruncated;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	TArray<FString> Tags;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FSteamUGCHandle File;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FSteamUGCHandle PreviewFile;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FString FileName;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 FileSize;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 PreviewFileSize;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FString URL;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 VotesUp;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 VotesDown;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	float Score;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 NumChildren;
public:
	FSteamUGCDetails() = default;

	FSteamUGCDetails(const SteamUGCDetails_t& data)
		: PublishedFileID(data.m_nPublishedFileId)
		, Result(_SteamResult(data.m_eResult))
		, FileType(static_cast<ESteamWorkshopFileType>(data.m_eFileType))
		, CreatorAppID(data.m_nCreatorAppID)
		, ConsumerAppID(data.m_nConsumerAppID)
		, Title(UTF8_TO_TCHAR(data.m_rgchTitle))
		, Description(UTF8_TO_TCHAR(data.m_rgchDescription))
		, SteamIDOwner(data.m_ulSteamIDOwner)
		, TimeCreated(data.m_rtimeCreated)
		, TimeUpdated(data.m_rtimeUpdated)
		, TimeAddedToUserList(data.m_rtimeAddedToUserList)
		, Visibility(static_cast<ESteamRemoteStoragePublishedFileVisibility>(data.m_eVisibility))
		, bBanned(data.m_bBanned)
		, bAcceptedForUse(data.m_bAcceptedForUse)
		, bTagsTruncated(data.m_bTagsTruncated)
		, File(data.m_hFile)
		, PreviewFile(data.m_hPreviewFile)
		, FileName(UTF8_TO_TCHAR(data.m_pchFileName))
		, FileSize(data.m_nFileSize)
		, PreviewFileSize(data.m_nPreviewFileSize)
		, URL(UTF8_TO_TCHAR(data.m_rgchURL))
		, VotesUp(data.m_unVotesUp)
		, VotesDown(data.m_unVotesDown)
		, Score(data.m_flScore)
		, NumChildren(data.m_unNumChildren)
	{
		FString m_Tags = UTF8_TO_TCHAR(data.m_rgchTags);
		m_Tags.ParseIntoArray(Tags, TEXT(","), true);
	}
};

USTRUCT(BlueprintType)
struct FCreateItemResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bUserNeedsToAcceptWorkshopLegalAgreement;
public:
	FCreateItemResult() = default;

	FCreateItemResult(const CreateItemResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, PublishedFileID(data.m_nPublishedFileId)
		, bUserNeedsToAcceptWorkshopLegalAgreement(data.m_bUserNeedsToAcceptWorkshopLegalAgreement)
	{
	}
};

USTRUCT(BlueprintType)
struct FUserFavoriteItemsListChanged
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bWasAddRequest;
public:
	FUserFavoriteItemsListChanged() = default;

	FUserFavoriteItemsListChanged(const UserFavoriteItemsListChanged_t& data)
		: PublishedFileID(data.m_nPublishedFileId)
		, Result(_SteamResult(data.m_eResult))
		, bWasAddRequest(data.m_bWasAddRequest)
	{
	}
};

USTRUCT(BlueprintType)
struct FStartPlaytimeTrackingResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
public:
	FStartPlaytimeTrackingResult() = default;

	FStartPlaytimeTrackingResult(const StartPlaytimeTrackingResult_t& data)
		: Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FStopPlaytimeTrackingResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
public:
	FStopPlaytimeTrackingResult() = default;

	FStopPlaytimeTrackingResult(const StopPlaytimeTrackingResult_t& data)
		: Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FGetUserItemVoteResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bVotedUp;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bVotedDown;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bVoteSkipped;
public:
	FGetUserItemVoteResult() = default;

	FGetUserItemVoteResult(const GetUserItemVoteResult_t& data)
		: PublishedFileID(data.m_nPublishedFileId)
		, Result(_SteamResult(data.m_eResult))
		, bVotedUp(data.m_bVotedUp)
		, bVotedDown(data.m_bVotedDown)
		, bVoteSkipped(data.m_bVoteSkipped)
	{
	}
};

USTRUCT(BlueprintType)
struct FSetUserItemVoteResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bVoteUp;
public:
	FSetUserItemVoteResult() = default;

	FSetUserItemVoteResult(const SetUserItemVoteResult_t& data)
		: PublishedFileID(data.m_nPublishedFileId)
		, Result(_SteamResult(data.m_eResult))
		, bVoteUp(data.m_bVoteUp)
	{
	}
};

USTRUCT(BlueprintType)
struct FUGCUpdateHandle
{
	GENERATED_BODY()
public:
	FUGCUpdateHandle() = default;

	FUGCUpdateHandle(uint64 val)
		: Value(val)
	{
	}

public:
	operator uint64() { return Value; }
private:
	uint64 Value;
};

USTRUCT(BlueprintType)
struct FUGCQueryHandle
{
	GENERATED_BODY()
public:
	FUGCQueryHandle() = default;

	FUGCQueryHandle(uint64 val)
		: Value(val)
	{
	}

public:
	operator uint64() const { return Value; }
private:
	uint64 Value;
};

USTRUCT(BlueprintType)
struct FSubmitItemUpdateResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bUserNeedsToAcceptWorkshopLegalAgreement;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
public:
	FSubmitItemUpdateResult() = default;

	FSubmitItemUpdateResult(const SubmitItemUpdateResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, bUserNeedsToAcceptWorkshopLegalAgreement(data.m_bUserNeedsToAcceptWorkshopLegalAgreement)
		, PublishedFileID(data.m_nPublishedFileId)
	{
	}
};

USTRUCT(BlueprintType)
struct FItemInstalled
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 AppID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
public:
	FItemInstalled() = default;

	FItemInstalled(const ItemInstalled_t& data)
		: AppID(data.m_unAppID)
		, PublishedFileID(data.m_nPublishedFileId)
	{
	}
};

USTRUCT(BlueprintType)
struct FDownloadItemResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 AppID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
public:
	FDownloadItemResult() = default;

	FDownloadItemResult(const DownloadItemResult_t& data)
		: AppID(data.m_unAppID)
		, PublishedFileID(data.m_nPublishedFileId)
		, Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamUGCQueryCompleted
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FUGCQueryHandle Handle;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 NumResultsReturned;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 TotalMatchingResults;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	bool bCachedData;
public:
	FSteamUGCQueryCompleted() = default;

	FSteamUGCQueryCompleted(const SteamUGCQueryCompleted_t& data)
		: Handle(data.m_handle)
		, Result(_SteamResult(data.m_eResult))
		, NumResultsReturned(data.m_unNumResultsReturned)
		, TotalMatchingResults(data.m_unTotalMatchingResults)
		, bCachedData(data.m_bCachedData)
	{
	}
};


USTRUCT(BlueprintType)
struct FAddAppDependencyResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 AppID;
public:
	FAddAppDependencyResult() = default;

	FAddAppDependencyResult(const AddAppDependencyResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, PublishedFileID(data.m_nPublishedFileId)
		, AppID(data.m_nAppID)
	{
	}
};

USTRUCT(BlueprintType)
struct FRemoveAppDependencyResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 AppID;
public:
	FRemoveAppDependencyResult() = default;

	FRemoveAppDependencyResult(const RemoveAppDependencyResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, PublishedFileID(data.m_nPublishedFileId)
		, AppID(data.m_nAppID)
	{
	}
};

USTRUCT(BlueprintType)
struct FAddUGCDependencyResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileId;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID ChildPublishedFileId;
public:
	FAddUGCDependencyResult() = default;

	FAddUGCDependencyResult(const AddUGCDependencyResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, PublishedFileId(data.m_nPublishedFileId)
		, ChildPublishedFileId(data.m_nChildPublishedFileId)
	{
	}
};

USTRUCT(BlueprintType)
struct FRemoveUGCDependencyResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileId;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID ChildPublishedFileId;
public:
	FRemoveUGCDependencyResult() = default;

	FRemoveUGCDependencyResult(const RemoveUGCDependencyResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, PublishedFileId(data.m_nPublishedFileId)
		, ChildPublishedFileId(data.m_nChildPublishedFileId)
	{
	}
};

USTRUCT(BlueprintType)
struct FUGCDeleteItemResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileId;
public:
	FUGCDeleteItemResult() = default;

	FUGCDeleteItemResult(const DeleteItemResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, PublishedFileId(data.m_nPublishedFileId)
	{
	}
};

USTRUCT(BlueprintType)
struct FGetAppDependenciesResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	FPublishedFileID PublishedFileID;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	TArray<int32> AppIDs;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 NumAppDependencies;
	UPROPERTY(BlueprintReadWrite, Category = "UGC")
	int32 TotalNumAppDependencies;

public:
	FGetAppDependenciesResult() = default;

	FGetAppDependenciesResult(const GetAppDependenciesResult_t& data)
		: Result(_SteamResult(data.m_eResult))
		, PublishedFileID(data.m_nPublishedFileId)
		, NumAppDependencies(data.m_nNumAppDependencies)
		, TotalNumAppDependencies(data.m_nTotalNumAppDependencies)
	{
		for (int32 i = 0; i < 32; i++)
		{
			AppIDs.Add(data.m_rgAppIDs[i]);
		}
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAddItemToFavorites, const FUserFavoriteItemsListChanged&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnCreateItem, const FCreateItemResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSetUserItemVote, const FSetUserItemVoteResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetUserItemVote, const FGetUserItemVoteResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRemoveItemFromFavorites, const FUserFavoriteItemsListChanged&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSubscribeItem, const FRemoteStorageSubscribePublishedFileResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSendQueryUGCRequest, const FSteamUGCQueryCompleted&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAddAppDependencyResult, const FAddAppDependencyResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRemoveAppDependencyResult, const FRemoveAppDependencyResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAddUGCDependencyResult, const FAddUGCDependencyResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRemoveUGCDependencyResult, const FRemoveUGCDependencyResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDeleteItemResult, const FUGCDeleteItemResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetAppDependenciesResult, const FGetAppDependenciesResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSubmitItemUpdate, const FSubmitItemUpdateResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnStartPlaytimeTracking, const FStartPlaytimeTrackingResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnStopPlaytimeTracking, const FStopPlaytimeTrackingResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnStopPlaytimeTrackingForAllItems, const FStopPlaytimeTrackingResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnUnsubscribeItem, const FRemoteStorageSubscribePublishedFileResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDownloadItem, const FDownloadItemResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDownloadItemResult, const FDownloadItemResult&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemInstalled, const FItemInstalled&, data);
