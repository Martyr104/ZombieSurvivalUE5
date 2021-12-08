/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamMatchmakingServers
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/SteamCoreModule.h"
#include "SteamCore/Steam.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "SteamMatchmakingServersTypes.generated.h"

UCLASS(BlueprintType)
class STEAMCORE_API UServerFilter : public UObject
{
	GENERATED_BODY()
public:
	UServerFilter();
	virtual ~UServerFilter() override;
public:
	/*
	* Servers running the specified map (ex. cs_italy)
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterMap(FString Value);

	/*
	* 
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterGameDataAnd(FString Value);

	/*
	* Servers with any of the given tag(s) in their 'hidden' tags (L4D2)
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterGameDataOr(FString Value);

	/*
	* 
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterGameDataNor(FString Value);

	/*
	* 
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterGameTagsAnd(FString Value);

	/*
	* 
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterGameTagsNor(FString Value);

	/*
	* 
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterAnd(FString Value);

	/*
	* 
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterOr(FString Value);

	/*
	* A special filter, specifies that servers matching all of the following [x] conditions should not be returned
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterNand(FString Value);

	/*
	* A special filter, specifies that servers matching any of the following [x] conditions should not be returned
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterNor(FString Value);

	/*
	* 	Return only servers on the specified IP address (port supported and optional)
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterGameAddr(FString Value);

	/*
	* Servers running dedicated
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterDedicated();

	/*
	* Servers using anti-cheat technology (VAC, but potentially others as well)
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterSecure();

	/*
	* Servers that are not full
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterNotFull();

	/*
	* Servers that are not empty
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterHasPlayers();

	/*
	* Servers that are empty
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterNoPlayers();

	/*
	* Servers running on a Linux platform
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterLinux();

	/*
	 * Servers running version [version] (can use * as a wildcard)
	 */
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterVersion(FString Value);

	/*
	 * Servers with their hostname matching [hostname] (can use * as a wildcard)
	 */
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterName(FString Value);

	/*
	* Servers that are whitelisted
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterWhitelisted();

	/*
	* Servers that are NOT running game [appid] (This was introduced to block Left 4 Dead games from the Steam Server Browser)
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterNotAppId(FString Value);

	/*
	* Servers that are spectator proxies
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterProxy();

	/*
	* Servers that are not password protected
	*/
	UFUNCTION(BlueprintCallable, Category = "Filters")
	void AddFilterPassword();
public:
	void SetReadyToDestroy()
	{
		this->RemoveFromRoot();
	}

public:
	UFUNCTION(BlueprintCallable, Category = "Filters")
	TMap<FString, FString> GetFilters();

	MatchMakingKeyValuePair_t* GetFiltersPtr() const { return Filters; }
	int32 GetNumFilters() const { return NumFilters; }
private:
	bool CanAddFilter() const { return NumFilters < MaxFilters; }
	int32 GetKeySize() const { return sizeof(Filters[NumFilters].m_szKey); }
	int32 GetValueSize() const { return sizeof(Filters[NumFilters].m_szValue); }
private:
	int32 MaxFilters;
	int32 NumFilters;
	MatchMakingKeyValuePair_t* Filters;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
enum class ESteamServerListRequestType : uint8
{
	Favorites = 0,
	Friends,
	History,
	Internet,
	Lan,
	Spectator
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct STEAMCORE_API FSteamServerAddr
{
	GENERATED_BODY()
public:
	FSteamServerAddr() = default;

	FSteamServerAddr(const servernetadr_t& data, CSteamID steamAddr)
		: IP(FIPv4Address(data.GetIP()).ToString())
		, Port(data.GetConnectionPort())
		, QueryPort(data.GetQueryPort())
		, ConnectionAddressString(data.GetConnectionAddressString())
		, SteamP2PAddr(LexToString(steamAddr.ConvertToUint64()))
	{
	}

protected:
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString IP;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	int32 Port;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	int32 QueryPort;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString ConnectionAddressString;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString SteamP2PAddr;
};

USTRUCT(BlueprintType)
struct STEAMCORE_API FGameServerItem
{
	GENERATED_BODY()
public:
	FGameServerItem() = default;

	FGameServerItem(class gameserveritem_t* data)
		: SteamServerAddr(data->m_NetAdr, data->m_steamID)
		, Ping(data->m_nPing)
		, Players(data->m_nPlayers)
		, MaxPlayers(data->m_nMaxPlayers)
		, BotPlayers(data->m_nBotPlayers)
		, ServerVersion(data->m_nServerVersion)
		, bPassword(data->m_bPassword)
		, bSecure(data->m_bSecure)
		, m_NetAdr(data->m_NetAdr)
		, m_ulTimeLastPlayed(data->m_ulTimeLastPlayed)
		, m_nAppID(data->m_nAppID)
		, m_bDoNotRefresh(data->m_bDoNotRefresh)
		, bHadSuccessfulResponse(data->m_bHadSuccessfulResponse)
		, m_steamID(data->m_steamID)
	{
		char m_ServerName[k_cbMaxGameServerName];
		FCStringAnsi::Strncpy(m_ServerName, data->GetName(), k_cbMaxGameServerName);

		char m_MapName[k_cbMaxGameServerMapName];
		FCStringAnsi::Strncpy(m_MapName, data->m_szMap, k_cbMaxGameServerMapName);

		char m_GameDescription[k_cbMaxGameServerGameDescription];
		FCStringAnsi::Strncpy(m_GameDescription, data->m_szGameDescription, k_cbMaxGameServerGameDescription);

		char m_GameTags[k_cbMaxGameServerTags];
		FCStringAnsi::Strncpy(m_GameTags, data->m_szGameTags, k_cbMaxGameServerTags);

		ServerName = m_ServerName;
		MapName = m_MapName;
		GameDescription = m_GameDescription;
		GameTags = m_GameTags;
	}

public:
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString ServerName;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString MapName;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString GameDescription;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString GameTags;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FSteamServerAddr SteamServerAddr;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	int32 Ping;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	int32 Players;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	int32 MaxPlayers;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	int32 BotPlayers;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	int32 ServerVersion;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	bool bPassword;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	bool bSecure;

	servernetadr_t m_NetAdr;
	uint32 m_ulTimeLastPlayed;
	uint32 m_nAppID;
	bool m_bDoNotRefresh;
	bool bHadSuccessfulResponse;
	CSteamID m_steamID;
};

USTRUCT(BlueprintType)
struct STEAMCORE_API FGameServerRule
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString Name;
	UPROPERTY(BlueprintReadWrite, Category = "MatchmakingServers")
	FString Value;

	FGameServerRule() = default;

	FGameServerRule(const char* InName, const char* InValue)
		: Name(UTF8_TO_TCHAR(InName))
		, Value(UTF8_TO_TCHAR(InValue))
	{
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnServerUpdated, const FGameServerItem&, data);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnServerPing, const FGameServerItem&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnServerRules, const TArray<FGameServerRule>&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE(FOnServerRefreshCompleted);
