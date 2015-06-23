//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FabricPrivatePCH.h"

#if PLATFORM_IOS
static NSMutableDictionary* AdCache = [NSMutableDictionary dictionary];
#endif

bool UMoPubFunctions::MoPubHasInterstitial(FString AdUnitId)
{
#if PLATFORM_IOS
	MPInterstitialAdController* Interstitial = [AdCache objectForKey:AdUnitId.GetNSString()];
	
	if (Interstitial && Interstitial.ready)
	{
		return true;
	}
#endif
	
	return false;
}

void UMoPubFunctions::MoPubShowInterstitial(FString AdUnitId)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		MPInterstitialAdController* Interstitial = [AdCache objectForKey:AdUnitId.GetNSString()];
		
		if (Interstitial && Interstitial.ready)
		{
			IOSAppDelegate* AppDelegate = (IOSAppDelegate*)[[UIApplication sharedApplication] delegate];
			[Interstitial showFromViewController:AppDelegate.IOSController];
		}
	});
#endif
}

void UMoPubFunctions::MoPubCacheInterstitial(FString AdUnitId)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		MPInterstitialAdController* Interstitial = [MPInterstitialAdController interstitialAdControllerForAdUnitId:AdUnitId.GetNSString()];
		[Interstitial loadAd];
		[AdCache setObject:Interstitial forKey:AdUnitId.GetNSString()];
	});
#endif
}
