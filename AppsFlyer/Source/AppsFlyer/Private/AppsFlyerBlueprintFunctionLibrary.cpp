#include "AppsFlyerPrivatePCH.h"
#include "AppsFlyerBlueprintFunctionLibrary.h"
#include "AppsFlyer.h"

DEFINE_LOG_CATEGORY_STATIC(LogAppsFlyerAnalytics, Log, All);

void UAppsFlyerBlueprintFunctionLibrary::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttr>& attributes)
{
	FAppsFlyerModule *appsFlyerModule = &FAppsFlyerModule::Get();
	if (appsFlyerModule)
	{
		TArray<FAnalyticsEventAttribute> convertedAttributes;

		for (int32 i = 0; i < attributes.Num(); i++)
		{
			convertedAttributes.Add(FAnalyticsEventAttribute(attributes[i].Name, attributes[i].Value));
		}

		appsFlyerModule->TrackEvent(eventName, convertedAttributes);
	}
	else
	{
		UE_LOG(LogAppsFlyerAnalytics, Warning, TEXT("UAppsFlyerBlueprintFunctionLibrary::TrackEvent: mixpanel module is NULL"));
	}
}


