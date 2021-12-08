/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamScreenshots
*/

#include "SteamScreenshots/SteamScreenshots.h"
#include "SteamCorePluginPrivatePCH.h"

void UScreenshots::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	OnScreenshotReadyCallback.Register(this, &UScreenshots::OnScreenshotReady);
	OnScreenshotRequestedCallback.Register(this, &UScreenshots::OnScreenshotRequested);

	if (IsRunningDedicatedServer())
	{
		OnScreenshotReadyCallback.SetGameserverFlag();
		OnScreenshotRequestedCallback.SetGameserverFlag();
	}
}

void UScreenshots::Deinitialize()
{
	OnScreenshotReadyCallback.Unregister();
	OnScreenshotRequestedCallback.Unregister();

	Super::Deinitialize();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

FScreenshotHandle UScreenshots::AddScreenshotToLibrary(FString FileName, FString ThumbnailFilename, int32 Width, int32 Height)
{
	LogVerbose("");

	FScreenshotHandle Handle;

	if (SteamScreenshots())
	{
		char FileNameAnsi[256];
		FCStringAnsi::Strncpy(FileNameAnsi, TCHAR_TO_UTF8(*FileName), 256);
		char ThumbnailAnsi[256];
		FCStringAnsi::Strncpy(ThumbnailAnsi, TCHAR_TO_UTF8(*ThumbnailFilename), 256);

		Handle = SteamScreenshots()->AddScreenshotToLibrary(FileNameAnsi, ThumbnailAnsi, Width, Height);
	}

	return Handle;
}

FScreenshotHandle UScreenshots::AddVRScreenshotToLibrary(ESteamVRScreenshotType EType, FString FileName, FString VRFileName)
{
	LogVerbose("");

	FScreenshotHandle Handle;

	if (SteamScreenshots())
	{
		char FileNameAnsi[256];
		FCStringAnsi::Strncpy(FileNameAnsi, TCHAR_TO_UTF8(*FileName), 256);
		char VrFileNameAnsi[256];
		FCStringAnsi::Strncpy(VrFileNameAnsi, TCHAR_TO_UTF8(*VRFileName), 256);

		Handle = SteamScreenshots()->AddVRScreenshotToLibrary(static_cast<EVRScreenshotType>(EType), FileNameAnsi, VrFileNameAnsi);
	}

	return Handle;
}

void UScreenshots::HookScreenshots(bool bHook)
{
	LogVerbose("");

	if (SteamScreenshots())
	{
		SteamScreenshots()->HookScreenshots(bHook);
	}
}

bool UScreenshots::IsScreenshotsHooked()
{
	LogVeryVerbose("");

	bool bResult = false;

	if (SteamScreenshots())
	{
		bResult = SteamScreenshots()->IsScreenshotsHooked();
	}

	return bResult;
}

bool UScreenshots::SetLocation(FScreenshotHandle Handle, FString Location)
{
	LogVerbose("");

	bool bResult = false;

	if (SteamScreenshots())
	{
		bResult = SteamScreenshots()->SetLocation(Handle, TCHAR_TO_UTF8(*Location));
	}

	return bResult;
}

bool UScreenshots::TagPublishedFile(FScreenshotHandle Handle, FPublishedFileID PublishedFileID)
{
	LogVerbose("");

	bool bResult = false;

	if (SteamScreenshots())
	{
		bResult = SteamScreenshots()->TagPublishedFile(Handle, PublishedFileID);
	}

	return bResult;
}

bool UScreenshots::TagUser(FScreenshotHandle Handle, FSteamID SteamID)
{
	LogVerbose("");

	bool bResult = false;

	if (SteamScreenshots())
	{
		bResult = SteamScreenshots()->TagUser(Handle, SteamID);
	}

	return bResult;
}

void UScreenshots::TriggerScreenshot()
{
	LogVerbose("");

	if (SteamScreenshots())
	{
		SteamScreenshots()->TriggerScreenshot();
	}
}

FScreenshotHandle UScreenshots::WriteScreenshot(TArray<uint8> PubRGB, int32 Width, int32 Height)
{
	LogVerbose("");

	FScreenshotHandle Handle;

	if (SteamScreenshots())
	{
		Handle = SteamScreenshots()->WriteScreenshot(PubRGB.GetData(), PubRGB.Num(), Width, Height);
	}

	return Handle;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam API Callbacks
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void UScreenshots::OnScreenshotReady(ScreenshotReady_t* pParam)
{
	LogVerbose("");

	auto Data = *pParam;
	AsyncTask(ENamedThreads::GameThread, [this, Data]()
	{
		ScreenshotReady.Broadcast(Data);
	});
}

void UScreenshots::OnScreenshotRequested(ScreenshotRequested_t* pParam)
{
	LogVerbose("");

	auto Data = *pParam;
	AsyncTask(ENamedThreads::GameThread, [this, Data]()
	{
		ScreenshotRequested.Broadcast(Data);
	});
}
