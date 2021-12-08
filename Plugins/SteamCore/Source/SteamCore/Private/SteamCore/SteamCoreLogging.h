/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*/

#define LogDebug(format, ...) UE_LOG(LogSteamCore, Log, TEXT("[%s] " format), *FString(__FUNCTION__), ##__VA_ARGS__)
#define LogVerbose(format, ...) UE_LOG(LogSteamCore, Verbose, TEXT("[%s] " format), *FString(__FUNCTION__), ##__VA_ARGS__)
#define LogVeryVerbose(format, ...) UE_LOG(LogSteamCore, VeryVerbose, TEXT("[%s] " format), *FString(__FUNCTION__), ##__VA_ARGS__)
#define LogError(format, ...) UE_LOG(LogSteamCore, Error, TEXT("[%s] " format), *FString(__FUNCTION__), ##__VA_ARGS__)
#define LogWarning(format, ...) UE_LOG(LogSteamCore, Warning, TEXT("[%s] " format), *FString(__FUNCTION__), ##__VA_ARGS__)
