/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamMatchmaking
*/

#include "SteamMatchmaking/SteamMatchmakingAsyncActions.h"
#include "SteamMatchmaking/SteamMatchmakingAsyncTasks.h"
#include "SteamCorePluginPrivatePCH.h"
#include <../Private/SteamSessionKeys.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreMatchmakingAsyncActionCreateLobby
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreMatchmakingAsyncActionCreateLobby* USteamCoreMatchmakingAsyncActionCreateLobby::CreateLobbyAsync(UObject* WorldContextObject, ESteamLobbyType LobbyType, int32 MaxMembers, float Timeout)
{
	LogVerbose("");

	if (USteamCoreSubsystem* Subsystem = GetInstancedSubsystem(WorldContextObject))
	{
		const auto AsyncObject = NewObject<USteamCoreMatchmakingAsyncActionCreateLobby>();
		const auto Task = new FOnlineAsyncTaskSteamCoreMatchmakingCreateLobby(Subsystem, AsyncObject, static_cast<ELobbyType>(LobbyType), MaxMembers, Timeout);
		AsyncObject->RegisterWithGameInstance(Subsystem->GetGameInstance());
		AsyncObject->m_WorldContextObject = WorldContextObject;
		Subsystem->QueueAsyncTask(Task);
		AsyncObject->Activate();

		return AsyncObject;
	}

	return nullptr;
}

void USteamCoreMatchmakingAsyncActionCreateLobby::HandleCallback(const FCreateLobbyData& Data, bool bWasSuccessful)
{
	LogVerbose("");

	AsyncTask(ENamedThreads::GameThread, [this, Data, bWasSuccessful]()
	{
		OnCallback.Broadcast(Data, bWasSuccessful);

		SetReadyToDestroy();
	});
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreMatchmakingAsyncActionCreateLobby
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreMatchmakingAsyncActionRequestLobbyList* USteamCoreMatchmakingAsyncActionRequestLobbyList::RequestLobbyListAsync(UObject* WorldContextObject, float Timeout)
{
	LogVerbose("");

	if (USteamCoreSubsystem* Subsystem = GetInstancedSubsystem(WorldContextObject))
	{
		const auto AsyncObject = NewObject<USteamCoreMatchmakingAsyncActionRequestLobbyList>();
		const auto Task = new FOnlineAsyncTaskSteamCoreRequestLobbyList(Subsystem, AsyncObject, Timeout);
		AsyncObject->RegisterWithGameInstance(Subsystem->GetGameInstance());
		AsyncObject->m_WorldContextObject = WorldContextObject;
		Subsystem->QueueAsyncTask(Task);
		AsyncObject->Activate();

		return AsyncObject;
	}

	return nullptr;
}

void USteamCoreMatchmakingAsyncActionRequestLobbyList::HandleCallback(const FLobbyMatchList& Data, bool bWasSuccessful)
{
	LogVerbose("");

	AsyncTask(ENamedThreads::GameThread, [this, Data, bWasSuccessful]()
	{
		OnCallback.Broadcast(Data, bWasSuccessful);

		SetReadyToDestroy();
	});
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreMatchmakingAsyncActionJoinLobby
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreMatchmakingAsyncActionJoinLobby* USteamCoreMatchmakingAsyncActionJoinLobby::JoinLobbyAsync(UObject* WorldContextObject, FSteamID SteamIDLobby, float Timeout)
{
	LogVerbose("");

	if (USteamCoreSubsystem* Subsystem = GetInstancedSubsystem(WorldContextObject))
	{
		const auto AsyncObject = NewObject<USteamCoreMatchmakingAsyncActionJoinLobby>();
		const auto Task = new FOnlineAsyncTaskSteamCoreJoinLobby(Subsystem, AsyncObject, SteamIDLobby, Timeout);
		AsyncObject->RegisterWithGameInstance(Subsystem->GetGameInstance());
		AsyncObject->m_WorldContextObject = WorldContextObject;
		Subsystem->QueueAsyncTask(Task);
		AsyncObject->Activate();

		return AsyncObject;
	}

	return nullptr;
}

void USteamCoreMatchmakingAsyncActionJoinLobby::HandleCallback(const FJoinLobbyData& Data, bool bWasSuccessful)
{
	LogVerbose("");

	AsyncTask(ENamedThreads::GameThread, [this, Data, bWasSuccessful]()
	{
		OnCallback.Broadcast(Data, bWasSuccessful);

		SetReadyToDestroy();
	});
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreCreateSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreCreateSession::USteamCoreCreateSession()
	: Delegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCompleted))
{
}

USteamCoreCreateSession* USteamCoreCreateSession::CreateSteamCoreSession(UObject* WorldContextObject, TMap<FString, FSteamSessionSetting> SessionSettings, FString SessionName, int32 MaxPlayers, bool bUseLAN, bool bAllowInvites, bool bUsesPresence, bool bAllowJoinViaPresence, bool bAllowJoinViaPresenceFriendsOnly, bool bAntiCheatProtected, bool bUsesStats, bool bShouldAdvertise, bool bUseLobbiesVoiceChatIfAvailable, float Timeout)
{
	LogVerbose("");

	if (USteamCoreSubsystem* Subsystem = GetInstancedSubsystem(WorldContextObject))
	{
		const auto AsyncObject = NewObject<USteamCoreCreateSession>();
		AsyncObject->RegisterWithGameInstance(Subsystem->GetGameInstance());
		AsyncObject->m_WorldContextObject = WorldContextObject;

		const bool bIsDedicated = IsRunningDedicatedServer();

		AsyncObject->m_SessionSettings.NumPublicConnections = MaxPlayers;
		AsyncObject->m_SessionSettings.NumPrivateConnections = 0;
		AsyncObject->m_SessionSettings.bShouldAdvertise = bShouldAdvertise;
		AsyncObject->m_SessionSettings.bAllowJoinInProgress = true;
		AsyncObject->m_SessionSettings.bIsLANMatch = bUseLAN;
		AsyncObject->m_SessionSettings.bAllowJoinViaPresence = bAllowJoinViaPresence;
		AsyncObject->m_SessionSettings.bIsDedicated = bIsDedicated;
		AsyncObject->m_SessionSettings.bUsesPresence = (bUsesPresence && !bIsDedicated);
		AsyncObject->m_SessionSettings.bAllowJoinViaPresenceFriendsOnly = bAllowJoinViaPresenceFriendsOnly;
		AsyncObject->m_SessionSettings.bAntiCheatProtected = bAntiCheatProtected;
		AsyncObject->m_SessionSettings.bUsesStats = bUsesStats;
		AsyncObject->m_SessionSettings.bShouldAdvertise = bShouldAdvertise;
		AsyncObject->m_SessionSettings.bAllowInvites = bAllowInvites;
#if ENGINE_MINOR_VERSION > 26
		AsyncObject->m_SessionSettings.bUseLobbiesIfAvailable = (bUsesPresence && !bIsDedicated);
		AsyncObject->m_SessionSettings.bUseLobbiesVoiceChatIfAvailable = (bUseLobbiesVoiceChatIfAvailable && !bIsDedicated);
#endif

		for (auto& Element : SessionSettings)
		{
			if (Element.Key.Len() == 0)
			{
				continue;
			}

			FOnlineSessionSetting Setting;
			Setting.AdvertisementType = EOnlineDataAdvertisementType::ViaOnlineService;

			if (Element.Value.Data.IsType<bool>())
			{
				Setting.Data.SetValue(Element.Value.Data.Get<bool>() ? 1 : 0);
			}
			else if (Element.Value.Data.IsType<int32>())
			{
				Setting.Data.SetValue(Element.Value.Data.Get<int32>());
			}
			else if (Element.Value.Data.IsType<FString>())
			{
				Setting.Data.SetValue(Element.Value.Data.Get<FString>());
			}

			AsyncObject->m_SessionSettings.Set(FName(*Element.Key), Setting);
		}

		FOnlineSessionSetting Setting;
		Setting.AdvertisementType = EOnlineDataAdvertisementType::ViaOnlineService;
		Setting.Data.SetValue(*SessionName);

		AsyncObject->m_SessionSettings.Set(STEAMKEY_OWNINGUSERNAME, Setting);

		return AsyncObject;
	}
	return nullptr;
}

void USteamCoreCreateSession::Activate()
{
	LogVerbose("");

	bool bSuccess = false;

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		const IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt.IsValid())
		{
			DelegateHandle = SessionInt->AddOnCreateSessionCompleteDelegate_Handle(Delegate);

			if (SessionInt->CreateSession(0, NAME_GameSession, m_SessionSettings))
			{
				bSuccess = true;
			}
		}
	}

	if (!bSuccess)
	{
		OnCompleted(NAME_GameSession, false);
	}
}

void USteamCoreCreateSession::OnCompleted(FName SessionName, bool bSuccessful)
{
	LogVerbose("Create Session %s Complete! %d", *SessionName.ToString(), bSuccessful);

	bool bSuccess = false;

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		const IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt.IsValid() && bSuccessful)
		{
			SessionInt->StartSession(NAME_GameSession);
			SessionInt->ClearOnCreateSessionCompleteDelegate_Handle(DelegateHandle);

			bSuccess = true;
		}
	}

	if (bSuccess)
	{
		OnSuccess.Broadcast();
	}
	else
	{
		OnFailure.Broadcast();
	}

	SetReadyToDestroy();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreFindSession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreFindSession::USteamCoreFindSession()
	: Delegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnCompleted))
{
}

USteamCoreFindSession* USteamCoreFindSession::FindSteamCoreSessions(UObject* WorldContextObject, TMap<FString, FSteamSessionSearchSetting> SearchSettings, int32 MaxResults /* = 50 */, bool bUseLAN /* = false */, ESteamSessionFindType ServerType /* = ESteamSessionFindType::Listen */, bool bEmptyServersOnly /* = false */, bool bSecureServersOnly /* = false */, float Timeout)
{
	LogVerbose("");

	if (USteamCoreSubsystem* Subsystem = GetInstancedSubsystem(WorldContextObject))
	{
		const auto AsyncObject = NewObject<USteamCoreFindSession>();
		AsyncObject->RegisterWithGameInstance(Subsystem->GetGameInstance());
		AsyncObject->m_WorldContextObject = WorldContextObject;
		AsyncObject->additionalSearchSettings = SearchSettings;
		AsyncObject->m_MaxResults = MaxResults;
		AsyncObject->m_bUseLAN = bUseLAN;
		AsyncObject->m_ServerType = ServerType;
		AsyncObject->m_bEmptyServersOnly = bEmptyServersOnly;
		AsyncObject->m_bSecureServersOnly = bSecureServersOnly;

		return AsyncObject;
	}
	return nullptr;
}

void USteamCoreFindSession::Activate()
{
	LogVerbose("");

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		const IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt.IsValid())
		{
			DelegateHandle = SessionInt->AddOnFindSessionsCompleteDelegate_Handle(Delegate);

			m_SearchSettings = MakeShareable(new FOnlineSessionSearch);

			m_SearchSettings->MaxSearchResults = m_MaxResults;
			m_SearchSettings->bIsLanQuery = m_bUseLAN;
			FOnlineSearchSettings& m_Settings = m_SearchSettings->QuerySettings;

			if (m_ServerType == ESteamSessionFindType::Listen)
			{
				m_Settings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
			}
			else
			{
				m_Settings.Set(SEARCH_DEDICATED_ONLY, 1, EOnlineComparisonOp::Equals);
			}

			if (m_bEmptyServersOnly)
			{
				m_Settings.Set(SEARCH_EMPTY_SERVERS_ONLY, m_bEmptyServersOnly ? 1 : 0, EOnlineComparisonOp::Equals);
			}
			if (m_bSecureServersOnly)
			{
				m_Settings.Set(SEARCH_SECURE_SERVERS_ONLY, m_bSecureServersOnly ? 1 : 0, EOnlineComparisonOp::Equals);
			}

			for (auto& Element : additionalSearchSettings)
			{
				if (Element.Key.Len() == 0)
				{
					continue;
				}

				if (Element.Value.Data.IsType<bool>())
				{
					m_Settings.Set(FName(*Element.Key), Element.Value.Data.Get<bool>() ? 1 : 0, static_cast<EOnlineComparisonOp::Type>(Element.Value.ComparisonOp));
				}
				else if (Element.Value.Data.IsType<int32>())
				{
					m_Settings.Set(FName(*Element.Key), Element.Value.Data.Get<int32>(), static_cast<EOnlineComparisonOp::Type>(Element.Value.ComparisonOp));
				}
				else if (Element.Value.Data.IsType<FString>())
				{
					m_Settings.Set(FName(*Element.Key), Element.Value.Data.Get<FString>(), static_cast<EOnlineComparisonOp::Type>(Element.Value.ComparisonOp));
				}
			}

			if (!SessionInt->FindSessions(0, m_SearchSettings.ToSharedRef()))
			{
				OnCompleted(false);
			}
		}
	}
}

void USteamCoreFindSession::OnCompleted(bool bSuccessful)
{
	LogVerbose("");

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt.IsValid())
		{
			SessionInt->ClearOnFindSessionsCompleteDelegate_Handle(DelegateHandle);

			if (m_SearchSettings.IsValid())
			{
				LogVerbose("Found sessions: %i ", m_SearchSettings->SearchResults.Num());

				TArray<FSteamSessionResult> Results;

				for (FOnlineSessionSearchResult& Element : m_SearchSettings->SearchResults)
				{
					TArray<FSteamSessionSetting> AdditionalSessionSettings;

					for (auto& SettingsElement : Element.Session.SessionSettings.Settings)
					{
						FSteamSessionSetting Setting;
						Setting.Key = SettingsElement.Key.ToString();

						switch (SettingsElement.Value.Data.GetType())
						{
						case EOnlineKeyValuePairDataType::Bool:
							bool bValue;
							SettingsElement.Value.Data.GetValue(bValue);
							Setting.Data.Set<bool>(bValue);
							break;
						case EOnlineKeyValuePairDataType::Int32:
							int32 IntValue;
							SettingsElement.Value.Data.GetValue(IntValue);
							Setting.Data.Set<int32>(IntValue);
							break;
						case EOnlineKeyValuePairDataType::String:
							FString Value;
							SettingsElement.Value.Data.GetValue(Value);
							Setting.Data.Set<FString>(Value);
							break;
						}

						AdditionalSessionSettings.Add(Setting);
					}

					FBlueprintSessionResult BPResult;
					BPResult.OnlineResult = Element;
					FString CustomSessionName;
					BPResult.OnlineResult.Session.SessionSettings.Get(STEAMKEY_OWNINGUSERNAME, CustomSessionName);

					if (CustomSessionName.Len() > 0)
					{
						BPResult.OnlineResult.Session.OwningUserName = CustomSessionName;
					}

					if (m_bUseLAN == false && Element.GetSessionIdStr().IsEmpty() == false)
					{
						FSteamID LobbyId = FCString::Atoi64(*Element.Session.GetSessionIdStr());

						if (LobbyId.IsValid())
						{
							if (ISteamMatchmaking* Matchmaking = SteamMatchmaking())
							{
								BPResult.OnlineResult.Session.NumOpenPublicConnections = (Matchmaking->GetLobbyMemberLimit(LobbyId) - Matchmaking->GetNumLobbyMembers(LobbyId));
							}
						}
					}

					BPResult.OnlineResult.PingInMs = Element.PingInMs;

					FString ResultText = FString::Printf(TEXT("Found a session (%s). Ping is %d"), *BPResult.OnlineResult.Session.OwningUserName, Element.PingInMs);

					FFrame::KismetExecutionMessage(*ResultText, ELogVerbosity::Log);

					m_SearchResults.Add(BPResult);

					Results.Add(FSteamSessionResult(BPResult, AdditionalSessionSettings));
				}

				OnCallback.Broadcast(Results);
			}
		}
	}

	SetReadyToDestroy();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		USteamCoreDestroySession
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USteamCoreDestroySession::USteamCoreDestroySession()
	: Delegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCompleted))
{
}

USteamCoreDestroySession* USteamCoreDestroySession::DestroySteamCoreSession(UObject* WorldContextObject, float Timeout)
{
	LogVerbose("");

	if (USteamCoreSubsystem* Subsystem = GetInstancedSubsystem(WorldContextObject))
	{
		const auto AsyncObject = NewObject<USteamCoreDestroySession>();
		AsyncObject->RegisterWithGameInstance(Subsystem->GetGameInstance());
		AsyncObject->m_WorldContextObject = WorldContextObject;

		return AsyncObject;
	}
	return nullptr;
}

void USteamCoreDestroySession::Activate()
{
	LogVerbose("");

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		const IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt.IsValid())
		{
			DelegateHandle = SessionInt->AddOnDestroySessionCompleteDelegate_Handle(Delegate);
			SessionInt->DestroySession(NAME_GameSession);

			return;
		}
	}

	OnFailure.Broadcast();
}

void USteamCoreDestroySession::OnCompleted(FName sessionName, bool bWasSuccessful)
{
	LogVerbose("");

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		const IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt.IsValid())
		{
			SessionInt->ClearOnDestroySessionCompleteDelegate_Handle(DelegateHandle);
		}
	}

	if (!IsInGameThread())
	{
		FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			if (bWasSuccessful)
			{
				OnSuccess.Broadcast();
			}
			else
			{
				OnFailure.Broadcast();
			}

			SetReadyToDestroy();
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	}
	else
	{
		if (bWasSuccessful)
		{
			OnSuccess.Broadcast();
		}
		else
		{
			OnFailure.Broadcast();
		}

		SetReadyToDestroy();
	}
}

USteamCoreUpdateSession::USteamCoreUpdateSession()
	: Delegate(FOnUpdateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCompleted))
{
}

USteamCoreUpdateSession* USteamCoreUpdateSession::UpdateSteamCoreSession(UObject* WorldContextObject, TMap<FString, FSteamSessionSearchSetting> Settings, FString SessionName, int32 MaxPlayers)
{
	LogVerbose("");

	if (USteamCoreSubsystem* Subsystem = GetInstancedSubsystem(WorldContextObject))
	{
		const auto AsyncObject = NewObject<USteamCoreUpdateSession>();
		AsyncObject->RegisterWithGameInstance(Subsystem->GetGameInstance());
		AsyncObject->m_WorldContextObject = WorldContextObject;

		AsyncObject->m_SessionSettings.NumPublicConnections = MaxPlayers;

		const auto OnlineSubsystem = IOnlineSubsystem::Get();

		if (OnlineSubsystem)
		{
			const IOnlineSessionPtr SessionInt = OnlineSubsystem->GetSessionInterface();

			if (SessionInt)
			{
				for (auto& Element : Settings)
				{
					if (Element.Key.Len() == 0)
					{
						continue;
					}

					FOnlineSessionSettings* SessionSettings = SessionInt->GetSessionSettings(NAME_GameSession);
					FOnlineSessionSetting* OldSetting = nullptr;

					OldSetting = SessionSettings->Settings.Find(*Element.Key);

					if (OldSetting)
					{
						LogVerbose("Updated old setting");

						if (Element.Value.Data.IsType<bool>())
						{
							OldSetting->Data = Element.Value.Data.Get<bool>() ? 1 : 0;
						}
						else if (Element.Value.Data.IsType<int32>())
						{
							OldSetting->Data = Element.Value.Data.Get<int32>();
						}
						else if (Element.Value.Data.IsType<FString>())
						{
							OldSetting->Data = Element.Value.Data.Get<FString>();
						}
					}
					else
					{
						LogVerbose("Added new setting");

						FOnlineSessionSetting Setting;
						Setting.AdvertisementType = EOnlineDataAdvertisementType::ViaOnlineService;

						if (Element.Value.Data.IsType<bool>())
						{
							Setting.Data.SetValue(Element.Value.Data.Get<bool>() ? 1 : 0);
						}
						else if (Element.Value.Data.IsType<int32>())
						{
							Setting.Data.SetValue(Element.Value.Data.Get<int32>());
						}
						else if (Element.Value.Data.IsType<FString>())
						{
							Setting.Data.SetValue(Element.Value.Data.Get<FString>());
						}

						SessionSettings->Set(FName(*Element.Key), Setting);

						AsyncObject->m_SessionSettings.Set(FName(*Element.Key), Setting);
					}
				}

				FOnlineSessionSetting Setting;
				Setting.AdvertisementType = EOnlineDataAdvertisementType::ViaOnlineService;
				Setting.Data.SetValue(*SessionName);

				AsyncObject->m_SessionSettings.Set(STEAMKEY_OWNINGUSERNAME, Setting);
			}
		}

		return AsyncObject;
	}
	return nullptr;
}

void USteamCoreUpdateSession::Activate()
{
	LogVerbose("");

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		const IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt->GetNumSessions() > 0)
		{
			FOnlineSessionSettings* Settings = SessionInt->GetSessionSettings(NAME_GameSession);

			if (Settings)
			{
				DelegateHandle = SessionInt->AddOnUpdateSessionCompleteDelegate_Handle(Delegate);

				if (!SessionInt->UpdateSession(NAME_GameSession, *Settings, true))
				{
					OnCompleted(NAME_GameSession, false);
				}
			}
			else
			{
				LogError("No session settings found");
			}
		}
		else
		{
			LogError("No active sessions found");
		}
	}
}

void USteamCoreUpdateSession::OnCompleted(FName SessionName, bool bWasSuccessful)
{
	LogVerbose("");

	const auto Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		const IOnlineSessionPtr SessionInt = Subsystem->GetSessionInterface();

		if (SessionInt)
		{
			SessionInt->ClearOnUpdateSessionCompleteDelegate_Handle(DelegateHandle);
		}
	}

	OnCallback.Broadcast();

	SetReadyToDestroy();
}
