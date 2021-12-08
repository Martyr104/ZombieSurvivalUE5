/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamApps
*/

#include "SteamApps/SteamAppsAsyncTasks.h"
#include "SteamCorePluginPrivatePCH.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		FOnlineAsyncTaskSteamCoreAppsGetFileDetails
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void FOnlineAsyncTaskSteamCoreAppsGetFileDetails::Tick()
{
	FOnlineAsyncTaskSteamCore::Tick();

	ISteamUtils* SteamUtilsPtr = IsRunningDedicatedServer() ? SteamGameServerUtils() : SteamUtils();
	check(SteamUtilsPtr);
	ISteamApps* SteamAppsPtr = GetApps();
	check(SteamAppsPtr);

	if (SteamUtilsPtr && SteamAppsPtr)
	{
		if (!bInit)
		{
			m_CallbackHandle = SteamAppsPtr->GetFileDetails(TCHAR_TO_UTF8(*m_FileName));
			bInit = true;
		}

		if (m_CallbackHandle != k_uAPICallInvalid)
		{
			bool bFailedCall = false;

			bIsComplete = SteamUtilsPtr->IsAPICallCompleted(m_CallbackHandle, &bFailedCall) ? true : false;

			if (bIsComplete)
			{
				bool bFailedResult;
				const bool bSuccessCallResult = SteamUtilsPtr->GetAPICallResult(m_CallbackHandle, &m_CallbackResults, sizeof(m_CallbackResults), m_CallbackResults.k_iCallback, &bFailedResult);
				bWasSuccessful = (bSuccessCallResult ? true : false) && (!bFailedCall ? true : false) && (!bFailedResult ? true : false) && ((m_CallbackResults.m_eResult == k_EResultOK) ? true : false);
			}
		}
		else
		{
			bIsComplete = true;
			bWasSuccessful = false;
		}
	}
	else
	{
		bIsComplete = true;
		bWasSuccessful = false;
	}
}

void FOnlineAsyncTaskSteamCoreAppsGetFileDetails::TriggerDelegates()
{
	LogVerbose("WasSuccessful: %d", WasSuccessful());

	m_OnSteamCallback.ExecuteIfBound(m_CallbackResults, bWasSuccessful);
}
