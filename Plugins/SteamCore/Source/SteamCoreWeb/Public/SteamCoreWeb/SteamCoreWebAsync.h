/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCoreWeb Documentation: https://eeldev.com
*/

#pragma once

#include "CoreMinimal.h"
#include "OnlineAsyncTaskManager.h"
#include "SteamWebTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SteamCoreWeb/SteamCoreWebSettings.h"
#include "SteamCoreWeb/SteamCoreWeb.h"
#include "Interfaces/IHttpRequest.h"
#include "Online/HTTP/Public/HttpModule.h"
#include "Runtime/Launch/Resources/Version.h"
#include "SteamCoreWebAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSteamCoreWebFailure);

class USteamCoreWebSubsystem;

class FOnlineAsyncTaskSteamCoreWeb : public FOnlineAsyncTaskBasic<class USteamCoreSubsystem>
{
public:
	FOnlineAsyncTaskSteamCoreWeb(USteamCoreWebSubsystem* subsystem, const FOnSteamCoreWebCallback& callback, FString interfaceName, FString functionName, FString apiKey = "", int32 apiVersion = 1, EVerb verb = EVerb::GET, bool bPublicURL = false)
		: OnCallback(callback)
		, m_Subsystem(subsystem)
		, bInit(false)
		, bReceivedCallback(false)
		, m_InterfaceName(interfaceName)
		, m_FunctionName(functionName)
		, m_RequestString(FRequestString(apiKey))
		, m_APIv(apiVersion)
		, bUsePublicURL(bPublicURL)
	{
		switch (verb)
		{
		case EVerb::GET:
			m_Verb = TEXT("GET");
			break;
		case EVerb::POST:
			m_Verb = TEXT("POST");
			break;
		case EVerb::PUT:
			m_Verb = TEXT("PUT");
			break;
		}
	}

	virtual ~FOnlineAsyncTaskSteamCoreWeb() override
	{
		m_HTTPRequest->OnProcessRequestComplete().Unbind();
	}

public:
	FOnSteamCoreWebCallback OnCallback;
protected:
	USteamCoreWebSubsystem* m_Subsystem;
#if ENGINE_MINOR_VERSION >= 26 || ENGINE_MAJOR_VERSION == 5
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> m_HTTPRequest = FHttpModule::Get().CreateRequest();
#else
	TSharedRef<IHttpRequest> m_HTTPRequest = FHttpModule::Get().CreateRequest();
#endif
	FHttpRequestPtr m_Request;
	FHttpResponsePtr m_Response;
	bool bInit;
	bool bReceivedCallback;
public:
	FString m_InterfaceName;
	FString m_FunctionName;
	FRequestString m_RequestString;
	int32 m_APIv;
	FString m_Verb;
	bool bUsePublicURL;
protected:
	virtual FString ToString() const override { return ""; }
	virtual void Tick() override;
	virtual void Finalize() override;
	virtual void OnProcessRequestComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool bConnectedSuccessfully);
private:
	float AsyncTimeout = GetDefault<USteamCoreWebSettings>()->AsyncTaskTimeout;
};

class FOnlineAsyncTaskManagerSteamCoreWeb : public FOnlineAsyncTaskManager
{
public:
	FOnlineAsyncTaskManagerSteamCoreWeb()
	{
	}

	FOnlineAsyncTaskManagerSteamCoreWeb(class USteamCoreWebSubsystem* subsystem)
		: SteamCoreWebSubsystem(subsystem)
	{
	}

	virtual ~FOnlineAsyncTaskManagerSteamCoreWeb() override
	{
	}

private:
	class USteamCoreWebSubsystem* SteamCoreWebSubsystem;
protected:
	virtual void OnlineTick() override;
};

UCLASS()
class STEAMCOREWEB_API USteamCoreWebAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	USteamCoreWebAsyncAction()
		: m_WorldContextObject(nullptr)
	{
		OnCallbackInternal.BindUFunction(this, "HandleCallback");
	}

	virtual ~USteamCoreWebAsyncAction() override
	{
		OnCallbackInternal.Unbind();
	}

public:
	UPROPERTY(BlueprintAssignable)
	FOnSteamCoreWebAsyncCallback OnCallback;

	FOnSteamCoreWebCallback OnCallbackInternal;
public:
	UFUNCTION()
	virtual void HandleCallback(const FString& data, bool bWasSuccessful);

protected:
	TWeakObjectPtr<UObject> m_WorldContextObject;
};
