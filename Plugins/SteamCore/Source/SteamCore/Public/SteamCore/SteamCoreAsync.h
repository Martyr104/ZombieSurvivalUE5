/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore Documentation: https://eeldev.com
*/

#pragma once

#include "CoreMinimal.h"
#include "OnlineAsyncTaskManager.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SteamCore/Steam.h"
#include "SteamCoreAsync.generated.h"

class USteamCoreAsyncAction;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailure);

class STEAMCORE_API FOnlineAsyncTaskSteamCore : public FOnlineAsyncTaskBasic<class USteamCoreSubsystem>
{
public:
	FOnlineAsyncTaskSteamCore(USteamCoreSubsystem* Subsystem, const SteamAPICall_t Handle, float Timeout = 10.f)
		: FOnlineAsyncTaskBasic(Subsystem)
		, bInit(false)
		, bTimedOut(false)
		, m_CallbackHandle(Handle)
		, m_AsyncObject(nullptr)
		, m_AsyncTimeout(Timeout)
	{
		
	}
	FOnlineAsyncTaskSteamCore(USteamCoreSubsystem* Subsystem, const SteamAPICall_t Handle, USteamCoreAsyncAction* AsyncObject = nullptr, float Timeout = 10.f)
		: FOnlineAsyncTaskBasic(Subsystem)
		, bInit(false)
		, bTimedOut(false)
		, m_CallbackHandle(Handle)
		, m_AsyncObject(AsyncObject)
		, m_AsyncTimeout(Timeout)
	{
	}

	virtual ~FOnlineAsyncTaskSteamCore() override
	{
	}

private:
	FOnlineAsyncTaskSteamCore();
public:
	bool bInit;
	bool bTimedOut;
	SteamAPICall_t m_CallbackHandle;
	USteamCoreAsyncAction* m_AsyncObject;
protected:
	virtual void Tick() override;
	virtual FString ToString() const override { return "SteamCoreAyncTask"; }
protected:
	float m_AsyncTimeout = 10.f;
};

class STEAMCORE_API FOnlineAsyncTaskManagerSteamCore : public FOnlineAsyncTaskManager
{
public:
	FOnlineAsyncTaskManagerSteamCore()
	{
	}

	FOnlineAsyncTaskManagerSteamCore(class USteamCoreSubsystem* subsystem)
		: SteamCoreSubsystem(subsystem)
	{
	}

public:
	virtual ~FOnlineAsyncTaskManagerSteamCore() override
	{
	}

private:
	class USteamCoreSubsystem* SteamCoreSubsystem;
protected:
	virtual void OnlineTick() override;
};

UCLASS()
class STEAMCORE_API USteamCoreAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;
	virtual void SetReadyToDestroy() override;
protected:
	static USteamCoreSubsystem* GetInstancedSubsystem(UObject* WorldContextObject);
protected:
	UPROPERTY()
	TWeakObjectPtr<UObject> m_WorldContextObject;
};
