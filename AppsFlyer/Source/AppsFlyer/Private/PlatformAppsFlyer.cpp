#include "AppsFlyerPrivatePCH.h"

#if PLATFORM_IOS

@interface AppsFlyerEventHandler : NSObject
{

}

+(id)StaticInit;
@end

@implementation AppsFlyerEventHandler

+ (id)StaticInit
{
	AppsFlyerEventHandler *instance = [[AppsFlyerEventHandler alloc] init];

	if (instance)
	{
		[[NSNotificationCenter defaultCenter] addObserver:instance
			selector : @selector(didFinishLaunchWithOptions : )
					   name:UIApplicationDidBecomeActiveNotification object : nil];
	}

	return instance;
}

-(void)didFinishLaunchWithOptions:(UIApplication *)application
{
	NSString *appID = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"AppsFlyerAppID"];
	NSString *devKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"AppsFlyerDevKey"];

	if (appID && devKey)
	{
		NSLog(@"Init AppsFlyer");
			PlatformAppsFlyerHelper::InitAppsFlyer(FString(appID), FString(devKey));
	}
}

@end

static AppsFlyerEventHandler *EventHandlerStaticInitializer = [AppsFlyerEventHandler StaticInit];


@implementation IOSAppsFlyer

+ (void)InitWithID : (NSString*)appID withDevKey : (NSString*)devKey;
{    
	if (![AppsFlyerTracker class])
		return;

	[AppsFlyerTracker sharedTracker].appsFlyerDevKey = devKey;
	[AppsFlyerTracker sharedTracker].appleAppID = appID;
}

+(void) TrackEvent:(NSString*) eventName withProperies:(NSDictionary *)properties
{
	dispatch_async(dispatch_get_main_queue(), ^
	{
		[[AppsFlyerTracker sharedTracker] trackEvent:eventName withValues : properties];
	});
}

@end
#endif // PLATFORM_IOS


bool PlatformAppsFlyerHelper::InitAppsFlyer(const FString& apiKey, const FString& devKey)
{
#if PLATFORM_IOS
	[IOSAppsFlyer InitWithID : [NSString stringWithFString : apiKey]
		withDevKey : [NSString stringWithFString : devKey]];

	return true;
#endif // PLATFORM_IOS

	return false;
}

void PlatformAppsFlyerHelper::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes)
{
#if PLATFORM_IOS    
	NSString* convertedEventName = [NSString stringWithFString : eventName];
	const int32 attrCount = attributes.Num();
	if (attrCount > 0)
	{
		NSDictionary* attributesDict = [NSMutableDictionary dictionaryWithCapacity : attrCount];
		for (auto attr : attributes)
		{
			NSString* attrName = [NSString stringWithFString : attr.AttrName];
			NSString* attrValue = [NSString stringWithFString : attr.AttrValue];
			[attributesDict setValue : attrValue forKey : attrName];
		}

		[IOSAppsFlyer TrackEvent : convertedEventName withProperies : attributesDict];
	}
#endif // PLATFORM_IOS
}
