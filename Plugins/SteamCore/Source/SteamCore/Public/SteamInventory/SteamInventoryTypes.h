/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamInventory
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCore/Steam.h"
#include "SteamCore/SteamTypes.h"
#include "SteamInventoryTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Enums
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum ESteamCoreItemFlags
{
	ENoTrade = 0,
	ERemoved = 8,
	EConsumed = 9,
};

ENUM_CLASS_FLAGS(ESteamCoreItemFlags)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FSteamItemInstanceID
{
	GENERATED_BODY()
public:
	FSteamItemInstanceID()
		: Value(k_SteamItemInstanceIDInvalid)
	{
	}

	FSteamItemInstanceID(uint64 value)
		: Value(value)
	{
	}

public:
	operator uint64() const { return Value; }
private:
	uint64 Value;
};

USTRUCT(BlueprintType)
struct FSteamItemDef
{
	GENERATED_BODY()
public:
	FSteamItemDef()
		: Value(0)
	{
	}

	FSteamItemDef(int32 data)
		: Value(data)
	{
	}

public:
	operator int32() const { return Value; }
protected:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 Value;
};

USTRUCT(BlueprintType)
struct FSteamItemDetails
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FSteamItemInstanceID InstanceID;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FSteamItemDef Definition;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 Quantity;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TArray<TEnumAsByte<ESteamCoreItemFlags>> Flags;
public:
	FSteamItemDetails()
		: Quantity(0)
	{
	}

	FSteamItemDetails(const SteamItemDetails_t& data)
		: InstanceID(data.m_itemId)
		, Definition(data.m_iDefinition)
		, Quantity(data.m_unQuantity)
	{
		for (int32 i = 0; i < 31; i++)
		{
			if (data.m_unFlags & 1 << i)
			{
				Flags.Add(static_cast<ESteamCoreItemFlags>(i));
			}
		}
	}
};

USTRUCT(BlueprintType)
struct FSteamInventoryResult
{
	GENERATED_BODY()
public:
	FSteamInventoryResult()
		: Value(0)
	{
	}

	FSteamInventoryResult(const SteamInventoryResult_t& data)
		: Value(data)
	{
	}

public:
	operator int32() const { return Value; }
	operator int32() { return Value; }

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 Value;
};

USTRUCT(BlueprintType)
struct FSteamInventoryEligiblePromoItemDefIDs
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FSteamID SteamID;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int NumEligiblePromoItemDefs;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	bool bCachedData;
public:
	FSteamInventoryEligiblePromoItemDefIDs() = default;

	FSteamInventoryEligiblePromoItemDefIDs(const SteamInventoryEligiblePromoItemDefIDs_t& data)
		: Result(_SteamResult(data.m_result))
		, SteamID(data.m_steamID)
		, NumEligiblePromoItemDefs(data.m_numEligiblePromoItemDefs)
		, bCachedData(data.m_bCachedData)
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamInventoryResultReady
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FSteamInventoryResult Handle;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	ESteamResult Result;
public:
	FSteamInventoryResultReady() = default;

	FSteamInventoryResultReady(const SteamInventoryResultReady_t& data)
		: Handle(data.m_handle)
		, Result(_SteamResult(data.m_result))
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamInventoryFullUpdate
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FSteamInventoryResult Handle;
public:
	FSteamInventoryFullUpdate() = default;

	FSteamInventoryFullUpdate(const SteamInventoryFullUpdate_t& data)
		: Handle(data.m_handle)
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamInventoryRequestPricesResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FString Currency;
public:
	FSteamInventoryRequestPricesResult() = default;

	FSteamInventoryRequestPricesResult(const SteamInventoryRequestPricesResult_t& data)
		: Result(_SteamResult(data.m_result))
		, Currency((strlen(data.m_rgchCurrency) > 0) ? data.m_rgchCurrency : "")
	{
	}
};

USTRUCT(BlueprintType)
struct FSteamInventoryStartPurchaseResult
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	ESteamResult Result;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FString OrderId;
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FString TransactionId;
public:
	FSteamInventoryStartPurchaseResult() = default;

	FSteamInventoryStartPurchaseResult(const SteamInventoryStartPurchaseResult_t& data)
		: Result(_SteamResult(data.m_result))
		, OrderId(LexToString(data.m_ulOrderID))
		, TransactionId(LexToString(data.m_ulTransID))
	{
	}
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Delegate declarations
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamInventoryResultReady, const FSteamInventoryResultReady&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamInventoryFullUpdate, const FSteamInventoryFullUpdate&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamInventoryStartPurchaseResultDelegate, const FSteamInventoryStartPurchaseResult&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamInventoryRequestPricesResultDelegate, const FSteamInventoryRequestPricesResult&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamInventoryEligiblePromoItemDefIDs, const FSteamInventoryEligiblePromoItemDefIDs&, data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSteamInventoryDefinitionUpdate);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRequestEligiblePromoItemDefinitionsIDs, const FSteamInventoryEligiblePromoItemDefIDs&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSteamInventoryRequestPricesResult, const FSteamInventoryRequestPricesResult&, data, bool, bWasSuccessful);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSteamInventoryStartPurchaseResult, const FSteamInventoryStartPurchaseResult&, data, bool, bWasSuccessful);
