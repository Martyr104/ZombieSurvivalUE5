/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCoreWeb Documentation: https://eeldev.com
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Package.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SteamWebTypes.h"
#include "SteamWebUtilities.generated.h"
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Steam Utilities Class
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
template <typename TEnum>
static FORCEINLINE FString GetSteamCoreWebEnumAsString(const FString& name, TEnum val)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *name, true);
	if (!EnumPtr)
	{
		return "";
	}

	return EnumPtr->GetNameStringByValue(static_cast<int64>(val));
}

UCLASS(abstract)
class STEAMCOREWEB_API USteamWebUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	* Parse JSON Result
	*
	* @param	jsonString	JsonString from Steam WEB Api
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Utilities")
	static bool ParseJson(const FString& jsonString, TArray<FSteamCoreJson>& data);

	/**
	* Try finding a string value from a JsonResult
	*
	* @param	jsonString		JsonString from Steam WEB Api
	* @param	key				The key that contains the value (NOT case sensitive)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Utilities", meta = (ExpandEnumAsExecs = result))
	static void FindJsonString(const FString& jsonString, FString key, FString& value, ESteamJsonResult& result);

	/**
	* Try finding an array of string values from a JsonResult
	*
	* @param	jsonString		JsonString from Steam WEB Api
	* @param	key				The key that contains the value (NOT case sensitive)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Utilities", meta = (ExpandEnumAsExecs = result))
	static void FindJsonStrings(const FString& jsonString, FString key, TArray<FString>& values, ESteamJsonResult& result);

	/**
	* Try finding a bool value from a JsonResult
	*
	* @param	jsonString		JsonString from Steam WEB Api
	* @param	key				The key that contains the value (NOT case sensitive)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Utilities", meta = (ExpandEnumAsExecs = result))
	static void FindJsonBool(const FString& jsonString, FString key, bool& value, ESteamJsonResult& result);

	/**
	* Try finding an array of bool values from a JsonResult
	*
	* @param	jsonString		JsonString from Steam WEB Api
	* @param	key				The key that contains the value (NOT case sensitive)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Utilities", meta = (ExpandEnumAsExecs = result))
	static void FindJsonBools(const FString& jsonString, FString key, TArray<bool>& values, ESteamJsonResult& result);

	/**
	* Try finding a number value from a JsonResult
	*
	* @param	jsonString		JsonString from Steam WEB Api
	* @param	key				The key that contains the value (NOT case sensitive)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Utilities", meta = (ExpandEnumAsExecs = result))
	static void FindJsonNumber(const FString& jsonString, FString key, int32& value, ESteamJsonResult& result);

	/**
	* Try finding an array of number values from a JsonResult
	*
	* @param	jsonString		JsonString from Steam WEB Api
	* @param	key				The key that contains the value (NOT case sensitive)
	*/
	UFUNCTION(BlueprintCallable, Category = "SteamCoreWeb|Utilities", meta = (ExpandEnumAsExecs = result))
	static void FindJsonNumbers(const FString& jsonString, FString key, TArray<int32>& values, ESteamJsonResult& result);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SteamCoreWeb|Utilities")
	static FString GetProjectKey();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SteamCoreWeb|Utilities")
	static int32 GetProjectAppID();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SteamCoreWeb|Utilities")
	static FString GetDevSteamID();

private:
	/*
	Find a value in string, returns the value index in the string
	*/
	static bool FindValueInString(const FString& string, const FString& key, FString& outString);
	static bool FindValuesInString(const FString& string, const FString& key, TArray<FString>& outStrings, int32 MaxResults = INDEX_NONE);
};
