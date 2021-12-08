/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCoreWeb Documentation: https://eeldev.com
*/

#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonValue.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "SteamWebTypes.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(SteamCoreWebLog, Log, All);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSteamCoreWebCallback, const FString&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSteamCoreWebAsyncCallback, const FString&, data, bool, bWasSuccessful);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Global enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UENUM(BlueprintType, meta = (Bitflags))
enum class ESubsystemWeb : uint8
{
	SteamCoreWeb = 0 UMETA(Hidden),
	Apps,
	Broadcast,
	CheatReporting,
	Community,
	Econ,
	EconMarket,
	Economy,
	GameInventory,
	GameNotifications,
	GameServers,
	GameServerStats,
	Inventory,
	LobbyMatchmaking,
	Leaderboards,
	MicroTxn,
	News,
	PlayerService,
	PublishedFile,
	PublishedItemSearch,
	PublishedItemVoting,
	RemoteStorage,
	User,
	UserAuth,
	UserStats,
	Workshop
};

ENUM_CLASS_FLAGS(ESubsystemWeb)

enum class EVerb : uint8
{
	GET = 0,
	POST,
	PUT
};

UENUM(BlueprintType)
enum class ESteamValueType : uint8
{
	STRING,
	NUMBER,
	BOOL
};

UENUM(BlueprintType)
enum class ESteamJsonResult : uint8
{
	Found,
	NotFound,
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FSteamCoreJson
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SteamCoreWeb")
	FString Key;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SteamCoreWeb")
	FString String;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SteamCoreWeb")
	int32 Number;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SteamCoreWeb")
	bool Bool;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SteamCoreWeb")
	ESteamValueType Type;
public:
	FSteamCoreJson() = default;

	FSteamCoreJson(FString key, FString value)
		: Key(key)
		, String(value)
		, Number(0)
		, Bool(false)
		, Type(ESteamValueType::STRING)
	{
	}

	FSteamCoreJson(FString key, double value)
		: Key(key)
		, String(LexToString(value))
		, Number(value)
		, Bool(false)
		, Type(ESteamValueType::NUMBER)
	{
	}

	FSteamCoreJson(FString key, bool value)
		: Key(key)
		, String(LexToString(value))
		, Number(0)
		, Bool(value)
		, Type(ESteamValueType::BOOL)
	{
	}
};

struct FRequestString
{
public:
	FRequestString()
		: bFormatted(false)
	{
	}

	FRequestString(FString key)
		: bFormatted(false)
	{
		if (key.Len() > 0)
		{
			Key = key;
			Str.Append(FString::Printf(TEXT("?key=%s"), *key));
		}
	}

	virtual ~FRequestString()
	{
	}

public:
	void Add(FString key, FString val)
	{
		if (key.Len() == 0 || val.Len() == 0)
		{
			return;
		}
		bool bHasEntry = Str.Len() > 0;
		Str.Append(FString::Printf(TEXT("%s%s=%s"), bHasEntry ? TEXT("&") : TEXT("?"), *key, *val));
	}

	void Add(FString key, int32 val)
	{
		if (key.Len() == 0)
		{
			return;
		}
		bool bHasEntry = Str.Len() > 0;
		Str.Append(FString::Printf(TEXT("%s%s=%s"), bHasEntry ? TEXT("&") : TEXT("?"), *key, *LexToString(val)));
	}

	void Add(FString key, bool bData)
	{
		if (key.Len() == 0)
		{
			return;
		}
		bool bHasEntry = Str.Len() > 0;
		Str.Append(FString::Printf(TEXT("%s%s=%s"), bHasEntry ? TEXT("&") : TEXT("?"), *key, *LexToString(bData)));
	}

	void Add(FString key, TArray<uint8> data)
	{
		if (key.Len() == 0 || data.Num() == 0)
		{
			return;
		}
		bool bHasEntry = Str.Len() > 0;
		Str.Append(FString::Printf(TEXT("%s%s="), bHasEntry ? TEXT("&") : TEXT("?"), *key));
		for (int32 i = 0; i < data.Num(); i++)
		{
			Str.AppendChar(data[i]);
		}
	}

	void Add(FString key, TArray<int32> data)
	{
		if (key.Len() == 0 || data.Num() == 0)
		{
			return;
		}
		bool bHasEntry = Str.Len() > 0;
		for (int32 i = 0; i < data.Num(); i++)
		{
			Str.Append(FString::Printf(TEXT("%s%s[%i]=%s"), bHasEntry ? TEXT("&") : TEXT("?"), *key, i, *LexToString(data[i])));
		}
	}

	void Add(FString key, TArray<FString> data)
	{
		if (key.Len() == 0 || data.Num() == 0)
		{
			return;
		}
		bool bHasEntry = Str.Len() > 0;
		for (int32 i = 0; i < data.Num(); i++)
		{
			Str.Append(FString::Printf(TEXT("%s%s[%i]=%s"), bHasEntry ? TEXT("&") : TEXT("?"), *key, i, *data[i]));
		}
	}

	void Add(FString customString)
	{
		if (customString.Len() == 0)
		{
			return;
		}
		Str.Append(customString);
	}

	void AddNumberField(const FString& fieldName, double number)
	{
		if (fieldName.Len() == 0)
		{
			return;
		}
		if (!Obj)
		{
			Obj = MakeShareable(new FJsonObject);
		}
		Obj->SetNumberField(fieldName, number);
	}

	void AddStringField(const FString& fieldName, const FString& stringValue)
	{
		if (fieldName.Len() == 0 || stringValue.Len() == 0)
		{
			return;
		}
		if (!Obj)
		{
			Obj = MakeShareable(new FJsonObject);
		}
		Obj->SetStringField(fieldName, stringValue);
	}

	void AddBoolField(const FString& fieldName, bool value)
	{
		if (fieldName.Len() == 0)
		{
			return;
		}
		if (!Obj)
		{
			Obj = MakeShareable(new FJsonObject);
		}
		Obj->SetBoolField(fieldName, value);
	}

	void AddArrayField(const FString& fieldName, const TArray<TSharedPtr<FJsonValue>>& arr)
	{
		if (fieldName.Len() == 0)
		{
			return;
		}
		if (!Obj)
		{
			Obj = MakeShareable(new FJsonObject);
		}
		Obj->SetArrayField(fieldName, arr);
	}

public:
	FString Get()
	{
		if (Obj && !bFormatted)
		{
			const auto JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonStr);
			FJsonSerializer::Serialize(Obj.ToSharedRef(), JsonWriter);
			Add("input_json", JsonStr);
			JsonWriter->Close();
			bFormatted = true;
		}

		return Str;
	}

	FString GetKey(bool bAsUrlFormat = true)
	{
		if (bAsUrlFormat)
		{
			return FString::Printf(TEXT("?key=%s"), *Key);
		}
		return Key;
	}

	bool IsJson() const { return Obj != nullptr; }
protected:
	FString Key;
	FString Str;
	FString JsonStr;
	TSharedPtr<FJsonObject> Obj;
	bool bFormatted;
};

struct FRequestURL
{
public:
	FRequestURL() = default;

	FRequestURL(FString interfaceName, FString functionName, FString requestString, int32 version = 1, bool bPublicAPI = false)
	{
		RequestURL = FString::Printf(TEXT("%s/%s/%s/v%i/%s"), bPublicAPI ? PublicURL : PartnerURL, *interfaceName, *functionName, version, *requestString);
	}

	virtual ~FRequestURL()
	{
	}

public:
	FString RequestURL;
	const TCHAR* PartnerURL = TEXT("https://partner.steam-api.com");
	const TCHAR* PublicURL = TEXT("https://api.steampowered.com");
public:
	operator FString() const { return RequestURL; }
	const TCHAR* operator*() const { return *RequestURL; }
};
