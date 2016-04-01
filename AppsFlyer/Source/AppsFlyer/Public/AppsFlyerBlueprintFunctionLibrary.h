#pragma once

#include "AnalyticsBlueprintLibrary.h"
#include "AppsFlyerBlueprintFunctionLibrary.generated.h"

UCLASS()
class APPSFLYER_API UAppsFlyerBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AppsFlyer Analytics")
	static void TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttr>& attributes);
};
