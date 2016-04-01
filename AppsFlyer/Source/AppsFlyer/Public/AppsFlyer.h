// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

#include "IAnalyticsProviderModule.h"
#include "IAnalyticsProvider.h"

class FAppsFlyerModule : public IModuleInterface
{
protected:
	bool bInitialized;
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FAppsFlyerModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FAppsFlyerModule >("AppsFlyer");
	}

	virtual void TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes);
};