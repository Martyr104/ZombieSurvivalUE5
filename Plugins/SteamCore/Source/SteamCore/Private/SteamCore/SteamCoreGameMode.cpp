/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*/

#include "SteamCoreGameMode.h"
#include <GameFramework/GameSession.h>

void ASteamCoreGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	ErrorMessage = GameSession->ApproveLogin(Options);
	FGameModeEvents::GameModePreLoginEvent.Broadcast(this, UniqueId, ErrorMessage);
}
