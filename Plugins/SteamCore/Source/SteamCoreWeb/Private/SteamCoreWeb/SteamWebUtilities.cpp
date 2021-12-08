/**
* Copyright (C) 2017-2021 | eelDev (Dry Eel Development)
*
* Official SteamCoreWeb Documentation: https://eeldev.com
*/

#include "SteamCoreWeb/SteamWebUtilities.h"
#include "SteamCoreWeb/SteamCoreWebPluginPrivatePCH.h"
#include "SteamCoreWeb/SteamCoreWebSettings.h"

TArray<FSteamCoreJson> ParseJson_Internal(TSharedPtr<FJsonObject> obj)
{
	TArray<FSteamCoreJson> m_Result;

	for (auto it = obj->Values.CreateConstIterator(); it; ++it)
	{
		auto m_Type = it->Value->Type;

		if (m_Type != EJson::Object)
		{
			if (m_Type != EJson::Array)
			{
				switch (m_Type)
				{
				case EJson::String:
					m_Result.Add(FSteamCoreJson(it.Key(), it.Value()->AsString()));
					break;
				case EJson::Number:
					m_Result.Add(FSteamCoreJson(it.Key(), it.Value()->AsNumber()));
					break;
				case EJson::Boolean:
					m_Result.Add(FSteamCoreJson(it.Key(), it.Value()->AsBool()));
					break;
				}
			}
			else if (m_Type == EJson::Array)
			{
				for (auto m_Data : it.Value()->AsArray())
				{
					if (m_Data->Type == EJson::Object)
					{
						TArray<FSteamCoreJson> m_ReturnedData = ParseJson_Internal(m_Data->AsObject());

						for (auto m_data : m_ReturnedData)
						{
							m_Result.Add(m_data);
						}
					}
				}
			}
		}
		else if (it->Value->Type == EJson::Object)
		{
			TArray<FSteamCoreJson> m_ReturnedData = ParseJson_Internal(it->Value->AsObject());

			for (auto m_data : m_ReturnedData)
			{
				m_Result.Add(m_data);
			}
		}
	}

	return m_Result;
}

bool USteamWebUtilities::ParseJson(const FString& jsonString, TArray<FSteamCoreJson>& data)
{
	TSharedPtr<FJsonObject> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		data = ParseJson_Internal(JsonParsed);

		return true;
	}
	return false;
}

void USteamWebUtilities::FindJsonString(const FString& jsonString, FString key, FString& value, ESteamJsonResult& result)
{
	result = ESteamJsonResult::NotFound;

	TArray<FSteamCoreJson> m_Data;
	key.RemoveSpacesInline();

	FString m_Result;

	if (ParseJson(jsonString, m_Data))
	{
		for (auto data : m_Data)
		{
			if (data.Key.Equals(key, ESearchCase::IgnoreCase) && data.Type == ESteamValueType::STRING)
			{
				value = data.String;

				result = ESteamJsonResult::Found;
				return;
			}
		}
		if (result == ESteamJsonResult::NotFound)
		{
			for (auto data : m_Data)
			{
				if (FindValueInString(data.String, key, value))
				{
					result = ESteamJsonResult::Found;
					return;
				}
			}
		}
	}
}

void USteamWebUtilities::FindJsonStrings(const FString& jsonString, FString key, TArray<FString>& values, ESteamJsonResult& result)
{
	result = ESteamJsonResult::NotFound;

	TArray<FSteamCoreJson> m_Data;
	key.RemoveSpacesInline();

	if (ParseJson(jsonString, m_Data))
	{
		for (auto data : m_Data)
		{
			if (data.Key.Equals(key, ESearchCase::IgnoreCase) && data.Type == ESteamValueType::STRING)
			{
				values.Add(data.String);
			}
		}

		result = values.Num() > 0 ? ESteamJsonResult::Found : ESteamJsonResult::NotFound;

		if (result == ESteamJsonResult::NotFound)
		{
			for (auto data : m_Data)
			{
				TArray<FString> m_Result;

				if (FindValuesInString(data.String, key, m_Result))
				{
					for (int32 i = 0; i < m_Result.Num(); i++)
					{
						values.Add(m_Result[i]);
					}
				}
			}
		}

		result = values.Num() > 0 ? ESteamJsonResult::Found : ESteamJsonResult::NotFound;
	}
}

void USteamWebUtilities::FindJsonBool(const FString& jsonString, FString key, bool& value, ESteamJsonResult& result)
{
	result = ESteamJsonResult::NotFound;

	TArray<FSteamCoreJson> m_Data;
	key.RemoveSpacesInline();

	if (ParseJson(jsonString, m_Data))
	{
		for (auto data : m_Data)
		{
			if (data.Key.Equals(key, ESearchCase::IgnoreCase) && data.Type == ESteamValueType::BOOL)
			{
				value = data.Bool;

				result = ESteamJsonResult::Found;
				return;
			}
		}
	}
}

void USteamWebUtilities::FindJsonBools(const FString& jsonString, FString key, TArray<bool>& values, ESteamJsonResult& result)
{
	result = ESteamJsonResult::NotFound;

	TArray<FSteamCoreJson> m_Data;
	key.RemoveSpacesInline();

	if (ParseJson(jsonString, m_Data))
	{
		for (auto data : m_Data)
		{
			if (data.Key.Equals(key, ESearchCase::IgnoreCase) && data.Type == ESteamValueType::BOOL)
			{
				values.Add(data.Bool);
			}
		}
		result = values.Num() > 0 ? ESteamJsonResult::Found : ESteamJsonResult::NotFound;
	}
}

void USteamWebUtilities::FindJsonNumber(const FString& jsonString, FString key, int32& value, ESteamJsonResult& result)
{
	result = ESteamJsonResult::NotFound;

	TArray<FSteamCoreJson> m_Data;
	key.RemoveSpacesInline();

	if (ParseJson(jsonString, m_Data))
	{
		for (auto data : m_Data)
		{
			if (data.Key.Equals(key, ESearchCase::IgnoreCase) && data.Type == ESteamValueType::NUMBER)
			{
				value = data.Number;

				result = ESteamJsonResult::Found;
				return;
			}
		}
	}
}

void USteamWebUtilities::FindJsonNumbers(const FString& jsonString, FString key, TArray<int32>& values, ESteamJsonResult& result)
{
	result = ESteamJsonResult::NotFound;

	TArray<FSteamCoreJson> m_Data;
	key.RemoveSpacesInline();

	if (ParseJson(jsonString, m_Data))
	{
		for (auto data : m_Data)
		{
			if (data.Key.Equals(key, ESearchCase::IgnoreCase) && data.Type == ESteamValueType::NUMBER)
			{
				values.Add(data.Number);
			}
		}

		result = values.Num() > 0 ? ESteamJsonResult::Found : ESteamJsonResult::NotFound;
	}
}

FString USteamWebUtilities::GetProjectKey()
{
	return GetDefault<USteamCoreWebSettings>()->Key;
}

int32 USteamWebUtilities::GetProjectAppID()
{
	return GetDefault<USteamCoreWebSettings>()->AppID;
}

FString USteamWebUtilities::GetDevSteamID()
{
	return GetDefault<USteamCoreWebSettings>()->DevSteamID;
}

bool USteamWebUtilities::FindValueInString(const FString& string, const FString& key, FString& outString)
{
	TArray<FString> m_Values;
	FindValuesInString(string, key, m_Values);

	if (m_Values.IsValidIndex(0))
	{
		outString = m_Values[0];
		return true;
	}
	return false;
}

bool USteamWebUtilities::FindValuesInString(const FString& string, const FString& key, TArray<FString>& outStrings, int32 MaxResults)
{
	FString m_Key = key;
	m_Key.ReplaceInline(TEXT(" "), TEXT(""));

	TArray<FString> m_ParsedString;
	string.ParseIntoArray(m_ParsedString, TEXT(","));

	for (int32 i = 0; i < m_ParsedString.Num(); i++)
	{
		if (m_ParsedString[i].Contains(key))
		{
			FString m_KeyValue;
			FString m_StringValue;
			m_ParsedString[i].Split(":", &m_KeyValue, &m_StringValue, ESearchCase::IgnoreCase, ESearchDir::FromStart);
			m_KeyValue.ReplaceInline(TEXT(" "), TEXT(""));

			if (m_KeyValue.Len() != m_Key.Len())
			{
				// key didnt match, lets try stripping it in case it has funny characters
				m_KeyValue.ReplaceInline(TEXT("\""), TEXT(""));

				if (m_KeyValue.Len() != m_Key.Len())
				{
					m_KeyValue.ReplaceInline(TEXT("{"), TEXT(""));
				}
				if (m_KeyValue.Len() != m_Key.Len())
				{
					m_KeyValue.ReplaceInline(TEXT("}"), TEXT(""));
				}
				if (m_KeyValue.Len() != m_Key.Len())
				{
					m_KeyValue.ReplaceInline(TEXT("["), TEXT(""));
				}
				if (m_KeyValue.Len() != m_Key.Len())
				{
					m_KeyValue.ReplaceInline(TEXT("]"), TEXT(""));
				}

				if (m_KeyValue.Len() != m_Key.Len())
				{
					continue;
				}
			}

			m_StringValue.ReplaceInline(TEXT("\""), TEXT(""));
			outStrings.Add(m_StringValue);

			if (MaxResults != INDEX_NONE)
			{
				if (outStrings.Num() >= MaxResults)
				{
					break;
				}
			}
		}
	}

	return outStrings.Num() > 0;
}
