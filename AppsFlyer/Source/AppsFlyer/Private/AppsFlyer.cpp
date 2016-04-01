// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "AppsFlyerPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FAppsFlyerModule"

DEFINE_LOG_CATEGORY_STATIC(LogAppsFlyerAnalytics, Log, All);

void FAppsFlyerModule::StartupModule()
{
	bInitialized = true;
}

void FAppsFlyerModule::ShutdownModule()
{

}

void FAppsFlyerModule::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes)
{
	if (bInitialized)
	{
		PlatformAppsFlyerHelper::TrackEvent(eventName, attributes);
	}
	else
	{
		UE_LOG(LogAppsFlyerAnalytics, Log, TEXT("FAppsFlyerModule::TrackEvent: Failed to track AppsFlyer event, becaise initialization has been failed."));
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAppsFlyerModule, AppsFlyer)