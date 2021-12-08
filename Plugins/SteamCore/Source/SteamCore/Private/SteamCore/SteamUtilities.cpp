/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCore Documentation: https://eeldev.com
*/

#include "SteamCore/SteamUtilities.h"
#include "SteamCorePluginPrivatePCH.h"
#include "OnlineSubsystemSteamModule.h"
#include "SteamMatchmakingServers/SteamMatchmakingServersTypes.h"
#include "OnlinePingInterfaceSteam.h"
#include "SteamSharedModule.h"
#include "SteamMatchmakingServers/SteamMatchmakingServersAsyncTasks.h"

TArray<FOnSteamMessage> USteamUtilities::s_SteamMessageListeners;

USteamCoreVoice::USteamCoreVoice(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Duration = INDEFINITELY_LOOPING_DURATION;
	NumChannels = 1;
	bLooping = false;
	bCanProcessAsync = true;
}

void USteamCoreVoice::AddAudioBuffer(const TArray<uint8>& Buffer)
{
	QueueAudio(Buffer.GetData(), Buffer.Num());
}

void USteamCoreVoice::DestroySteamCoreVoice(USteamCoreVoice* OBJ)
{
	LogVerbose("");

	if (OBJ)
	{
		OBJ->RemoveFromRoot();
	}
}

USteamCoreVoice* USteamCoreVoice::ConstructSteamCoreVoice(int32 AudioSampleRate)
{
	LogVerbose("");

	check(AudioSampleRate > 0);

	USteamCoreVoice* Obj = NewObject<USteamCoreVoice>();
	Obj->AddToRoot();
	Obj->SetSampleRate(AudioSampleRate);

	return Obj;
}

FSteamID USteamUtilities::MakeSteamID(FString Value)
{
	uint64 TempId = 0;
	LexFromString(TempId, *Value);
	return FSteamID(TempId);
}

FSteamGameID USteamUtilities::MakeSteamGameID(FString Value)
{
	uint64 TempId = 0;
	LexFromString(TempId, *Value);
	return FSteamGameID(TempId);
}

FString USteamUtilities::BreakSteamID(FSteamID SteamID)
{
	return LexToString(static_cast<uint64>(SteamID));
}

FString USteamUtilities::BreakSteamGameID(FSteamGameID SteamID)
{
	return LexToString(static_cast<uint64>(SteamID));
}

FPublishedFileID USteamUtilities::MakePublishedFileID(FString Value)
{
	uint64 TempId = 0;
	LexFromString(TempId, *Value);
	return FPublishedFileID(TempId);
}

FSteamUGCHandle USteamUtilities::MakeUGCHandle(FString Value)
{
	uint64 TempId = 0;
	LexFromString(TempId, *Value);
	return FSteamUGCHandle(TempId);
}

FSteamInventoryUpdateHandle USteamUtilities::MakeInventoryUpdateHandle(FString Value)
{
	uint64 TempId = 0;
	LexFromString(TempId, *Value);
	return FSteamInventoryUpdateHandle(TempId);
}

FSteamTicketHandle USteamUtilities::MakeTicketHandle(FString Value)
{
	uint64 TempId = 0;
	LexFromString(TempId, *Value);
	return FSteamTicketHandle(TempId);
}

FString USteamUtilities::BreakPublishedFileID(FPublishedFileID FileID)
{
	return LexToString(static_cast<uint64>(FileID));
}

FString USteamUtilities::BreakUGCHandle(FSteamUGCHandle Handle)
{
	return LexToString(static_cast<uint64>(Handle));
}

FString USteamUtilities::BreakInventoryUpdateHandle(FSteamInventoryUpdateHandle Handle)
{
	return LexToString(static_cast<uint64>(Handle));
}

FString USteamUtilities::BreakTicketHandle(FSteamTicketHandle Handle)
{
	return LexToString(static_cast<uint64>(Handle));
}

bool USteamUtilities::IsValid(FSteamID SteamID)
{
	return CSteamID(SteamID.GetValue()).IsValid();
}

bool USteamUtilities::IsPublishedFileIDValid(FPublishedFileID PublishedFileId)
{
	return PublishedFileId.IsValid();
}

bool USteamUtilities::Equal(FSteamID A, FSteamID B)
{
	return A == B;
}

bool USteamUtilities::NotEqual(FSteamID A, FSteamID B)
{
	return A != B;
}

bool USteamUtilities::PublishedFileID_Equals(FPublishedFileID A, FPublishedFileID B)
{
	return A == B;
}

bool USteamUtilities::PublishedFileID_NotEquals(FPublishedFileID A, FPublishedFileID B)
{
	return A != B;
}

bool USteamUtilities::SteamItemInstanceID_Equals(FSteamItemInstanceID A, FSteamItemInstanceID B)
{
	return static_cast<uint64>(A) == static_cast<uint64>(B);
}

void USteamUtilities::SteamItemInstanceID_Equals_Exec(FSteamItemInstanceID A, FSteamItemInstanceID B, ESteamCoreIdentical& Result)
{
	Result = static_cast<uint64>(A) == static_cast<uint64>(B) ? ESteamCoreIdentical::Identical : ESteamCoreIdentical::NotIdentical;
}

ESteamAccountType USteamUtilities::GetAccountType(FSteamID SteamID)
{
	return static_cast<ESteamAccountType>((CSteamID(SteamID.GetValue())).GetEAccountType());
}

bool USteamUtilities::IsLobby(FSteamID SteamID)
{
	return CSteamID(SteamID.GetValue()).IsLobby();
}

bool USteamUtilities::IsSteamAvailable()
{
	return SteamAPI_Init();
}

UServerFilter* USteamUtilities::ConstructServerFilter(UObject* WorldContextObject)
{
	UServerFilter* Object = nullptr;

	if (WorldContextObject)
	{
		Object = NewObject<UServerFilter>(WorldContextObject);

		if (Object)
		{
			Object->AddToRoot();
		}
	}
	else
	{
		UE_LOG(LogSteamCore, Error, TEXT("No world context object when creating UServerFilter object!"));
	}

	return Object;
}

FString USteamUtilities::EncryptString(FString String)
{
	FString Result;

	if (String.Len() > 0)
	{
		Result = FMD5::HashAnsiString(*String);
	}

	return Result;
}

void USteamUtilities::GetPublicIp(const FOnHTTPResponse& Callback)
{
	LogVeryVerbose("");

	FHttpModule* HttpModule = &FHttpModule::Get();

	if (HttpModule && HttpModule->IsHttpEnabled())
	{
		auto Request = HttpModule->CreateRequest();
		Request->SetVerb("GET");
		Request->SetURL(FString("http://api.ipify.org"));
		Request->SetHeader("User-Agent", "X-SteamCore/1.0");
		Request->SetHeader("Content-Type", "text/html");

		Request->OnProcessRequestComplete().BindLambda([Callback](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (Response)
			{
				Callback.ExecuteIfBound(Response->GetContentAsString());
			}
		});

		if (!Request->ProcessRequest())
		{
			LogWarning("Unable to send HTTP request");
		}
	}
}

void USteamUtilities::ReleaseRequest()
{
	if (FOnlineAsyncTaskSteamCoreMatchmakingServersServerList::m_CallbackResults != nullptr)
	{
		SteamMatchmakingServers()->ReleaseRequest(FOnlineAsyncTaskSteamCoreMatchmakingServersServerList::m_CallbackResults);
		FOnlineAsyncTaskSteamCoreMatchmakingServersServerList::m_CallbackResults = nullptr;
	}
}

void USteamUtilities::CancelQuery()
{
	if (FOnlineAsyncTaskSteamCoreMatchmakingServersServerList::m_CallbackResults != nullptr)
	{
		SteamMatchmakingServers()->CancelQuery(FOnlineAsyncTaskSteamCoreMatchmakingServersServerList::m_CallbackResults);
	}
}

FSteamID USteamUtilities::GetSteamIdFromPlayerState(APlayerState* PlayerState)
{
	FSteamID SteamId;

	if (PlayerState)
	{
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION > 24
		SteamId = FSteamID(FCString::Atoi64(*PlayerState->GetUniqueId().ToString()));
#else
		SteamId = FSteamID(FCString::Atoi64(*PlayerState->UniqueId.ToString()));
#endif
	}

	return SteamId;
}

TArray<uint8> USteamUtilities::BP_StringToBytes(FString String)
{
	TArray<uint8> Array;
	Array.SetNum(String.Len());

	StringToBytes(String, Array.GetData(), String.Len());
	
	return Array;
}

FString USteamUtilities::BP_BytesToString(TArray<uint8> Array)
{
	return BytesToString(Array.GetData(), Array.Num());
}

bool USteamUtilities::IsSteamServerInitialized()
{
	if (FSteamSharedModule::IsAvailable())
	{
		const auto ServerHandle = FSteamSharedModule::Get().ObtainSteamServerInstanceHandle();
		
		if (ServerHandle.IsValid())
		{
			return ServerHandle->IsInitialized();
		}
	}

	return false;
}

bool USteamUtilities::IsUsingP2PRelays()
{
	FOnlineSubsystemSteam* SteamSubsystem = static_cast<FOnlineSubsystemSteam*>(IOnlineSubsystem::Get(STEAM_SUBSYSTEM));

	if (SteamSubsystem && SteamSubsystem->GetPingInterface())
	{
		return SteamSubsystem->GetPingInterface()->IsUsingP2PRelays();
	}

	return false;
}

FHostPingData USteamUtilities::GetHostPingData()
{
	FOnlineSubsystemSteam* SteamSubsystem = static_cast<FOnlineSubsystemSteam*>(IOnlineSubsystem::Get(STEAM_SUBSYSTEM));

	if (SteamSubsystem && SteamSubsystem->GetPingInterface())
	{
		return FHostPingData(SteamSubsystem->GetPingInterface()->GetHostPingData());
	}

	return FHostPingData();
}

int32 USteamUtilities::GetPingFromHostData(const FHostPingData& Data)
{
	FOnlineSubsystemSteam* SteamSubsystem = static_cast<FOnlineSubsystemSteam*>(IOnlineSubsystem::Get(STEAM_SUBSYSTEM));

	if (SteamSubsystem && SteamSubsystem->GetPingInterface())
	{
		return SteamSubsystem->GetPingInterface()->GetPingFromHostData(Data);
	}

	return 0;
}

bool USteamUtilities::IsRecalculatingPing()
{
	FOnlineSubsystemSteam* SteamSubsystem = static_cast<FOnlineSubsystemSteam*>(IOnlineSubsystem::Get(STEAM_SUBSYSTEM));

	if (SteamSubsystem && SteamSubsystem->GetPingInterface())
	{
		return SteamSubsystem->GetPingInterface()->IsRecalculatingPing();
	}

	return false;
}