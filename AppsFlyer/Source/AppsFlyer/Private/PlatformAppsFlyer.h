#ifndef PlatformAppsFlyer_h
#define PlatformAppsFlyer_h

#include "AppsFlyerPrivatePCH.h"

#if PLATFORM_IOS
#import <Foundation/Foundation.h>
#include "AppsFlyerSDK/AppsFlyerTracker.h"

@interface IOSAppsFlyer : NSObject

+ (void)InitWithID : (NSString*)appID withDevKey : (NSString*)devKey;
+(void) TrackEvent:(NSString*) eventName withProperies:(NSDictionary *)properties;

@end
#endif // PLATFORM_IOS

class PlatformAppsFlyerHelper
{
protected:

    PlatformAppsFlyerHelper();
public:
	virtual ~PlatformAppsFlyerHelper() {};
    
    static bool InitAppsFlyer(const FString& apiKey, const FString& devKey);
    static void TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes);
};

#endif /* PlatformAppsFlyer_h */
