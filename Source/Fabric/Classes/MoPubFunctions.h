//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "MoPubFunctions.generated.h"

UCLASS(NotBlueprintable)
class UMoPubFunctions : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (Keywords = "mopub ad advertising intersitial"), Category = "Fabric|MoPub")
	static bool MoPubHasInterstitial(FString AdUnitId);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "mopub ad advertising intersitial"), Category = "Fabric|MoPub")
	static void MoPubShowInterstitial(FString AdUnitId);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "mopub ad advertising intersitial"), Category = "Fabric|MoPub")
	static void MoPubCacheInterstitial(FString AdUnitId);
};
