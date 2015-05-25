//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FabricPrivatePCH.h"
#include "FabricSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogFabric);

#define LOCTEXT_NAMESPACE "Fabric"

class FFabric : public IFabric
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FFabric, Fabric )

void FFabric::StartupModule()
{
	const UFabricSettings* DefaultSettings = GetDefault<UFabricSettings>();

#if PLATFORM_IOS
	NSMutableArray* Kits = [NSMutableArray array];
	
	if (DefaultSettings->bEnableCrashlytics)
	{
		[Kits addObject:CrashlyticsKit];
	}
	
	if (DefaultSettings->bEnableMoPub)
	{
		[Kits addObject:MoPubKit];
	}
	
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Fabric with:Kits];
	});
#endif

	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Fabric",
										 LOCTEXT("RuntimeSettingsName", "Fabric"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the Fabric plugin"),
										 GetMutableDefault<UFabricSettings>()
										 );
	}
}


void FFabric::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
