/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCoreWeb Documentation: https://eeldev.com
*/

#include "SteamCoreWeb/SteamCoreWeb.h"
#include "SteamCoreWeb/SteamCoreWebAsync.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FSteamCoreWebModule"

DEFINE_LOG_CATEGORY(SteamCoreWebLog);

void FSteamCoreWebModule::StartupModule()
{
	OnlineAsyncTaskThreadRunnable = new FOnlineAsyncTaskManagerSteamCoreWeb();
	check(OnlineAsyncTaskThreadRunnable);

	OnlineAsyncTaskThread = FRunnableThread::Create(OnlineAsyncTaskThreadRunnable, TEXT("SteamCoreWeb"), 128 * 1024, TPri_Normal);
	check(OnlineAsyncTaskThread);

	//UE_LOG(SteamCoreWebLog, Warning, TEXT("Created thread (ID:%d)."), OnlineAsyncTaskThread->GetThreadID());
}

void FSteamCoreWebModule::ShutdownModule()
{
	if (OnlineAsyncTaskThread)
	{
		delete OnlineAsyncTaskThread;
		OnlineAsyncTaskThread = nullptr;
	}

	if (OnlineAsyncTaskThreadRunnable)
	{
		delete OnlineAsyncTaskThreadRunnable;
		OnlineAsyncTaskThreadRunnable = nullptr;
	}
}

bool FSteamCoreWebModule::Tick(float DeltaTime)
{
	if (OnlineAsyncTaskThreadRunnable)
	{
		OnlineAsyncTaskThreadRunnable->GameTick();
	}

	return true;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSteamCoreWebModule, SteamCoreWeb)void USteamCoreWebSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	FSteamCoreWebModule* m_CoreModule = FModuleManager::Get().GetModulePtr<FSteamCoreWebModule>("SteamCoreWeb");

	if (m_CoreModule)
	{
		OnlineAsyncTaskThreadRunnable = m_CoreModule->OnlineAsyncTaskThreadRunnable;
		OnlineAsyncTaskThread = m_CoreModule->OnlineAsyncTaskThread;
	}
}

void USteamCoreWebSubsystem::Deinitialize()
{
	OnlineAsyncTaskThreadRunnable = nullptr;
	OnlineAsyncTaskThread = nullptr;
}

bool USteamCoreWebSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (SubsystemType == ESubsystemWeb::SteamCoreWeb)
	{
		return true;
	}

	bool m_Result = true;

	if (const USteamCoreWebSettings* m_Settings = GetDefault<USteamCoreWebSettings>())
	{
		m_Result = (m_Settings->DisabledSubsystems & (1 << static_cast<int32>(SubsystemType))) == 0;
	}

	return m_Result;
}

void USteamCoreWebSubsystem::QueueAsyncTask(class FOnlineAsyncTask* asyncTask)
{
	check(OnlineAsyncTaskThreadRunnable);
	OnlineAsyncTaskThreadRunnable->AddToInQueue(asyncTask);
}

void USteamCoreWebSubsystem::QueueAsyncOutgoingItem(class FOnlineAsyncItem* asyncItem)
{
	check(OnlineAsyncTaskThreadRunnable);
	OnlineAsyncTaskThreadRunnable->AddToOutQueue(asyncItem);
}
