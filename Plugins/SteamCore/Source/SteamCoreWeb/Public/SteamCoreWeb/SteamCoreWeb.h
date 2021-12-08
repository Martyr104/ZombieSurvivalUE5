/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCoreWeb Documentation: https://eeldev.com
*/

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "SteamWebUtilities.h"
#include "SteamCoreWebSettings.h"
#include "Containers/Ticker.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SteamCoreWeb.generated.h"

class FSteamCoreWebModule : public IModuleInterface, public FTickerObjectBase
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool Tick(float DeltaTime) override;
public:
	class FOnlineAsyncTaskManagerSteamCoreWeb* OnlineAsyncTaskThreadRunnable;
	class FRunnableThread* OnlineAsyncTaskThread;
};

UCLASS(abstract)
class STEAMCOREWEB_API USteamCoreWeb : public UObject
{
	GENERATED_BODY()
};

UCLASS()
class STEAMCOREWEB_API USteamCoreWebSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	class FOnlineAsyncTaskManagerSteamCoreWeb* OnlineAsyncTaskThreadRunnable;
	class FRunnableThread* OnlineAsyncTaskThread;
	ESubsystemWeb SubsystemType;
public:
	USteamCoreWebSubsystem()
		: SubsystemType(ESubsystemWeb::SteamCoreWeb)
	{
	}

public:
	void QueueAsyncTask(class FOnlineAsyncTask* asyncTask);
	void QueueAsyncOutgoingItem(class FOnlineAsyncItem* asyncItem);
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
};
