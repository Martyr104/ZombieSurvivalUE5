/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamUserStats
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "SteamUserStatsTypes.generated.h"

class UTexture2D;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

UENUM(BlueprintType)
enum class ESteamLeaderboardDataRequest : uint8
{
	Global = 0,
	GlobalAroundUser = 1,
	Friends = 2,
	Users = 3
};

UENUM(BlueprintType)
enum class ESteamLeaderboardSortMethod : uint8
{
	None = 0,
	Ascending = 1,
	Descending = 2
};

UENUM(BlueprintType)
enum class ESteamLeaderboardDisplayType : uint8
{
	None = 0,
	Numeric = 1,
	TimeSeconds = 2,
	TimeMilliSeconds = 3
};

UENUM(BlueprintType)
enum class ESteamLeaderboardUploadScoreMethod : uint8
{
	None = 0,
	KeepBest = 1,
	ForceUpdate = 2
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FSteamLeaderboardEntries
{
	GENERATED_BODY()
public:
	FSteamLeaderboardEntries()
		: Value(0)
	{
	}

	FSteamLeaderboardEntries(uint64 value)
		: Value(value)
	{
	}

public:
	operator uint64() const { return Value; }
private:
	uint64 Value;
};

USTRUCT(BlueprintType)
struct FSteamLeaderboardEntry
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamID SteamID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 GlobalRank;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 Score;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 Details;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamUGCHandle UGCHandle;

	FSteamLeaderboardEntry()
		: GlobalRank(0)
		, Score(0)
		, Details(0)
	{
	}

	FSteamLeaderboardEntry(const LeaderboardEntry_t& data)
		: SteamID(data.m_steamIDUser)
		, GlobalRank(data.m_nGlobalRank)
		, Score(data.m_nScore)
		, Details(data.m_cDetails)
		, UGCHandle(data.m_hUGC)
	{
	}

	operator LeaderboardEntry_t()
	{
		LeaderboardEntry_t m_Data;
		m_Data.m_cDetails = Details;
		m_Data.m_hUGC = UGCHandle;
		m_Data.m_nGlobalRank = GlobalRank;
		m_Data.m_nScore = Score;
		m_Data.m_steamIDUser = SteamID;

		return m_Data;
	}
};

USTRUCT(BlueprintType)
struct FSteamLeaderboard
{
	GENERATED_BODY()
public:
	FSteamLeaderboard()
		: Value(0)
	{
	}

	FSteamLeaderboard(uint64 value)
		: Value(value)
	{
	}

public:
	operator uint64() const { return Value; }

private:
	uint64 Value;
};

USTRUCT(BlueprintType)
struct FUserAchievementIconFetched
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamGameID GameID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FString AchievementName;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	bool bAchieved;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	UTexture2D* Icon;

	int m_nIconHandle;
public:
	FUserAchievementIconFetched() = default;

	FUserAchievementIconFetched(const UserAchievementIconFetched_t& data)
		: GameID(data.m_nGameID)
		, AchievementName(UTF8_TO_TCHAR(data.m_rgchAchievementName))
		, bAchieved(data.m_bAchieved)
		, m_nIconHandle(data.m_nIconHandle)
	{
	}
};

USTRUCT(BlueprintType)
struct FUserAchievementStored
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamGameID GameID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	bool bGroupAchievement;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FString AchievementName;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 CurrentProgress;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 MaxProgress;
public:
	FUserAchievementStored() = default;

	FUserAchievementStored(const UserAchievementStored_t& data)
		: GameID(data.m_nGameID)
		, bGroupAchievement(data.m_bGroupAchievement)
		, AchievementName(UTF8_TO_TCHAR(data.m_rgchAchievementName))
		, CurrentProgress(data.m_nCurProgress)
		, MaxProgress(data.m_nMaxProgress)
	{
	}
};

USTRUCT(BlueprintType)
struct FUserStatsReceived
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamID GameID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamID SteamID;
public:
	FUserStatsReceived() = default;

	FUserStatsReceived(const UserStatsReceived_t& data)
		: GameID(data.m_nGameID)
		, Result(_SteamResult(data.m_eResult))
		, SteamID(data.m_steamIDUser)
	{
	}
};

USTRUCT(BlueprintType)
struct FUserStatsStored
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamGameID GameID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	ESteamResult Result;

public:
	FUserStatsStored() = default;

	FUserStatsStored(const UserStatsStored_t& data)
		: GameID(data.m_nGameID)
		, Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FUserStatsUnloaded
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamID SteamIDUser;
public:
	FUserStatsUnloaded() = default;

	FUserStatsUnloaded(const UserStatsUnloaded_t& data)
		: SteamIDUser(data.m_steamIDUser)
	{
	}
};

USTRUCT(BlueprintType)
struct FLeaderboardScoresDownloaded
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboard SteamLeaderboard;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboardEntries SteamLeaderboardEntries;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 EntryCount;
public:
	FLeaderboardScoresDownloaded() = default;

	FLeaderboardScoresDownloaded(const LeaderboardScoresDownloaded_t& data)
		: SteamLeaderboard(data.m_hSteamLeaderboard)
		, SteamLeaderboardEntries(data.m_hSteamLeaderboardEntries)
		, EntryCount(data.m_cEntryCount)
	{
	}
};

USTRUCT(BlueprintType)
struct FLeaderboardScoresDownloadedForUsers
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboard SteamLeaderboard;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboardEntries SteamLeaderboardEntries;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 EntryCount;
public:
	FLeaderboardScoresDownloadedForUsers() = default;

	FLeaderboardScoresDownloadedForUsers(const LeaderboardScoresDownloaded_t& data)
		: SteamLeaderboard(data.m_hSteamLeaderboard)
		, SteamLeaderboardEntries(data.m_hSteamLeaderboardEntries)
		, EntryCount(data.m_cEntryCount)
	{
	}
};

USTRUCT(BlueprintType)
struct FRequestUserStatsData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamGameID GameID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamID SteamIDUser;
public:
	FRequestUserStatsData() = default;

	FRequestUserStatsData(const UserStatsReceived_t& data)
		: GameID(data.m_nGameID)
		, Result(_SteamResult(data.m_eResult))
		, SteamIDUser(data.m_steamIDUser)
	{
	}
};

USTRUCT(BlueprintType)
struct FLeaderboardScoreUploaded
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	bool bSuccess;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboard SteamLeaderboard;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 Score;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	bool bScoreChanged;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 GlobalRankNew;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 GlobalRankPrevious;
public:
	FLeaderboardScoreUploaded() = default;

	FLeaderboardScoreUploaded(const LeaderboardScoreUploaded_t& data)
		: bSuccess(data.m_bSuccess > 0)
		, SteamLeaderboard(data.m_hSteamLeaderboard)
		, Score(data.m_nScore)
		, bScoreChanged(data.m_bScoreChanged > 0)
		, GlobalRankNew(data.m_nGlobalRankNew)
		, GlobalRankPrevious(data.m_nGlobalRankPrevious)
	{
	}
};

USTRUCT(BlueprintType)
struct FAttachLeaderboardUGCData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboard SteamLeaderboard;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	ESteamResult Result;
public:
	FAttachLeaderboardUGCData() = default;

	FAttachLeaderboardUGCData(const LeaderboardUGCSet_t& data)
		: SteamLeaderboard(data.m_hSteamLeaderboard)
		, Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FLeaderboardFindResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboard SteamLeaderboard;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	bool bLeaderboardFound;
public:
	FLeaderboardFindResult() = default;

	FLeaderboardFindResult(const LeaderboardFindResult_t& data)
		: SteamLeaderboard(data.m_hSteamLeaderboard)
		, bLeaderboardFound(data.m_bLeaderboardFound > 0)
	{
	}
};

USTRUCT(BlueprintType)
struct FFindOrCreateLeaderboardData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamLeaderboard SteamLeaderboard;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	bool bLeaderboardFound;
public:
	FFindOrCreateLeaderboardData() = default;

	FFindOrCreateLeaderboardData(const LeaderboardFindResult_t& data)
		: SteamLeaderboard(data.m_hSteamLeaderboard)
		, bLeaderboardFound(data.m_bLeaderboardFound > 0)
	{
	}
};


USTRUCT(BlueprintType)
struct FNumberOfCurrentPlayers
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	bool bSuccess;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	int32 Players;
public:
	FNumberOfCurrentPlayers() = default;

	FNumberOfCurrentPlayers(const NumberOfCurrentPlayers_t& data)
		: bSuccess(data.m_bSuccess > 0)
		, Players(data.m_cPlayers)
	{
	}
};

USTRUCT(BlueprintType)
struct FGlobalAchievementPercentagesReady
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamGameID GameID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	ESteamResult Result;
public:
	FGlobalAchievementPercentagesReady() = default;

	FGlobalAchievementPercentagesReady(const GlobalAchievementPercentagesReady_t& data)
		: GameID(data.m_nGameID)
		, Result(_SteamResult(data.m_eResult))
	{
	}
};

USTRUCT(BlueprintType)
struct FGlobalStatsReceived
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	FSteamGameID GameID;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "UserStats")
	ESteamResult Result;
public:
	FGlobalStatsReceived() = default;

	FGlobalStatsReceived(const GlobalStatsReceived_t& data)
		: GameID(data.m_nGameID)
		, Result(_SteamResult(data.m_eResult))
	{
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserAchievementIconFetched, const FUserAchievementIconFetched&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserAchievementStored, const FUserAchievementStored&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserStatsReceived, const FUserStatsReceived&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserStatsStored, const FUserStatsStored&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserStatsUnloaded, const FUserStatsUnloaded&, data);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDownloadLeaderboardEntries, const FLeaderboardScoresDownloaded&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDownloadLeaderboardEntriesForUsers, const FLeaderboardScoresDownloadedForUsers&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestUserStats, const FRequestUserStatsData&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnUploadLeaderboardScore, const FLeaderboardScoreUploaded&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAttachLeaderboardUGC, const FAttachLeaderboardUGCData&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnFindLeaderboard, const FLeaderboardFindResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnFindOrCreateLeaderboard, const FFindOrCreateLeaderboardData&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetNumberOfCurrentPlayers, const FNumberOfCurrentPlayers&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestGlobalAchievementPercentages, const FGlobalAchievementPercentagesReady&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestGlobalStats, const FGlobalStatsReceived&, data, bool, bWasSuccessful);
