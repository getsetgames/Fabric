//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "FabricSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UFabricSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UFabricSettings(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Enable Crashlytics"))
	bool bEnableCrashlytics;
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Enable MoPub"))
	bool bEnableMoPub;
};
