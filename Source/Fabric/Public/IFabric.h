//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ModuleManager.h"

class IFabric : public IModuleInterface
{

public:

	static inline IFabric& Get()
	{
		return FModuleManager::LoadModuleChecked< IFabric >( "Fabric" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "Fabric" );
	}
};

