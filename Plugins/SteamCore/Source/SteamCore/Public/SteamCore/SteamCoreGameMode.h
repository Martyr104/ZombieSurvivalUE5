/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SteamCoreGameMode.generated.h"

UCLASS()
class STEAMCORE_API ASteamCoreGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
};
