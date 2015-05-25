//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "CoreUObject.h"
#include "Engine.h"

#include "IFabric.h"

// You should place include statements to your module's private header files here.  You only need to
// add includes for headers that are used in most of your module's source files though.

#if PLATFORM_IOS
#import "IOSAppDelegate.h"
#import "IOSView.h"

#import <Fabric/Fabric.h>
#import <Crashlytics/Crashlytics.h>
#import <MoPub/MoPub.h>
#endif

DECLARE_LOG_CATEGORY_EXTERN(LogFabric, Log, All);

#include "FabricClasses.h"
